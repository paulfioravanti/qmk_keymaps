// Combos
// REF: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
// REF: https://docs.qmk.fm/#/feature_combo?id=combos
enum combos {
  ASI_ESCAPE,
  FJ_ENTER,
  DOOM_TYPIST_CLEAR_ALL,
  DOOM_TYPIST_DASH,
  DOOM_TYPIST_DASH_BACKWARD,
  DOOM_TYPIST_DASH_FORWARD,
  DOOM_TYPIST_DASH_LEFT,
  DOOM_TYPIST_DASH_RIGHT,
  DOOM_TYPIST_FORCE_COMBAT,
  DOOM_TYPIST_FORCE_EXPLORATION,
  DOOM_TYPIST_RETURN_TO_AUTO_MODE,
  DOOM_TYPIST_TOGGLE_RUN,
  STENO_A,
  STENO_B,
  STENO_C,
  STENO_D,
  STENO_E,
  STENO_E_LEFT,
  STENO_F,
  STENO_G,
  STENO_H,
  STENO_I,
  STENO_I_LEFT,
  STENO_J,
  STENO_K,
  STENO_L,
  STENO_M,
  STENO_MINUS,
  STENO_N,
  STENO_O,
  STENO_P,
  STENO_PLUS,
  STENO_Q,
  STENO_R,
  STENO_S,
  STENO_T,
  STENO_U,
  STENO_U_LEFT,
  STENO_V,
  STENO_W,
  STENO_X,
  STENO_Y,
  STENO_Z
};

// NOTE: Gaming chords come from this steno dictionary:
// https://github.com/paulfioravanti/steno-dictionaries/blob/main/dictionaries/gaming.md

