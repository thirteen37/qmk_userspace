// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-
// target: qmk

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once


#define MIRYOKU_ALTERNATIVES_BASE_AZERTY_FLIP \
KC_A,              KC_Z,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
LT(U_BUTTON,KC_Q), ALGR_T(KC_S),      KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              ALGR_T(KC_L),      LT(U_BUTTON,KC_M), \
LALT_T(KC_W),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_V),      KC_B,              KC_N,              RSFT_T(KC_COMM),   RGUI_T(KC_DOT),    RCTL_T(KC_SLSH),   RALT_T(KC_QUOT),   \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_BEAKL15_FLIP \
KC_Q,              KC_H,              KC_O,              KC_U,              KC_X,              KC_G,              KC_C,              KC_R,              KC_F,              KC_Z,              \
LT(U_BUTTON,KC_Y), ALGR_T(KC_I),      KC_E,              KC_A,              KC_DOT,            KC_D,              KC_S,              KC_T,              ALGR_T(KC_N),      LT(U_BUTTON,KC_B), \
LALT_T(KC_J),      LCTL_T(KC_SLSH),   LGUI_T(KC_COMM),   LSFT_T(KC_K),      KC_QUOT,           KC_W,              RSFT_T(KC_M),      RGUI_T(KC_L),      RCTL_T(KC_P),      RALT_T(KC_V),      \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_COLEMAK_FLIP \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_G,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LT(U_BUTTON,KC_A), ALGR_T(KC_R),      KC_S,              KC_T,              KC_D,              KC_H,              KC_N,              KC_E,              ALGR_T(KC_I),      LT(U_BUTTON,KC_O), \
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_V),      KC_B,              KC_K,              RSFT_T(KC_M),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH_FLIP \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LT(U_BUTTON,KC_A), ALGR_T(KC_R),      KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              ALGR_T(KC_I),      LT(U_BUTTON,KC_O), \
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_D),      KC_V,              KC_K,              RSFT_T(KC_H),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDHK_FLIP \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LT(U_BUTTON,KC_A), ALGR_T(KC_R),      KC_S,              KC_T,              KC_G,              KC_K,              KC_N,              KC_E,              ALGR_T(KC_I),      LT(U_BUTTON,KC_O), \
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_D),      KC_V,              KC_M,              RSFT_T(KC_H),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_DVORAK_FLIP \
KC_QUOT,           KC_COMM,           KC_DOT,            KC_P,              KC_Y,              KC_F,              KC_G,              KC_C,              KC_R,              KC_L,              \
LT(U_BUTTON,KC_A), ALGR_T(KC_O),      KC_E,              KC_U,              KC_I,              KC_D,              KC_H,              KC_T,              ALGR_T(KC_N),      LT(U_BUTTON,KC_S), \
LALT_T(KC_SLSH),   LCTL_T(KC_Q),      LGUI_T(KC_J),      LSFT_T(KC_K),      KC_X,              KC_B,              RSFT_T(KC_M),      RGUI_T(KC_W),      RCTL_T(KC_V),      RALT_T(KC_Z),      \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_HALMAK_FLIP \
KC_W,              KC_L,              KC_R,              KC_B,              KC_Z,              KC_QUOT,           KC_Q,              KC_U,              KC_D,              KC_J,              \
LT(U_BUTTON,KC_S), ALGR_T(KC_H),      KC_N,              KC_T,              KC_COMM,           KC_DOT,            KC_A,              KC_E,              ALGR_T(KC_O),      LT(U_BUTTON,KC_I), \
LALT_T(KC_F),      LCTL_T(KC_M),      LGUI_T(KC_V),      LSFT_T(KC_C),      KC_SLSH,           KC_G,              RSFT_T(KC_P),      RGUI_T(KC_X),      RCTL_T(KC_K),      RALT_T(KC_Y),      \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_WORKMAN_FLIP \
KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,           \
LT(U_BUTTON,KC_A), ALGR_T(KC_S),      KC_H,              KC_T,              KC_G,              KC_Y,              KC_N,              KC_E,              ALGR_T(KC_O),      LT(U_BUTTON,KC_I), \
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_M),      LSFT_T(KC_C),      KC_V,              KC_K,              RSFT_T(KC_L),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_QWERTY_FLIP \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
LT(U_BUTTON,KC_A), ALGR_T(KC_S),      KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              ALGR_T(KC_L),      LT(U_BUTTON,KC_QUOT),\
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_V),      KC_B,              KC_N,              RSFT_T(KC_M),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_QWERTZ_FLIP \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Z,              KC_U,              KC_I,              KC_O,              KC_P,              \
LT(U_BUTTON,KC_A), ALGR_T(KC_S),      KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              ALGR_T(KC_L),      LT(U_BUTTON,KC_QUOT),\
LALT_T(KC_Y),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_V),      KC_B,              KC_N,              RSFT_T(KC_M),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_AZERTY \
KC_A,              KC_Z,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
LT(U_BUTTON,KC_Q), ALGR_T(KC_S),      KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              ALGR_T(KC_L),      LT(U_BUTTON,KC_M), \
LALT_T(KC_W),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_V),      KC_B,              KC_N,              RSFT_T(KC_COMM),   RGUI_T(KC_DOT),    RCTL_T(KC_SLSH),   RALT_T(KC_QUOT),   \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_BEAKL15 \
KC_Q,              KC_H,              KC_O,              KC_U,              KC_X,              KC_G,              KC_C,              KC_R,              KC_F,              KC_Z,              \
LT(U_BUTTON,KC_Y), ALGR_T(KC_I),      KC_E,              KC_A,              KC_DOT,            KC_D,              KC_S,              KC_T,              ALGR_T(KC_N),      LT(U_BUTTON,KC_B), \
LALT_T(KC_J),      LCTL_T(KC_SLSH),   LGUI_T(KC_COMM),   LSFT_T(KC_K),      KC_QUOT,           KC_W,              RSFT_T(KC_M),      RGUI_T(KC_L),      RCTL_T(KC_P),      RALT_T(KC_V),      \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_COLEMAK \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_G,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LT(U_BUTTON,KC_A), ALGR_T(KC_R),      KC_S,              KC_T,              KC_D,              KC_H,              KC_N,              KC_E,              ALGR_T(KC_I),      LT(U_BUTTON,KC_O), \
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_V),      KC_B,              KC_K,              RSFT_T(KC_M),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LT(U_BUTTON,KC_A), ALGR_T(KC_R),      KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              ALGR_T(KC_I),      LT(U_BUTTON,KC_O), \
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_D),      KC_V,              KC_K,              RSFT_T(KC_H),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDHK \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LT(U_BUTTON,KC_A), ALGR_T(KC_R),      KC_S,              KC_T,              KC_G,              KC_K,              KC_N,              KC_E,              ALGR_T(KC_I),      LT(U_BUTTON,KC_O), \
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_D),      KC_V,              KC_M,              RSFT_T(KC_H),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_DVORAK \
KC_QUOT,           KC_COMM,           KC_DOT,            KC_P,              KC_Y,              KC_F,              KC_G,              KC_C,              KC_R,              KC_L,              \
LT(U_BUTTON,KC_A), ALGR_T(KC_O),      KC_E,              KC_U,              KC_I,              KC_D,              KC_H,              KC_T,              ALGR_T(KC_N),      LT(U_BUTTON,KC_S), \
LALT_T(KC_SLSH),   LCTL_T(KC_Q),      LGUI_T(KC_J),      LSFT_T(KC_K),      KC_X,              KC_B,              RSFT_T(KC_M),      RGUI_T(KC_W),      RCTL_T(KC_V),      RALT_T(KC_Z),      \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_HALMAK \
KC_W,              KC_L,              KC_R,              KC_B,              KC_Z,              KC_QUOT,           KC_Q,              KC_U,              KC_D,              KC_J,              \
LT(U_BUTTON,KC_S), ALGR_T(KC_H),      KC_N,              KC_T,              KC_COMM,           KC_DOT,            KC_A,              KC_E,              ALGR_T(KC_O),      LT(U_BUTTON,KC_I), \
LALT_T(KC_F),      LCTL_T(KC_M),      LGUI_T(KC_V),      LSFT_T(KC_C),      KC_SLSH,           KC_G,              RSFT_T(KC_P),      RGUI_T(KC_X),      RCTL_T(KC_K),      RALT_T(KC_Y),      \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_WORKMAN \
KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,           \
LT(U_BUTTON,KC_A), ALGR_T(KC_S),      KC_H,              KC_T,              KC_G,              KC_Y,              KC_N,              KC_E,              ALGR_T(KC_O),      LT(U_BUTTON,KC_I), \
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_M),      LSFT_T(KC_C),      KC_V,              KC_K,              RSFT_T(KC_L),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_QWERTY \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
LT(U_BUTTON,KC_A), ALGR_T(KC_S),      KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              ALGR_T(KC_L),      LT(U_BUTTON,KC_QUOT),\
LALT_T(KC_Z),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_V),      KC_B,              KC_N,              RSFT_T(KC_M),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_BASE_QWERTZ \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Z,              KC_U,              KC_I,              KC_O,              KC_P,              \
LT(U_BUTTON,KC_A), ALGR_T(KC_S),      KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              ALGR_T(KC_L),      LT(U_BUTTON,KC_QUOT),\
LALT_T(KC_Y),      LCTL_T(KC_X),      LGUI_T(KC_C),      LSFT_T(KC_V),      KC_B,              KC_N,              RSFT_T(KC_M),      RGUI_T(KC_COMM),   RCTL_T(KC_DOT),    RALT_T(KC_SLSH),   \
U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP


