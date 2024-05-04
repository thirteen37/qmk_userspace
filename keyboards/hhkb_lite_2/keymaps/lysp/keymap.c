#include QMK_KEYBOARD_H

// Helpful defines
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define _BN 0
#define _BL 1
#define _FN 2
#define _FL 3
#define _MN 4

enum custom_keycodes { NORM = SAFE_RANGE, LYSP };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BN] =
LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,      KC_BSPC,
    KC_LCTL,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
    KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                KC_RSFT,
                 MO(_FN), KC_LALT, KC_LGUI,                       KC_SPC,                        KC_RGUI, KC_RALT,
                                                                                                                         KC_UP,
                                                                                                                KC_LEFT, KC_DOWN, KC_RGHT
),
[_BL] =
LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_ESC,
    KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,      KC_BSPC,
    GUI_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
    KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                KC_RSFT,
                 MO(_FL), KC_LALT, KC_LCTL,                       KC_SPC,                        KC_RCTL, KC_RALT,
                                                                                                                         KC_UP,
                                                                                                                KC_LEFT, KC_DOWN, KC_RGHT
),
[_FN] =
LAYOUT(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
    KC_CAPS,     _______, _______, _______, _______, _______, _______, KC_MUTE, KC_PSCR, KC_BRMD, KC_BRMU, KC_UP,   XXXXXXX,      KC_BSPC,
    _______,         _______, _______, _______, _______, _______, _______, KC_VOLU, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,          _______,
    _______,             LYSP,    _______, _______, _______, _______, _______, KC_VOLD, KC_END, KC_PGDN, KC_DOWN,                 _______,
                 _______, _______, _______,                        TO(_MN),                     _______, _______,
                                                                                                                         KC_PGUP,
                                                                                                                KC_HOME, KC_PGDN, KC_END
),
[_FL] =
LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  QK_BOOT,
    KC_CAPS,     _______, _______, _______, _______, _______, _______, KC_MUTE, KC_PSCR, KC_BRMD, KC_BRMU, KC_UP,   XXXXXXX,      KC_BSPC,
    _______,         _______, _______, _______, _______, _______, _______, KC_VOLU, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,          _______,
    _______,             NORM,    _______, _______, _______, _______, _______, KC_VOLD, KC_END, KC_PGDN, KC_DOWN,                 _______,
                 _______, _______, _______,                        TO(_MN),                     _______, _______,
                                                                                                                         KC_PGUP,
                                                                                                                KC_HOME, KC_PGDN, KC_END
),
[_MN] =
LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_TAB,  KC_NUM,  KC_PSLS, KC_PAST, XXXXXXX, XXXXXXX, _______,
    _______,     _______, _______, _______, _______, _______, _______, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, XXXXXXX,      _______,
    _______,         KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN2, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,           _______,
    _______,              _______, _______, _______, _______, _______, _______, XXXXXXX, KC_P1,  KC_P2,   KC_P3,                  _______,
                 TO(0),   _______, _______,                        _______,                  KC_P0,   KC_PDOT,
                                                                                                                         _______,
                                                                                                                _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case NORM:
                set_single_persistent_default_layer(_BN);
                return false;
            case LYSP:
                set_single_persistent_default_layer(_BL);
                return false;
        }
    }
    update_tri_layer(_BL, _FN, _FL);
    return true;
}
