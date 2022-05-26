/*
 * Good on you for modifying your layout, this is the most nonQMK layout you will come across
 * There are three modes, Steno (the default), QWERTY (Toggleable) and a Momentary symbol layer
 *
 * Don't modify the steno layer directly, instead add chords using the keycodes and macros
 * from sten.h to the layout you want to modify.
 *
 * Observe the comment above processQWERTY!
 *
 * http://docs.gboards.ca
 */

#include QMK_KEYBOARD_H
#include "sten.h"
#include "keymap_steno.h"

// Proper Layers
#define FUNCT   (LSD | LK | LP | LH)
#define MEDIA   (LSD | LK | LW | LR)
#define MOVE    (ST1 | ST2)

// QMK Layers
#define STENO_LAYER   0
#define GAMING        1
#define GAMING_2      2

/* Keyboard Layout
 * ,---------------------------------.    ,------------------------------.
 * | FN  | LSU | LFT | LP | LH | ST1 |    | ST3 | RF | RP | RL | RT | RD |
 * |-----+-----+-----+----+----|-----|    |-----|----+----+----+----+----|
 * | PWR | LSD | LK  | LW | LR | ST2 |    | ST4 | RR | BB | RG | RS | RZ |
 * `---------------------------------'    `------------------------------'
 *                   ,---------------,    .---------------.
 *                   | LNO | LA | LO |    | RE | RU | RNO |
 *                   `---------------'    `---------------'
 */

