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

## N-key Rollover

To toggle [n-key rollover][] (NKRO), press LShift+RShift+N. If you want to have
NKRO enabled by default, add the line

```c
#define FORCE_NKRO`
```

to the `config.h` file ([source][NKRO doesn't work with ergodox ez]).

## Stenography

> Feel free to ignore this section if you are not using the Stenography layer.

In order to use the Stenography layer (currently `STEN` in [`keymap.c`][]),
you will need to install [Plover][] (`brew cask install plover`), and configure
it in the following way:

- Click the [Configure...] button in the main "Plover" window, and the
  "Plover Configuration" window should open
- Under the [Machine] tab, select "Gemini PR" from the "Stenotype Machine"
  dropdown menu
- Click the [Configure...] button next to the "Stenotype Machine" dropdown menu,
  and the "Serial Port Configuration" window should open
- Click the "Scan" button next to the "Port" dropdown menu
- Under the "Port" dropdown menu, there should now be an option that looks
  something like `/dev/cu.usbmodem4`, which you should select
- Click the "Baudrate" dropdown menu and select "115200"
- Press the [OK] button on the "Serial Port Configuration" window
- Press the [Save] button on the "Plover Configuration" window
- At the bottom of the main "Plover" window, you should see a green circle with
  a "Gemini PR connected" message
- If the "Gemini PR connected" message is not showing, then try pressing the
  "refresh" button next to the message to attempt a re-connection. If that does
  not work, then check the [Stenography in QMK][] documentation page and/or
  [Plover's Troubleshooting wiki page][]

## Flash Firmware

Follow instructions (and watch video) on the
[ErgoDox EZ Graphical Configurator page][].

[ErgoDox EZ Graphical Configurator page]: https://ergodox-ez.com/pages/graphical-configurator
[`keymap.c`]: keymap.c
[my original ErgoDox Firmware configuration]: https://github.com/paulfioravanti/ergodox-firmware/blob/custom-layout/firmware/keyboard/ergodox/layout/custom-layout.c
[n-key rollover]: https://en.wikipedia.org/wiki/Rollover_(key)#n-key_rollover
[NKRO doesn't work with ergodox ez]: https://github.com/qmk/qmk_firmware/issues/1695
[Plover]: https://www.openstenoproject.org/plover/
[Plover's Troubleshooting wiki page]: https://github.com/openstenoproject/plover/wiki/Troubleshooting:-Common-Issues
[QMK ErgoDox EZ default keymap]: https://github.com/qmk/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/default/keymap.c
[Stenography in QMK]: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_stenography.md#configuring-qmk-for-steno
[Teensy Loader for Mac OS]: https://pjrc.com/teensy/loader_mac.html
