#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define CODER 1 // coder layer
#define MEDIA 2 // media keys
#define PLVR 3 // steno layer for Plover
#define TXBOLT 4 // TxBolt Steno Virtual Serial

// Helpers to make keymaps a bit easier to read at a glance
#define ___ KC_TRNS
#define _x_ KC_NO

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  AND_AND,
  AND_EQUALS,
  BACKWARD_PIPE,
  COFFEE,
  DOUBLE_COLON,
  DOWN_ARROW,
  DOWN_PANE,
  ENG,
  EQUALS_EQUALS,
  EXCLUSIVE_RANGE,
  FORWARD_PIPE,
  HASH_ROCKET,
  INCLUSIVE_RANGE,
  JPN,
  LAUGH,
  LEFT_ERB,
  LEFT_PANE,
  MATCH_OPERATOR,
  MINUS_EQUALS,
  MINUS_ONE,
  MONOSNAP,
  NEUTRAL,
  NOT_EQUALS,
  OR_EQUALS,
  OR_OR,
  PLUS_EQUALS,
  PLUS_ONE,
  RIGHT_ARROW,
  RIGHT_ERB,
  RIGHT_PANE,
  SAD,
  SINGLE_ARROW,
  SMILE,
  SPERMY,
  TROLL,
  UP_ARROW,
  UP_PANE,
  WINK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base Qwerty layer
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * |  ~`    |  1!  |  2@  |  3#  |  4$  |  5%  | PLVR |  |  =   |  6^  |  7&  |  8*  |  9(  |  0)  |  -_    |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | MO   |  | MO   |   Y  |   U  |   I  |   O  |   P  |  ' "   |
 * |--------+------+------+------+------+------| MEDIA|  | MEDIA|------+------+------+------+------+--------|
 * |CTRL/ESC|   A  |   S  |   D  |   F  |   G  |------|  |------|   H  |   J  |   K  |   L  |  ;:  |CTRL/ESC|
 * |--------+------+------+------+------+------| MO   |  | MO   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | CODER|  | CODER|   N  |   M  |  ,<  |  .>  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   |acuAct|grvAct| LCmd |divvy |alfred|                              |LPane |RPane |UPane |DPane | RCmd |
 *   `----------------------------------'                              `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      | LCmd | LAlt |  | RAlt | RCmd |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | home |  | pageU|      |      |
 *                               |BSPACE|DELETE|------|  |------| ENTER| SPACE|
 *                               |      |      | end  |  | pageD|      |      |
 *                               `--------------------'  `--------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_GRV,         KC_1,         KC_2,     KC_3,           KC_4,           KC_5,      TG(PLVR),
  KC_TAB,         KC_Q,         KC_W,     KC_E,           KC_R,           KC_T,      MO(MEDIA),
  LCTL_T(KC_ESC), KC_A,         KC_S,     KC_D,           KC_F,           KC_G,
  KC_LSHIFT,      KC_Z,         KC_X,     KC_C,           KC_V,           KC_B,      MO(CODER),
  LALT(KC_E),     LALT(KC_GRV), KC_LGUI,  SGUI(KC_SPACE), LALT(KC_SPACE),
                                                                          KC_LGUI,   KC_LALT,
                                                                                     KC_HOME,
                                                          KC_BSPACE,      KC_DELETE, KC_END,
  // right hand
  KC_EQUAL,  KC_6,    KC_7,      KC_8,       KC_9,    KC_0,      KC_MINUS,
  MO(MEDIA), KC_Y,    KC_U,      KC_I,       KC_O,    KC_P,      KC_QUOTE,
             KC_H,    KC_J,      KC_K,       KC_L,    KC_SCOLON, RCTL_T(KC_ESC),
  MO(CODER), KC_N,    KC_M,      KC_COMMA,   KC_DOT,  KC_SLSH,   KC_RSHIFT,
                      LEFT_PANE, RIGHT_PANE, UP_PANE, DOWN_PANE, KC_RGUI,
  KC_LALT,   KC_RGUI,
  KC_PGUP,
  KC_PGDOWN, KC_ENTER, KC_SPACE
),

