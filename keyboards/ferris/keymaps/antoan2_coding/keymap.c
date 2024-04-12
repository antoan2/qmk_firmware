#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
    {KC_1, KC_F1}, {KC_2, KC_F2}, {KC_3, KC_F3}, {KC_4, KC_F4}, {KC_5, KC_F5}, {KC_6, KC_F6}, {KC_7, KC_F7}, {KC_8, KC_F8}, {KC_9, KC_F9},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

void matrix_init_user(void) {
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

#define SP_C_CEDI RALT(KC_COMMA)
#define DEAD_HAT RALT(KC_6)
#define DEAD_GRAVE RALT(KC_GRAVE)
#define DEAD_AIGU RALT(KC_QUOTE)
#define DEAD_TREMA RSFT(DEAD_AIGU)

enum layer_names {
    _BL,
    _NAV_MEDIA,
    _SYM,
    _NUM_FN,
    _MOUSE,
    _SPECIALS,
};

enum custom_keycodes {
    VIM_SAVE = SAFE_RANGE,
    VIM_SAVE_QUIT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case VIM_SAVE:
            if (record->event.pressed) {
                SEND_STRING(":w" SS_TAP(X_ENTER));
                return false;
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case VIM_SAVE_QUIT:
            if (record->event.pressed) {
                SEND_STRING(":wq" SS_TAP(X_ENTER));
                return false;
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
};

enum { TD_E_HAT = 0, TD_E_TREMA, TD_E_AIGU, TD_E_GRAVE, TD_A_HAT, TD_A_GRAVE, TD_C_CEDILLE, TD_I_HAT, TD_I_TREMA, TD_O_HAT, TD_U_HAT, TD_U_TREMA, TD_U_GRAVE };

void dance_e_hat(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("6") "e");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("6") "E");
        reset_tap_dance(state);
    }
}

void dance_e_trema(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("\"") "e");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("\"") "E");
        reset_tap_dance(state);
    }
}

void dance_e_aigu(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("e"));
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("E"));
        reset_tap_dance(state);
    }
}

void dance_e_grave(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("`") "e");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("`") "E");
        reset_tap_dance(state);
    }
}

void dance_a_hat(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("6") "a");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("6") "A");
        reset_tap_dance(state);
    }
}

void dance_a_grave(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("`") "a");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("`") "A");
        reset_tap_dance(state);
    }
}

void dance_i_hat(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("6") "i");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("6") "I");
        reset_tap_dance(state);
    }
}

void dance_i_trema(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("\"") "i");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("\"") "I");
        reset_tap_dance(state);
    }
}

void dance_o_hat(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("6") "o");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("6") "O");
        reset_tap_dance(state);
    }
}

void dance_o_grave(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("`") "o");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("`") "O");
        reset_tap_dance(state);
    }
}

void dance_u_hat(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("6") "u");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("6") "U");
        reset_tap_dance(state);
    }
}

void dance_u_trema(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("\"") "u");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("\"") "U");
        reset_tap_dance(state);
    }
}

void dance_u_grave(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT("`") "u");
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_RALT("`") "U");
        reset_tap_dance(state);
    }
}

void dance_c_cedille(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_RALT(",c"));
        reset_tap_dance(state);
    } else {
        SEND_STRING(SS_LSFT(SS_RALT(",c")));
        reset_tap_dance(state);
    }
}
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Esc, twice for Caps Lock
    [TD_E_HAT] = ACTION_TAP_DANCE_FN(dance_e_hat), [TD_E_TREMA] = ACTION_TAP_DANCE_FN(dance_e_trema), [TD_E_AIGU] = ACTION_TAP_DANCE_FN(dance_e_aigu), [TD_E_GRAVE] = ACTION_TAP_DANCE_FN(dance_e_grave), [TD_A_HAT] = ACTION_TAP_DANCE_FN(dance_a_hat), [TD_A_GRAVE] = ACTION_TAP_DANCE_FN(dance_a_grave), [TD_C_CEDILLE] = ACTION_TAP_DANCE_FN(dance_c_cedille), [TD_I_HAT] = ACTION_TAP_DANCE_FN(dance_i_hat), [TD_I_TREMA] = ACTION_TAP_DANCE_FN(dance_i_trema), [TD_O_HAT] = ACTION_TAP_DANCE_FN(dance_o_hat), [TD_U_HAT] = ACTION_TAP_DANCE_FN(dance_u_hat), [TD_U_TREMA] = ACTION_TAP_DANCE_FN(dance_u_trema), [TD_U_GRAVE] = ACTION_TAP_DANCE_FN(dance_u_grave),
};

