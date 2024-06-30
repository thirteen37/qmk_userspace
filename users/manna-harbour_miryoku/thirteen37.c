#include "thirteen37.h"

// per-key tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // faster shifts
        case LSFT_T(KC_V):
        case RSFT_T(KC_M):
            return TAPPING_TERM - 40;
        default:
            return TAPPING_TERM;
    }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 400;
}

// achordion for Atreus
#if defined(KEYBOARD_atreus) || defined(KEYBOARD_keyboardio_atreus)
bool on_left_hand(keypos_t pos) {
    return (pos.row < 3) && (pos.col < 5);
}

bool on_right_hand(keypos_t pos) {
    return (pos.row < 3) && (pos.col > 5);
}

bool on_thumb(keypos_t pos) {
    return (pos.row > 2);
}

bool atreus_opposite_hands(const keyrecord_t* tap_hold_record,
                           const keyrecord_t* other_record) {
    return on_thumb(tap_hold_record->event.key) ||
        on_thumb(other_record->event.key) ||
        (on_left_hand(tap_hold_record->event.key) ==
         on_right_hand(other_record->event.key));
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    return atreus_opposite_hands(tap_hold_record, other_record);
}
#endif