#define MIRYOKU_ALTERNATIVES_TAP_AZERTY_FLIP \
KC_A,              KC_Z,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
KC_Q,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_M,              \
KC_W,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_QUOT,           \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_BEAKL15_FLIP \
KC_Q,              KC_H,              KC_O,              KC_U,              KC_X,              KC_G,              KC_C,              KC_R,              KC_F,              KC_Z,              \
KC_Y,              KC_I,              KC_E,              KC_A,              KC_DOT,            KC_D,              KC_S,              KC_T,              KC_N,              KC_B,              \
KC_J,              KC_SLSH,           KC_COMM,           KC_K,              KC_QUOT,           KC_W,              KC_M,              KC_L,              KC_P,              KC_V,              \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAK_FLIP \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_G,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
KC_A,              KC_R,              KC_S,              KC_T,              KC_D,              KC_H,              KC_N,              KC_E,              KC_I,              KC_O,              \
KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_K,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH_FLIP \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              KC_I,              KC_O,              \
KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAKDHK_FLIP \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_K,              KC_N,              KC_E,              KC_I,              KC_O,              \
KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_M,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_DVORAK_FLIP \
KC_QUOT,           KC_COMM,           KC_DOT,            KC_P,              KC_Y,              KC_F,              KC_G,              KC_C,              KC_R,              KC_L,              \
KC_A,              KC_O,              KC_E,              KC_U,              KC_I,              KC_D,              KC_H,              KC_T,              KC_N,              KC_S,              \
KC_SLSH,           KC_Q,              KC_J,              KC_K,              KC_X,              KC_B,              KC_M,              KC_W,              KC_V,              KC_Z,              \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_HALMAK_FLIP \
KC_W,              KC_L,              KC_R,              KC_B,              KC_Z,              KC_QUOT,           KC_Q,              KC_U,              KC_D,              KC_J,              \
KC_S,              KC_H,              KC_N,              KC_T,              KC_COMM,           KC_DOT,            KC_A,              KC_E,              KC_O,              KC_I,              \
KC_F,              KC_M,              KC_V,              KC_C,              KC_SLSH,           KC_G,              KC_P,              KC_X,              KC_K,              KC_Y,              \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_WORKMAN_FLIP \
KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,           \
KC_A,              KC_S,              KC_H,              KC_T,              KC_G,              KC_Y,              KC_N,              KC_E,              KC_O,              KC_I,              \
KC_Z,              KC_X,              KC_M,              KC_C,              KC_V,              KC_K,              KC_L,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_QWERTY_FLIP \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_QUOT,           \
KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_QWERTZ_FLIP \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Z,              KC_U,              KC_I,              KC_O,              KC_P,              \
KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_QUOT,           \
KC_Y,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            KC_TAB,            KC_SPC,            KC_ESC,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_AZERTY \
KC_A,              KC_Z,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
KC_Q,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_M,              \
KC_W,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_QUOT,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_BEAKL15 \
KC_Q,              KC_H,              KC_O,              KC_U,              KC_X,              KC_G,              KC_C,              KC_R,              KC_F,              KC_Z,              \
KC_Y,              KC_I,              KC_E,              KC_A,              KC_DOT,            KC_D,              KC_S,              KC_T,              KC_N,              KC_B,              \
KC_J,              KC_SLSH,           KC_COMM,           KC_K,              KC_QUOT,           KC_W,              KC_M,              KC_L,              KC_P,              KC_V,              \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAK \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_G,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
KC_A,              KC_R,              KC_S,              KC_T,              KC_D,              KC_H,              KC_N,              KC_E,              KC_I,              KC_O,              \
KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_K,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              KC_I,              KC_O,              \
KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAKDHK \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_K,              KC_N,              KC_E,              KC_I,              KC_O,              \
KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_M,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_DVORAK \
KC_QUOT,           KC_COMM,           KC_DOT,            KC_P,              KC_Y,              KC_F,              KC_G,              KC_C,              KC_R,              KC_L,              \
KC_A,              KC_O,              KC_E,              KC_U,              KC_I,              KC_D,              KC_H,              KC_T,              KC_N,              KC_S,              \
KC_SLSH,           KC_Q,              KC_J,              KC_K,              KC_X,              KC_B,              KC_M,              KC_W,              KC_V,              KC_Z,              \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_HALMAK \
KC_W,              KC_L,              KC_R,              KC_B,              KC_Z,              KC_QUOT,           KC_Q,              KC_U,              KC_D,              KC_J,              \
KC_S,              KC_H,              KC_N,              KC_T,              KC_COMM,           KC_DOT,            KC_A,              KC_E,              KC_O,              KC_I,              \
KC_F,              KC_M,              KC_V,              KC_C,              KC_SLSH,           KC_G,              KC_P,              KC_X,              KC_K,              KC_Y,              \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_WORKMAN \
KC_Q,              KC_D,              KC_R,              KC_W,              KC_B,              KC_J,              KC_F,              KC_U,              KC_P,              KC_QUOT,           \
KC_A,              KC_S,              KC_H,              KC_T,              KC_G,              KC_Y,              KC_N,              KC_E,              KC_O,              KC_I,              \
KC_Z,              KC_X,              KC_M,              KC_C,              KC_V,              KC_K,              KC_L,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_QWERTY \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_QUOT,           \
KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_TAP_QWERTZ \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Z,              KC_U,              KC_I,              KC_O,              KC_P,              \
KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_QUOT,           \
KC_Y,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP


