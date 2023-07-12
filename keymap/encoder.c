#ifdef ENCODER_ENABLE

// TODO: choose actions for each layer
bool encoder_update_user(uint8_t index, bool clockwise) {
  uint16_t mod = 0;
  uint16_t code = 0;
  if (index == 0) {
    switch (biton32(layer_state)) {
      case L_MOVE:
        code = clockwise ? KC_PGUP : KC_PGDN;
        break; 
      case L_PROG:
        code = clockwise ? KC_VOLD : KC_VOLU;
        break;
      default:
        code = clockwise ? KC_UP : KC_DOWN;
        break;
    }
  } else if (index == 1) {
    switch (biton32(layer_state)) {
      case L_MOVE:
        mod = KC_LCTRL;
        code = clockwise ? KC_LEFT : KC_RIGHT;
        break;
      case L_PROG:
        code = clockwise ? KC_MEDIA_NEXT_TRACK : KC_MEDIA_PREV_TRACK;
        break;
      default:
        code = clockwise ? KC_LEFT : KC_RIGHT;
        break;
    }
  }
  if (code) {
    if (mod) {
      register_code(mod);
    }
    tap_code(code);
    if (mod) {
      unregister_code(mod);
    }
  }
  return true;
}

#endif