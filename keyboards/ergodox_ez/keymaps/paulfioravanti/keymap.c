#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
// For stenography
#include "keymap_steno.h"
// Custom files
#include "./keycodes/custom_keycodes.c"
#include "./keycodes/process_record_user.c"
#include "./combos.c"
#include "./user/layer_state_set_user.c"
#include "./user/keyboard_post_init_user.c"

enum layers {
  BASE, // Default layer
  CODER, // Coder layer
  MEDIA, // Media keys
  STENO, // Stenography layer
  CHORD // Chorded QWERTY layer
};

// Helpers to make keymaps a bit easier to read at a glance
enum helpers {
  ___ = KC_TRNS,
  _x_ = KC_NO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base Qwerty layer
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * |  ~`    |  1!  |  2@  |  3#  |  4$  |  5%  |STENO |  |  +=  |  6^  |  7&  |  8*  |  9(  |  0)  |  -_    |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | MO   |  | TG   |   Y  |   U  |   I  |   O  |   P  |  ' "   |
 * |--------+------+------+------+------+------| MEDIA|  | CHORD|------+------+------+------+------+--------|
 * |CTRL/ESC|   A  |   S  |   D  |   F  |   G  |------|  |------|   H  |   J  |   K  |   L  |  ;:  |CTRL/ESC|
 * |--------+------+------+------+------+------| MO   |  | MO   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | CODER|  | CODER|   N  |   M  |  ,<  |  .>  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   |acuAct|grvAct| LCmd |divvy |alfred|                              |LPane |RPane |UPane |DPane |LCmd~ |
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
  KC_GRV,         KC_1,         KC_2,     KC_3,           KC_4,           KC_5,      TG(STENO),
  KC_TAB,         KC_Q,         KC_W,     KC_E,           KC_R,           KC_T,      MO(MEDIA),
  LCTL_T(KC_ESC), KC_A,         KC_S,     KC_D,           KC_F,           KC_G,
  KC_LSHIFT,      KC_Z,         KC_X,     KC_C,           KC_V,           KC_B,      MO(CODER),
  LALT(KC_E),     LALT(KC_GRV), KC_LGUI,  SGUI(KC_SPACE), LALT(KC_SPACE),
                                                                          KC_LGUI,   KC_LALT,
                                                                                     KC_HOME,
                                                          KC_BSPACE,      KC_DELETE, KC_END,
  // right hand
  KC_EQUAL,  KC_6,    KC_7,      KC_8,       KC_9,    KC_0,      KC_MINUS,
  TG(CHORD), KC_Y,    KC_U,      KC_I,       KC_O,    KC_P,      KC_QUOTE,
             KC_H,    KC_J,      KC_K,       KC_L,    KC_SCOLON, RCTL_T(KC_ESC),
  MO(CODER), KC_N,    KC_M,      KC_COMMA,   KC_DOT,  KC_SLSH,   KC_RSHIFT,
                      LEFT_PANE, RIGHT_PANE, UP_PANE, DOWN_PANE, LGUI(KC_TILDE),
  KC_LALT,   KC_RGUI,
  KC_PGUP,
  KC_PGDOWN, KC_ENTER, KC_SPACE
),

/* Keymap 1: Programmer's toolkit layer (see keycodes/custom_keycodes.c)
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  | LCmd~|  | F12  |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |UP_ARROW|  &&= |  |>  |  &&  |  ->  |  !=  |      |  |      |pageU |   [  |  {   | <%=  |COFFEE| TROLL  |
 * |--------+------+------+------+------+------|  [x] |  | [x]  |------+------+------+------+------+--------|
 * |R_ARROW |  +=  |  |   | ||=  |  =>  |  ==  |------|  |------|arrowL|arrowD|arrowU|arrowR|      |  +1    |
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * |DN_ARROW|  -=  |  <|  |  ||  |  ~>  |  =~  |      |  |      |pageD |   ]  |  }   |  %>  |   \  |  -1    |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   |  ::  |  ..  |  ... | VRSN |GS_TS |                              |LAUGH |SMILE | WINK |NEUTRL|  SAD |
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
  RESET,        KC_F1,           KC_F2,           KC_F3,     KC_F4,        KC_F5,          LGUI(KC_TILDE),
  UP_ARROW,     AND_EQUALS,      FORWARD_PIPE,    AND_AND,   SINGLE_ARROW, NOT_EQUALS,     _x_,
  RIGHT_ARROW,  PLUS_EQUALS,     KC_PIPE,         OR_EQUALS, HASH_ROCKET,  EQUALS_EQUALS,
  DOWN_ARROW,   MINUS_EQUALS,    BACKWARD_PIPE,   OR_OR,     SPERMY,       MATCH_OPERATOR, ___,
  DOUBLE_COLON, INCLUSIVE_RANGE, EXCLUSIVE_RANGE, VRSN,      GS_TIMESTAMP,
                                                                           ___,            ___,
                                                                                           ENG,
                                                             MONOSNAP,     SGUI(KC_5),     JPN,
  // right hand
  KC_F12, KC_F6,     KC_F7,          KC_F8,                KC_F9,     KC_F10,    KC_F11,
  _x_,    KC_PGUP,   KC_LBRACKET,    KC_LEFT_CURLY_BRACE,  LEFT_ERB,  COFFEE,    TROLL,
          KC_LEFT,   KC_DOWN,        KC_UP,                KC_RIGHT,  ___,       PLUS_ONE,
  ___,    KC_PGDOWN, KC_RBRACKET,    KC_RIGHT_CURLY_BRACE, RIGHT_ERB, KC_BSLASH, MINUS_ONE,
                     LAUGH,          SMILE,                WINK,      NEUTRAL,   SAD,
  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
  KC_AUDIO_MUTE,
  KC_MEDIA_PLAY_PAUSE, KC_WWW_BACK, KC_WWW_FORWARD
),

/* Keymap 2: Media and mouse keys
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * |   [x]  |  [x] |  [x] |  [x] |  [x] |  [x] |  [x] |  | [x]  |  [x] |  [x] |  [x] |  [x] |  [x] |  [x]   |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |   [x]  |  [x] |  [x] | MsUp |  [x] |  [x] |      |  |      |  [x] |  [x] |  [x] |  [x] |  [x] |  [x]   |
 * |--------+------+------+------+------+------|      |  | [x]  |------+------+------+------+------+--------|
 * |   [x]  |  [x] |MsLeft|MsDown|MsRght|  [x] |------|  |------|MsLeft|MsDown| MsUp |MsRght|  [x] |  Play  |
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * |   [x]  |  [x] |  [x] |  [x] |  [x] |  [x] |  [x] |  | [x]  |  [x] |  [x] | Prev | Next |  [x] |  [x]   |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   | [x]  |  [x] |  [x] | Lclk | Rclk |                              |VolUp |VolDn | Mute |  [x] |  [x] |
 *   `----------------------------------'                              `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |  [x] |  [x] |  | [x]  | [x]  |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |  [x] |  | [x]  | Rclk |Lclk  |
 *                               |  [x] |  [x] |------|  |------|      |      |
 *                               |      |      |  [x] |  | [x]  |      |      |
 *                               `--------------------'  `--------------------'
 */
[MEDIA] = LAYOUT_ergodox(
  // left hand
  _x_, _x_, _x_,     _x_,     _x_,     _x_, _x_,
  _x_, _x_, _x_,     KC_MS_U, _x_,     _x_, ___,
  _x_, _x_, KC_MS_L, KC_MS_D, KC_MS_R, _x_,
  _x_, _x_, _x_,     _x_,     _x_,     _x_, _x_,
  _x_, _x_, _x_,     KC_BTN1, KC_BTN2,
                                       _x_, _x_,
                                            _x_,
                                  _x_, _x_, _x_,
  // right hand
  _x_, _x_,     _x_,     _x_,     _x_,     _x_, _x_,
  _x_, _x_,     _x_,     _x_,     _x_,     _x_, _x_,
       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _x_, KC_MPLY,
  _x_, _x_,     ___,     KC_MPRV, KC_MNXT, _x_, _x_,
                KC_VOLU, KC_VOLD, KC_MUTE, _x_, _x_,
  _x_, _x_,
  _x_,
  _x_, KC_BTN2, KC_BTN1
),

/* Keymap 3: Stenography
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * | BSPACE |  [x] |  [x] |  [x] |  [x] |  [x] |      |  | [x]  |  [x] |  [x] |  [x] |  [x] |  [x] | SPACE  |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |  |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|  [x] |  | [x]  |------+------+------+------+------+--------|
 * |   [x]  |   S  |   T  |   P  |   H  |   *  |------|  |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * |   [x]  |   S  |   K  |   W  |   R  |   *  |  [x] |  | [x]  |   *  |   R  |   B  |   G  |   s  |   Z    |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   | [x]  |  [x] |      |  [x] |   #  |                              |   #  |  [x] |  [x] |  [x] |  [x] |
 *   `----------------------------------'                              `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |   #  |  [x] |  | [x]  |  #   |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |  [x] |  | [x]  |      |      |
 *                               |  A   |   O  |------|  |------|  E   |  U   |
 *                               |      |      |  [x] |  | [x]  |      |      |
 *                               `--------------------'  `--------------------'
 */
[STENO] = LAYOUT_ergodox(
  // left hand
  KC_BSPC, _x_,    _x_,    _x_,    _x_,    _x_,     ___,
  ___,     STN_N1, STN_N2, STN_N3, STN_N4, STN_N5,  _x_,
  _x_,     STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,
  _x_,     STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, _x_,
  _x_,     _x_,    ___,    _x_,    STN_NC,
                                           STN_NC,  _x_,
                                                    _x_,
                                   STN_A,  STN_O,   _x_,

  // right hand
  _x_, _x_,     _x_,    _x_,    _x_,    _x_,    KC_SPACE,
  _x_, STN_N6,  STN_N7, STN_N8, STN_N9, STN_NA, STN_NB,
       STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
  _x_, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
                STN_NC, _x_,    _x_,    _x_,    _x_,
  _x_, STN_NC,
  _x_,
  _x_, STN_E,   STN_U
),
/* Keymap 4: Chorded Qwerty layer (see combos.c)
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * |  ~`    |  1!  |  2@  |  3#  |  4$  |  5%  |  [x] |  |  +=  |  6^  |  7&  |  8*  |  9(  |  0)  |  -_    |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |  Tab   | NUM  | NUM  | NUM  | NUM  | NUM  |      |  |      | NUM  | NUM  | NUM  | NUM  | NUM  |  ' "   |
 * |--------+------+------+------+------+------|  [x] |  |      |------+------+------+------+------+--------|
 * |CTRL/ESC|   Q  |   W  |   E  |   R  |   T  |------|  |------|   Y  |   U  |   I  |   O  |   P  |CTRL/ESC|
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  [x] |  |  [x] |   N  |   M  |  ,<  |  .>  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   |acuAct|grvAct| LCmd |divvy |alfred|                              |LPane |RPane |UPane |DPane |LCmd~ |
 *   `----------------------------------'                              `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      | LCmd | LAlt |  | RAlt | RCmd |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | home |  | pageU|      |      |
 *                               |BSPACE|DELETE|------|  |------| ENTER| SPACE|
 *                               |      |      | end  |  | pageD|      |      |
 *                               `--------------------'  `--------------------'
 */
[CHORD] = LAYOUT_ergodox(
  // left hand
  KC_GRV,         KC_1,         KC_2,     KC_3,           KC_4,           KC_5,      _x_,
  KC_TAB,         NUM,          NUM,      NUM,            NUM,            NUM,       _x_,
  LCTL_T(KC_ESC), KC_Q,         KC_W,     KC_E,           KC_R,           KC_T,
  KC_LSHIFT,      KC_Z,         KC_X,     KC_C,           KC_V,           KC_B,      _x_,
  LALT(KC_E),     LALT(KC_GRV), KC_LGUI,  SGUI(KC_SPACE), LALT(KC_SPACE),
                                                                          KC_LGUI,   KC_LALT,
                                                                                     KC_HOME,
                                                          KC_BSPACE,      KC_DELETE, KC_END,
  // right hand
  KC_EQUAL,  KC_6,    KC_7,      KC_8,       KC_9,    KC_0,      KC_MINUS,
  ___,       NUM,     NUM,       NUM,        NUM,     NUM,       KC_QUOTE,
             KC_Y,    KC_U,      KC_I,       KC_O,    KC_P,      RCTL_T(KC_ESC),
  _x_,       KC_N,    KC_M,      KC_COMMA,   KC_DOT,  KC_SLSH,   KC_RSHIFT,
                      LEFT_PANE, RIGHT_PANE, UP_PANE, DOWN_PANE, LGUI(KC_TILDE),
  KC_LALT,   KC_RGUI,
  KC_PGUP,
  KC_PGDOWN, KC_ENTER, KC_SPACE
)};
