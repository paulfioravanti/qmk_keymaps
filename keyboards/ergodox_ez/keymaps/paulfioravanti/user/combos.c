// Combos for chorded QWERTY
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
// https://docs.qmk.fm/#/feature_combo?id=combos
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
