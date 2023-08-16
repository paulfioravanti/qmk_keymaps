bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool dashing;

    // NOTE: Gaming chords come from this steno dictionary:
    // https://github.com/paulfioravanti/steno-dictionaries/blob/main/dictionaries/gaming.md
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
            // Mirrors "W-RBGS": "{#CONTROL(BACKSPACE)}{^/db}{#RETURN}"
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
            // Mirrors "P-RBGS": "{#CONTROL(BACKSPACE)}{^/df}{#RETURN}"
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
            // Mirrors "K-RBGS": "{#CONTROL(BACKSPACE)}{^/dl}{#RETURN}"
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
            // Mirrors "R-RBGS": "{#CONTROL(BACKSPACE)}{^/dr}{#RETURN}"
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
            // Mirrors "W-RBGS": "{#CONTROL(BACKSPACE)}{^/db}{#RETURN}"
            // (`dashing` means #CONTROL(BACKSPACE) has been pressed)
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
            // Mirrors "P-RBGS": "{#CONTROL(BACKSPACE)}{^/df}{#RETURN}"
            // (`dashing` means #CONTROL(BACKSPACE) has been pressed)
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
            // Mirrors "R-RBGS": "{#CONTROL(BACKSPACE)}{^/dr}{#RETURN}"
            // (`dashing` means #CONTROL(BACKSPACE) has been pressed)
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
            // Mirrors "K-RBGS": "{#CONTROL(BACKSPACE)}{^/dl}{#RETURN}"
            // (`dashing` means #CONTROL(BACKSPACE) has been pressed)
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
