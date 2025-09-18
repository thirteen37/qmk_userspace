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

// Comprehensive Encoder Behavior Implementation
//
// This implementation handles ALL encoder behavior through the encoder_update_user()
// callback function, providing complete control over encoder functionality per layer.
// No encoder maps are used - everything is handled in the callback.
//
// Enhanced App/Tab Switching:
// NUM Layer: App switching with platform modifier+Tab
// - Platform modifier (CMD on Mac, ALT on Windows/Linux) is held only when left encoder is rotated
// - Each rotation sends Tab (forward) or Shift+Tab (backward)
// - Platform modifier remains held until NUM layer is exited
//
// SYM Layer: Tab switching with CTRL+Tab
// - CTRL key is held only when left encoder is rotated
// - Each rotation sends Tab (forward) or Shift+Tab (backward)
// - CTRL remains held until SYM layer is exited
//
// All Other Layers:
// Handled through encoder_update_user() with appropriate layer-specific behavior
// including volume, scrolling, undo/redo, mouse acceleration, RGB controls, etc.
//
// Function Usage Notes:
// - tap_code(): For basic keycodes (volume, media, page up/down, mouse wheel)
// - tap_code16(): For keycodes with modifiers (undo/redo, app/tab switching)
// - Direct functions: For RGB matrix controls (immediate effect)

// State tracking for modifier hold behavior
typedef struct {
    bool app_switching_active;    // Platform modifier held for app switching on NUM layer
    bool tab_switching_active;    // CTRL held for tab switching on SYM layer
} modifier_state_t;

static modifier_state_t mod_state = {false, false};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3_ex2(
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
                            'X', 'X', 'X',  'X', 'X', 'X'
    );


// All encoder behavior handled by encoder_update_user() callback function below

bool encoder_update_user(uint8_t index, bool clockwise) {
    // Get current layer
    uint8_t current_layer = get_highest_layer(layer_state);

    // Handle all encoder behavior based on current layer and encoder index
    switch (current_layer) {
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
                if (!mod_state.app_switching_active) {
                    register_mods(U_APP_MOD);
                    mod_state.app_switching_active = true;
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
                if (!mod_state.tab_switching_active) {
                    register_mods(U_TAB_MOD);
                    mod_state.tab_switching_active = true;
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

layer_state_t layer_state_set_user(layer_state_t state) {
    // Release app switch modifier if NUM layer is no longer active and we were app switching
    if (!layer_state_cmp(state, U_NUM) && mod_state.app_switching_active) {
        unregister_mods(U_APP_MOD);
        mod_state.app_switching_active = false;
    }

    // Release tab switch modifier if SYM layer is no longer active and we were tab switching
    if (!layer_state_cmp(state, U_SYM) && mod_state.tab_switching_active) {
        unregister_mods(U_TAB_MOD);
        mod_state.tab_switching_active = false;
    }

    return state;
}
