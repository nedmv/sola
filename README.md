**SoLa** is a keymap for [Sofle RGB keyboard](https://github.com/josefadamcik/SofleKeyboard).

## Features
- English layout based on QWERTY
- Russian layout based on ЙЦУКЕН
- [lang_shift](https://github.com/klavarog/lang_shift) to unify these layouts

## Usage
1. Install [QMK Firmware](https://docs.qmk.fm/#/newbs_getting_started).
2. Clone this repo. Create a link for folder named `keymap` inside your QMK installation.
```sh
ln -s PATH_TO_THIS_REPO/sola/keymap PATH_TO_QMK_FIRMWARE/keyboards/sofle/keymaps/sola
```
3. Compile firmware.
```
qmk compile -kb sofle -km sola
```
Or run `./compile.sh`.
4. Flash firmware to both halves of keyboard.
```sh
qmk flash -kb sofle -km sola -bl avrdude-split-left
qmk flash -kb sofle -km sola -bl avrdude-split-right
```
Or run
```sh
./flash.sh left
./flash.sh right
```

## Debugging
1. Add "CONSOLE_ENABLE = yes" to `rules.mk`.
2. Add some debug prints in code with `dprintf`.
3. Compile and flash new version of firmware.
4. Download [hid_listen](https://www.pjrc.com/teensy/hid_listen.html).
5. Run `hid_listen` binary from terminal and see your debug output.
