// Copyright 2022 Daniel Osipishin (@subrezon)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_id {
    _QWE = 0,
    _NUM,
    _SYM,
    _OPT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWE] = LAYOUT(
    //.--------+--------+--------+--------+--------.                 .--------+--------+--------+--------+--------.
           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    //|--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
    //|--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,  KC_DOT, KC_COMM, KC_SLSH,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_TAB, KC_LALT, KC_LCTL,MO(_NUM),  KC_SPC,  KC_ESC, KC_LGUI, KC_BSPC, KC_LSFT,MO(_SYM),  KC_DEL,  KC_ENT
    //'--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),

    [_NUM] = LAYOUT(
    //.--------+--------+--------+--------+--------.                 .--------+--------+--------+--------+--------.
        KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                    KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_BSLS,
    //|--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
        KC_MINS,    KC_4,    KC_5,    KC_6,    KC_0,                    KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_CAPS,
    //|--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
         KC_GRV,    KC_1,    KC_2,    KC_3,  KC_EQL,                    KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_TAB, KC_LALT, KC_LCTL, _______,  KC_SPC,  KC_ESC, KC_LGUI, KC_BSPC, KC_LSFT,MO(_OPT),  KC_DEL,  KC_ENT
    //'--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),

    [_SYM] = LAYOUT(
    //.--------+--------+--------+--------+--------.                 .--------+--------+--------+--------+--------.
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                   KC_MPRV, KC_PGUP,   KC_UP, KC_PGDN, KC_PIPE,
    //|--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
        KC_UNDS,  KC_DLR, KC_PERC, KC_CIRC, KC_RPRN,                   KC_MPLY, KC_LEFT, KC_DOWN, KC_RGHT, KC_LSFT,
    //|--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
        KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PLUS,                   KC_MNXT, KC_HOME,  KC_INS,  KC_END, KC_DQUO,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_TAB, KC_LALT, KC_LCTL,MO(_OPT),  KC_SPC,  KC_ESC, KC_LGUI, KC_BSPC, KC_LSFT, _______,  KC_DEL,  KC_ENT
    //'--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),

    [_OPT] = LAYOUT(
    //.--------+--------+--------+--------+--------.                 .--------+--------+--------+--------+--------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
    //'--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
    ),

};

#ifdef OLED_ENABLE

bool oled_task_user(void) {
       oled_write_P(PSTR("Layer:\n"), false);

       switch (get_highest_layer(layer_state)) {
              case _QWE :
                     oled_write_P(PSTR("QWERTY\n"), false);
                     break;

              case _NUM :
                     oled_write_P(PSTR("Numbers\n"), false);
                     break;

              case _SYM :
                     oled_write_P(PSTR("Symbols\n"), false);
                     break;

              case _OPT :
                     oled_write_P(PSTR("Options\n"), false);
                     break;

              default :
                     oled_write_P(PSTR("Undefined\n"), false);
       }

       return false;
};

#endif