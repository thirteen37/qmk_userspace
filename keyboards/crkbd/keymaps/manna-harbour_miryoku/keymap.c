// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3_ex2(
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
                            'X', 'X', 'X',  'X', 'X', 'X'
    );

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // BASE layer - Volume and vertical scroll
    [U_BASE] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),    // Left encoder: Volume
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),    // Encoder 1 (if present)
        ENCODER_CCW_CW(MS_WHLD, MS_WHLU),    // Right encoder: Vertical scroll
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)     // Encoder 3 (if present)
    },
    // EXTRA layer - Same as base
    [U_EXTRA] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(MS_WHLD, MS_WHLU),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    // TAP layer - Same as base
    [U_TAP] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(MS_WHLD, MS_WHLU),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    // BUTTON layer - Click precision and undo/redo
    [U_BUTTON] = { 
        ENCODER_CCW_CW(KC_ACL0, KC_ACL2),    // Mouse acceleration
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(U_UND, U_RDO),        // Undo/redo
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    // NAV layer - Page navigation and undo/redo
    [U_NAV] = { 
        ENCODER_CCW_CW(KC_PGDN, KC_PGUP),    // Page up/down
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(U_UND, U_RDO),        // Undo/redo
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    // MOUSE layer - Scroll wheel controls
    [U_MOUSE] = { 
        ENCODER_CCW_CW(MS_WHLL, MS_WHLR),    // Horizontal scroll
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(MS_WHLD, MS_WHLU),    // Vertical scroll
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    // MEDIA layer - Track and volume controls
    [U_MEDIA] = {
        ENCODER_CCW_CW(KC_MPRV, KC_MNXT),    // Previous/next track
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),    // Volume
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    // NUM layer - Number increment/decrement and vertical navigation
    [U_NUM] = {
        ENCODER_CCW_CW(KC_MINS, KC_PLUS),    // -/+ for number adjustment
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(MS_WHLD, MS_WHLU),    // Vertical scroll
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    // SYM layer - Symbol navigation and vertical scroll
    [U_SYM] = {
        ENCODER_CCW_CW(KC_LBRC, KC_RBRC),    // Bracket types
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(MS_WHLD, MS_WHLU),    // Vertical scroll
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    // FUN layer - Function keys and system controls
    [U_FUN] = {
        ENCODER_CCW_CW(KC_BRID, KC_BRIU),    // Screen brightness
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(MS_WHLD, MS_WHLU),    // Vertical scroll
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    }
};
#endif
