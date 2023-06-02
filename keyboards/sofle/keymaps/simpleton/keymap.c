#include QMK_KEYBOARD_H

enum layers {
    COLEMAK = 0,
    NUMBERS,
    SYMBOLS,
    NAVIGATION,
    FUNCTIONS,
    UMLAUTS,
    MINECRAFT,
    DOTA,
    QWERTY,
    OLD,
    TEMPLATE
};

// homerow mods
const uint16_t PROGMEM A_GUI   = GUI_T(KC_A);
const uint16_t PROGMEM R_ALT   = ALT_T(KC_R);
const uint16_t PROGMEM S_SHIFT = SFT_T(KC_S);
const uint16_t PROGMEM T_CTRL  = CTL_T(KC_T);
const uint16_t PROGMEM N_CTRL  = CTL_T(KC_N);
const uint16_t PROGMEM E_SHIFT = SFT_T(KC_E);
const uint16_t PROGMEM I_ALT   = ALT_T(KC_I);
const uint16_t PROGMEM O_GUI   = GUI_T(KC_O);

// thumb keys
const uint16_t PROGMEM TAB_SYM  = LT(SYMBOLS,    KC_TAB);
const uint16_t PROGMEM SPC_NUM  = LT(NUMBERS,    KC_SPACE);
const uint16_t PROGMEM BSPC_NAV = LT(NAVIGATION, KC_BACKSPACE);
const uint16_t PROGMEM ENT_FUN  = LT(FUNCTIONS,  KC_ENTER);

// base layer switches
const uint16_t PROGMEM DF_CLMK = DF(COLEMAK);
const uint16_t PROGMEM DF_MINE = DF(MINECRAFT);
const uint16_t PROGMEM DF_DOTA = DF(DOTA);
const uint16_t PROGMEM DF_QWER = DF(QWERTY);
const uint16_t PROGMEM DF_OLD  = DF(OLD);

// key overrides
const key_override_t shift_comma_to_semicolon = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON);
const key_override_t shift_dot_to_colon       = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,   KC_COLON);

// unicode
enum unicode_names {
    A_DIAERESIS_SMALL,
    A_DIAERESIS_CAPITAL,
    O_DIAERESIS_SMALL,
    O_DIAERESIS_CAPITAL,
    U_DIAERESIS_SMALL,
    U_DIAERESIS_CAPITAL,
    S_SHARP_SMALL,
    S_SHARP_CAPITAL
};

const uint32_t PROGMEM unicode_map[] = {
    [A_DIAERESIS_SMALL]   = 0xe4,    // ä
    [A_DIAERESIS_CAPITAL] = 0xc4,    // Ä
    [O_DIAERESIS_SMALL]   = 0xf6,    // ö
    [O_DIAERESIS_CAPITAL] = 0xd6,    // Ö
    [U_DIAERESIS_SMALL]   = 0xfc,    // ü
    [U_DIAERESIS_CAPITAL] = 0xdc,    // Ü
    [S_SHARP_SMALL]       = 0xdf,    // ß
    [S_SHARP_CAPITAL]     = 0x1e9e,  // ẞ
};

const uint16_t PROGMEM MO_UML = MO(UMLAUTS);
const uint16_t PROGMEM XP_AD  = XP(A_DIAERESIS_SMALL, A_DIAERESIS_CAPITAL);
const uint16_t PROGMEM XP_OD  = XP(O_DIAERESIS_SMALL, O_DIAERESIS_CAPITAL);
const uint16_t PROGMEM XP_UD  = XP(U_DIAERESIS_SMALL, U_DIAERESIS_CAPITAL);
const uint16_t PROGMEM XP_SS  = XP(S_SHARP_SMALL,     S_SHARP_CAPITAL);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [COLEMAK] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX,   A_GUI,   R_ALT, S_SHIFT,  T_CTRL,    KC_G,                      KC_M,  N_CTRL, E_SHIFT,   I_ALT,   O_GUI, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX, XXXXXXX,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          XXXXXXX, XXXXXXX, TAB_SYM, SPC_NUM, XXXXXXX, XXXXXXX,BSPC_NAV, ENT_FUN, XXXXXXX, XXXXXXX
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [NUMBERS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                   KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                   KC_MINS,    KC_4,    KC_5,    KC_6, KC_SCLN, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______,  KC_EQL,    KC_1,    KC_2,    KC_3,  KC_GRV, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______, _______, _______,    KC_0, KC_BSLS, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [SYMBOLS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                   KC_UNDS,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_EXLM,   KC_AT, KC_HASH, KC_TILD, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______, _______, _______, KC_RPRN, KC_PIPE, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [NAVIGATION] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, KC_PGUP,   KC_UP, KC_PGDN, KC_CAPS,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______,  KC_ESC, KC_LEFT, KC_DOWN, KC_RGHT, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, KC_HOME,  KC_INS,  KC_END, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [FUNCTIONS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_SCRL,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                   _______, _______, _______, _______,  MO_UML, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10, _______, _______, DF_CLMK, DF_QWER, DF_MINE, DF_DOTA,  DF_OLD, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [UMLAUTS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______,   XP_AD,   XP_OD,   XP_SS,   XP_UD, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [MINECRAFT] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, DF_CLMK,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_GRV,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_SCLN,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX, XXXXXXX,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, KC_LCTL,  KC_SPC, KC_LALT,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [DOTA] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, DF_CLMK,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_GRV,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_SCLN,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX, XXXXXXX,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, KC_LCTL,  KC_SPC, KC_LALT,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [QWERTY] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, DF_CLMK,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_GRV,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, KC_LCTL,  KC_SPC, KC_LALT,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [OLD] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, DF_CLMK,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_T,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_G,  KC_GRV,    KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_B, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V, XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, KC_LCTL,  KC_SPC, KC_LALT,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [TEMPLATE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    )
};

const key_override_t **key_overrides = (const key_override_t *[]) {
    &shift_comma_to_semicolon,
    &shift_dot_to_colon,
    NULL
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_GUI:
        case R_ALT:
        case S_SHIFT:
        case T_CTRL:
        case N_CTRL:
        case E_SHIFT:
        case I_ALT:
        case O_GUI:
            return TAPPING_TERM + 50;
        case TAB_SYM:
        case SPC_NUM:
        case BSPC_NAV:
        case ENT_FUN:
            return TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}