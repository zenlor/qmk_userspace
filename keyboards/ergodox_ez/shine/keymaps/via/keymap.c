/* Copyright 2022 IFo Hancroft
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Default Layer
    * *---------------------------------------------------------------------*                             *---------------------------------------------------------------------*
    * | =       | 1       | 2       | 3       | 4       | 5       | Left    |                             | RIGHT   | 6       | 7       | 8       | 9       | 0       | -       |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * | Del     | Q       | W       | E       | R       | T       | L1      |                             | L1      | Y       | U       | I       | O       | P       | \       |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * | BkSp    | A       | S       | D       | F       | G       | Hyper   |                             | Meh     | H       | J       | K       | L       | ; / L2  | ' / CMD |
    * |---------+---------+---------+---------+---------+---------+---------*                             *---------+---------+---------+---------+---------+---------+---------|
    * | Shift   | Z/Ctrl  | X       | C       | V       | B       |                                                 | N       | M       | ,       | .       | //Ctrl  | Shift   |
    * |---------+---------+---------+---------+---------+---------*                                                 *---------+---------+---------+---------+---------+---------|
    * | Grv/L1  | "       | AltShf  | Left    | Right   |                                                                     | Up      | Down    | [       | ]       | ~L1     |
    * *-------------------------------------------------*                                                                     *-------------------------------------------------*
    *
    *                                                             *-------------------*         *-------------------*
    *                                                             | App     | LGui    |         | Alt     | Ctrl/Esc|
    *                                                   *---------+---------+---------|         |---------+---------+---------*
    *                                                   |         |         | Home    |         | PgUp    |         |         |
    *                                                   | Space   | BkSp    |---------|         |---------| Tab     | Enter   |
    *                                                   |         |         | End     |         | PgDn    |         |         |
    *                                                   *---------+---------+---------*         *---------+---------+---------*
    */

    LAYOUT_ergodox_pretty(
        KC_EQL,       KC_1,        KC_2,          KC_3,    KC_4,     KC_5,          KC_LEFT,                          KC_RGHT,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,               KC_MINS,
        KC_DEL,       KC_Q,        KC_W,          KC_E,    KC_R,     KC_T,          TG(1),                            TG(1),         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,               KC_BSLS,
        KC_BSPC,      KC_A,        KC_S,          KC_D,    KC_F,     KC_G,                                                           KC_H,     KC_J,     KC_K,     KC_L,     LT(2, KC_SCLN),     GUI_T(KC_QUOT),
        KC_LSFT,      CTL_T(KC_Z), KC_X,          KC_C,    KC_V,     KC_B,          ALL_T(KC_NO),                     MEH_T(KC_NO),  KC_N,     KC_M,     KC_COMM,  KC_DOT,   CTL_T(KC_SLSH),     KC_RSFT,
        LT(0,KC_GRV), KC_QUOT,     LALT(KC_LSFT), KC_LEFT, KC_RIGHT,                                                                           KC_UP,    KC_DOWN,  KC_LBRC,  KC_RBRC,            TT(1),

                                                                     ALT_T(KC_APP), KC_LGUI,              KC_LALT,    CTL_T(KC_ESC),
                                                                                    KC_HOME,              KC_PGUP,
                                                           KC_SPC,   KC_BSPC,       KC_END,               KC_PGDN,    KC_TAB,        KC_ENT
    ),

    LAYOUT_ergodox_pretty(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                                                    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,                                                                        _______,  _______,  _______,  _______,  _______,

                                                                    _______,  _______,            _______,  _______,
                                                                              _______,            _______,
                                                          _______,  _______,  _______,            _______,  _______,  _______
    ),

    LAYOUT_ergodox_pretty(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                                                    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,                                                                        _______,  _______,  _______,  _______,  _______,

                                                                    _______,  _______,            _______,  _______,
                                                                              _______,            _______,
                                                          _______,  _______,  _______,            _______,  _______,  _______
    ),

    LAYOUT_ergodox_pretty(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                                                    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,                                                                        _______,  _______,  _______,  _______,  _______,

                                                                    _______,  _______,            _______,  _______,
                                                                              _______,            _______,
                                                          _______,  _______,  _______,            _______,  _______,  _______
    )
};

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
