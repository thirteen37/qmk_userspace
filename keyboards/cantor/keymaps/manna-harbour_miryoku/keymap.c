#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

// thumb combos for Capslock (hyper) key
const uint16_t PROGMEM thumbcombos_tertiary[] = {LT(U_MEDIA,KC_ESC), LT(U_FUN,KC_DEL), COMBO_END};
combo_t key_combos[] = {
  COMBO(thumbcombos_tertiary, KC_CAPS)
};