// Mirrors "SK-P": "{#ESCAPE}{MODE:RESET}"
const uint16_t PROGMEM asi_escape_combo[] = {
    KC_Z, KC_X, KC_K, COMBO_END
};
// Mirrors "R-R" chord for Enter/Return
const uint16_t PROGMEM fj_enter_combo[] = {
    KC_V, KC_M, COMBO_END
};
// Mirrors "KHRAUL": "{#CONTROL(BACKSPACE)}"
const uint16_t PROGMEM doom_typist_clear_all_combo[] = {
    KC_X, KC_F, KC_V, KC_BACKSPACE, KC_SPACE, KC_L, COMBO_END
};
// Mirrors "-RBGS" chord
const uint16_t PROGMEM doom_typist_dash_combo[] = {
    KC_M, KC_COMMA, KC_DOT, KC_SLASH, COMBO_END
};
// Mirrors "W-RBGS": "{#CONTROL(BACKSPACE)}{^/db}{#RETURN}"
const uint16_t PROGMEM doom_typist_dash_backward_combo[] = {
    KC_C, KC_M, KC_COMMA, KC_DOT, KC_SLASH, COMBO_END
};
// Mirrors "P-RBGS": "{#CONTROL(BACKSPACE)}{^/df}{#RETURN}"
const uint16_t PROGMEM doom_typist_dash_forward_combo[] = {
    KC_D, KC_M, KC_COMMA, KC_DOT, KC_SLASH, COMBO_END
};
// Mirrors "K-RBGS": "{#CONTROL(BACKSPACE)}{^/dl}{#RETURN}"
const uint16_t PROGMEM doom_typist_dash_left_combo[] = {
    KC_X, KC_M, KC_COMMA, KC_DOT, KC_SLASH, COMBO_END
};
// Mirrors "R-RBGS": "{#CONTROL(BACKSPACE)}{^/dr}{#RETURN}"
const uint16_t PROGMEM doom_typist_dash_right_combo[] = {
    KC_V, KC_M, KC_COMMA, KC_DOT, KC_SLASH, COMBO_END
};
// Mirrors "KPWA*T": "{#COMMA}",
const uint16_t PROGMEM doom_typist_force_combat_combo[] = {
    KC_X, KC_D, KC_C, KC_BACKSPACE, KC_N, KC_SEMICOLON, COMBO_END
};
// Mirrors "SPHRO*R": "{#GRAVE}"
const uint16_t PROGMEM doom_typist_force_exploration_combo[] = {
    KC_Z, KC_D, KC_F, KC_V, KC_DELETE, KC_N, KC_M, COMBO_END
};
// Mirrors "A*UPLD": "{#CONTROL}"
const uint16_t PROGMEM doom_typist_return_to_auto_mode_combo[] = {
    KC_BACKSPACE, KC_N, KC_SPACE, KC_K, KC_L, KC_QUOTE, COMBO_END
};
// Mirrors "R*UPB": "{#TAB}"
const uint16_t PROGMEM doom_typist_toggle_run_combo[] = {
    KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
const uint16_t PROGMEM steno_a_combo[] = {
    KC_BACKSPACE, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_b_combo[] = {
    KC_D, KC_C, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_c_combo[] = {
    KC_X, KC_V, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_d_combo[] = {
    KC_S, KC_X, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_e_combo[] = {
    KC_B, KC_ENTER, COMBO_END
};
const uint16_t PROGMEM steno_e_left_combo[] = {
    KC_Z, KC_X, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_f_combo[] = {
    KC_S, KC_D, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_g_combo[] = {
    KC_S, KC_X, KC_D, KC_C, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_h_combo[] = {
    KC_F, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_i_combo[] = {
    KC_B, KC_ENTER, KC_SPACE, COMBO_END
};
const uint16_t PROGMEM steno_i_left_combo[] = {
    KC_Z, KC_X, KC_C, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_j_combo[] = {
    KC_Z, KC_X, KC_C, KC_V, KC_N, COMBO_END
};
// NOTE: KC_SLASH/-S needed so that strafing left and turning left can be done
// at the same time
const uint16_t PROGMEM steno_k_combo[] = {
    KC_X, KC_N, KC_SLASH, COMBO_END
};
const uint16_t PROGMEM steno_l_combo[] = {
    KC_F, KC_V, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_m_combo[] = {
    KC_D, KC_F, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_minus_combo[] = {
    KC_F, KC_K, KC_COMMA, COMBO_END
};
const uint16_t PROGMEM steno_n_combo[] = {
    KC_S, KC_D, KC_F, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_o_combo[] = {
    KC_DELETE, KC_N, COMBO_END
};
// NOTE: KC_SLASH (steno -S) needed so that moving forward and turning left can
// be done at the same time in Doom Typist
const uint16_t PROGMEM steno_p_combo[] = {
    KC_D, KC_N, KC_SLASH, COMBO_END
};
const uint16_t PROGMEM steno_plus_combo[] = {
    KC_D, KC_F, KC_V, KC_N, KC_SPACE, KC_SLASH, COMBO_END
};
const uint16_t PROGMEM steno_q_combo[] = {
    KC_X, KC_C, KC_N, COMBO_END
};
// NOTE: KC_SLASH (steno -S) needed so that strafing right and turning left can
// be done at the same time in Doom Typist
const uint16_t PROGMEM steno_r_combo[] = {
    KC_V, KC_N, KC_SLASH, COMBO_END
};
const uint16_t PROGMEM steno_s_combo[] = {
    KC_Z, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_t_combo[] = {
    KC_S, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_u_combo[] = {
    KC_B, KC_SPACE, COMBO_END
};
const uint16_t PROGMEM steno_u_left_combo[] = {
    KC_C, KC_V, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_v_combo[] = {
    KC_Z, KC_V, KC_N, COMBO_END
};
// NOTE: KC_SLASH/-S needed so that moving backward and turning left can be done
// at the same time
const uint16_t PROGMEM steno_w_combo[] = {
    KC_C, KC_N, KC_SLASH, COMBO_END
};
const uint16_t PROGMEM steno_x_combo[] = {
    KC_X, KC_D, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_y_combo[] = {
    KC_X, KC_C, KC_V, KC_N, COMBO_END
};
const uint16_t PROGMEM steno_z_combo[] = {
    KC_Z, KC_S, KC_X, KC_D, KC_C, KC_N, COMBO_END
};

combo_t key_combos[COMBO_COUNT] = {
    [ASI_ESCAPE] = COMBO(asi_escape_combo, KC_ESCAPE),
    [FJ_ENTER] = COMBO(fj_enter_combo, KC_ENTER),
    [DOOM_TYPIST_CLEAR_ALL] = COMBO(doom_typist_clear_all_combo, LCTL(KC_BACKSPACE)),
    [DOOM_TYPIST_DASH] = COMBO(doom_typist_dash_combo, DASH),
    [DOOM_TYPIST_DASH_BACKWARD] = COMBO(doom_typist_dash_backward_combo, DASH_BACKWARD),
    [DOOM_TYPIST_DASH_FORWARD] = COMBO(doom_typist_dash_forward_combo, DASH_FORWARD),
    [DOOM_TYPIST_DASH_LEFT] = COMBO(doom_typist_dash_left_combo, DASH_LEFT),
    [DOOM_TYPIST_DASH_RIGHT] = COMBO(doom_typist_dash_right_combo, DASH_RIGHT),
    // NOTE: Key customisable on the doom UI as "Force Combat Mode".
    [DOOM_TYPIST_FORCE_COMBAT] = COMBO(doom_typist_force_combat_combo, KC_COMMA),
    [DOOM_TYPIST_FORCE_EXPLORATION] = COMBO(doom_typist_force_exploration_combo, KC_GRAVE),
    // NOTE: Key customisable on the doom UI as "Unlock Game Mode".
    [DOOM_TYPIST_RETURN_TO_AUTO_MODE] = COMBO(doom_typist_return_to_auto_mode_combo, KC_LEFT_CTRL),
    [DOOM_TYPIST_TOGGLE_RUN] = COMBO(doom_typist_toggle_run_combo, KC_TAB),
    [STENO_A] = COMBO(steno_a_combo, KC_A),
    [STENO_B] = COMBO(steno_b_combo, KC_B),
    [STENO_C] = COMBO(steno_c_combo, KC_C),
    [STENO_D] = COMBO(steno_d_combo, KC_D),
    [STENO_E] = COMBO(steno_e_combo, KC_E),
    [STENO_E_LEFT] = COMBO(steno_e_left_combo, KC_E),
    [STENO_F] = COMBO(steno_f_combo, KC_F),
    [STENO_G] = COMBO(steno_g_combo, KC_G),
    [STENO_H] = COMBO(steno_h_combo, KC_H),
    [STENO_I] = COMBO(steno_i_combo, KC_I),
    [STENO_I_LEFT] = COMBO(steno_i_left_combo, KC_I),
    [STENO_J] = COMBO(steno_j_combo, KC_J),
    [STENO_K] = COMBO(steno_k_combo, KC_K),
    [STENO_L] = COMBO(steno_l_combo, KC_L),
    [STENO_M] = COMBO(steno_m_combo, KC_M),
    [STENO_MINUS] = COMBO(steno_minus_combo, KC_MINUS),
    [STENO_N] = COMBO(steno_n_combo, KC_N),
    [STENO_O] = COMBO(steno_o_combo, KC_O),
    [STENO_P] = COMBO(steno_p_combo, KC_P),
    [STENO_PLUS] = COMBO(steno_plus_combo, KC_PLUS),
    [STENO_Q] = COMBO(steno_q_combo, KC_Q),
    [STENO_R] = COMBO(steno_r_combo, KC_R),
    [STENO_S] = COMBO(steno_s_combo, KC_S),
    [STENO_T] = COMBO(steno_t_combo, KC_T),
    [STENO_U] = COMBO(steno_u_combo, KC_U),
    [STENO_U_LEFT] = COMBO(steno_u_left_combo, KC_U),
    [STENO_V] = COMBO(steno_v_combo, KC_V),
    [STENO_W] = COMBO(steno_w_combo, KC_W),
    [STENO_X] = COMBO(steno_x_combo, KC_X),
    [STENO_Y] = COMBO(steno_y_combo, KC_Y),
    [STENO_Z] = COMBO(steno_z_combo, KC_Z)
};
