// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"

// CRKBD-specific platform-agnostic user codes for encoder behavior
// Browser navigation and app/tab switching that adapts to the current platform:
// - Mac: CMD+[ / CMD+] for browser, CMD for app switching, CTRL for tab switching
// - Windows/Linux: Browser media keys (KC_WFWD/KC_WBAK) for navigation, ALT for app switching, CTRL for tab switching
// - FUN mode: Not available (set to KC_NO)
#if defined (MIRYOKU_CLIPBOARD_FUN)
  #define U_FWD KC_NO // Browser forward - not available in FUN mode
  #define U_BCK KC_NO // Browser backward - not available in FUN mode
  #define U_APP_MOD MOD_BIT(KC_NO) // App switch modifier - not available in FUN mode
  #define U_TAB_MOD MOD_BIT(KC_NO) // Tab switch modifier - not available in FUN mode
  #define U_WIN_SWITCH_CW KC_NO // Window switch clockwise - not available in FUN mode
  #define U_WIN_SWITCH_CCW KC_NO // Window switch counter-clockwise - not available in FUN mode
  #define U_WORKSPACE_CW KC_NO // Workspace switch clockwise - not available in FUN mode
  #define U_WORKSPACE_CCW KC_NO // Workspace switch counter-clockwise - not available in FUN mode
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_FWD LGUI(KC_RBRC) // Browser forward
  #define U_BCK LGUI(KC_LBRC) // Browser backward
  #define U_APP_MOD MOD_BIT(KC_LGUI) // App switch modifier (CMD)
  #define U_TAB_MOD MOD_BIT(KC_LCTL) // Tab switch modifier (CTRL)
  #define U_WIN_MOD MOD_BIT(KC_LGUI) // Window management modifier (CMD)
  #define U_WIN_SWITCH_CW LGUI(KC_GRV) // Window switch clockwise (CMD+`)
  #define U_WIN_SWITCH_CCW LGUI(LSFT(KC_GRV)) // Window switch counter-clockwise (CMD+SHIFT+`)
  #define U_WORKSPACE_CW LCTL(KC_RGHT) // Workspace switch clockwise (CTRL+Right)
  #define U_WORKSPACE_CCW LCTL(KC_LEFT) // Workspace switch counter-clockwise (CTRL+Left)
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_FWD KC_WFWD // Browser forward (media key)
  #define U_BCK KC_WBAK // Browser backward (media key)
  #define U_APP_MOD MOD_BIT(KC_LALT) // App switch modifier (ALT)
  #define U_TAB_MOD MOD_BIT(KC_LCTL) // Tab switch modifier (CTRL)
  #define U_WIN_MOD MOD_BIT(KC_LALT) // Window management modifier (ALT)
  #define U_WIN_SWITCH_CW LALT(KC_TAB) // Window switch clockwise (ALT+Tab)
  #define U_WIN_SWITCH_CCW LALT(LSFT(KC_TAB)) // Window switch counter-clockwise (ALT+SHIFT+Tab)
  #define U_WORKSPACE_CW LGUI(KC_RGHT) // Workspace switch clockwise (WIN+Right)
  #define U_WORKSPACE_CCW LGUI(KC_LEFT) // Workspace switch counter-clockwise (WIN+Left)
#else
  #define U_FWD KC_WFWD // Browser forward (media key, default)
  #define U_BCK KC_WBAK // Browser backward (media key, default)
  #define U_APP_MOD MOD_BIT(KC_LALT) // App switch modifier (ALT, default)
  #define U_TAB_MOD MOD_BIT(KC_LCTL) // Tab switch modifier (CTRL, default)
  #define U_WIN_MOD MOD_BIT(KC_LALT) // Window management modifier (ALT, default)
  #define U_WIN_SWITCH_CW LALT(KC_TAB) // Window switch clockwise (ALT+Tab, default)
  #define U_WIN_SWITCH_CCW LALT(LSFT(KC_TAB)) // Window switch counter-clockwise (ALT+SHIFT+Tab, default)
  #define U_WORKSPACE_CW LGUI(KC_RGHT) // Workspace switch clockwise (WIN+Right, default)
  #define U_WORKSPACE_CCW LGUI(KC_LEFT) // Workspace switch counter-clockwise (WIN+Left, default)
#endif

