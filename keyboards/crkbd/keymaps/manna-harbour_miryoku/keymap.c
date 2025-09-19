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
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_FWD LGUI(KC_RBRC) // Browser forward
  #define U_BCK LGUI(KC_LBRC) // Browser backward
  #define U_APP_MOD MOD_BIT(KC_LGUI) // App switch modifier (CMD)
  #define U_TAB_MOD MOD_BIT(KC_LCTL) // Tab switch modifier (CTRL)
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_FWD KC_WFWD // Browser forward (media key)
  #define U_BCK KC_WBAK // Browser backward (media key)
  #define U_APP_MOD MOD_BIT(KC_LALT) // App switch modifier (ALT)
  #define U_TAB_MOD MOD_BIT(KC_LCTL) // Tab switch modifier (CTRL)
#else
  #define U_FWD KC_WFWD // Browser forward (media key, default)
  #define U_BCK KC_WBAK // Browser backward (media key, default)
  #define U_APP_MOD MOD_BIT(KC_LALT) // App switch modifier (ALT, default)
  #define U_TAB_MOD MOD_BIT(KC_LCTL) // Tab switch modifier (CTRL, default)
#endif

// Contextual Encoder Behavior Implementation using Pure QMK LT Functionality
//
// This implementation provides contextual encoder behavior that changes based on:
// 1. Current active layer (Base, Nav, Num, Sym, etc.)
// 2. Encoder button hold state (using QMK's built-in LT functionality)
//
// Architecture:
// - Uses QMK's LT (Layer-Tap) for encoder buttons: LT(U_ENC_LEFT, KC_ENT) and LT(U_ENC_RIGHT, KC_SPC)
// - Proxy layers (U_ENC_LEFT, U_ENC_RIGHT) activate automatically when encoder buttons are held
// - encoder_update_user() dispatches behavior based on current layer and context
// - layer_state_set_user() captures base layer context and manages modifier states
//
// Enhanced App/Tab Switching:
// NUM Layer: App switching with platform modifier held automatically
// SYM Layer: Tab switching with CTRL modifier held automatically
//
// Platform Adaptation:
// - Mac: CMD+[/], CMD for apps, CTRL for tabs
// - Windows/Linux: Media keys for browser, ALT for apps, CTRL for tabs
//
// Function Usage:
// - tap_code(): Basic keycodes (volume, scroll, navigation)
// - tap_code16(): Keycodes with modifiers (shortcuts, app switching)
// - Direct RGB functions: Immediate visual feedback

// Minimal state tracking for contextual encoder behavior
// QMK's LT functionality handles encoder button detection automatically
typedef struct {
    bool app_switching_active;       // Platform modifier held for app switching on NUM layer
    bool tab_switching_active;       // CTRL held for tab switching on SYM layer
    uint8_t base_layer;              // The base layer when encoder proxy layer was activated
} encoder_state_t;

static encoder_state_t enc_state = {false, false, 0};

// Encoder proxy layers - activated automatically by QMK's LT functionality
// Available on rev4.1 with encoder buttons, no-op on standard revisions
enum custom_encoder_layers {
    U_ENC_LEFT = U_FUN + 1,     // Proxy layer activated by LT(U_ENC_LEFT, KC_ENT)
    U_ENC_RIGHT,                // Proxy layer activated by LT(U_ENC_RIGHT, KC_SPC)
};


