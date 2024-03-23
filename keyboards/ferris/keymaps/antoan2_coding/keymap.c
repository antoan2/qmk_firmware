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
    _MOUSE,
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
        KC_Q,         KC_W,         KC_E,           KC_R,         KC_T,          KC_Y, KC_U,         LT(4, KC_I),            KC_O,           KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),   LSFT_T(KC_F), KC_G,          KC_H, RSFT_T(KC_J), RCTL_T(KC_K),    LALT_T(KC_L),   RGUI_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,           KC_V,         KC_B,          KC_N, KC_M,         KC_COMM,         KC_DOT,         KC_SLSH,
                                    LT(3, KC_TAB), LT(1, KC_BACKSPACE),          LT(2, KC_SPACE), KC_ENTER
    ),
	[_NAV] = LAYOUT(
        KC_MEDIA_PREV_TRACK, KC_VOLU, KC_VOLD,             KC_MEDIA_NEXT_TRACK,   KC_TRNS,      KC_TRNS, KC_MS_WH_DOWN,  KC_MS_WH_UP, KC_TRNS,  KC_TRNS,
        KC_LEFT_GUI,             KC_LEFT_ALT, KC_LEFT_CTRL,             KC_LEFT_SHIFT,               KC_TRNS,               KC_TRNS, KC_LEFT, KC_DOWN,      KC_UP,         KC_RIGHT,
        KC_MEDIA_REWIND,     KC_MUTE, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD, KC_TRNS,    KC_TRNS,           KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP,    KC_END,
                                                           KC_TRNS,             KC_TRNS,               KC_TRNS, KC_TRNS
    ),
	[_SYM] = LAYOUT(
        KC_TILDE,  KC_AT,               KC_HASH,               KC_DOLLAR,     KC_PERCENT,      KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK,            KC_QUESTION,          KC_BACKSLASH,
        KC_EXCLAIM,KC_LEFT_PAREN,       KC_LEFT_BRACKET,       KC_UNDERSCORE, KC_EXCLAIM,      KC_TRNS,       KC_EQUAL,     KC_RIGHT_BRACKET,       KC_RIGHT_PAREN,       KC_DOUBLE_QUOTE ,
        KC_GRAVE,  KC_LEFT_CURLY_BRACE, KC_LEFT_ANGLE_BRACKET, KC_MINUS,      KC_PIPE,         KC_TRNS,       KC_PLUS,      KC_RIGHT_ANGLE_BRACKET, KC_RIGHT_CURLY_BRACE, KC_QUOTE,
                                                                           KC_TRNS,       KC_TRNS,         KC_TRNS,       KC_TRNS
    ),
    [_NUM] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_0,    KC_1, KC_2, KC_3, KC_TRNS,
                                               KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS
    ),
    [_MOUSE] = LAYOUT(
        KC_TRNS,    KC_TRNS,  KC_MS_WH_UP,   KC_TRNS,     KC_TRNS,               KC_TRNS, KC_MS_BTN1, KC_TRNS, KC_MS_BTN2, KC_TRNS,
        KC_MS_LEFT, KC_MS_UP, KC_MS_DOWN,    KC_MS_RIGHT, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_MS_WH_DOWN, KC_TRNS,     KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS
    ),
};


// home row both index fingers
const uint16_t PROGMEM esc_combo[] = {LCTL_T(KC_D), RCTL_T(KC_K), COMBO_END};
// home row both middle fingers
const uint16_t PROGMEM cap_word_combo[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};
// home row both last fingers
// Allow access to the lgui key with a combo on the base layer home row
const uint16_t PROGMEM lgui_combo[] = {LGUI_T(KC_A), RGUI_T(KC_SCLN), COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(cap_word_combo, QK_CAPS_WORD_TOGGLE),
    COMBO(lgui_combo, KC_LEFT_GUI), // Equivalent to nav modifier + LGUI
};
// clang-format on