// Contextual Encoder Behavior Implementation
//
// Simplified architecture:
// - Uses QMK's LT (Layer-Tap) for encoder buttons: LT(U_ENC_LEFT, KC_ENT) and LT(U_ENC_RIGHT, KC_SPC)
// - Each encoder button only affects its own encoder (left button for left encoder, right for right)
// - Proxy layers (U_ENC_LEFT, U_ENC_RIGHT) activate automatically when encoder buttons are held
// - encoder_update_user() checks if we're on a proxy layer and dispatches accordingly
//
// Platform Adaptation:
// - Mac: CMD+[/], CMD for apps, CTRL for tabs
// - Windows/Linux: Media keys for browser, ALT for apps, CTRL for tabs
//
// Function Usage:
// - tap_code(): Basic keycodes (volume, scroll, navigation)
// - tap_code16(): Keycodes with modifiers (shortcuts, app switching)
// - Direct RGB functions: Immediate visual feedback

// App/window switching timeout (milliseconds)
// How long to wait after the last encoder rotation before releasing modifier
#define WINDOW_SWITCH_TIMEOUT_MS 500

// State tracking for app/tab switching with held modifiers
typedef struct {
    bool window_switching_active;    // Alt modifier held for window switching on NUM layer (no timeout)
    bool num_window_switching_active; // Platform modifier held for window management on NUM layer (button held)
    bool app_switching_active;       // Platform modifier held for app switching on Base layer (with timeout)
    bool tab_switching_active;       // CTRL held for tab switching on SYM layer
    uint8_t base_layer;              // The base layer when encoder proxy layer was activated
} encoder_state_t;

static encoder_state_t enc_state = {false, false, false, false, 0};

// Deferred execution token for window switching timeout
static deferred_token window_switch_timeout_token = INVALID_DEFERRED_TOKEN;

// Timeout callback to release app switching modifier (Base layer)
static uint32_t window_switch_timeout_callback(uint32_t trigger_time, void *cb_arg) {
    if (enc_state.app_switching_active) {
        unregister_mods(U_APP_MOD);
        enc_state.app_switching_active = false;
    }
    window_switch_timeout_token = INVALID_DEFERRED_TOKEN;
    return 0; // Don't repeat
}

// Encoder proxy layers - activated automatically by QMK's LT functionality
enum custom_encoder_layers {
    U_ENC_LEFT = U_FUN + 1,     // Proxy layer activated by LT(U_ENC_LEFT, KC_ENT) - left encoder button
    U_ENC_RIGHT,                // Proxy layer activated by LT(U_ENC_RIGHT, KC_SPC) - right encoder button
};

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t highest = get_highest_layer(state);
    uint8_t prev_highest = get_highest_layer(layer_state);

    // Capture base layer when entering an encoder proxy layer
    if (highest == U_ENC_LEFT || highest == U_ENC_RIGHT) {
        // Only capture if we weren't already in a proxy layer
        if (prev_highest != U_ENC_LEFT && prev_highest != U_ENC_RIGHT) {
            enc_state.base_layer = prev_highest;
        }
    }

    // Detect when we're entering the left encoder proxy layer (button pressed)
    // Cancel the window switch timeout since we're now doing volume control
    if (highest == U_ENC_LEFT && prev_highest != U_ENC_LEFT) {
        if (window_switch_timeout_token != INVALID_DEFERRED_TOKEN) {
            cancel_deferred_exec(window_switch_timeout_token);
            window_switch_timeout_token = INVALID_DEFERRED_TOKEN;
        }
    }

    // Detect when we're exiting the left encoder proxy layer
    if (prev_highest == U_ENC_LEFT && highest != U_ENC_LEFT) {
        // Release window switch modifier if we were on Base/Extra/Tap when we entered
        if ((enc_state.base_layer == U_BASE || enc_state.base_layer == U_EXTRA ||
             enc_state.base_layer == U_TAP) && enc_state.window_switching_active) {
            unregister_mods(MOD_BIT(KC_LALT));
            enc_state.window_switching_active = false;
        }
        // Release NUM layer window switch modifier if we were on NUM when we entered
        if (enc_state.base_layer == U_NUM && enc_state.num_window_switching_active) {
            unregister_mods(U_WIN_MOD);
            enc_state.num_window_switching_active = false;
        }
    }

    // Release app switch modifier if not in Base/Extra/Tap layers
    if (!layer_state_cmp(state, U_BASE) && !layer_state_cmp(state, U_EXTRA) &&
        !layer_state_cmp(state, U_TAP) && enc_state.app_switching_active) {
        unregister_mods(U_APP_MOD);
        enc_state.app_switching_active = false;
        // Cancel timeout when manually releasing via layer change
        if (window_switch_timeout_token != INVALID_DEFERRED_TOKEN) {
            cancel_deferred_exec(window_switch_timeout_token);
            window_switch_timeout_token = INVALID_DEFERRED_TOKEN;
        }
    }

    // Release window switch modifier if NUM layer is no longer active
    if (!layer_state_cmp(state, U_NUM) && enc_state.window_switching_active) {
        unregister_mods(MOD_BIT(KC_LALT));
        enc_state.window_switching_active = false;
    }

    // Release NUM layer window management modifier if NUM layer is no longer active
    if (!layer_state_cmp(state, U_NUM) && enc_state.num_window_switching_active) {
        unregister_mods(U_WIN_MOD);
        enc_state.num_window_switching_active = false;
    }

    // Release tab switch modifier if SYM layer is no longer active
    if (!layer_state_cmp(state, U_SYM) && enc_state.tab_switching_active) {
        unregister_mods(U_TAB_MOD);
        enc_state.tab_switching_active = false;
    }

    return state;
}

