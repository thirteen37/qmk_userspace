// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3_ex2(
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R',
                            'X', 'X', 'X',  'X', 'X', 'X'
    );
