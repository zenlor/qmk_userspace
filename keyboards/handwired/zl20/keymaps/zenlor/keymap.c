#include QMK_KEYBOARD_H

#define KC_SUPER KC_LEFT_GUI

#define _NUMPAD 0
#define _RAISE 1
#define _LOWER 2
#define _LARKA 3
#define _LARKB 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUMPAD] = LAYOUT(
            KC_ESC,     KC_KP_7, KC_KP_8, KC_KP_9,
            KC_TAB,     KC_KP_4, KC_KP_5, KC_KP_6,
            MO(_RAISE), KC_KP_1, KC_KP_2, KC_KP_3,
            MO(_LOWER), KC_KP_0, KC_UP,   KC_RSHIFT,
            KC_SUPER,   KC_LEFT, KC_DOWN, KC_RIGHT
            ),
    [_RAISE] = LAYOUT(
            KC_ESC,   TO(_LARKA), KC_KP_8, KC_KP_9,
            KC_TAB,   KC_KP_4,    KC_KP_5, KC_KP_6,
            KC_TRNS,  KC_KP_1,    KC_KP_2, KC_KP_3,
            KC_TRNS,  KC_KP_0,    KC_UP,   KC_RSHIFT,
            KC_SUPER, KC_LEFT,    KC_DOWN, KC_RIGHT
            ),
    [_LOWER] = LAYOUT(
            KC_ESC,   KC_KP_7, KC_KP_8, KC_KP_9,
            KC_TAB,   KC_KP_4, KC_KP_5, KC_KP_6,
            KC_TRNS,  KC_KP_1, KC_KP_2, KC_KP_3,
            KC_TRNS,  KC_KP_0, KC_UP,   KC_RSHIFT,
            KC_SUPER, KC_LEFT, KC_DOWN, KC_RIGHT
            ),

    [_LARKA] = LAYOUT(
            MO(_LARKB), KC_4, KC_5, KC_6,
            KC_TAB,     KC_1, KC_2, KC_3,
            KC_Q,       KC_W, KC_E, KC_R,
            KC_A,       KC_S, KC_D, KC_F,
            KC_Z,       KC_X, KC_T, KC_G
            ),
    [_LARKB] = LAYOUT(
            KC_TRNS, TO(_NUMPAD), KC_5,  KC_6,
            KC_TAB,  KC_F1,       KC_F2, KC_F3,
            KC_Q,    KC_W,        KC_E,  KC_R,
            KC_A,    KC_S,        KC_D,  KC_F,
            KC_Z,    KC_X,        KC_T,  KC_G
            )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