// Chordal hold layout - conditional based on revision
#if defined(KEYBOARD_crkbd_rev4_1_standard) || defined(KEYBOARD_crkbd_rev4_1_mini)
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3_ex2(
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
                            'X', 'X', 'X',  'X', 'X', 'X'
    );
#else
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       'X', 'X', 'X',  'X', 'X', 'X'
    );
#endif

// Handle encoder behavior when no encoder button is pressed
static void handle_encoder_no_button(uint8_t index, bool clockwise, uint8_t current_layer) {
    switch (current_layer) {
        case U_BASE:
        case U_EXTRA:
        case U_TAP:
            if (index == 0) { // Left encoder: App switching with platform modifier held
                if (!enc_state.app_switching_active) {
                    register_mods(U_APP_MOD);
                    enc_state.app_switching_active = true;
                }
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    tap_code16(LSFT(KC_TAB));
                }

                // Cancel any existing timeout and schedule a new one
                if (window_switch_timeout_token != INVALID_DEFERRED_TOKEN) {
                    cancel_deferred_exec(window_switch_timeout_token);
                }
                window_switch_timeout_token = defer_exec(WINDOW_SWITCH_TIMEOUT_MS, window_switch_timeout_callback, NULL);
            } else if (index == 2) { // Right encoder: Vertical scroll
                tap_code(clockwise ? MS_WHLU : MS_WHLD);
            }
            break;

        case U_BUTTON:
            if (index == 0) { // Left encoder: Browser forward/backward (media keys on Windows/Linux, CMD+[/] on Mac)
                tap_code16(clockwise ? U_FWD : U_BCK);
            } else if (index == 2) { // Right encoder: Undo/redo
                tap_code16(clockwise ? U_RDO : U_UND); // Use tap_code16 for modifier combinations
            }
            break;

        case U_NAV:
            if (index == 0) { // Left encoder: Left/right cursor
                tap_code(clockwise ? KC_RGHT : KC_LEFT);
            } else if (index == 2) { // Right encoder: Undo/redo
                tap_code16(clockwise ? U_RDO : U_UND); // Use tap_code16 for modifier combinations
            }
            break;

        case U_MOUSE:
            if (index == 0) { // Left encoder: Horizontal scroll
                tap_code(clockwise ? MS_WHLR : MS_WHLL);
            } else if (index == 2) { // Right encoder: Vertical scroll
                tap_code(clockwise ? MS_WHLU : MS_WHLD);
            }
            break;

        case U_MEDIA:
            if (index == 0) { // Left encoder: Volume
                tap_code(clockwise ? KC_VOLU : KC_VOLD);
            } else if (index == 2) { // Right encoder: Volume control
                tap_code(clockwise ? KC_VOLU : KC_VOLD);
            }
            break;

        case U_NUM:
            if (index == 0) { // Left encoder: Window switching with Alt modifier held
                if (!enc_state.window_switching_active) {
                    register_mods(MOD_BIT(KC_LALT));
                    enc_state.window_switching_active = true;
                }
                tap_code16(clockwise ? KC_TAB : LSFT(KC_TAB));
            } else if (index == 2) { // Right encoder: Vertical scroll
                tap_code(clockwise ? MS_WHLU : MS_WHLD);
            }
            break;

        case U_SYM:
            if (index == 0) { // Left encoder: Tab switching with platform modifier held
                if (!enc_state.tab_switching_active) {
                    register_mods(U_TAB_MOD);
                    enc_state.tab_switching_active = true;
                }
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    tap_code16(LSFT(KC_TAB)); // Use tap_code16 for modifier combinations
                }
            } else if (index == 2) { // Right encoder: Vertical scroll
                tap_code(clockwise ? MS_WHLU : MS_WHLD);
            }
            break;

        case U_FUN:
            if (index == 0) { // Left encoder: RGB animation
                // Use direct RGB matrix functions instead of keycodes with tap_code()
                if (clockwise) {
                    rgb_matrix_step();
                } else {
                    rgb_matrix_step_reverse();
                }
            } else if (index == 2) { // Right encoder: RGB brightness
                // Use direct RGB matrix functions for immediate effect
                if (clockwise) {
                    rgb_matrix_increase_val();
                } else {
                    rgb_matrix_decrease_val();
                }
            }
            break;
    }
}