#define MIRYOKU_ALTERNATIVES_NAV_INVERTEDT_FLIP \
KC_PGUP,           KC_HOME,           KC_UP,             KC_END,            KC_INS,            U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_PGDN,           KC_LEFT,           KC_DOWN,           KC_RGHT,           CW_TOGG,           U_NA,              TD(U_TD_U_NAV),    TD(U_TD_U_NUM),    KC_ALGR,           U_NA,              \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_NA,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_NAV_FLIP \
KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            KC_INS,            U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           CW_TOGG,           U_NA,              TD(U_TD_U_NAV),    TD(U_TD_U_NUM),    KC_ALGR,           U_NA,              \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_NA,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_NAV_INVERTEDT \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_INS,            KC_HOME,           KC_UP,             KC_END,            KC_PGUP,           \
U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_RGHT,           KC_PGDN,           \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_NAV_VI \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           CW_TOGG,           \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            KC_INS,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_NAV \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP


#define MIRYOKU_ALTERNATIVES_MOUSE_INVERTEDT_FLIP \
KC_WH_U,           KC_WH_L,           KC_MS_U,           KC_WH_R,           U_NU,              U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_WH_D,           KC_MS_L,           KC_MS_D,           KC_MS_R,           U_NU,              U_NA,              TD(U_TD_U_MOUSE),  TD(U_TD_U_SYM),    KC_ALGR,           U_NA,              \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_NA,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_MOUSE_FLIP \
KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           U_NU,              U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           U_NU,              U_NA,              TD(U_TD_U_MOUSE),  TD(U_TD_U_SYM),    KC_ALGR,           U_NA,              \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_NA,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_MOUSE_INVERTEDT \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_NU,              KC_WH_L,           KC_MS_U,           KC_WH_R,           KC_WH_U,           \
U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_R,           KC_WH_D,           \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_MOUSE_VI \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           U_NU,              \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_MOUSE \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP


#define MIRYOKU_ALTERNATIVES_MEDIA_INVERTEDT_FLIP \
RGB_HUI,           RGB_SAI,           KC_VOLU,           RGB_VAI,           RGB_TOG,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
RGB_MOD,           KC_MPRV,           KC_VOLD,           KC_MNXT,           U_NU,              U_NA,              TD(U_TD_U_MEDIA),  TD(U_TD_U_FUN),    KC_ALGR,           U_NA,              \
U_NU,              U_NU,              U_NU,              U_NU,              OU_AUTO,           U_NA,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_NP,              U_NP,              KC_MUTE,           KC_MPLY,           KC_MSTP,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_MEDIA_FLIP \
RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           RGB_TOG,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           U_NU,              U_NA,              TD(U_TD_U_MEDIA),  TD(U_TD_U_FUN),    KC_ALGR,           U_NA,              \
U_NU,              U_NU,              U_NU,              U_NU,              OU_AUTO,           U_NA,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_NP,              U_NP,              KC_MUTE,           KC_MPLY,           KC_MSTP,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_MEDIA_INVERTEDT \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_MOD,           KC_VOLU,           RGB_HUI,           RGB_SAI,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              U_NU,              KC_MPRV,           KC_VOLD,           KC_MNXT,           RGB_VAI,           \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_MEDIA_VI \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           RGB_TOG,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           U_NU,              \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              U_NU,              U_NU,              U_NU,              U_NU,              OU_AUTO,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_MEDIA \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           \
U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,              \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP


#define MIRYOKU_ALTERNATIVES_NUM_FLIP \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           \
U_NA,              KC_ALGR,           TD(U_TD_U_NAV),    TD(U_TD_U_NUM),    U_NA,              KC_EQL,            KC_4,              KC_5,              KC_6,              KC_SCLN,           \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              KC_BSLS,           KC_1,              KC_2,              KC_3,              KC_GRV,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MINS,           KC_0,              KC_DOT,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_NUM \
KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,              \
KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP


#define MIRYOKU_ALTERNATIVES_SYM_FLIP \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           \
U_NA,              KC_ALGR,           TD(U_TD_U_MOUSE),  TD(U_TD_U_SYM),    U_NA,              KC_PLUS,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_COLN,           \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              KC_PIPE,           KC_EXLM,           KC_AT,             KC_HASH,           KC_TILD,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_UNDS,           KC_LPRN,           KC_RPRN,           U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_SYM \
KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  KC_ALGR,           U_NA,              \
KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           U_NA,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_NP,              U_NP,              KC_LPRN,           KC_RPRN,           KC_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP


#define MIRYOKU_ALTERNATIVES_FUN_FLIP \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_PSCR,           KC_F7,             KC_F8,             KC_F9,             KC_F12,            \
U_NA,              KC_ALGR,           TD(U_TD_U_MEDIA),  TD(U_TD_U_FUN),    U_NA,              KC_SCRL,           KC_F4,             KC_F5,             KC_F6,             KC_F11,            \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NA,              KC_PAUS,           KC_F1,             KC_F2,             KC_F3,             KC_F10,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_TAB,            KC_SPC,            KC_APP,            U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_FUN \
KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,              \
KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP


#define MIRYOKU_ALTERNATIVES_BUTTON \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
KC_LALT,           KC_LCTL,           KC_LGUI,           KC_LSFT,           U_NU,              U_NU,              KC_RSFT,           KC_RGUI,           KC_RCTL,           KC_RALT,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
