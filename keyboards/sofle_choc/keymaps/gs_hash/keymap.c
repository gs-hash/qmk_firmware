/* Copyright 2023 Brian Low
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
 *
 * 2025-11-22 gs-hash modifications to layout
 */
#include QMK_KEYBOARD_H
#include "rgb_matrix.h"

#define OFS MT(MOD_RSFT,KC_F)
#define OJS MT(MOD_RSFT,KC_J)
#define ODT MT(MOD_LALT,KC_D)

enum layers {
    _BASE = 0,
    _NAV = 1,
    _SYM = 2,
    _FN1 = 3
};

enum combos {
    JK_ESC,
};

const uint16_t PROGMEM jk_combo[] = {
    OJS,
    KC_K,
    COMBO_END
};

combo_t key_combos[] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
};

// Only allow J+K = Escape while the base layer is active.
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return get_highest_layer(layer_state | default_layer_state) == _BASE;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  N/A  |    | N/A   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | GUI  | LALT | _SYM | LCTL | /Enter  /       \Space \  | RALT | _FN1  | RCTL | GUI  |
 *            |      |      |      |      |/       /         \ _NAV \ |      |      |      |      |
*            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,   KC_A,   KC_S,     ODT,    OFS,     KC_G,                          KC_H,     OJS,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_NO,      KC_NO,     KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LGUI, KC_LALT, MO(_SYM), KC_LCTL,  KC_ENT,    LT(_NAV, KC_SPC), KC_RALT, TG(_FN1), KC_RCTL, KC_RGUI
),
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |Home  | PgUp | PgDn | End  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | _SYM |      | /       /       \      \  |      | _FN1 |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
    _______,   _______,   _______,    _______,    _______,    _______,                           _______,   _______,     _______,    _______,       _______,    _______,
    _______,   _______,   _______,    _______,    _______,    _______,                           KC_HOME,   KC_PGUP,     KC_PGDN,     KC_END,       _______,     KC_DEL,
    _______,   _______,   _______,    _______,    _______,    _______,                           KC_LEFT,   KC_DOWN,     KC_UP,     KC_RIGHT,       _______,    _______,
    _______,   _______,   _______,    _______,    _______,    _______,  KC_NO  ,        KC_NO  , RCTL(KC_LEFT), RCTL(KC_RIGHT),     _______,    _______,       _______,    _______,
                          _______,    _______,    _______,    _______,  _______,        _______, _______,   _______,     _______,    _______
),
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  [   |  ]   |  {   |  }   |  (   |   )  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|  -   |  _   |  =   |  +   |  `   |  ~   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|  \   |  |   |  /   |  *   |  <   |  >   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | _SYM |      | /       /       \      \  |      | _FN1 |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYM] = LAYOUT(
    _______,   _______,   _______,    _______,    _______,    _______,                           _______,     _______,     _______,    _______,       _______,    _______,
    _______,   _______,   _______,    _______,    S(KC_1),    S(KC_2),                           KC_LBRC,     KC_RBRC,     S(KC_LBRC),  S(KC_RBRC),   S(KC_9),    S(KC_0),
    _______,   _______,   _______,    _______,    S(KC_9),    S(KC_0),                           KC_MINS,     S(KC_MINS),     KC_EQL,    S(KC_EQL),    KC_GRV,    S(KC_GRV),
    CW_TOGG,   _______,   _______,    _______,    _______,    _______,  KC_NO  ,        KC_NO  , KC_BSLS,     S(KC_BSLS),     KC_SLSH,     S(KC_8), S(KC_COMM),   S(KC_DOT),
                          _______,    _______,    _______,    _______,  _______,        _______, _______,     _______,     _______,    _______
),
/*
 * _FN1 - Function keys, media and RGB (toggle with the right thumb key).
 * Blank cells are transparent; CW toggles Caps Word.
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Mute | Vol- | Vol+ |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Prev | Next |      |      |      |      |
 * |------+------+------+------+------+------|  N/A  |    |  N/A  |------+------+------+------+------+------|
 * |  CW  |      |      |      |      |      |-------|    |-------| RGB  | Mode | Bri+ | Bri- |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      | FN1  |      |      |
 *            |      |      |      |      |/       /         \      \ |      |toggle|      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_FN1] = LAYOUT(
      KC_F1,     KC_F2,     KC_F3,      KC_F4,      KC_F5,      KC_F6,                             KC_F7,       KC_F8,       KC_F9,     KC_F10,        KC_F11,     KC_F12,
    _______,   _______,   _______,    _______,    _______,    _______,                           KC_MUTE,     KC_VOLD,     KC_VOLU,    _______,       _______,    _______,
    _______,   _______,   _______,    _______,    _______,    _______,                           KC_MPRV,     KC_MNXT,     _______,    _______,       _______,    _______,
    _______,   _______,   _______,    _______,    _______,    _______,   KC_NO,           KC_NO, QK_RGB_MATRIX_TOGGLE, QK_RGB_MATRIX_MODE_NEXT, QK_RGB_MATRIX_VALUE_UP, QK_RGB_MATRIX_VALUE_DOWN, _______, _______,
                          _______,    _______,    _______,     _______,  _______,        _______, _______,     _______,     _______,    _______
)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NAV]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_SYM]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN1]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif
