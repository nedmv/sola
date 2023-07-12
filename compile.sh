#!/bin/bash
QMK_KEYBOARD="sofle"
QMK_KEYMAP="sola"
qmk compile -j 0 -kb ${QMK_KEYBOARD} -km ${QMK_KEYMAP}