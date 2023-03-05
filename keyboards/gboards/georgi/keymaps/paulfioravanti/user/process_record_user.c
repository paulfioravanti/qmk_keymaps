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
            // Mirrors "W-RBGS": "{:ATTACH:/db}{:KEY_COMBO:RETURN}"
            SEND_STRING(
              SS_DOWN(X_LCTRL)
              SS_TAP(X_BACKSPACE)
              SS_UP(X_LCTRL)
              "/db"
              SS_TAP(X_ENTER)
            );
            // Log Dash Backward using Alfred workflow
            SEND_STRING(
              SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI)
              SS_TAP(X_W)
              SS_UP(X_LCTRL) SS_UP(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LGUI)
            );
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_FORWARD:
        if (record->event.pressed) {
            // Mirrors "P-RBGS": "{:ATTACH:/df}{:KEY_COMBO:RETURN}"
            SEND_STRING(
              SS_DOWN(X_LCTRL)
              SS_TAP(X_BACKSPACE)
              SS_UP(X_LCTRL)
              "/df"
              SS_TAP(X_ENTER)
            );
            // Log Dash Forward using Alfred workflow
            SEND_STRING(
              SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI)
              SS_TAP(X_P)
              SS_UP(X_LCTRL) SS_UP(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LGUI)
            );
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_LEFT:
        if (record->event.pressed) {
            // Mirrors "K-RBGS": "{:ATTACH:/dl}{:KEY_COMBO:RETURN}"
            SEND_STRING(
              SS_DOWN(X_LCTRL)
              SS_TAP(X_BACKSPACE)
              SS_UP(X_LCTRL)
              "/dl"
              SS_TAP(X_ENTER)
            );
            // Log Dash Left using Alfred workflow
            SEND_STRING(
              SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI)
              SS_TAP(X_K)
              SS_UP(X_LCTRL) SS_UP(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LGUI)
            );
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case DASH_RIGHT:
        if (record->event.pressed) {
            // Mirrors "R-RBGS": "{:ATTACH:/dr}{:KEY_COMBO:RETURN}"
            SEND_STRING(
              SS_DOWN(X_LCTRL)
              SS_TAP(X_BACKSPACE)
              SS_UP(X_LCTRL)
              "/dr"
              SS_TAP(X_ENTER)
            );
            // Log Dash Right using Alfred workflow
            SEND_STRING(
              SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI)
              SS_TAP(X_R)
              SS_UP(X_LCTRL) SS_UP(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LGUI)
            );
            dashing = true;
        } else {
            dashing = false;
        }
        return false;
    case KC_D:
        if (record->event.pressed && dashing) {
            // Mirrors "W-RBGS": "{:ATTACH:/db}{:KEY_COMBO:RETURN}"
            SEND_STRING("/db" SS_TAP(X_ENTER));
            // Log Dash Backward using Alfred workflow
            SEND_STRING(
              SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI)
              SS_TAP(X_W)
              SS_UP(X_LCTRL) SS_UP(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LGUI)
            );
            return false;
        }
        return true;
    case KC_E:
        if (record->event.pressed && dashing) {
            // Mirrors "P-RBGS": "{:ATTACH:/df}{:KEY_COMBO:RETURN}"
            SEND_STRING("/df" SS_TAP(X_ENTER));
            // Log Dash Forward using Alfred workflow
            SEND_STRING(
              SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI)
              SS_TAP(X_P)
              SS_UP(X_LCTRL) SS_UP(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LGUI)
            );
            return false;
        }
        return true;
    case KC_F:
        if (record->event.pressed && dashing) {
            // Mirrors "R-RBGS": "{:ATTACH:/dr}{:KEY_COMBO:RETURN}"
            SEND_STRING("/dr" SS_TAP(X_ENTER));
            // Log Dash Right using Alfred workflow
            SEND_STRING(
              SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI)
              SS_TAP(X_R)
              SS_UP(X_LCTRL) SS_UP(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LGUI)
            );
            return false;
        }
        return true;
    case KC_S:
        if (record->event.pressed && dashing) {
            // Mirrors "K-RBGS": "{:ATTACH:/dl}{:KEY_COMBO:RETURN}"
            SEND_STRING("/dl" SS_TAP(X_ENTER));
            // Log Dash Left using Alfred workflow
            SEND_STRING(
              SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI)
              SS_TAP(X_K)
              SS_UP(X_LCTRL) SS_UP(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LGUI)
            );
            return false;
        }
        return true;
    case STENO_MODE:
        if (record->event.pressed) {
            layer_off(GAMING);
            // Log Steno Mode using Alfred workflow
            SEND_STRING(
              SS_DOWN(X_LCTRL) SS_DOWN(X_LALT) SS_DOWN(X_LSHIFT) SS_DOWN(X_LGUI)
              SS_TAP(X_S)
              SS_UP(X_LCTRL) SS_UP(X_LALT) SS_UP(X_LSHIFT) SS_UP(X_LGUI)
            );
            return false;
        }
        return true;
    }
    return true;
};
