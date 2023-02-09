// HID Commands
enum hid_responses {
  TOGGLE_DOOM_TYPIST_MODE = 0x1,
  TOGGLE_GAMING = 0x2,
  SWITCH_TO_GAMING = 0x3,
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
        if (biton32(layer_state) == GAMING) {
          // Doom Typist (Ctrl-Backspace):
          // Erase any text that may have been entered inadvertently just
          // before steno mode is selected.
          SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_BACKSPACE) SS_UP(X_LCTRL));
          layer_off(GAMING);
          data[1] = SWITCH_TO_STENO;
        } else {
          layer_on(GAMING);
          data[1] = SWITCH_TO_GAMING;
        }
        break;
      case TOGGLE_GAMING:
        if (biton32(layer_state) == GAMING) {
          layer_off(GAMING);
          data[1] = SWITCH_TO_STENO;
        } else {
          layer_on(GAMING);
          data[1] = SWITCH_TO_GAMING;
        }
        break;
      case SWITCH_TO_GAMING:
        layer_on(GAMING);
        data[1] = SWITCH_TO_GAMING;
        break;
      case SWITCH_TO_STENO:
        layer_off(GAMING);
        data[1] = SWITCH_TO_STENO;
        break;
      default:
        data[1] = NO_ACTION_TAKEN;
        break;
    }
    raw_hid_send(data, length);
};