// Helper function to get the contextual layer for encoder behavior
uint8_t get_encoder_context_layer(void) {
    uint8_t highest = get_highest_layer(layer_state);

    // If we're in an encoder proxy layer, use the base layer for context
    if (highest == U_ENC_LEFT || highest == U_ENC_RIGHT) {
        return enc_state.base_layer;
    }

    return highest;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Capture base layer context when encoder proxy layers are activated by LT
    if (layer_state_cmp(state, U_ENC_LEFT) || layer_state_cmp(state, U_ENC_RIGHT)) {
        // Only update base layer if we're transitioning INTO a proxy layer
        if (!layer_state_cmp(layer_state, U_ENC_LEFT) && !layer_state_cmp(layer_state, U_ENC_RIGHT)) {
            enc_state.base_layer = get_highest_layer(layer_state);
        }
    }

    // Release app switch modifier if NUM layer is no longer active and we were app switching
    if (!layer_state_cmp(state, U_NUM) && enc_state.app_switching_active) {
        unregister_mods(U_APP_MOD);
        enc_state.app_switching_active = false;
    }

    // Release tab switch modifier if SYM layer is no longer active and we were tab switching
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

// All encoder behavior handled by encoder_update_user() with automatic LT proxy layer activation

bool encoder_update_user(uint8_t index, bool clockwise) {
    // Get current layer (may be proxy layer) and determine contextual behavior
    uint8_t current_layer = get_highest_layer(layer_state);
    uint8_t context_layer = get_encoder_context_layer();

    // Handle encoder behavior - proxy layers activated automatically by QMK's LT
    switch (current_layer) {
        case U_ENC_LEFT:
            // Enhanced contextual behavior when left encoder button is held (via LT)
            switch (context_layer) {
                case U_BASE:
                case U_EXTRA:
                case U_TAP:
                    if (index == 0) { // Left encoder: Window management
                        #if defined(MIRYOKU_CLIPBOARD_MAC)
                        tap_code16(clockwise ? LGUI(KC_GRV) : LGUI(LSFT(KC_GRV))); // CMD+` for window switching
                        #else
                        tap_code16(clockwise ? LALT(KC_TAB) : LALT(LSFT(KC_TAB))); // ALT+Tab for window switching
                        #endif
                    } else if (index == 2) { // Right encoder: Workspace switching
                        #if defined(MIRYOKU_CLIPBOARD_MAC)
                        tap_code16(clockwise ? LCTL(KC_RGHT) : LCTL(KC_LEFT)); // CTRL+Arrow for workspace
                        #else
                        tap_code16(clockwise ? LGUI(KC_RGHT) : LGUI(KC_LEFT)); // WIN+Arrow for desktop
                        #endif
                    }
                    break;

                case U_NUM:
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
                    } else if (index == 2) { // Right encoder: Number input
                        static uint8_t num_sequence[] = {KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9};
                        static uint8_t num_index = 0;
                        num_index = clockwise ? (num_index + 1) % 10 : (num_index + 9) % 10;
                        tap_code(num_sequence[num_index]);
                    }
                    break;

                case U_SYM:
                    if (index == 0) { // Left encoder: Recent tabs (browser)
                        tap_code16(clockwise ? LCTL(LSFT(KC_TAB)) : LCTL(KC_TAB));
                    } else if (index == 2) { // Right encoder: Text selection
                        tap_code16(clockwise ? LSFT(KC_RGHT) : LSFT(KC_LEFT));
                    }
                    break;

                case U_NAV:
                    if (index == 0) { // Left encoder: Word-wise navigation
                        tap_code16(clockwise ? LCTL(KC_RGHT) : LCTL(KC_LEFT)); // Word jump
                    } else if (index == 2) { // Right encoder: Undo/redo
                        tap_code16(clockwise ? U_RDO : U_UND);
                    }
                    break;

                default:
                    // Default behavior for other layers - same as base layer
                    if (index == 0) { // Left encoder: Volume
                        tap_code(clockwise ? KC_VOLU : KC_VOLD);
                    } else if (index == 2) { // Right encoder: Vertical scroll
                        tap_code(clockwise ? MS_WHLU : MS_WHLD);
                    }
                    break;
            }
            break;

        case U_ENC_RIGHT:
            // Enhanced contextual behavior when right encoder button is held (via LT)
            switch (context_layer) {
                case U_BASE:
                case U_EXTRA:
                case U_TAP:
                    if (index == 0) { // Left encoder: Text navigation
                        tap_code16(clockwise ? LCTL(KC_RGHT) : LCTL(KC_LEFT)); // Word jump
                    } else if (index == 2) { // Right encoder: Page navigation
                        tap_code(clockwise ? KC_PGDN : KC_PGUP);
                    }
                    break;

                case U_MOUSE:
                    if (index == 0) { // Left encoder: Mouse acceleration
                        // Adjust mouse movement speed
                        tap_code(clockwise ? MS_ACL2 : MS_ACL0);
                    } else if (index == 2) { // Right encoder: Mouse wheel horizontal
                        tap_code(clockwise ? MS_WHLR : MS_WHLL);
                    }
                    break;

                case U_MEDIA:
                    if (index == 0) { // Left encoder: Playback speed (if supported)
                        tap_code(clockwise ? KC_MFFD : KC_MRWD);
                    } else if (index == 2) { // Right encoder: Playlist navigation
                        tap_code16(clockwise ? LCTL(KC_MNXT) : LCTL(KC_MPRV));
                    }
                    break;

                default:
                    // Default behavior - same as base layer
                    if (index == 0) { // Left encoder: Volume
                        tap_code(clockwise ? KC_VOLU : KC_VOLD);
                    } else if (index == 2) { // Right encoder: Vertical scroll
                        tap_code(clockwise ? MS_WHLU : MS_WHLD);
                    }
                    break;
            }
            break;

        case U_BASE:
        case U_EXTRA:
        case U_TAP:
            if (index == 0) { // Left encoder: Volume
                tap_code(clockwise ? KC_VOLU : KC_VOLD);
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
            } else if (index == 2) { // Right encoder: Track prev/next
                tap_code(clockwise ? KC_MNXT : KC_MPRV);
            }
            break;

        case U_NUM:
            if (index == 0) { // Left encoder: App switching with platform modifier held
                if (!enc_state.app_switching_active) {
                    register_mods(U_APP_MOD);
                    enc_state.app_switching_active = true;
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

    return false; // Skip default encoder handling since we handle everything here
}
