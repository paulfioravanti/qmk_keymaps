// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
// Default all Ergodox EZ right-hand-side lights to be off.
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
  // NOTE: "GeminiPR" is a stenography protocol that I've chosen to use when
  // communicating with Plover. The other option was "TX Bolt".
  // Although QMK says TX Bolt is the "default" protocol, it is an older
  // protocol than GeminiPR.
  // More information in the QMK docs:
  // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_stenography.md#plover-with-steno-protocol
  steno_set_mode(STENO_MODE_GEMINI);
};
