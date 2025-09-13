// CRKBD keymap by @ozbakan - macOS optimized

#include QMK_KEYBOARD_H

enum custom_keycodes {
    CTL_SPC = SAFE_RANGE, // Control + Space for macOS input method toggle
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_SPC:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                wait_ms(30);
                tap_code(KC_SPC);
                wait_ms(10);
                unregister_code(KC_LCTL);
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: Base QWERTY, Volume and Brightness
    [0] = LAYOUT_split_3x6_3_ex2(
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_F15,              KC_VOLU, KC_Y, KC_U, KC_I, KC_O, KC_P,    KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_F14,              KC_VOLD, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                               KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                KC_LGUI, MO(1), LT(2, KC_ESC),                               LALT_T(KC_ENT), KC_SPC, KC_RCTL
    ),

    // Layer 1: Numbers, Navigation
    [1] = LAYOUT_split_3x6_3_ex2(
        _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_END,              KC_PGUP, KC_6,    KC_7,    KC_8,   KC_9,     KC_0,    _______,
        _______, _______, _______, _______, _______, _______, KC_HOME,             KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  KC_P0,   _______,
        _______, _______, _______, _______, _______, _______,                               MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_BTN1, MS_BTN2,
                                   _______, _______, _______,                               KC_RGUI, KC_RCTL, KC_RSFT
    ),

    // Layer 2: Symbols
    [2] = LAYOUT_split_3x6_3_ex2(
        _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC, _______,              _______, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, _______,
        _______, _______, _______, _______, _______, KC_TILD, _______,              _______, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, _______,
        _______, _______, _______, _______, _______,  KC_GRV,                                KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, _______,
                                   _______, _______, _______,                                KC_RGUI, KC_RCTL, KC_RSFT
    )
};
