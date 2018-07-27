# ErgoDox EZ Personal Configuration

This is a QMK port over of [my original ErgoDox Firmware configuration][], and
all further layout tinkering will happen here.

This keymap started out with the [QMK ErgoDox EZ default keymap][], and I
further customised it from there.

## Compile

Assuming that

```sh
git clone git@github.com:qmk/qmk_firmware.git
cd qmk_firmware
make ergodox_ez:paulfioravanti
```

## Flash Firmware

Follow instructions (and watch video) on the
[ErgoDox EZ Graphical Configurator page][].

[ErgoDox EZ Graphical Configurator page]: https://ergodox-ez.com/pages/graphical-configurator
[my original ErgoDox Firmware configuration]: https://github.com/paulfioravanti/ergodox-firmware/blob/custom-layout/firmware/keyboard/ergodox/layout/custom-layout.c
[QMK ErgoDox EZ default keymap]: https://github.com/qmk/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/default/keymap.c
