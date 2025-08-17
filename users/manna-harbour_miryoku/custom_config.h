// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define EE_HANDS

#undef TAPPING_TERM
#define TAPPING_TERM 200
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 120

#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD

#define FLOW_TAP_TERM 150

// Ergodox extended layout

#ifdef KEYBOARD_kinesis
#define MIRYOKU_MAPPING( \
K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39 \
) \
LAYOUT( \
	KC_ESC,  XXX,   XXX,   XXX,   XXX,   XXX,   XXX,   XXX,   XXX, \
	XXX,     KC_1,  KC_2,  KC_3,  KC_4,  KC_5, \
	XXX,     K00,   K01,   K02,   K03,   K04, \
	KC_CAPS, K10,   K11,   K12,   K13,   K14, \
	KC_LSFT, K20,   K21,   K22,   K23,   K24, \
	         XXX,   XXX,   XXX,   XXX,        \
	                              K34,   XXX, \
	                                     XXX, \
	                       K32,   K33,   K34, \
    XXX,   XXX,   XXX,   XXX,   XXX,   XXX,   XXX,   XXX,   XXX, \
    KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  XXX, \
    K05,   K06,   K07,   K08,   K09,   XXX, \
    K15,   K16,   K17,   K18,   K19,   XXX, \
    K25,   K26,   K27,   K28,   K29,   KC_RSFT, \
           XXX,   XXX,   XXX,   XXX,        \
    XXX,   K35,                             \
    XXX,                                    \
    K35,   K36,   K37                       \
)
#endif
