#include QMK_KEYBOARD_H

void matrix_init_user(void) {
  // debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

enum layer_names {
    _BL,
    _NAV,
    _SYM,
    _NUM,
};

// Almost exactly https://peppe.rs/posts/programming_on_34_keys/
// But for symlayer, and some of the home row modifiers

// TODO:
// - MISSING BACKSLASH...
// - Probably not so much

// KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
//                             KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BL] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,                        KC_Y, KC_U, KC_I,    KC_O,   KC_P,
        KC_A, LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), LGUI_T(KC_G),      RGUI_T(KC_H), RSFT_T(KC_J), RCTL_T(KC_K),    RALT_T(KC_L),   KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V, KC_B,                        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                    LT(3, KC_TAB), LT(1, KC_BACKSPACE),       LT(2, KC_SPACE), KC_ENTER
    ),
	[_NAV] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,    KC_LEFT_PAREN,   KC_RIGHT_PAREN,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_LEFT, KC_DOWN,             KC_UP,                   KC_RIGHT,        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_LEFT_BRACKET,     KC_RIGHT_BRACKET,        KC_QUOTE,        KC_DOUBLE_QUOTE,
                                               KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS
    ),
	[_SYM] = LAYOUT(
        KC_EXCLAIM,    KC_AT,        KC_HASH,     KC_DOLLAR,     KC_PERCENT,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_UNDERSCORE, KC_PLUS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TILDE,      KC_GRAVE,     KC_PIPE,     KC_EQUAL,      KC_MINUS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                              KC_TRNS,       KC_TRNS,          KC_TRNS, KC_TRNS
    ),
[_NUM] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_0,    KC_1, KC_2, KC_3, KC_TRNS,
                                           KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM esc_combo[] = {KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM cap_word_combo[] = {KC_Z, KC_SLASH, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(cap_word_combo, QK_CAPS_WORD_TOGGLE),
};
// clang-format on
