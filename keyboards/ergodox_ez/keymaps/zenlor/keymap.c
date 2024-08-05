#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// https://configure.ergodox-ez.com/keyboard_layouts/kbyevg

// Layouts
#define BASE  0
#define RAISE 1
#define LOWER 2
#define GAMY  3
#define GAMZ  4
#define GAMX  5

// Keycodes
enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  RGB_FFA500,
  RGB_008000,
  RGB_800080,
  RGB_FF0000,
  DODGEJUMP,
  AUTOFIRE1
};

bool autofire1;
uint16_t autofire1_timer = false;
uint16_t autofire_interval = 100;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Prose layer
 *
 * Layer switch keys:
 * [tap/toggle]
 * (momentary)
 * {toggle}
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  |  [   |           |   ]  |   6  |   7  |   8  |   9  |   0  |   F5   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   C-D  |   Q  |   W  |   E  |   R  |   T  |  {   |           |   }  |   Y  |   U  |   I  |   O  |   P  |   C-U  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   C-E  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   C-Y  |
 * |--------+------+------+------+------+------|  (   |           |   )  |------+------+------+------+------+--------|
 * |   C-C  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | /    |   M-X  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |C-Spc |  Esc |  Tab | Super|LShift|                                       |[RAIS]|  -   |  '   | Enter| [LWR]|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LAlt | Home |       | PgUp | LCtrl|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  End |       |PgDwn |        |      |
 *                                 | BSPC | LCtl |------|       |------|  LAlt  | Space|
 *                                 |      |      | [LWR]|       | BSPC |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [BASE] = LAYOUT_ergodox(
    LCTL(KC_E),     KC_1,      KC_2,   KC_3,    KC_4,      KC_5, KC_LBRACKET,
    LCTL(KC_F),     KC_Q,      KC_W,   KC_E,    KC_R,      KC_T, KC_LCBR,
    LGUI(KC_G),     KC_A,      KC_S,   KC_D,    KC_F,      KC_G,
    LCTL(KC_C),     KC_Z,      KC_X,   KC_C,    KC_V,      KC_B, KC_LPRN,
    LCTL(KC_SPACE), KC_ESCAPE, KC_TAB, KC_LGUI, KC_LSHIFT,
                                                                       KC_LALT, KC_HOME,
                                                                                KC_END,
                                                            KC_BSPACE, KC_LCTL, MO(LOWER),

    // Right hand
    KC_RBRACKET,    KC_6,     KC_7,     KC_8,     KC_9,      KC_0,      KC_F5,
    KC_RCBR,        KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,      LGUI(KC_GRAVE),
                    KC_H,     KC_J,     KC_K,     KC_L,      KC_SCOLON, RCTL(KC_P),
    KC_RPRN,        KC_N,     KC_M,     KC_COMMA, KC_DOT,    KC_SLASH,  RCTL(RSFT(KC_P)),
    MO(RAISE),      KC_MINUS, KC_QUOTE, KC_ENTER, MO(LOWER),

    KC_PGUP,   KC_LCTL,
    KC_PGDOWN,
    KC_BSPACE, KC_LALT, KC_SPACE),

