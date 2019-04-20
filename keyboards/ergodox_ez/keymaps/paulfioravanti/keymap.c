#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
// For stenography
#include "keymap_steno.h"

#define BASE 0 // Default layer
#define CODER 1 // Coder layer
#define MEDIA 2 // Media keys
#define STENO 3 // Stenography layer
#define CHORD 4 // Chorded QWERTY layer

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
  NUM,
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

// Combos for chorded QWERTY
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
enum combos {
  QZ_A,
  WX_S,
  EC_D,
  RV_F,
  TB_G,
  YN_H,
  UM_J,
  ICOMMA_K,
  ODOT_L,
  PSLASH_SCOLON,
  NUMQ_1,
  NUMW_2,
  NUME_3,
  NUMR_4,
  NUMBSPACE_5,
  NUMU_6,
  NUMI_7,
  NUMO_8,
  NUMP_9,
  NUMDELETE_0
};

const uint16_t PROGMEM qz_combo[] = {KC_Q, KC_Z, COMBO_END};
const uint16_t PROGMEM wx_combo[] = {KC_W, KC_X, COMBO_END};
const uint16_t PROGMEM ec_combo[] = {KC_E, KC_C, COMBO_END};
const uint16_t PROGMEM rv_combo[] = {KC_R, KC_V, COMBO_END};
const uint16_t PROGMEM tb_combo[] = {KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM yn_combo[] = {KC_Y, KC_N, COMBO_END};
const uint16_t PROGMEM um_combo[] = {KC_U, KC_M, COMBO_END};
const uint16_t PROGMEM icomma_combo[] = {KC_I, KC_COMMA, COMBO_END};
const uint16_t PROGMEM odot_combo[] = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM pslash_combo[] = {KC_P, KC_SLASH, COMBO_END};
const uint16_t PROGMEM numq_combo[] = {NUM, KC_Q, COMBO_END};
const uint16_t PROGMEM numw_combo[] = {NUM, KC_W, COMBO_END};
const uint16_t PROGMEM nume_combo[] = {NUM, KC_E, COMBO_END};
const uint16_t PROGMEM numr_combo[] = {NUM, KC_R, COMBO_END};
const uint16_t PROGMEM numbspace_combo[] = {NUM, KC_BSPACE, COMBO_END};
const uint16_t PROGMEM numu_combo[] = {NUM, KC_U, COMBO_END};
const uint16_t PROGMEM numi_combo[] = {NUM, KC_I, COMBO_END};
const uint16_t PROGMEM numo_combo[] = {NUM, KC_O, COMBO_END};
const uint16_t PROGMEM nump_combo[] = {NUM, KC_P, COMBO_END};
const uint16_t PROGMEM numdelete_combo[] = {NUM, KC_DELETE, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QZ_A] = COMBO(qz_combo, KC_A),
  [WX_S] = COMBO(wx_combo, KC_S),
  [EC_D] = COMBO(ec_combo, KC_D),
  [RV_F] = COMBO(rv_combo, KC_F),
  [TB_G] = COMBO(tb_combo, KC_G),
  [YN_H] = COMBO(yn_combo, KC_H),
  [UM_J] = COMBO(um_combo, KC_J),
  [ICOMMA_K] = COMBO(icomma_combo, KC_K),
  [ODOT_L] = COMBO(odot_combo, KC_L),
  [PSLASH_SCOLON] = COMBO(pslash_combo, KC_SCOLON),
  [NUMQ_1] = COMBO(numq_combo, KC_1),
  [NUMW_2] = COMBO(numw_combo, KC_2),
  [NUME_3] = COMBO(nume_combo, KC_3),
  [NUMR_4] = COMBO(numr_combo, KC_4),
  [NUMBSPACE_5] = COMBO(numbspace_combo, KC_5),
  [NUMU_6] = COMBO(numu_combo, KC_6),
  [NUMI_7] = COMBO(numi_combo, KC_7),
  [NUMO_8] = COMBO(numo_combo, KC_8),
  [NUMP_9] = COMBO(nump_combo, KC_9),
  [NUMDELETE_0] = COMBO(numdelete_combo, KC_0)
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

/* Keymap 1: Programmer's toolkit layer
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  | LCmd~|  | F12  |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |UP_ARROW|  &&= |  |>  |  &&  |  ->  |  !=  |      |  |      |pageU |   [  |  {   | <%=  |COFFEE| TROLL  |
 * |--------+------+------+------+------+------|  [x] |  | [x]  |------+------+------+------+------+--------|
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
  RESET,       KC_F1,        KC_F2,           KC_F3,           KC_F4,        KC_F5,          LGUI(KC_TILDE),
  UP_ARROW,    AND_EQUALS,   FORWARD_PIPE,    AND_AND,         SINGLE_ARROW, NOT_EQUALS,     _x_,
  RIGHT_ARROW, PLUS_EQUALS,  KC_PIPE,         OR_EQUALS,       HASH_ROCKET,  EQUALS_EQUALS,
  DOWN_ARROW,  MINUS_EQUALS, BACKWARD_PIPE,   OR_OR,           SPERMY,       MATCH_OPERATOR, ___,
  KC_ESC,      DOUBLE_COLON, INCLUSIVE_RANGE, EXCLUSIVE_RANGE, ___,
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
 *
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
// MEDIA AND MOUSE
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
 *
 * ,--------------------------------------------------.  ,--------------------------------------------------.
 * | BSPACE |  [x] |  [x] |  [x] |  [x] |  [x] |      |  | [x]  |  [x] |  [x] |  [x] |  [x] |  [x] | SPACE  |
 * |--------+------+------+------+------+------+------|  |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |  |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|  [x] |  | [x]  |------+------+------+------+------+--------|
 * |   [x]  |   S  |   T  |   P  |   H  |   *  |------|  |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
 * |   [x]  |   S  |   K  |   W  |   R  |   *  |  [x] |  | [x]  |   *  |   R  |   B  |   G  |   s  |   Z    |
 * `--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
 *   | [x]  |  [x] |      |   A  |   O  |                              |   E  |   U  |  [x] |  [x] |  [x] |
 *   `----------------------------------'                              `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |  [x] |  [x] |  | [x]  | [x]  |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |  [x] |  | [x]  |      |      |
 *                               |  A   |   O  |------|  |------|  E   |  U   |
 *                               |      |      |  [x] |  | [x]  |      |      |
 *                               `--------------------'  `--------------------'
 */
[STENO] = LAYOUT_ergodox(  // layer 3 : Stenography
  // left hand
  KC_BSPC, _x_,    _x_,    _x_,    _x_,    _x_,     ___,
  ___,     STN_N1, STN_N2, STN_N3, STN_N4, STN_N5,  _x_,
  _x_,     STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,
  _x_,     STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, _x_,
  _x_,     _x_,    ___,    STN_A,  STN_O,
                                           _x_,     _x_,
                                                    _x_,
                                   STN_A,  STN_O,   _x_,

  // right hand
  _x_, _x_,     _x_,    _x_,    _x_,    _x_,    KC_SPACE,
  _x_, STN_N6,  STN_N7, STN_N8, STN_N9, STN_NA, STN_NB,
       STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
  _x_, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
                STN_E,  STN_U,  _x_,    _x_,    _x_,
  _x_, _x_,
  _x_,
  _x_, STN_E,   STN_U
),
/* Keymap 4: Chorded Qwerty layer
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
[CHORD] = LAYOUT_ergodox( // Layer 4: Chorded QWERTY
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
)
};

// NOTE: Sending Hex codes for Emojis involved needing to keep my
// input source permanently on "Unicode Hex Input", which doesn't
// seem to play well with Japanese IME, so Emojis will just have
// to stay as Slack-style strings for now.
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
        // SEND_STRING(SS_LALT("2615"));
        SEND_STRING(":coffee:");
        return false;
      case DOUBLE_COLON:
        SEND_STRING("::");
        return false;
      case DOWN_ARROW:
        // SEND_STRING(SS_LALT("2B07"));
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
        // SEND_STRING(SS_LALT("D83D+DE02"));
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
        // SEND_STRING(SS_LALT("D83D+DC4E"));
        SEND_STRING(":-1:");
        return false;
      case MONOSNAP:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_5));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case NEUTRAL:
        // SEND_STRING(SS_LALT("D83D+DE10"));
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
        // SEND_STRING(SS_LALT("D83D+DC4D"));
        SEND_STRING(":+1:");
        return false;
      case RIGHT_ARROW:
        // SEND_STRING(SS_LALT("27A1"));
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
        // SEND_STRING(SS_LALT("D83D+DE1E"));
        SEND_STRING(":disappointed:");
        return false;
      case SINGLE_ARROW:
        SEND_STRING("->");
        return false;
      case SMILE:
        // SEND_STRING(SS_LALT("D83D+DE04"));
        SEND_STRING(":smile:");
        return false;
      case SPERMY:
        SEND_STRING("~>");
        return false;
      case TROLL:
        SEND_STRING(":trollface:");
        return false;
      case UP_ARROW:
        // SEND_STRING(SS_LALT("2B06"));
        SEND_STRING(":arrow_up:");
        return false;
      case UP_PANE:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_UP));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case WINK:
        // SEND_STRING(SS_LALT("D83D+DE09"));
        SEND_STRING(":wink:");
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    // Set Unicode mode to Mac OS. More information:
    // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_unicode.md
    set_unicode_input_mode(UC_OSX);
    // Default all Ergodox EZ right-hand-side lights to be off.
    rgblight_mode(0);
    rgblight_init();
    // NOTE: "GeminiPR" is a stenography protocol that I've chosen to use when
    // communicating with Plover. The other option was "TX Bolt".
    // Although QMK says TX Bolt is the "default" protocol, it is an older
    // protocol than GeminiPR.
    // More information in the QMK docs:
    // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_stenography.md#plover-with-steno-protocol
    steno_set_mode(STENO_MODE_GEMINI);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
// NOTE: Not all cases here will get used, but there's probably no harm
// in keeping them here.
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
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
      #endif
      break;
    default:
      break;
  }
  return state;
}
