bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool dashing;

    switch (keycode) {
    case DASH:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTRL) SS_TAP(X_BACKSPACE) SS_UP(X_LCTRL));
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_BACKWARD:
        if (record->event.pressed) {
            SEND_STRING(
              SS_DOWN(X_LCTRL)
              SS_TAP(X_BACKSPACE)
              SS_UP(X_LCTRL)
              "/db"
              SS_TAP(X_ENTER)
            );
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_FORWARD:
        if (record->event.pressed) {
            SEND_STRING(
              SS_DOWN(X_LCTRL)
              SS_TAP(X_BACKSPACE)
              SS_UP(X_LCTRL)
              "/df"
              SS_TAP(X_ENTER)
            );
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_LEFT:
        if (record->event.pressed) {
            SEND_STRING(
              SS_DOWN(X_LCTRL)
              SS_TAP(X_BACKSPACE)
              SS_UP(X_LCTRL)
              "/dl"
              SS_TAP(X_ENTER)
            );
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_RIGHT:
        if (record->event.pressed) {
            SEND_STRING(
              SS_DOWN(X_LCTRL)
              SS_TAP(X_BACKSPACE)
              SS_UP(X_LCTRL)
              "/dr"
              SS_TAP(X_ENTER)
            );
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
        return true;
    case KC_E:
        if (record->event.pressed && dashing) {
            SEND_STRING("/df" SS_TAP(X_ENTER));
            return false;
        }
        return true;
    case KC_F:
        if (record->event.pressed && dashing) {
            SEND_STRING("/dr" SS_TAP(X_ENTER));
            return false;
        }
        return true;
    case KC_S:
        if (record->event.pressed && dashing) {
            SEND_STRING("/dl" SS_TAP(X_ENTER));
            return false;
        }
        return true;
    }
    return true;
};