/* Keymap 1: Programmer's toolkit layer
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  | LCmd~|  | F12  |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |UP_ARROW|  &&= |  |>  |  &&  |  ->  |  !=  |      |  |      |pageU |   [  |  {   | <%=  |COFFEE| TROLL  |
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * |R_ARROW |  +=  |  |   | ||=  |  =>  |  ==  |------|  |------|arrowL|arrowD|arrowU|arrowR|      |  +1    |
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * |DN_ARROW|  -=  |  <|  |  ||  |  ~>  |  =~  |      |  |      |pageD |   ]  |  }   |  %>  |   \  |  -1    |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   | esc  |  ::  |  ..  |  ... |      |                              |LAUGH |SMILE | WINK |NEUTRL|  SAD |
 *   `----------------------------------'                              `----------------------------------'
 *                                      ,-------------.  ,---------------.
 *                                      |      |      |  |volumeD|volumeU|
 *                               ,------|------|------|  |-------+-------+------.
 *                               |      |      | ENG  |  | mute  |       |      |
 *                               |mnoSnp|skitch|------|  |-------|browBk |browFw|
 *                               |      |      | JPN  |  | pause |       |      |
 *                               `--------------------'  `----------------------'
 */
[CODER] = LAYOUT_ergodox(
  // left hand
  RESET,           KC_F1,        KC_F2,           KC_F3,           KC_F4,        KC_F5,          LGUI(KC_TILDE),
  UP_ARROW,        AND_EQUALS,   FORWARD_PIPE,    AND_AND,         SINGLE_ARROW, NOT_EQUALS,     ___,
  UNICODE(0x27A1), PLUS_EQUALS,  KC_PIPE,         OR_EQUALS,       HASH_ROCKET,  EQUALS_EQUALS,
  DOWN_ARROW,      MINUS_EQUALS, BACKWARD_PIPE,   OR_OR,           SPERMY,       MATCH_OPERATOR, ___,
  KC_ESC,          DOUBLE_COLON, INCLUSIVE_RANGE, EXCLUSIVE_RANGE, ___,
                                                                                 ___,            ___,
                                                                                                 ENG,
                                                                   MONOSNAP,     SGUI(KC_5),     JPN,
  // right hand
  KC_F12, KC_F6,     KC_F7,          KC_F8,                KC_F9,     KC_F10,    KC_F11,
  ___,    KC_PGUP,   KC_LBRACKET,    KC_LEFT_CURLY_BRACE,  LEFT_ERB,  COFFEE,    TROLL,
          KC_LEFT,   KC_DOWN,        KC_UP,                KC_RIGHT,  ___,       PLUS_ONE,
  ___,    KC_PGDOWN, KC_RBRACKET,    KC_RIGHT_CURLY_BRACE, RIGHT_ERB, KC_BSLASH, MINUS_ONE,
                     LAUGH,          SMILE,                WINK,      NEUTRAL,   SAD,
  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
  KC_AUDIO_MUTE,
  KC_MEDIA_PLAY_PAUSE, KC_WWW_BACK, KC_WWW_FORWARD
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |  |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |  |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|  |------|MsLeft|MsDown| MsUp |MsRght|      |  Play  |
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |  |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                              |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                              `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      | Rclk |Lclk  |
 *                               |      |      |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
// MEDIA AND MOUSE
[MEDIA] = LAYOUT_ergodox(
  // left hand
  ___, ___, ___,     ___,     ___,     ___,     ___,
  ___, ___, ___,     KC_MS_U, ___,     ___,     ___,
  ___, ___, KC_MS_L, KC_MS_D, KC_MS_R, ___,
  ___, ___, ___,     ___,     ___,     ___,     ___,
  ___, ___, ___,     ___,     ___,
                                       ___,     ___,
                                                ___,
                              KC_BTN1, KC_BTN2, ___,
  // right hand
  ___, ___,     ___,     ___,     ___,     ___, ___,
  ___, ___,     ___,     ___,     ___,     ___, ___,
       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, ___, KC_MPLY,
  ___, ___,     ___,     KC_MPRV, KC_MNXT, ___, ___,
                 KC_VOLU, KC_VOLD, KC_MUTE, ___, ___,
  ___, ___,
  ___,
  ___, KC_BTN2, KC_BTN1
),
/* Keymap 3: Modified QWERTY for Plover Stego
 *
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * |        |      |      |      |      |      | BASE |  |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |MO    |  |MO    |   6  |   7  |   8  |   9  |  0   |        |
 * |--------+------+------+------+------+------|MEDIA |  |MEDIA |------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |------|  |------|   Y  |   U  |   I  |   O  |  P   |   [    |
 * |--------+------+------+------+------+------|MO    |  |MO    |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |CODER |  |CODER |   H  |   J  |   K  |   L  |  ;   |   '    |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                              |      |      |      |      |      |
 *   `----------------------------------'                              `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |  C   |   V  |------|  |------|  N   |  M   |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
[PLVR] = LAYOUT_ergodox(  // layer 3 : PLVR
  // left hand
  _x_,  _x_, _x_,  _x_,  _x_,  _x_,  TG(PLVR),
  _x_, KC_1, KC_2, KC_3, KC_4, KC_5, MO(MEDIA),
  _x_, KC_Q, KC_W, KC_E, KC_R, KC_T,
  _x_, KC_A, KC_S, KC_D, KC_F, KC_G, MO(CODER),
  _x_, _x_,  _x_,  _x_,  _x_,
                               _x_,  _x_,
                                     _x_,
                         KC_C, KC_V, _x_,
  // right hand
  _x_,       _x_,  _x_,  _x_,  _x_,  _x_,     _x_,
  MO(MEDIA), KC_6, KC_7, KC_8, KC_9, KC_0,    _x_,
             KC_Y, KC_U, KC_I, KC_O, KC_P,    KC_LBRC,
  MO(CODER), KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
                   _x_,  _x_,  _x_,  _x_,     _x_,
  _x_,       _x_,
  _x_,
  _x_,       KC_N, KC_M
),
// TxBolt Codes
#define Sl 0b00000001
#define Tl 0b00000010
#define Kl 0b00000100
#define Pl 0b00001000
#define Wl 0b00010000
#define Hl 0b00100000
#define Rl 0b01000001
#define Al 0b01000010
#define Ol 0b01000100
#define X  0b01001000
#define Er 0b01010000
#define Ur 0b01100000
#define Fr 0b10000001
#define Rr 0b10000010
#define Pr 0b10000100
#define Br 0b10001000
#define Lr 0b10010000
#define Gr 0b10100000
#define Tr 0b11000001
#define Sr 0b11000010
#define Dr 0b11000100
#define Zr 0b11001000
#define NM 0b11010000
#define GRPMASK 0b11000000
#define GRP0 0b00000000
#define GRP1 0b01000000
#define GRP2 0b10000000
#define GRP3 0b11000000
/* Keymap 4: TxBolt (Serial) for Stego
 *
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      | BASE |  |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |MO    |  |MO    |   #  |   #  |   #  |   #  |  #   |   #    |
 * |--------+------+------+------+------+------|MEDIA |  |MEDIA |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|  |------|   *  |   F  |   P  |   L  |  T   |   D    |
 * |--------+------+------+------+------+------|MO    |  |MO    |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |CODER |  |CODER |   *  |   R  |   B  |   G  |  S   |   Z    |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                              |      |      |      |      |      |
 *   `----------------------------------'                              `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |  A   |   O  |------|  |------|  E   |  U   |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
[TXBOLT] = LAYOUT_ergodox(  // layer 4 : TXBOLT
  // left hand
  KC_BSPC, _x_,   _x_,   _x_,   _x_,   _x_,   TG(BASE),
  _x_,     M(NM), M(NM), M(NM), M(NM), M(NM), MO(MEDIA),
  _x_,     M(Sl), M(Tl), M(Pl), M(Hl), M(X),
  _x_,     M(Sl), M(Kl), M(Wl), M(Rl), M(X),  MO(CODER),
  _x_,     _x_,   _x_,   _x_,   _x_,
                                       _x_,   _x_,
                                              _x_,
                                M(Al), M(Ol), _x_,
  // right hand
  _x_,       _x_,   _x_,   _x_,   _x_,   _x_,   _x_,
  MO(MEDIA), M(NM), M(NM), M(NM), M(NM), M(NM), _x_,
             M(X),  M(Fr), M(Pr), M(Lr), M(Tr), M(Dr),
  MO(CODER), M(X),  M(Rr), M(Br), M(Gr), M(Sr), M(Zr),
                    _x_,   _x_,   _x_,   _x_,   _x_,
  _x_,       _x_,
  _x_,
  _x_,       M(Er), M(Ur)
)
};

// NOTE: Sending Hex codes for Emojis involved needing to keep my
// input source permanently on "Unicode Hex Input", which doesn't
// seem to play well with Japanese IME, so Emojis will just have
// to stay as Slack-style strings.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case AND_AND:
        SEND_STRING("&&");
        return false;
      case AND_EQUALS:
        SEND_STRING("&&=");
        return false;
      case BACKWARD_PIPE:
        SEND_STRING("<|");
        return false;
      case COFFEE:
        /* SEND_STRING(SS_LALT("2615")); */
        SEND_STRING(":coffee:");
        return false;
      case DOUBLE_COLON:
        SEND_STRING("::");
        return false;
      case DOWN_ARROW:
        /* SEND_STRING(SS_LALT("2B07")); */
        SEND_STRING(":arrow_down:");
        return false;
      case DOWN_PANE:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_DOWN));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case ENG:
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_TAP(X_SCOLON));
        SEND_STRING(SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
        return false;
      case EQUALS_EQUALS:
        SEND_STRING("==");
        return false;
      case EXCLUSIVE_RANGE:
        SEND_STRING("...");
        return false;
      case FORWARD_PIPE:
        SEND_STRING("|>");
        return false;
      case HASH_ROCKET:
        SEND_STRING("=>");
        return false;
      case INCLUSIVE_RANGE:
        SEND_STRING("..");
        return false;
      case JPN:
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_TAP(X_J));
        SEND_STRING(SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
        return false;
      case LAUGH:
        /* SEND_STRING(SS_LALT("D83D+DE02")); */
        SEND_STRING(":joy:");
        return false;
      case LEFT_ERB:
        SEND_STRING("<%=");
        return false;
      case LEFT_PANE:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_LEFT));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case MATCH_OPERATOR:
        SEND_STRING("=~");
        return false;
      case MINUS_EQUALS:
        SEND_STRING("-=");
        return false;
      case MINUS_ONE:
        /* SEND_STRING(SS_LALT("D83D+DC4E")); */
        SEND_STRING(":-1:");
        return false;
      case MONOSNAP:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_5));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case NEUTRAL:
        /* SEND_STRING(SS_LALT("D83D+DE10")); */
        SEND_STRING(":neutral:");
        return false;
      case NOT_EQUALS:
        SEND_STRING("!=");
        return false;
      case OR_EQUALS:
        SEND_STRING("||=");
        return false;
      case OR_OR:
        SEND_STRING("||");
        return false;
      case PLUS_EQUALS:
        SEND_STRING("+=");
        return false;
      case PLUS_ONE:
        /* SEND_STRING(SS_LALT("D83D+DC4D")); */
        SEND_STRING(":+1:");
        return false;
      case RIGHT_ARROW:
        /* SEND_STRING(SS_LALT("27A1")); */
        /* UNICODE(0x000027A1); */
        SEND_STRING(":arrow_right:");
        return false;
      case RIGHT_ERB:
        SEND_STRING("%>");
        return false;
      case RIGHT_PANE:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_RIGHT));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case SAD:
        /* SEND_STRING(SS_LALT("D83D+DE1E")); */
        SEND_STRING(":disappointed:");
        return false;
      case SINGLE_ARROW:
        SEND_STRING("->");
        return false;
      case SMILE:
        /* SEND_STRING(SS_LALT("D83D+DE04")); */
        SEND_STRING(":smile:");
        return false;
      case SPERMY:
        SEND_STRING("~>");
        return false;
      case TROLL:
        SEND_STRING(":trollface:");
        return false;
      case UP_ARROW:
        /* SEND_STRING(SS_LALT("2B06")); */
        SEND_STRING(":arrow_up:");
        return false;
      case UP_PANE:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_UP));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case WINK:
        /* SEND_STRING(SS_LALT("D83D+DE09")); */
        SEND_STRING(":wink:");
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_OSX);
    rgblight_mode(0);
    rgblight_init();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
    case 0:
      #ifdef RGBLIGHT_COLOR_LAYER_0
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
      #else
      #ifdef RGBLIGHT_ENABLE
        rgblight_init();
      #endif
      #endif
      break;
    case 1:
      ergodox_right_led_1_on();
      #ifdef RGBLIGHT_COLOR_LAYER_1
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
      #endif
      break;
    case 2:
      ergodox_right_led_2_on();
      #ifdef RGBLIGHT_COLOR_LAYER_2
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
      #endif
      break;
    case 3:
      ergodox_right_led_3_on();
      #ifdef RGBLIGHT_COLOR_LAYER_3
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
      #endif
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      #ifdef RGBLIGHT_COLOR_LAYER_4
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
      #endif
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      #ifdef RGBLIGHT_COLOR_LAYER_5
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
      #endif
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      #ifdef RGBLIGHT_COLOR_LAYER_6
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
      #endif
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      #ifdef RGBLIGHT_COLOR_LAYER_7
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
      #endif
      break;
    default:
      break;
  }

  return state;
};