// Note: You can only use basic keycodes here!
// P() is just a wrapper to make your life easier.
// PC() applies the mapping to all of the StenoLayers.
//   To overload, declare it with P() first.
//   Be sure to enable in rules.mk and see colemak-dh for usage
//
// FN is unavailable. That is reserved for system use.
// Chords containing PWR are always available, even in steno mode.
//
// http://docs.gboards.ca
uint32_t processQwerty(bool lookup) {
    // Specials
    P( RT  | RS  | RD  | RZ | LNO,        SEND_STRING(VERSION); SEND_STRING(__DATE__));
    P( LNO | RNO | LA  | LO | RE | RU,    SEND(KC_MPLY));
    P( LFT | LK  | LP  | LW,              REPEAT());
    P( ST1 | ST2 | LW  | ST4,             SEND(KC_BSPC));

    // Mouse Keys
    P( LO  | LSD | LK,    CLICK_MOUSE(KC_MS_BTN2));
    P( LO  | LR  | LW,    CLICK_MOUSE(KC_MS_BTN1));

    // Thumb Chords
    P( LA  | LO  | RE  | RU,    SEND(KC_CAPS));
    P( LA  | RU,                SEND(KC_ESC));
    P( LO  | RE,                SEND(KC_LCTL));
    P( LNO | RNO | LA | RU,     SEND(KC_LCTL); SEND(KC_LSFT));
    P( LNO | LA  | RE,          SEND(KC_LCTL); SEND(KC_LSFT); SEND(KC_LALT));

    // Mods
    P( RT | RD   | RS | RZ,    SEND(KC_LGUI));
    P( RT | RD,                SEND(KC_LCTL));
    P( RS | RZ,                SEND(KC_LALT));
    P( LA | LNO,               SEND(KC_LCTL));
    P( LA | LO,                SEND(KC_LALT));
    P( LO,                     SEND(KC_LSFT));

    // Function Layer
    P( FUNCT | RF | RR,    SEND(KC_F5));
    P( FUNCT | RP | RB,    SEND(KC_F6));
    P( FUNCT | RL | RG,    SEND(KC_F7));
    P( FUNCT | RT | RS,    SEND(KC_F8));
    P( FUNCT | RF,         SEND(KC_F1));
    P( FUNCT | RP,         SEND(KC_F2));
    P( FUNCT | RL,         SEND(KC_F3));
    P( FUNCT | RT,         SEND(KC_F4));
    P( FUNCT | RR,         SEND(KC_F9));
    P( FUNCT | RG,         SEND(KC_F10));
    P( FUNCT | RB,         SEND(KC_F11));
    P( FUNCT | RS,         SEND(KC_F12));

    // Movement Layer
    P( MOVE | RF,     SEND(KC_LEFT));
    P( MOVE | RP,     SEND(KC_DOWN));
    P( MOVE | RL,     SEND(KC_UP));
    P( MOVE | RT,     SEND(KC_RIGHT));
    P( MOVE | ST3,    SEND(KC_PGUP));
    P( MOVE | ST4,    SEND(KC_PGDN));

    // Media Layer
    P( MEDIA | RF,    SEND(KC_MPRV));
    P( MEDIA | RP,    SEND(KC_MPLY));
    P( MEDIA | RL,    SEND(KC_MPLY));
    P( MEDIA | RT,    SEND(KC_MNXT));
    P( MEDIA | RD,    SEND(KC_VOLU));
    P( MEDIA | RZ,    SEND(KC_VOLD));
    P( MEDIA | RS,    SEND(KC_MUTE));

    // Number Row, Left
    P( LNO | LSU,    SEND(KC_1));
    P( LNO | LFT,    SEND(KC_2));
    P( LNO | LP,     SEND(KC_3));
    P( LNO | LH,     SEND(KC_4));
    P( LNO | ST1,    SEND(KC_5));
    P( LNO | ST3,    SEND(KC_6));
    P( LNO | RF,     SEND(KC_7));
    P( LNO | RP,     SEND(KC_8));
    P( LNO | RL,     SEND(KC_9));
    P( LNO | RT,     SEND(KC_0));

    // Number Row, Right
    P( RNO | LSU,    SEND(KC_1));
    P( RNO | LFT,    SEND(KC_2));
    P( RNO | LP,     SEND(KC_3));
    P( RNO | LH,     SEND(KC_4));
    P( RNO | ST1,    SEND(KC_5));
    P( RNO | ST3,    SEND(KC_6));
    P( RNO | RF,     SEND(KC_7));
    P( RNO | RP,     SEND(KC_8));
    P( RNO | RL,     SEND(KC_9));
    P( RNO | RT,     SEND(KC_0));
    P( RNO | LA,     SEND(KC_5));

    // Specials
    P( RU | RNO,    SEND(KC_TAB));
    P( RE | RU,     SEND(KC_BSPC));
    P( RD | RZ,     SEND(KC_ENT));
    P( RE,          SEND(KC_ENT));
    P( RD,          SEND(KC_BSPC));
    P( LNO,         SEND(KC_BSPC));
    P( RNO,         SEND(KC_BSPC));
    P( LA,          SEND(KC_SPC));
    P( RU,          SEND(KC_SPC));
    P( RZ,          SEND(KC_ESC));

    // Symbols and Numbers
 	P( PWR | RE | RU,      SEND(KC_ENT));
    P( PWR | LA | LO,      SEND(KC_SPC));
    P( PWR | LP | LW,      SEND(KC_LSFT); SEND(KC_9));       // (
    P( PWR | LH | LR,      SEND(KC_LSFT); SEND(KC_0));       // )
    P( PWR | ST1 | ST2,    SEND(KC_GRV));                    // `
    P( PWR | RD | RZ,      SEND(KC_ESC));
    P( PWR | LSU | LSD,    SEND(KC_LSFT); SEND(KC_3));       // #
    P( PWR | LFT | LK,     SEND(KC_LSFT); SEND(KC_4));       // $
    P( PWR | LSU,          SEND(KC_LSFT); SEND(KC_1));       // !
    P( PWR | LSD,          SEND(KC_LSFT); SEND(KC_5));       // %
    P( PWR | LFT,          SEND(KC_LSFT); SEND(KC_2));       // @
    P( PWR | LK,           SEND(KC_LSFT); SEND(KC_6));       // ^
    P( PWR | LP,           SEND(KC_LSFT); SEND(KC_LBRC));    // {
    P( PWR | LW,           SEND(KC_LBRC));
    P( PWR | LH,           SEND(KC_LSFT); SEND(KC_RBRC));    // }
    P( PWR | LR,           SEND(KC_RBRC));
    P( PWR | ST1,          SEND(KC_LSFT); SEND(KC_BSLS));    // |
    P( PWR | ST2,          SEND(KC_LSFT); SEND(KC_GRV));     // ~
    P( PWR | ST3,          SEND(KC_QUOT));
    P( PWR | ST4,          SEND(KC_LSFT); SEND(KC_QUOT));    // "
    P( PWR | RF,           SEND(KC_KP_PLUS));
    P( PWR | RR,           SEND(KC_LSFT); SEND(KC_7));       // &
    P( PWR | RP,           SEND(KC_MINS));
    P( PWR | RB,           SEND(KC_EQL));
    P( PWR | RL,           SEND(KC_SLSH));
    P( PWR | RG,           SEND(KC_COMM));
    P( PWR | RT,           SEND(KC_PAST));
    P( PWR | RS,           SEND(KC_DOT));
    P( PWR | RD,           SEND(KC_TAB));
    P( PWR | LA,           SEND(KC_LSFT));
    P( PWR | LO,           SEND(KC_SLSH));
    P( PWR | RE,           SEND(KC_SCLN));
    P( PWR | RU,           SEND(KC_BSLS));
    P( PWR | LNO,          SEND(KC_BSLS));
    P( PWR | RF | RR,      SEND(KC_LEFT));
    P( PWR | RP | RB,      SEND(KC_DOWN));
    P( PWR | RL | RG,      SEND(KC_UP));
    P( PWR | RT | RS,      SEND(KC_RIGHT));

    // Letters
    P( LSU | LSD,    SEND(KC_A));
    P( LFT | LK,     SEND(KC_S));
    P( LP  | LW,     SEND(KC_D));
    P( LH  | LR,     SEND(KC_F));
    P( ST1 | ST2,    SEND(KC_G));
    P( ST3 | ST4,    SEND(KC_H));
    P( RF  | RR,     SEND(KC_J));
    P( RT  | RS,     SEND(KC_SCLN));
    P( RG  | RL,     SEND(KC_L));
    P( RP  | RB,     SEND(KC_K));
    P( LSU,          SEND(KC_Q));
    P( LSD,          SEND(KC_Z));
    P( LFT,          SEND(KC_W));
    P( LK,           SEND(KC_X));
    P( LP,           SEND(KC_E));
    P( LW,           SEND(KC_C));
    P( LH,           SEND(KC_R));
    P( LR,           SEND(KC_V));
    P( ST1,          SEND(KC_T));
    P( ST2,          SEND(KC_B));
    P( ST3,          SEND(KC_Y));
    P( ST4,          SEND(KC_N));
    P( RF,           SEND(KC_U));
    P( RR,           SEND(KC_M));
    P( RP,           SEND(KC_I));
    P( RB,           SEND(KC_COMM));
    P( RL,           SEND(KC_O));
    P( RG,           SEND(KC_DOT));
    P( RT,           SEND(KC_P));
    P( RS,           SEND(KC_SLSH));
    P( RNO,          SEND(KC_BSPC));
    P( LNO,          SEND(KC_BSPC));

    return 0;
}

