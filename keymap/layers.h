#pragma once

enum sofle_layers {
    // Language layers for lang-shift must be in that order.
    L_EN = 0, // Base English layer, based on QWERTY
    L_EN_S, // Shifted English layer
    L_RU, // Base Russian layer, based on ЙЦУКЕН
    L_RU_S, // Shifted Russian layer.

    L_MOVE, // Movement layer (arrows, F1-F12)
    L_PROG, // Program layer (Meh hotkeys, media)
    L_KEEB, // Keyboard layer (lighting, sound, reset)
};