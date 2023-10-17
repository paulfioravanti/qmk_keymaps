// HID Commands
enum hid_responses {
  TOGGLE_DOOM_TYPIST_MODE = 0x1,
  TOGGLE_QWERTY = 0x2,
  SWITCH_TO_QWERTY = 0x3,
  SWITCH_TO_STENO = 0x4,
  NO_ACTION_TAKEN = 0x9
};

// USB Human Interface Device (HID) communication
// REF: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rawhid.md
// REF: https://docs.qmk.fm/#/feature_rawhid
void raw_hid_receive(uint8_t *data, uint8_t length) {
    // data is the packet received from host.
    // We only care about the integer values in the first array element.
    switch (data[0]) {
      case TOGGLE_DOOM_TYPIST_MODE:
        if (biton32(layer_state) == QWERTY) {
          layer_off(QWERTY);
          data[1] = SWITCH_TO_STENO;
          // Doom Typist (Ctrl-Backspace):
          // Erase any text that may have been entered inadvertently just
          // before steno mode is selected.
          SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_BACKSPACE) SS_UP(X_LCTRL));
        } else {
          layer_on(QWERTY);
          data[1] = SWITCH_TO_QWERTY;
        }
        break;
      case TOGGLE_QWERTY:
        if (biton32(layer_state) == QWERTY) {
          layer_off(QWERTY);
          data[1] = SWITCH_TO_QWERTY;
        } else {
          layer_on(QWERTY);
          data[1] = SWITCH_TO_QWERTY;
        }
        break;
      case SWITCH_TO_QWERTY:
        layer_on(QWERTY);
        data[1] = SWITCH_TO_QWERTY;
        break;
      case SWITCH_TO_STENO:
        layer_off(QWERTY);
        data[1] = SWITCH_TO_STENO;
        break;
      default:
        data[1] = NO_ACTION_TAKEN;
        break;
    }
    raw_hid_send(data, length);
};
