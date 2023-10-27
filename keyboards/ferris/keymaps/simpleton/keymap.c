#include QMK_KEYBOARD_H

enum layers {
    COLEMAK = 0,
    NUMBERS,
    SYMBOLS,
    NAVIGATION,
    FUNCTIONS,
    UMLAUTS,
    BASIC,
    TEMPLATE
};

// homerow mods
#define A_GUI   LGUI_T(KC_A)
#define R_ALT   LALT_T(KC_R)
#define S_SHIFT LSFT_T(KC_S)
#define T_CTRL  LCTL_T(KC_T)
#define N_CTRL  RCTL_T(KC_N)
#define E_SHIFT RSFT_T(KC_E)
#define I_ALT   RALT_T(KC_I)
#define O_GUI   RGUI_T(KC_O)

// thumb keys
#define TAB_FUN  LT(FUNCTIONS,  KC_TAB)
#define SPC_NAV  LT(NAVIGATION, KC_SPACE)
#define BSPC_NUM LT(NUMBERS,    KC_BACKSPACE)
#define ENT_SYM  LT(SYMBOLS,    KC_ENTER)

// combos
#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT   LCTL(KC_X)
#define REDO  LCTL(KC_Y)
#define UNDO  LCTL(KC_Z)

// base layer switches
#define DF_CLMK  DF(COLEMAK)
#define DF_BASIC DF(BASIC  )

// // key overrides
// const key_override_t shift_comma_to_semicolon = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON);
// const key_override_t shift_dot_to_colon       = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,   KC_COLON);

// const key_override_t **key_overrides = (const key_override_t *[]) {
//     &shift_comma_to_semicolon,
//     &shift_dot_to_colon,
//     NULL
// };

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

#define MO_UML MO(UMLAUTS)
#define XP_AD  XP(A_DIAERESIS_SMALL, A_DIAERESIS_CAPITAL)
#define XP_OD  XP(O_DIAERESIS_SMALL, O_DIAERESIS_CAPITAL)
#define XP_UD  XP(U_DIAERESIS_SMALL, U_DIAERESIS_CAPITAL)
#define XP_SS  XP(S_SHARP_SMALL,     S_SHARP_CAPITAL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [COLEMAK] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────╥────────┬────────┬────────┬────────┬────────┐
           KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
          A_GUI,   R_ALT, S_SHIFT,  T_CTRL,    KC_G,    KC_M,  N_CTRL, E_SHIFT,   I_ALT,   O_GUI,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
           KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
    //└────────┴────────┴────────┼────────┼────────╫────────┼────────┼────────┴────────┴────────┘
                                   TAB_FUN, SPC_NAV,BSPC_NUM, ENT_SYM
    //                           └────────┴────────╨────────┴────────┘
    ),
    [NUMBERS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────╥────────┬────────┬────────┬────────┬────────┐
        KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        KC_SCLN,    KC_4,    KC_5,    KC_6, KC_MINS, _______, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
         KC_GRV,    KC_1,    KC_2,    KC_3,  KC_EQL, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┼────────┼────────╫────────┼────────┼────────┴────────┴────────┘
                                   KC_BSLS,    KC_0, _______, _______
    //                           └────────┴────────╨────────┴────────┘
    ),
    [SYMBOLS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────╥────────┬────────┬────────┬────────┬────────┐
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_UNDS, _______, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PLUS, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┼────────┼────────╫────────┼────────┼────────┴────────┴────────┘
                                   KC_PIPE, KC_RPRN, _______, _______
    //                           └────────┴────────╨────────┴────────┘
    ),
    [NAVIGATION] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────╥────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______,    COPY, KC_PGUP,   KC_UP, KC_PGDN,    REDO,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,   PASTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______,     CUT, KC_HOME,  KC_INS,  KC_END,    UNDO,
    //└────────┴────────┴────────┼────────┼────────╫────────┼────────┼────────┴────────┴────────┘
                                   _______, _______, KC_BSPC,  KC_DEL
    //                           └────────┴────────╨────────┴────────┘
    ),
    [FUNCTIONS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────╥────────┬────────┬────────┬────────┬────────┐
       DF_BASIC, _______, _______, _______, _______, KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______, KC_SCRL,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10,
    //└────────┴────────┴────────┼────────┼────────╫────────┼────────┼────────┴────────┴────────┘
                                   _______, _______,  KC_ESC,  MO_UML
    //                           └────────┴────────╨────────┴────────┘
    ),
    [UMLAUTS] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────╥────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
          XP_AD,   XP_OD,   XP_SS,   XP_UD, _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┼────────┼────────╫────────┼────────┼────────┴────────┴────────┘
                                   _______, _______, _______, _______
    //                           └────────┴────────╨────────┴────────┘
    ),
    [BASIC] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────╥────────┬────────┬────────┬────────┬────────┐
           KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, DF_CLMK,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
           KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
           KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
    //└────────┴────────┴────────┼────────┼────────╫────────┼────────┼────────┴────────┴────────┘
                                    KC_TAB,  KC_SPC, KC_BSPC,  KC_ENT
    //                           └────────┴────────╨────────┴────────┘
    ),
    [TEMPLATE] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────╥────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┴────────┼────────┼────────╫────────┼────────┼────────┴────────┴────────┘
                                   _______, _______, _______, _______
    //                           └────────┴────────╨────────┴────────┘
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case S_SHIFT:
        case T_CTRL:
        case N_CTRL:
        case E_SHIFT:
            return TAPPING_TERM;

        case A_GUI:
        case R_ALT:
        case I_ALT:
        case O_GUI:
            return TAPPING_TERM + 50;

        case TAB_FUN:
        case SPC_NAV:
        case BSPC_NUM:
        case ENT_SYM:
            return TAPPING_TERM;

        default:
            return TAPPING_TERM;
    }
}
