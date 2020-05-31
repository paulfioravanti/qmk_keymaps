// Runs whenever there is a layer state change.
// NOTE: Not all cases here will get used, but there's probably no harm
// in keeping them here.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
    case 0:
      #ifdef RGBLIGHT_COLOR_LAYER_0
        rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
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
