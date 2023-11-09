#include "keymap_steno.h"
#include "raw_hid.h"
#include QMK_KEYBOARD_H

enum layers {
  STENO,
  QWERTY,
  QWERTY_CAPS,
  SYMBOL
};

enum custom_keycodes {
  DASH = SAFE_RANGE,
  DASH_BACKWARD,
  DASH_FORWARD,
  DASH_LEFT,
  DASH_RIGHT,
  STENO_MODE
};

#include "./user/combos.c"
#include "./user/process_record_user.c"
#include "./user/hid.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [STENO] = LAYOUT(
    TO(QWERTY),      STN_N1,  STN_N2,  STN_N3,     STN_N4,       STN_N5,    /* | */ STN_N6,   STN_N7,   STN_N8,     STN_N9,    STN_NA,          STN_FN,
    STN_FN,          STN_S1,  STN_TL,  STN_PL,     STN_HL,       STN_ST1,   /* | */ STN_ST3,  STN_FR,   STN_PR,     STN_LR,    STN_TR,          STN_DR,
    STN_PWR,         STN_S2,  STN_KL,  STN_WL,     STN_RL,       STN_ST2,   /* | */ STN_ST4,  STN_RR,   STN_BR,     STN_GR,    STN_SR,          STN_ZR,
                                       STN_NB,     STN_A,        STN_O,     /* | */ STN_E,    STN_U,    STN_NC
  ),
  [QWERTY] = LAYOUT(
    TO(STENO),       KC_Q,    KC_W,    KC_E,       KC_R,         KC_T,      /* | */ KC_Y,     KC_U,     KC_I,       KC_O,      KC_P,            KC_QUOTE,
    LCTL(KC_ESC),    KC_A,    KC_S,    KC_D,       KC_F,         KC_G,      /* | */ KC_H,     KC_J,     KC_K,       KC_L,      KC_SEMICOLON,    RCTL(KC_ESC),
    MO(QWERTY_CAPS), KC_Z,    KC_X,    KC_C,       KC_V,         KC_B,      /* | */ KC_N,     KC_M,     KC_COMMA,   KC_DOT,    KC_SLASH,        MO(QWERTY_CAPS),
                                       MO(SYMBOL), KC_BACKSPACE, KC_DELETE, /* | */ KC_ENTER, KC_SPACE, MO(SYMBOL)
  ),
  [QWERTY_CAPS] = LAYOUT(
    _______,         S(KC_Q), S(KC_W), S(KC_E),    S(KC_R),      S(KC_T),   /* | */ S(KC_Y),  S(KC_U),  S(KC_I),    S(KC_O),   S(KC_P),         S(KC_QUOTE),
    _______,         S(KC_A), S(KC_S), S(KC_D),    S(KC_F),      S(KC_G),   /* | */ S(KC_H),  S(KC_J),  S(KC_K),    S(KC_L),   S(KC_SEMICOLON), _______,
    _______,         S(KC_Z), S(KC_X), S(KC_C),    S(KC_V),      S(KC_B),   /* | */ S(KC_N),  S(KC_M),  S(KC_COMM), S(KC_DOT), S(KC_SLASH),     KC_RSFT,
                                       _______,    _______,      _______,   /* | */ _______,  _______, _______
  ),
  [SYMBOL] = LAYOUT(
    _______,         KC_1,    KC_2,    KC_3,       KC_4,         KC_5,      /* | */ KC_6,     KC_7,     KC_8,       KC_9,      KC_0,            KC_SCLN,
    _______,         KC_EXLM, KC_AT,   KC_LT,      KC_GT,        KC_BSLS,   /* | */ KC_DQT,   KC_PLUS,  KC_MINS,    KC_SLASH,  KC_ASTR,         KC_TAB,
    _______,         KC_PERC, KC_CIRC, KC_LBRC,    KC_RBRC,      KC_GRAVE,  /* | */ KC_MINS,  KC_AMPR,  KC_EQUAL,   KC_COMM,   KC_DOT,          KC_RSFT,
                                       _______,    _______,      _______,   /* | */ _______, _______, _______
  )
};

void keyboard_post_init_user(void) {
  // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_stenography.md#plover-with-steno-protocol
  steno_set_mode(STENO_MODE_GEMINI);
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // or uint8_t layer = get_highest_layer(state);
    switch (get_highest_layer(state)) {
        case (STENO):
          // red LED off
          palClearPad(GPIOA, 0);
          // green LED off
          palClearPad(GPIOA, 1);
          break;
        case (QWERTY):
          combo_enable();
          // red LED on
          palSetPad(GPIOA, 0);
          // green LED off
          palClearPad(GPIOA, 1);
          break;
        case (QWERTY_CAPS):
          // same as QWERTY
          combo_enable();
          // red LED off
          palClearPad(GPIOA, 0);
          // green LED on
          palSetPad(GPIOA, 1);
          break;
        case (SYMBOL):
          // both LEDs on for Symbol
          combo_disable();
          palSetPad(GPIOA, 0);
          palSetPad(GPIOA, 1);
          break;
        default:
          // shouldn't happen but just in case
          //combo_disable();
          palClearPad(GPIOA, 0);
          palClearPad(GPIOA, 1);
          break;
    }

    return state;
}
