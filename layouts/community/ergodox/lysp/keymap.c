#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#ifdef LAYOUT_ergodox_pretty
#define BASE 0 // Default layer
#define FNKY 1 // Fn and media
#define MSNM 2 // Mouse and numpad
#define GAME 3 // Gamepad
#define GAMEFN 4 // Gamepad Fn

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty \
  (
   KC_GRV,   KC_1,    KC_2,    KC_3,  KC_4,    KC_5,         KC_ESC,           KC_EQL,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
   KC_TAB,   KC_Q,    KC_W,    KC_E,  KC_R,    KC_T,         KC_BSLS,          KC_LBRC,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC,
   KC_CAPS,  KC_A,    KC_S,    KC_D,  KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
   KC_LSFT,  KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,         GUI_T(KC_LGUI),   RGUI_T(KC_NO), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
   MO(FNKY), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,                                                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TG(MSNM),
                                               CTL_T(KC_NO), ALT_T(KC_APP),    RALT_T(KC_NO), RCTL_T(KC_NO),
                                                             KC_HOME,          KC_PGUP,
                                      KC_SPC,  KC_DEL,       KC_END,           KC_PGDN,       KC_ENT,  KC_BSPC
  ),

  [FNKY] = LAYOUT_ergodox_pretty \
  (
   _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,
   _______, _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,
   _______, _______, _______, _______, _______, _______,                   KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, XXXXXXX,_______,
   _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,_______,
   _______, _______, _______, _______, _______,                                     KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX,TG(GAME),
                                                _______, _______, _______, _______,
                                                         _______, _______,
                                       _______, _______, _______, _______, _______, KC_INS
  ),

  [MSNM] = LAYOUT_ergodox_pretty \
  (
   _______, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC,
   _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_WH_L, _______, KC_BTN1, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,
   _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_WH_R,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NO,
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_BTN2, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
   _______, _______, _______, _______, _______,                                     KC_P0,   KC_P0,   KC_PDOT, KC_PENT, _______,
                                                _______, _______, _______, _______,
                                                         _______, _______,
                                       _______, _______, _______, _______, _______, _______
  ),

  [GAME] = LAYOUT_ergodox_pretty \
  (
   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______,    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   MO(GAMEFN), _______, _______, _______, _______,                                     _______, _______, _______, _______, TG(GAME),
                                                   _______, _______, _______, _______,
                                                            _______, _______,
                                          KC_SPC, KC_BSPC,  _______, _______, _______, KC_DEL
  ),

  [GAMEFN] = LAYOUT_ergodox_pretty \
  (
   _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
   _______, _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
   _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, TG(GAME),
                                                _______, _______, _______, _______,
                                                         _______, _______,
                                       _______, _______, _______, _______, _______, KC_INS
  ),
};
#endif

#ifdef RGBLIGHT_COLOR_LAYER_0
void matrix_init_user(void) {
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
};
#endif

bool process_record_lysp(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
        case RGB_SLD:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_mode(1);
#endif
            }
            return false;
    }
    return true;
}

#if !defined(KEYBOARD_kinesis) && !defined(KEYBOARD_hhkb_lite_2)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_lysp(keycode, record);
}
#endif

#if defined(KEYBOARD_ergodox_ez) || defined(KEYBOARD_ergodox_infinity)
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        default:
            break;
    }
    return state;
}
#endif