enum custom_keycodes {
  DASH = SAFE_RANGE,
  DASH_BACKWARD,
  DASH_FORWARD,
  DASH_LEFT,
  DASH_RIGHT
};

// Combos
enum combos {
  ASI_ESCAPE,
  GOTO_STENO_LAYER,
  GZDOOM_TYPIST_CLEAR_ALL,
  GZDOOM_TYPIST_DASH,
  GZDOOM_TYPIST_DASH_BACKWARD,
  GZDOOM_TYPIST_DASH_FORWARD,
  GZDOOM_TYPIST_DASH_LEFT,
  GZDOOM_TYPIST_DASH_RIGHT,
  GZDOOM_TYPIST_FORCE_COMBAT,
  GZDOOM_TYPIST_FORCE_EXPLORATION,
  GZDOOM_TYPIST_RETURN_TO_AUTO_MODE
};

// NOTE: This combo is meant to mirror the chord used to switch to the gaming
// layer in `sten.c`.

// Mimics "SK-P": "{:CMT:eSCaPe (⎋)}{:KEY_COMBO:ESCAPE}{MODE:RESET}"
const uint16_t PROGMEM asi_escape_combo[] = {
    KC_A, KC_S, KC_I, COMBO_END
};
const uint16_t PROGMEM goto_steno_layer_combo[] = {
    KC_LEFT_CTRL, KC_H, COMBO_END
};
// Mimics "KHRAUL": "{:CMT: CLear ALL}{:KEY_COMBO:CONTROL_L(BACKSPACE)}"
const uint16_t PROGMEM gzdoom_typist_clear_all_combo[] = {
    KC_S, KC_R, KC_F, KC_BACKSPACE, KC_SPACE, KC_O, COMBO_END
};
const uint16_t PROGMEM gzdoom_typist_dash_combo[] = {
    KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mimics "W-RBGS": "{:CMT:dash backward}{:ATTACH:/db}{:KEY_COMBO:RETURN}"
const uint16_t PROGMEM gzdoom_typist_dash_backward_combo[] = {
    KC_D, KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mimics "P-RBGS": "{:CMT:dash forward}{:ATTACH:/df}{:KEY_COMBO:RETURN}"
const uint16_t PROGMEM gzdoom_typist_dash_forward_combo[] = {
    KC_E, KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mimics "K-RBGS": "{:CMT:dash left}{:ATTACH:/dl}{:KEY_COMBO:RETURN}"
const uint16_t PROGMEM gzdoom_typist_dash_left_combo[] = {
    KC_S, KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mimics "R-RBGS": "{:CMT:dash right}{:ATTACH:/dr}{:KEY_COMBO:RETURN}"
const uint16_t PROGMEM gzdoom_typist_dash_right_combo[] = {
    KC_F, KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mimics "KPWA*T": "{:CMT:force COMBAT}{:KEY_COMBO:GRAVE}",
const uint16_t PROGMEM gzdoom_typist_force_combat_combo[] = {
    KC_S, KC_E, KC_D, KC_BACKSPACE, KC_H, KC_P, COMBO_END
};
// Mimics "SPHRO*R": "{:CMT:force EXPLORE}{:KEY_COMBO:ESCAPE}"
const uint16_t PROGMEM gzdoom_typist_force_exploration_combo[] = {
    KC_A, KC_E, KC_R, KC_F, KC_DELETE, KC_H, KC_J, COMBO_END
};
// Mimics "A*UPL": "{:CMT:return to AUto Mode}{:KEY_COMBO:CONTROL_L}"
const uint16_t PROGMEM gzdoom_typist_return_to_auto_mode_combo[] = {
    KC_BACKSPACE, KC_H, KC_SPACE, KC_I, KC_O, COMBO_END
};

combo_t key_combos[COMBO_COUNT] = {
    [ASI_ESCAPE] = COMBO(asi_escape_combo, KC_ESCAPE),
    [GOTO_STENO_LAYER] = COMBO(goto_steno_layer_combo, TO(STENO_LAYER)),
    [GZDOOM_TYPIST_CLEAR_ALL] = COMBO(gzdoom_typist_clear_all_combo, LCTL(KC_BACKSPACE)),
    [GZDOOM_TYPIST_DASH] = COMBO(gzdoom_typist_dash_combo, DASH),
    [GZDOOM_TYPIST_DASH_BACKWARD] = COMBO(gzdoom_typist_dash_backward_combo, DASH_BACKWARD),
    [GZDOOM_TYPIST_DASH_FORWARD] = COMBO(gzdoom_typist_dash_forward_combo, DASH_FORWARD),
    [GZDOOM_TYPIST_DASH_LEFT] = COMBO(gzdoom_typist_dash_left_combo, DASH_LEFT),
    [GZDOOM_TYPIST_DASH_RIGHT] = COMBO(gzdoom_typist_dash_right_combo, DASH_RIGHT),
    // NOTE: Key customisable on the GZDoom UI as "Force Combat Mode".
    [GZDOOM_TYPIST_FORCE_COMBAT] = COMBO(gzdoom_typist_force_combat_combo, KC_GRAVE),
    [GZDOOM_TYPIST_FORCE_EXPLORATION] = COMBO(gzdoom_typist_force_exploration_combo, KC_ESCAPE),
    // NOTE: Key customisable on the GZDoom UI as "Unlock Game Mode".
    [GZDOOM_TYPIST_RETURN_TO_AUTO_MODE] = COMBO(gzdoom_typist_return_to_auto_mode_combo, KC_LEFT_CTRL)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool dashing;

    switch (keycode) {
    case DASH:
        if (record->event.pressed) {
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_BACKWARD:
        if (record->event.pressed) {
            SEND_STRING("/db" SS_TAP(X_ENTER));
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_FORWARD:
        if (record->event.pressed) {
            SEND_STRING("/df" SS_TAP(X_ENTER));
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_LEFT:
        if (record->event.pressed) {
            SEND_STRING("/dl" SS_TAP(X_ENTER));
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_RIGHT:
        if (record->event.pressed) {
            SEND_STRING("/dr" SS_TAP(X_ENTER));
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case KC_D:
        if (record->event.pressed && dashing) {
            SEND_STRING("/db" SS_TAP(X_ENTER));
            return false;
        }
    case KC_E:
        if (record->event.pressed && dashing) {
            SEND_STRING("/df" SS_TAP(X_ENTER));
            return false;
        }
    case KC_S:
        if (record->event.pressed && dashing) {
            SEND_STRING("/dl" SS_TAP(X_ENTER));
            return false;
        }
    case KC_F:
        if (record->event.pressed && dashing) {
            SEND_STRING("/dr" SS_TAP(X_ENTER));
            return false;
        }
    }
    return true;
};

// "Layers"
// Steno layer should be first in your map.
// When PWR | FN | ST3 | ST4 is pressed, the layer is increased to the next map. You must return to STENO_LAYER at the end.
// If you need more space for chords, remove the two gaming layers.
// Note: If using NO_ACTION_TAPPING, LT will not work!

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Main layer, everything goes through here
    [STENO_LAYER] = LAYOUT_georgi(
        STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,       STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        STN_PWR, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,       STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                   STN_N1,  STN_A,   STN_O,         STN_E,   STN_U,   STN_N7
    ),
    // Gaming layer with Numpad, Very limited
    [GAMING] = LAYOUT_georgi(
        KC_GRAVE,     KC_Q, KC_W, KC_E,                          KC_R,         KC_T,      /* | */ KC_Y,     KC_U,     KC_I,                          KC_O, KC_P,         KC_ESCAPE,
        KC_LEFT_CTRL, KC_A, KC_S, KC_D,                          KC_F,         KC_G,      /* | */ KC_H,     KC_J,     KC_K,                          KC_L, KC_SEMICOLON, KC_QUOTE,
                                  LT(GAMING_2, KC_LEFT_BRACKET), KC_BACKSPACE, KC_DELETE, /* | */ KC_ENTER, KC_SPACE, LT(GAMING_2, KC_RIGHT_BRACKET)
    ),

    [GAMING_2] = LAYOUT_georgi(
        KC_GRAVE, KC_1, KC_2, KC_3,                KC_4, KC_BACKSLASH, /* | */ KC_6,     KC_7,     KC_8,                KC_9,   KC_MINUS,    TO(STENO_LAYER),
        KC_TAB,   KC_Z, KC_X, KC_C,                KC_V, KC_B,         /* | */ KC_N,     KC_M,     KC_COMMA,            KC_DOT, KC_QUESTION, KC_DOUBLE_QUOTE,
                              KC_LEFT_CURLY_BRACE, KC_5, KC_0,         /* | */ KC_ENTER, KC_SPACE, KC_RIGHT_CURLY_BRACE
    )
};

// Don't fuck with this, thanks.
size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
