// Combos
// REF: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
// REF: https://docs.qmk.fm/#/feature_combo?id=combos
enum combos {
  ASI_ESCAPE,
  FJ_ENTER,
  GOTO_STENO_LAYER,
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

// Mirrors "SK-P": "{:KEY_COMBO:ESCAPE}{MODE:RESET}"
const uint16_t PROGMEM asi_escape_combo[] = {
    KC_A, KC_S, KC_I, COMBO_END
};
// Mirrors "R-R" chord for Enter/Return
const uint16_t PROGMEM fj_enter_combo[] = {
    KC_F, KC_J, COMBO_END
};
// Mirrors the (PWR | ST4) chord used to switch to the gaming layer in `sten.c`.
const uint16_t PROGMEM goto_steno_layer_combo[] = {
    KC_LEFT_CTRL, KC_H, COMBO_END
};
// Mirrors "KHRAUL": "{:KEY_COMBO:CONTROL_L(BACKSPACE)}"
const uint16_t PROGMEM doom_typist_clear_all_combo[] = {
    KC_S, KC_R, KC_F, KC_BACKSPACE, KC_SPACE, KC_O, COMBO_END
};
const uint16_t PROGMEM doom_typist_dash_combo[] = {
    KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mirrors "W-RBGS": "{:ATTACH:/db}{:KEY_COMBO:RETURN}"
const uint16_t PROGMEM doom_typist_dash_backward_combo[] = {
    KC_D, KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mirrors "P-RBGS": "{:ATTACH:/df}{:KEY_COMBO:RETURN}"
const uint16_t PROGMEM doom_typist_dash_forward_combo[] = {
    KC_E, KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mirrors "K-RBGS": "{:ATTACH:/dl}{:KEY_COMBO:RETURN}"
const uint16_t PROGMEM doom_typist_dash_left_combo[] = {
    KC_S, KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mirrors "R-RBGS": "{:ATTACH:/dr}{:KEY_COMBO:RETURN}"
const uint16_t PROGMEM doom_typist_dash_right_combo[] = {
    KC_F, KC_J, KC_K, KC_L, KC_SEMICOLON, COMBO_END
};
// Mirrors "KPWA*T": "{:KEY_COMBO:GRAVE}",
const uint16_t PROGMEM doom_typist_force_combat_combo[] = {
    KC_S, KC_E, KC_D, KC_BACKSPACE, KC_H, KC_P, COMBO_END
};
// Mirrors "SPHRO*R": "{:KEY_COMBO:ESCAPE}"
const uint16_t PROGMEM doom_typist_force_exploration_combo[] = {
    KC_A, KC_E, KC_R, KC_F, KC_DELETE, KC_H, KC_J, COMBO_END
};
// Mirrors "A*UPL": "{:KEY_COMBO:CONTROL_L}"
const uint16_t PROGMEM doom_typist_return_to_auto_mode_combo[] = {
    KC_BACKSPACE, KC_H, KC_SPACE, KC_I, KC_O, COMBO_END
};
const uint16_t PROGMEM doom_typist_toggle_run_combo[] = {
    KC_U, KC_I, KC_O, KC_P, COMBO_END
};
const uint16_t PROGMEM steno_a_combo[] = {
    KC_BACKSPACE, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_b_combo[] = {
    KC_E, KC_D, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_c_combo[] = {
    KC_S, KC_F, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_d_combo[] = {
    KC_W, KC_S, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_e_combo[] = {
    KC_G, KC_ENTER, COMBO_END
};
const uint16_t PROGMEM steno_e_left_combo[] = {
    KC_A, KC_S, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_f_combo[] = {
    KC_W, KC_E, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_g_combo[] = {
    KC_W, KC_S, KC_E, KC_D, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_h_combo[] = {
    KC_R, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_i_combo[] = {
    KC_G, KC_ENTER, KC_SPACE, COMBO_END
};
const uint16_t PROGMEM steno_i_left_combo[] = {
    KC_A, KC_S, KC_D, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_j_combo[] = {
    KC_A, KC_S, KC_D, KC_F, KC_H, COMBO_END
};
// NOTE: KC_QUOTE/Z needed so that strafing left and turning left can be done
// at the same time
const uint16_t PROGMEM steno_k_combo[] = {
    KC_S, KC_H, KC_QUOTE, COMBO_END
};
const uint16_t PROGMEM steno_l_combo[] = {
    KC_R, KC_F, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_m_combo[] = {
    KC_E, KC_R, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_minus_combo[] = {
    KC_R, KC_I, KC_K, COMBO_END
};
const uint16_t PROGMEM steno_n_combo[] = {
    KC_W, KC_E, KC_R, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_o_combo[] = {
    KC_DELETE, KC_H, COMBO_END
};
// NOTE: KC_QUOTE/-Z needed so that moving forward and turning left can be done
// at the same time
const uint16_t PROGMEM steno_p_combo[] = {
    KC_E, KC_H, KC_QUOTE, COMBO_END
};
const uint16_t PROGMEM steno_plus_combo[] = {
    KC_E, KC_R, KC_F, KC_H, KC_SPACE, KC_SEMICOLON, COMBO_END
};
const uint16_t PROGMEM steno_q_combo[] = {
    KC_S, KC_D, KC_H, COMBO_END
};
// NOTE: KC_QUOTE/-Z needed so that strafing right and turning left can be done
// at the same time
const uint16_t PROGMEM steno_r_combo[] = {
    KC_F, KC_H, KC_QUOTE, COMBO_END
};
const uint16_t PROGMEM steno_s_combo[] = {
    KC_A, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_t_combo[] = {
    KC_W, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_u_combo[] = {
    KC_G, KC_SPACE, COMBO_END
};
const uint16_t PROGMEM steno_u_left_combo[] = {
    KC_D, KC_F, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_v_combo[] = {
    KC_A, KC_F, KC_H, COMBO_END
};
// NOTE: KC_QUOTE/-Z needed so that moving backward and turning left can be done
// at the same time
const uint16_t PROGMEM steno_w_combo[] = {
    KC_D, KC_H, KC_QUOTE, COMBO_END
};
const uint16_t PROGMEM steno_x_combo[] = {
    KC_S, KC_E, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_y_combo[] = {
    KC_S, KC_D, KC_F, KC_H, COMBO_END
};
const uint16_t PROGMEM steno_z_combo[] = {
    KC_A, KC_W, KC_S, KC_E, KC_D, KC_H, COMBO_END
};

combo_t key_combos[COMBO_COUNT] = {
    [ASI_ESCAPE] = COMBO(asi_escape_combo, KC_ESCAPE),
    [FJ_ENTER] = COMBO(fj_enter_combo, KC_ENTER),
    [GOTO_STENO_LAYER] = COMBO(goto_steno_layer_combo, TO(STENO_LAYER)),
    [DOOM_TYPIST_CLEAR_ALL] = COMBO(doom_typist_clear_all_combo, LCTL(KC_BACKSPACE)),
    [DOOM_TYPIST_DASH] = COMBO(doom_typist_dash_combo, DASH),
    [DOOM_TYPIST_DASH_BACKWARD] = COMBO(doom_typist_dash_backward_combo, DASH_BACKWARD),
    [DOOM_TYPIST_DASH_FORWARD] = COMBO(doom_typist_dash_forward_combo, DASH_FORWARD),
    [DOOM_TYPIST_DASH_LEFT] = COMBO(doom_typist_dash_left_combo, DASH_LEFT),
    [DOOM_TYPIST_DASH_RIGHT] = COMBO(doom_typist_dash_right_combo, DASH_RIGHT),
    // NOTE: Key customisable on the doom UI as "Force Combat Mode".
    [DOOM_TYPIST_FORCE_COMBAT] = COMBO(doom_typist_force_combat_combo, KC_GRAVE),
    [DOOM_TYPIST_FORCE_EXPLORATION] = COMBO(doom_typist_force_exploration_combo, KC_ESCAPE),
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
