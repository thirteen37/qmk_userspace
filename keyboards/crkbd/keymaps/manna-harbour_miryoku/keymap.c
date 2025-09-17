// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"

// Comprehensive Encoder Behavior Implementation
//
// This implementation handles ALL encoder behavior through the encoder_update_user()
// callback function, providing complete control over encoder functionality per layer.
// No encoder maps are used - everything is handled in the callback.
//
// Enhanced App/Tab Switching:
// NUM Layer: App switching with CMD+Tab
// - CMD key is held only when left encoder is rotated
// - Each rotation sends Tab (forward) or Shift+Tab (backward)
// - CMD remains held until NUM layer is exited
//
// SYM Layer: Tab switching with CTRL+Tab
// - CTRL key is held only when left encoder is rotated
// - Each rotation sends Tab (forward) or Shift+Tab (backward)
// - CTRL remains held until SYM layer is exited
//
// All Other Layers:
// Handled through encoder_update_user() with appropriate layer-specific behavior
// including volume, scrolling, undo/redo, mouse acceleration, RGB controls, etc.

// State tracking for modifier hold behavior
typedef struct {
    bool app_switching_active;    // CMD held for app switching on NUM layer
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
            if (index == 0) { // Left encoder: Mouse acceleration
                tap_code(clockwise ? KC_ACL2 : KC_ACL0);
            } else if (index == 2) { // Right encoder: Undo/redo
                tap_code(clockwise ? U_RDO : U_UND);
            }
            break;

        case U_NAV:
            if (index == 0) { // Left encoder: Page up/down
                tap_code(clockwise ? KC_PGUP : KC_PGDN);
            } else if (index == 2) { // Right encoder: Undo/redo
                tap_code(clockwise ? U_RDO : U_UND);
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
            if (index == 0) { // Left encoder: App switching with CMD held
                if (!mod_state.app_switching_active) {
                    register_mods(MOD_BIT(KC_LGUI));
                    mod_state.app_switching_active = true;
                }
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    tap_code16(LSFT(KC_TAB));
                }
            } else if (index == 2) { // Right encoder: Vertical scroll
                tap_code(clockwise ? MS_WHLU : MS_WHLD);
            }
            break;

        case U_SYM:
            if (index == 0) { // Left encoder: Tab switching with CTRL held
                if (!mod_state.tab_switching_active) {
                    register_mods(MOD_BIT(KC_LCTL));
                    mod_state.tab_switching_active = true;
                }
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    tap_code16(LSFT(KC_TAB));
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
    // Release CMD if NUM layer is no longer active and we were app switching
    if (!layer_state_cmp(state, U_NUM) && mod_state.app_switching_active) {
        unregister_mods(MOD_BIT(KC_LGUI));
        mod_state.app_switching_active = false;
    }

    // Release CTRL if SYM layer is no longer active and we were tab switching
    if (!layer_state_cmp(state, U_SYM) && mod_state.tab_switching_active) {
        unregister_mods(MOD_BIT(KC_LCTL));
        mod_state.tab_switching_active = false;
    }

    return state;
}
