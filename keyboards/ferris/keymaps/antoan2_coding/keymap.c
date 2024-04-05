#include QMK_KEYBOARD_H

void matrix_init_user(void) {
  // debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

enum layer_names {
    _BL,
    _NAV_MEDIA,
    _SYM,
    _NUM_FN,
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
        KC_Q,         KC_W,         LT(4, KC_E),    KC_R,         KC_T,          KC_Y, KC_U,         KC_I,            KC_O,           KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),   LSFT_T(KC_F), KC_G,          KC_H, RSFT_T(KC_J), RCTL_T(KC_K),    LALT_T(KC_L),   RGUI_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,           KC_V,         KC_B,          KC_N, KC_M,         KC_COMM,         KC_DOT,         KC_SLSH,
                                        LT(3, KC_TAB), LT(2, KC_BACKSPACE),          LT(1, KC_SPACE), KC_ENTER
    ),
	[_NAV_MEDIA] = LAYOUT(
        KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,   KC_VOLU,       KC_VOLD,                KC_TRNS,      KC_TRNS, KC_MS_WH_DOWN, KC_MS_WH_UP,  KC_MS_WH_LEFT, KC_MS_WH_RIGHT,
        KC_LEFT_GUI,         KC_LEFT_ALT,           KC_LEFT_CTRL,  KC_LEFT_SHIFT,          KC_TRNS,      KC_TRNS, KC_DOWN,       KC_UP,        KC_LEFT,       KC_RIGHT,
        KC_MEDIA_REWIND,     KC_MEDIA_FAST_FORWARD, KC_MUTE,       KC_MEDIA_PLAY_PAUSE,    KC_TRNS,      KC_TRNS, KC_PAGE_DOWN,  KC_PAGE_UP,   KC_HOME,       KC_END,
                                                                               KC_TRNS,                KC_TRNS,      KC_TRNS, KC_TRNS
    ),
	[_SYM] = LAYOUT(
        KC_TILDE,  KC_AT,               KC_HASH,         KC_DOLLAR,     KC_PERCENT,                    KC_CIRCUMFLEX, KC_AMPERSAND,    KC_ASTERISK,            KC_QUESTION,          KC_TRNS,
        KC_EXCLAIM,KC_LEFT_PAREN,       KC_LEFT_BRACKET, KC_UNDERSCORE, KC_MINUS,                      KC_PLUS,       KC_EQUAL,        KC_RIGHT_BRACKET,       KC_RIGHT_PAREN,       KC_COLON,
        KC_GRAVE,  KC_LEFT_CURLY_BRACE, KC_TRNS,         KC_QUOTE,      KC_LEFT_ANGLE_BRACKET,         KC_RIGHT_ANGLE_BRACKET,       KC_DOUBLE_QUOTE, KC_BACKSLASH,   KC_RIGHT_CURLY_BRACE,   KC_PIPE,
                                                                           KC_TRNS,       KC_TRNS,         KC_TRNS,       KC_TRNS
    ),
    [_NUM_FN] = LAYOUT(
        KC_F1,        KC_F2,        KC_F3,        KC_F4, KC_F5,                                       KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10,
        LGUI_T(KC_1), LALT_T(KC_2), LCTL_T(KC_3), LSFT_T(KC_4), KC_5,          KC_6,    RSFT_T(KC_7), RCTL_T(KC_8),    LALT_T(KC_9),   RGUI_T(KC_0),
        KC_SLASH,     KC_PLUS, KC_MINUS, KC_ASTERISK, KC_DOT,                       KC_COMMA, KC_EQUAL, KC_TRNS, KC_F11, KC_F12,
                                               KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS
    ),
    [_MOUSE] = LAYOUT(
        KC_TRNS, KC_MS_BTN1, KC_TRNS, KC_MS_BTN2, KC_TRNS,             QK_DYNAMIC_TAPPING_TERM_UP,    KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_LEFT, KC_MS_WH_RIGHT,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS,             QK_DYNAMIC_TAPPING_TERM_DOWN,  KC_MS_DOWN,    KC_MS_UP,    KC_MS_LEFT,    KC_MS_RIGHT,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS,             QK_DYNAMIC_TAPPING_TERM_PRINT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_TRNS,       KC_TRNS,
                                                  KC_TRNS,    KC_TRNS,             KC_TRNS,  KC_TRNS
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // If using the mouse, should be long...
        case LT(4, KC_E):
            return TAPPING_TERM + 500;
        // LGUI and RGUI should be slower to activate for now
        case LGUI_T(KC_A):
            return TAPPING_TERM + 400;
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + 400;
        case LALT_T(KC_S):
            return TAPPING_TERM + 40;
        case LALT_T(KC_L):
            return TAPPING_TERM + 40;
        default:
            return TAPPING_TERM;
    }
}
