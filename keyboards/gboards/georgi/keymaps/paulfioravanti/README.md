# Georgi Personal Configuration

The major changes in this layout from the [default Georgi QMK layout][] consist
of the following:

- Change the QMK key mnemonics in the Gaming layers from using shorter aliases
  to longer, and, in my opinion more legible, [key names][]
- Change some of the keys used in the gaming layer to more closely resemble the
  QWERTY layer in my [Ergodox EZ keymap][]

## Compile

```sh
cd qmk_firmware
make git-submodule
qmk compile -kb georgi -km paulfioravanti
```

This should result in an `gboards_georgi_paulfioravanti.hex` file being generated
in the `qmk_firmware` root directory.

## Stenography

If you are using a Georgi, I will assume you already know about stenography and
[Plover][].

## Flash Firmware

The tiny button on the left side of the Georgi puts it into bootloader mode so
you can load firmware into it. More details in the [Georgi docs][].

Then, open up QMK Toolbox and follow their instructions.

[default Georgi QMK layout]: https://github.com/qmk/qmk_firmware/tree/master/keyboards/gboards/georgi
[Ergodox EZ keymap]: ../../../../ergodox_ez/keymaps/paulfioravanti/keymap.c
[key names]: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
[Georgi docs]: http://docs.gboards.ca/docs/Georgi-Firmwares/
[Plover]: https://www.openstenoproject.org/plover/
