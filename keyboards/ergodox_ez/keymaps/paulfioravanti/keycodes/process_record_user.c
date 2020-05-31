// NOTE: Sending Hex codes for Emojis involved needing to keep my
// input source permanently on "Unicode Hex Input", which doesn't
// seem to play well with Japanese IME, so Emojis will just have
// to stay as Slack-style strings for now.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
      case AND_AND:
        SEND_STRING("&&");
        return false;
      case AND_EQUALS:
        SEND_STRING("&&=");
        return false;
      case BACKWARD_PIPE:
        SEND_STRING("<|");
        return false;
      case COFFEE:
        // SEND_STRING(SS_LALT("2615"));
        SEND_STRING(":coffee:");
        return false;
      case DOUBLE_COLON:
        SEND_STRING("::");
        return false;
      case DOWN_ARROW:
        // SEND_STRING(SS_LALT("2B07"));
        SEND_STRING(":arrow_down:");
        return false;
      case DOWN_PANE:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_DOWN));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case ENG:
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_TAP(X_SCOLON));
        SEND_STRING(SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
        return false;
      case EQUALS_EQUALS:
        SEND_STRING("==");
        return false;
      case EXCLUSIVE_RANGE:
        SEND_STRING("...");
        return false;
      case FORWARD_PIPE:
        SEND_STRING("|>");
        return false;
      case HASH_ROCKET:
        SEND_STRING("=>");
        return false;
      case INCLUSIVE_RANGE:
        SEND_STRING("..");
        return false;
      case JPN:
        SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_TAP(X_J));
        SEND_STRING(SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
        return false;
      case LAUGH:
        // SEND_STRING(SS_LALT("D83D+DE02"));
        SEND_STRING(":joy:");
        return false;
      case LEFT_ERB:
        SEND_STRING("<%=");
        return false;
      case LEFT_PANE:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_LEFT));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case MATCH_OPERATOR:
        SEND_STRING("=~");
        return false;
      case MINUS_EQUALS:
        SEND_STRING("-=");
        return false;
      case MINUS_ONE:
        // SEND_STRING(SS_LALT("D83D+DC4E"));
        SEND_STRING(":-1:");
        return false;
      case MONOSNAP:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_5));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case NEUTRAL:
        // SEND_STRING(SS_LALT("D83D+DE10"));
        SEND_STRING(":neutral:");
        return false;
      case NOT_EQUALS:
        SEND_STRING("!=");
        return false;
      case OR_EQUALS:
        SEND_STRING("||=");
        return false;
      case OR_OR:
        SEND_STRING("||");
        return false;
      case PLUS_EQUALS:
        SEND_STRING("+=");
        return false;
      case PLUS_ONE:
        // SEND_STRING(SS_LALT("D83D+DC4D"));
        SEND_STRING(":+1:");
        return false;
      case RIGHT_ARROW:
        // SEND_STRING(SS_LALT("27A1"));
        SEND_STRING(":arrow_right:");
        return false;
      case RIGHT_ERB:
        SEND_STRING("%>");
        return false;
      case RIGHT_PANE:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_RIGHT));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case SAD:
        // SEND_STRING(SS_LALT("D83D+DE1E"));
        SEND_STRING(":disappointed:");
        return false;
      case SINGLE_ARROW:
        SEND_STRING("->");
        return false;
      case SMILE:
        // SEND_STRING(SS_LALT("D83D+DE04"));
        SEND_STRING(":smile:");
        return false;
      case SPERMY:
        SEND_STRING("~>");
        return false;
      case TROLL:
        SEND_STRING(":trollface:");
        return false;
      case UP_ARROW:
        // SEND_STRING(SS_LALT("2B06"));
        SEND_STRING(":arrow_up:");
        return false;
      case UP_PANE:
        SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI));
        SEND_STRING(SS_TAP(X_UP));
        SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LALT));
        return false;
      case WINK:
        // SEND_STRING(SS_LALT("D83D+DE09"));
        SEND_STRING(":wink:");
        return false;
    }
  }
  return true;
}