/* 1: Raise
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | F1   |  F2  |  F3  |  F4  |  F5  |      |           |      | F6   |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  !   |  @   |  Up  |   {  |   }  |      |           |      | PgUp |   7  |   8  |   9  |   +  |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  #   | Left | Down | Right|   $  |------|           |------| PgDwn|   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  [   |  ]   |   (  |   )  |   &  |      |           |      |   `  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | Esc  | Ins  | Super| LShft|                                       |######|   .  |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Bspc | LCtl |------|       |------| LAlt | Spc  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [RAISE] = LAYOUT_ergodox(
    KC_TRANSPARENT, KC_F1,       KC_F2,       KC_F3,   KC_F4,     KC_F5,   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,     KC_AT,       KC_UP,   KC_LCBR,   KC_RCBR, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_HASH,     KC_LEFT,     KC_DOWN, KC_RIGHT,  KC_DLR,
    KC_TRANSPARENT, KC_LBRACKET, KC_RBRACKET, KC_LPRN, KC_RPRN,   KC_AMPR, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_ESCAPE,   KC_INSERT,   KC_LGUI, KC_LSHIFT,
                                                                       KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                       KC_TRANSPARENT,
                                                                   KC_DELETE, KC_LCTL, KC_TRANSPARENT,

    KC_TRANSPARENT,      KC_F6,     KC_F7,     KC_F8,  KC_F9, KC_F10,    KC_F11,
    MT(KC_END, KC_PSCR), KC_PGUP,   KC_7,      KC_8,   KC_9,  KC_ASTR,   KC_F12,
                         KC_PGDOWN, KC_4,      KC_5,   KC_6,  KC_PLUS,   KC_TRANSPARENT,
    KC_PSCR,             KC_GRAVE,  KC_1,      KC_2,   KC_3,  KC_BSLASH, KC_TRANSPARENT,
                                     KC_TRANSPARENT, KC_DOT, KC_0,  KC_EQUAL,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LALT,        KC_SPACE),

/* 2: Lower
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      | Acc0 | Acc1 | Acc2 |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MUp  |      |      |      |           |      |      | End  | Home |      |      | [GAMX] |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | MLft | MDwn | MRgt |      |------|           |------| Lft  | Dwn  |  Up  |  Rgt |      | [GAMZ] |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgDn | PgUp |      |      | [GAMY] |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Bspc | LCtl |------|       |------| LAlt | Spc  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [LOWER] = LAYOUT_ergodox(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT,
                                                                            KC_MS_BTN2, KC_MS_BTN1, KC_TRANSPARENT,

    RGB_TOG,        RGB_HUI,        RGB_HUD,        RGB_VAD,        RGB_VAI,        RGB_MOD,        RGB_SLD,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(GAMX),
                    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, TO(GAMZ),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(GAMY),
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_FFA500, RGB_008000,
    RGB_800080,
    RGB_FF0000, KC_TRANSPARENT, KC_TRANSPARENT),

/* 3: Gaming Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | C-T  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |  T   |   -  |   7  |   8  |   9  |   0  |  =     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   1  |   2  |   3  |   4  |   5  |  6     |
 * |--------+------+------+------+------+------|      |           |S-Tab |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Tab  |   Q  |   W  |   E  |   `  | RShft  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |X/LCtl|   S  |Macro |   V  | Esc  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |  M   |C-Left|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |  R   |      |      |
 *                                 |[BASE]|      |------|       |------| Spc  |  F   |
 *                                 |      |      |      |       | lAlt |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [GAMY] = LAYOUT_ergodox(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT,
                                                                          TO(BASE), KC_TRANSPARENT, KC_TRANSPARENT,

    LCTL(KC_T),   KC_F1,       KC_F2, KC_F3, KC_F4,  KC_F5,     KC_F6,
    KC_T,         KC_KP_MINUS, KC_7,  KC_8,  KC_9,   KC_0,      KC_EQUAL,
                  KC_1,        KC_2,  KC_3,  KC_4,   KC_5,      KC_6,
    LSFT(KC_TAB), KC_TAB,      KC_Q,  KC_W,  KC_E,   KC_GRAVE,  KC_RSHIFT,
                               KC_X,  KC_S,  KC_V,   DODGEJUMP, KC_ESCAPE,
    KC_M, LCTL(KC_LEFT),
    KC_R,
    KC_LALT, KC_SPACE, KC_F),

/* 4: More Gaming Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |(exit)|  F6  |  F7  |  F8  |  F9  |  Ent |  BSPC  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |   F  |   7  |   8  |   9  |   0  |   -  |  =     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   1  |   2  |   3  |   4  |   5  |  6     |
 * |--------+------+------+------+------+------|      |           |S-Tab |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Tab  |   Q  |   W  |   E  |   R  |  T     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |(exit)|      |      |      |      |                                       |   A  |   S  |   D  |   F  |  G   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |  M   | Esc  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |  R   |      |      |
 *                                 |[BASE]|      |------|       |------| SPC  | LALT |
 *                                 |      |      |      |       | LCTL |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [GAMZ] = LAYOUT_ergodox(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT,
                                                                          TO(BASE), KC_TRANSPARENT, KC_TRANSPARENT,

    TO(BASE),  KC_F6,   KC_F7,   KC_F8, KC_F9, KC_ENTER, KC_BSPACE,
    KC_GRAVE,  KC_7,    KC_8,    KC_9,  KC_0,  KC_MINUS, KC_EQUAL,
               KC_1,    KC_2,    KC_3,  KC_4,  KC_5,     KC_6,
    KC_Z,      KC_TAB,  KC_Q,    KC_W,  KC_E,  KC_R,     KC_T,
                        KC_A,    KC_S,  KC_D,  KC_F,     KC_G,
    KC_T, KC_M,
    LCTL(KC_T),
    KC_LCTL, KC_SPACE, KC_LALT),

/* 5: More Gaming Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | Grave|   1  |   2  |   3  |   4  |   5  |  6     |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |  Tab |   Q  |   W  |   E  |   R  |   T  |  7     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   A  |   S  |   D  |   F  |   G  |  8     |
 * |--------+------+------+------+------+------|      |           | RSft |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   Z  |   X  |   C  |   V  |   B  |  9     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   A  |   S  |   D  | LCtrl|  Esc |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |  M   | Esc  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |  R   |      |      |
 *                                 |[BASE]|      |------|       |------|  Spc | LSft |
 *                                 |      |      |      |       |  P   |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [GAMX] = LAYOUT_ergodox(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT,
                                                                          TO(BASE), KC_TRANSPARENT, KC_TRANSPARENT,

    KC_GRAVE,  KC_1, KC_2, KC_3, KC_4, KC_5,    KC_6,
    KC_TAB,    KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_7,
               KC_A, KC_S, KC_D, KC_F, KC_G,    KC_8,
    KC_RSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_9,
                     KC_A, KC_S, KC_D, KC_LCTL, KC_ESC,
    KC_M, KC_I,
    KC_I,
    KC_P, KC_SPACE, KC_LSHIFT),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(RAISE)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Custom Macros
    case DODGEJUMP:
      if (record->event.pressed) {
        // keycodes: https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string_keycodes.h
        SEND_STRING(SS_DOWN(X_SPACE)SS_DOWN(X_V));
        _delay_ms(5);
        SEND_STRING(SS_UP(X_SPACE)SS_UP(X_V));
      }
      break;

    case AUTOFIRE1:
      if (record->event.pressed) {
          autofire1 ^= 1;
          autofire1_timer = timer_read();
      } else {
          autofire1 = 0;
          autofire1_timer = 0;
      }
      break;

    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      break;

    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;

    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      break;
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
}

// Runs constantly in the background, in a loop.
/*
void matrix_scan_user(void) {
    // AUTOFIRE1
    if (autofire1 && timer_elapsed(autofire1_timer) >= autofire_interval) {
        autofire1_timer = timer_read();
        SEND_STRING(SS_TAP(X_1));
    }
}
*/

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
