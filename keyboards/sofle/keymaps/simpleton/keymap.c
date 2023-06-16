#include QMK_KEYBOARD_H

enum layers {
    COLEMAK = 0,
    MEDIA,
    NAVIGATION,
    MOUSE,
    FUNCTIONS,
    NUMBERS,
    SYMBOLS,
    MINECRAFT,
    DOTA,
    QWERTY,
    OLD,
    TEMPLATE
};

// homerow mods
#define A_GUI   GUI_T(KC_A)
#define R_ALT   ALT_T(KC_R)
#define S_SHIFT SFT_T(KC_S)
#define T_CTRL  CTL_T(KC_T)
#define N_CTRL  CTL_T(KC_N)
#define E_SHIFT SFT_T(KC_E)
#define I_ALT   ALT_T(KC_I)
#define O_GUI   GUI_T(KC_O)

// thumb keys
#define ESC_MEDI LT(MEDIA,      KC_ESC      )
#define SPC_NAVI LT(NAVIGATION, KC_SPACE    )
#define TAB_MOUS LT(MOUSE,      KC_TAB      )
#define ENT_FUNC LT(FUNCTIONS,  KC_ENTER    )
#define BSPC_NUM LT(NUMBERS,    KC_BACKSPACE)
#define DEL_SYMB LT(SYMBOLS,    KC_DEL      )

// combos
#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT   LCTL(KC_X)
#define REDO  LCTL(KC_Y)
#define UNDO  LCTL(KC_Z)

// base layer switches
#define DF_CLMK DF(COLEMAK  )
#define DF_MINE DF(MINECRAFT)
#define DF_DOTA DF(DOTA     )
#define DF_QWER DF(QWERTY   )
#define DF_OLD  DF(OLD      )

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
#define XP_SS  XP(S_SHARP_SMALL,     S_SHARP_CAPITAL    )

// keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [ COLEMAK ] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX,   A_GUI,   R_ALT, S_SHIFT,  T_CTRL,    KC_G,                      KC_M,  N_CTRL, E_SHIFT,   I_ALT,   O_GUI, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX, XXXXXXX,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          XXXXXXX, XXXXXXX,ESC_MEDI,SPC_NAVI,TAB_MOUS,ENT_FUNC,BSPC_NUM,DEL_SYMB, XXXXXXX, XXXXXXX
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [ MEDIA ] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______,   XP_AD,   XP_OD,   XP_SS,   XP_UD, _______,                   _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______, _______, KC_MSTP, KC_MPLY, KC_MUTE, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [ NAVIGATION ] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                      COPY, KC_PGUP,   KC_UP, KC_PGDN,    REDO, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                     PASTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______,     CUT, KC_HOME,  KC_INS,  KC_END,    UNDO, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______, _______,  KC_ENT, KC_BSPC,  KC_DEL, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [ MOUSE ] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______,                      COPY, KC_WH_U, KC_MS_U, KC_WH_D,    REDO, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                     PASTE, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, _______, _______, _______, _______, _______,     CUT, KC_WH_L, _______, KC_WH_R,    UNDO, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [ FUNCTIONS ] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_SCRL,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                   _______, DF_CLMK, DF_QWER, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10, _______, _______, _______, DF_DOTA, DF_MINE,  DF_OLD, _______, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______,  KC_ESC,  KC_SPC,  KC_TAB, _______, _______, _______, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [ NUMBERS ] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_SCLN,    KC_4,    KC_5,    KC_6, KC_MINS,                   _______, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______,  KC_GRV,    KC_1,    KC_2,    KC_3,  KC_EQL, _______, _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, KC_BSLS,    KC_0, _______, _______, _______, _______, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [ SYMBOLS ] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                   _______, _______, _______, _______, _______, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_UNDS,                   _______, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PLUS, _______, _______, _______, _______, _______, _______, _______, _______,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, KC_PIPE, KC_RPRN, _______, _______, _______, _______, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [ MINECRAFT ] = LAYOUT(
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
    [ DOTA ] = LAYOUT(
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
    [ QWERTY ] = LAYOUT(
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
    [ OLD ] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                 ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, DF_CLMK,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_T,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
    //├────────┼────────┼────────┼────────┼────────┼────────┤                 ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_G,  KC_GRV,    KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────╥────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_B, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V, XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
    //└────────┴────────┼────────┼────────┼────────┼────────┼────────╫────────┼────────┼────────┼────────┼────────┼────────┴────────┘
                          _______, _______, KC_LCTL,  KC_SPC, KC_LALT,  KC_ENT,  KC_DEL, KC_BSPC, _______, _______
    //                  └────────┴────────┴────────┴────────┴────────╨────────┴────────┴────────┴────────┴────────┘
    ),
    [ TEMPLATE ] = LAYOUT(
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case T_CTRL:
        case N_CTRL:
            return TAPPING_TERM;

        case A_GUI:
        case R_ALT:
        case S_SHIFT:
        case E_SHIFT:
        case I_ALT:
        case O_GUI:
            return TAPPING_TERM + 50;

        case ESC_MEDI:
        case SPC_NAVI:
        case TAB_MOUS:
        case ENT_FUNC:
        case BSPC_NUM:
        case DEL_SYMB:
            return TAPPING_TERM;

        default:
            return TAPPING_TERM;
    }
}
