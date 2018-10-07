# ErgoDox EZ Personal Configuration

This is a QMK port over of [my original ErgoDox Firmware configuration][], and
all further layout tinkering will happen here.

This keymap started out with the [QMK ErgoDox EZ default keymap][], and I
further customised it from there.

## Dependencies

In order to install compiled firmware on to the ErgoDox, install the
[Teensy Loader for Mac OS][]:

```sh
brew cask install teensy
```

## Compile

```sh
cp -r qmk_keymaps/keyboards/ergodox_ez/keymaps/paulfioravanti qmk_firmware/keyboards/ergodox_ez/keymaps
cd qmk_firmware
make ergodox_ez:paulfioravanti
```

This should result in an `ergodox_ez_paulfioravanti.hex` file being generated
in the `qmk_firmware` root directory.

## Flash Firmware

Follow instructions (and watch video) on the
[ErgoDox EZ Graphical Configurator page][].

### N-key Rollover

To toggle [n-key rollover][] (NKRO), press LShift+RShift+N. If you want to have
NKRO enabled by default, add `#define FORCE_NKRO` to the `config.h` file
([source][NKRO doesn't work with ergodox ez]).


[ErgoDox EZ Graphical Configurator page]: https://ergodox-ez.com/pages/graphical-configurator
[my original ErgoDox Firmware configuration]: https://github.com/paulfioravanti/ergodox-firmware/blob/custom-layout/firmware/keyboard/ergodox/layout/custom-layout.c
[n-key rollover]: https://en.wikipedia.org/wiki/Rollover_(key)#n-key_rollover
[NKRO doesn't work with ergodox ez]: https://github.com/qmk/qmk_firmware/issues/1695
[QMK ErgoDox EZ default keymap]: https://github.com/qmk/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/default/keymap.c
[Teensy Loader for Mac OS]: https://pjrc.com/teensy/loader_mac.html