// Handle left encoder when its button is held
static void handle_left_encoder_with_button(bool clockwise, uint8_t context_layer) {
    switch (context_layer) {
        case U_BASE:
        case U_EXTRA:
        case U_TAP:
            // Volume control
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;

        case U_NUM:
            // Window management with platform modifier held
            if (!enc_state.num_window_switching_active) {
                register_mods(U_WIN_MOD);
                enc_state.num_window_switching_active = true;
            }
            #if defined(MIRYOKU_CLIPBOARD_MAC)
                // On Mac: CMD+` (grave accent) for window switching within the same app
                tap_code16(clockwise ? KC_GRV : LSFT(KC_GRV));
            #else
                // On Windows/Linux: Alt+Tab for window switching
                tap_code16(clockwise ? KC_TAB : LSFT(KC_TAB));
            #endif
            break;

        case U_SYM:
            // Recent tabs (browser)
            tap_code16(clockwise ? LCTL(KC_TAB) : LCTL(LSFT(KC_TAB)));
            break;

        case U_NAV:
            // Word-wise navigation
            tap_code16(clockwise ? LCTL(KC_RGHT) : LCTL(KC_LEFT));
            break;

        case U_FUN:
            // RGB animation speed
            if (clockwise) {
                rgb_matrix_increase_speed();
            } else {
                rgb_matrix_decrease_speed();
            }
            break;

        default:
            // Default: Volume
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;
    }
}

// Handle right encoder when its button is held
static void handle_right_encoder_with_button(bool clockwise, uint8_t context_layer) {
    switch (context_layer) {
        case U_BASE:
        case U_EXTRA:
        case U_TAP:
            // Page navigation
            tap_code(clockwise ? KC_PGDN : KC_PGUP);
            break;

        case U_MOUSE:
            // Mouse wheel horizontal
            tap_code(clockwise ? MS_WHLR : MS_WHLL);
            break;

        case U_MEDIA:
            // Track prev/next
            tap_code(clockwise ? KC_MNXT : KC_MPRV);
            break;

        case U_FUN:
            // RGB hue
            if (clockwise) {
                rgb_matrix_increase_hue();
            } else {
                rgb_matrix_decrease_hue();
            }
            break;

        default:
            // Default: Vertical scroll
            tap_code(clockwise ? MS_WHLU : MS_WHLD);
            break;
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t current_layer = get_highest_layer(layer_state);

    // Left encoder (index 0)
    if (index == 0) {
        if (current_layer == U_ENC_LEFT) {
            // Left encoder button is held - use special behavior
            handle_left_encoder_with_button(clockwise, enc_state.base_layer);
        } else {
            // No button held - use normal layer behavior
            handle_encoder_no_button(index, clockwise, current_layer);
        }
    }
    // Right encoder (index 2)
    else if (index == 2) {
        if (current_layer == U_ENC_RIGHT) {
            // Right encoder button is held - use special behavior
            handle_right_encoder_with_button(clockwise, enc_state.base_layer);
        } else {
            // No button held - use normal layer behavior
            handle_encoder_no_button(index, clockwise, current_layer);
        }
    }

    return false; // Skip default encoder handling
}
