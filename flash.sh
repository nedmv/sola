#!/bin/bash
QMK_KEYBOARD="sofle"
QMK_KEYMAP="sola"

SCRIPT_DIR=$(dirname "$0")
LAST_FLASH_LOG="${SCRIPT_DIR}/flashing.log"
COMMON_LOG="${SCRIPT_DIR}/flashing.info"

BOOTLOADER=avrdude

if [ "$1" = "left" ]; then
    BOOTLOADER=avrdude-split-left
    echo "Ready to flash firmware"
    echo "Plug in left half of your keyboard"
elif [ "$1" = "right" ]; then
    BOOTLOADER=avrdude-split-right
    echo "Ready to flash firmware"
    echo "Plug in right half of your keyboard"
else
    echo "Invalid argument (use 'left' or 'right')" && exit 1
fi

qmk flash -kb ${QMK_KEYBOARD} -km ${QMK_KEYMAP} -bl $BOOTLOADER | tee "$LAST_FLASH_LOG" || { echo "Failed to flash firmware."; exit 1; }

HASH=$(git log -n1 --pretty=format:'%h')
BINARY_SIZE=$(grep -E " [0-9]+\/[0-9]+ " "$LAST_FLASH_LOG" | sed -E 's|.*( [0-9]+\/[0-9]+).*|\1|g')

echo "$(date +"%F %T"): Flashed version $HASH ($BINARY_SIZE bytes)." >> "$COMMON_LOG"