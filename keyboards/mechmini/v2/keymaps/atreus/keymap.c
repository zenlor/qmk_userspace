#include QMK_KEYBOARD_H

#define _BL 0
#define _RAISE 1
#define _LOWER 2
#define ____ KC_TRNS
#define _XX_ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Default layer
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   `  |   \  |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Tab  | GUI  | Shift| Bksp | Ctrl | Alt  |Space | Fun  |   -  |   '  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_BL] = LAYOUT_ortho(
    KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,    KC_NO,   KC_NO,   KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,
    KC_A,   KC_S,   KC_D,    KC_F,    KC_G,    KC_NO,   KC_NO,   KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN,
    KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    KC_GRV,  KC_BSLS, KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH,
    KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC, MO(_RAISE), KC_MINS, KC_QUOT, KC_ENT),
/* Function layer
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |  Up  |   $  |   %  |      |      | PgUp |   7  |   8  |   9  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   (  | Left | Down |Right |   )  |      |      | PgDn |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   [  |   ]  |   #  |   {  |   }  |   ^  |   &  |   *  |   1  |   2  |   3  |   +  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Upper| Ins  |      |      |      |      |      |      |      |   .  |   0  |   =  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho(
    KC_EXLM,    KC_AT,   KC_UP,   KC_DLR,  KC_PERC, KC_NO,   KC_NO,   KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC,
    KC_LPRN,    KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN, KC_NO,   KC_NO,   KC_PGDN, KC_4,    KC_5,   KC_6, KC_NO,
    KC_LBRC,    KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_1,    KC_2,   KC_3, KC_PLUS,
    TG(_LOWER), KC_INS,  KC_LGUI, KC_LSFT, KC_DEL,  KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL),
/* Upper layer
 * ,-----------------------------------------------------------------------------------.
 * | Ins  | Home |      | End  | PgUp |      |      |  Up  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |      |      | PgDn |      |      | Down |  F4  |  F5  |  F6  | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Vol+ |      |      |      |      |      |      |  F1  |  F2  |  F3  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Vol- |      |      |      |      |      |      |      |PrtSc |ScrLk | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho(
    KC_INS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NO, KC_NO, KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_NO, KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_NO,  KC_VOLU, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
    KC_NO,  KC_VOLD, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   TO(_BL), KC_PSCR, KC_SCRL, KC_MPLY
),
};