// home row both index fingers
const uint16_t PROGMEM esc_combo[] = {LCTL_T(KC_D), RCTL_T(KC_K), COMBO_END};
// home row both middle fingers
const uint16_t PROGMEM cap_word_combo[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};
// home row both last fingers
// Allow access to the lgui key with a combo on the base layer home row
const uint16_t PROGMEM lgui_combo[]    = {LGUI_T(KC_Z), RGUI_T(KC_SLSH), COMBO_END};
const uint16_t PROGMEM vim_save[]      = {LT(_SPECIALS, KC_SCLN), KC_W, COMBO_END};
const uint16_t PROGMEM vim_save_quit[] = {LT(_SPECIALS, KC_SCLN), KC_Q, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),  COMBO(cap_word_combo, QK_CAPS_WORD_TOGGLE), COMBO(lgui_combo, KC_LEFT_GUI), // Equivalent to nav modifier + LGUI
    COMBO(vim_save, VIM_SAVE), COMBO(vim_save_quit, VIM_SAVE_QUIT),
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // If using the mouse, should be long...
        case LT(_MOUSE, KC_E):
            return TAPPING_TERM + 500;
        // LGUI and RGUI should be slower to activate for now
        case LGUI_T(KC_Z):
            return TAPPING_TERM + 400;
        case RGUI_T(KC_SLSH):
            return TAPPING_TERM + 400;
        case LALT_T(KC_S):
            return TAPPING_TERM + 40;
        case LALT_T(KC_L):
            return TAPPING_TERM + 40;
        default:
            return TAPPING_TERM;
    }
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
        KC_Q,         KC_W,         LT(_MOUSE, KC_E),    KC_R,         KC_T,          KC_Y, KC_U,         KC_I,            KC_O,           KC_P,
        LT(_NUM_FN, KC_A), LALT_T(KC_S), LCTL_T(KC_D),   LSFT_T(KC_F), KC_G,          KC_H, RSFT_T(KC_J), RCTL_T(KC_K),    LALT_T(KC_L),   LT(_SPECIALS, KC_SCLN),
        LGUI_T(KC_Z),         KC_X,         KC_C,           KC_V,         KC_B,          KC_N, KC_M,         KC_COMM,         KC_DOT,         RGUI_T(KC_SLSH),
                                        KC_TAB, LT(_SYM, KC_BACKSPACE),          LT(_NAV_MEDIA, KC_SPACE), KC_ENTER
    ),
	[_NAV_MEDIA] = LAYOUT(
        KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,   KC_VOLU,       KC_VOLD,                KC_TRNS,      KC_TRNS, KC_MS_WH_DOWN, KC_MS_WH_UP,  KC_MS_WH_LEFT, KC_MS_WH_RIGHT,
        KC_LEFT_GUI,         KC_LEFT_ALT,           KC_LEFT_CTRL,  KC_LEFT_SHIFT,          KC_TRNS,      KC_TRNS, KC_DOWN,       KC_UP,        KC_LEFT,       KC_RIGHT,
        KC_MEDIA_REWIND,     KC_MEDIA_FAST_FORWARD, KC_MUTE,       KC_MEDIA_PLAY_PAUSE,    KC_TRNS,      KC_TRNS, KC_PAGE_DOWN,  KC_PAGE_UP,   KC_HOME,       KC_END,
                                                                               KC_TRNS,                KC_TRNS,      KC_TRNS, KC_TRNS
    ),
	[_SYM] = LAYOUT(
        KC_TILDE,  KC_AT,               KC_HASH,         KC_DOLLAR,     KC_PERCENT,                    KC_CIRC, KC_AMPERSAND,    KC_ASTERISK,            KC_QUESTION,          KC_TRNS,
        KC_EXCLAIM,KC_LEFT_PAREN,       KC_LEFT_BRACKET, KC_UNDERSCORE, KC_MINUS,                      KC_PLUS,       KC_EQUAL,        KC_RIGHT_BRACKET,       KC_RIGHT_PAREN,       KC_COLON,
        KC_GRAVE,  KC_LEFT_CURLY_BRACE, KC_TRNS,         KC_QUOTE,      KC_LEFT_ANGLE_BRACKET,         KC_RIGHT_ANGLE_BRACKET,       KC_DOUBLE_QUOTE, KC_BACKSLASH,   KC_RIGHT_CURLY_BRACE,   KC_PIPE,
                                                                           KC_TRNS,       KC_TRNS,         KC_TRNS,       KC_TRNS
    ),
    [_NUM_FN] = LAYOUT(
        // KC_F1,        KC_F2,        KC_F3,        KC_F4, KC_F5,                                       KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10,
        // LGUI_T(KC_1), LALT_T(KC_2), LCTL_T(KC_3), LSFT_T(KC_4), KC_5,          KC_6,    RSFT_T(KC_7), RCTL_T(KC_8),    LALT_T(KC_9),   RGUI_T(KC_0),
        // KC_SLASH,     KC_PLUS, KC_MINUS, KC_ASTERISK, KC_DOT,                       KC_COMMA, KC_EQUAL, KC_TRNS, KC_F11, KC_F12,
        //                                        KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_SLASH, KC_7, KC_8, KC_9, KC_MINUS,
KC_TRNS, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_TRNS,               KC_ASTERISK, KC_4, KC_5, KC_6, KC_PLUS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, KC_1, KC_2, KC_3, KC_EQUAL,
                            KC_TRNS, KC_TRNS,               KC_0, KC_TRNS
    ),
    [_MOUSE] = LAYOUT(
        KC_TRNS, KC_MS_BTN1, KC_TRNS, KC_MS_BTN2, KC_TRNS,             QK_DYNAMIC_TAPPING_TERM_UP,    KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_LEFT, KC_MS_WH_RIGHT,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS,             QK_DYNAMIC_TAPPING_TERM_DOWN,  KC_MS_DOWN,    KC_MS_UP,    KC_MS_LEFT,    KC_MS_RIGHT,
        KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS,             QK_DYNAMIC_TAPPING_TERM_PRINT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_TRNS,       KC_TRNS,
                                                  KC_TRNS,    KC_TRNS,             KC_TRNS,  KC_TRNS
    ),
    [_SPECIALS] = LAYOUT(
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, DEAD_AIGU, DEAD_GRAVE, KC_TRNS,               KC_TRNS, DEAD_HAT, DEAD_TREMA, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, TD_C_CEDILLE, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS
    )
};
