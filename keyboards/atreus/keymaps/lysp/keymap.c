#include QMK_KEYBOARD_H

#define _QW 0
#define _RS 1
#define _LW 2
#define _SD 3
#define _MK 4

// Tap Dance declarations
enum {
    TD_SCLN,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for semi-colon, twice for F19 (for use with Hyper key)
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_F19),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = LAYOUT( /* Qwerty */
  KC_Q,           KC_W,   KC_E,    KC_R,    KC_T,                       KC_Y,           KC_U,    KC_I,    KC_O,    KC_P          ,
  KC_A,           KC_S,   KC_D,    KC_F,    KC_G,                       KC_H,           KC_J,    KC_K,    KC_L,    TD(TD_SCLN)   ,
  KC_Z,           KC_X,   KC_C,    KC_V,    KC_B,                       KC_N,           KC_M,    KC_COMM, KC_DOT,  KC_SLSH       ,
  LT(_SD,KC_ESC), KC_TAB, MO(_RS), KC_LSFT, KC_BSPC,  KC_LCTL, KC_LALT, LT(_MK,KC_SPC), KC_LGUI, KC_MINS, KC_QUOT, SFT_T(KC_ENT) ),
/*
 *  !       @     [     ]    &        ||      up     7     8     9    *
 *  #       $     (     )    *        ||      dn     4     5     6    +
 *  %       ^     {     }    =        ||       `     1     2     3    \
 * lower  insert  fn  shift  del ctrl || alt space  super  .     0    ⏎
 */
[_RS] = LAYOUT( /* [> RAISE <] */
  KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_AMPR,                   KC_UP,   KC_7,    KC_8,   KC_9, KC_ASTR ,
  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_ASTR,                   KC_DOWN, KC_4,    KC_5,   KC_6, KC_PLUS ,
  KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_GRV,                    KC_EQL,  KC_1,    KC_2,   KC_3, KC_BSLS ,
  TG(_LW), KC_INS,  _______, _______, KC_DEL,  _______, _______, _______, _______, KC_DOT, KC_0, _______ ),
/*
 * insert home   ↑   end   pgup       ||      up     F7     F8    F9     F10
 *  del    ←     ↓    →    pgdn       ||     down    F4     F5    F6     F11
 * voldn volup  mute       reset      ||             F1     F2    F3     F12
 *        caps   L0  shift   ␈   ctrl || alt space  super  prtsc scroll pause
 */
[_LW] = LAYOUT( /* [> LOWER <] */
  KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_VOLU, KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
  KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_VOLD, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
  KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, QK_BOOT,                   KC_MUTE, KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
  XXXXXXX, KC_CAPS, TO(_QW), _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS ),
/* Super Duper */
[_SD] = LAYOUT( /* [> Super Duper <] */
  _______, _______, _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______ ,
  _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______ ,
  _______, _______, _______, _______, _______,                   _______, _______, _______, _______,  _______ ,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______ ),
/* Mouse keys */
[_MK] = LAYOUT( /* [> Mouse keys <] */
  KC_BTN3, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U,                   _______, _______, _______, _______, _______ ,
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                   _______, _______, _______, _______, _______ ,
  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______ ,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ),

};
