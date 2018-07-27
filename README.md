# QMK Firmware Keymaps

Custom firmware keymaps I have made for mechanical keyboards running
[QMK Firmware][].

## Dependencies

I use Mac OS, so the tools needed to compile the layout are listed in the
[Install Build Tools - Mac OS section][] of the QMK documentation:

```sh
brew tap osx-cross/avr
brew tap PX4/homebrew-px4
brew update
brew install avr-gcc
brew install dfu-programmer
brew install gcc-arm-none-eabi
brew install avrdude
```

## Install

```sh
git clone git@github.com:qmk/qmk_firmware.git
git clone git@github.com:paulfioravanti/qmk_firmware_keymaps.git
```

Then, copy the relevant keymap folder from the `qmk_firmware_keymaps` directory
into the `qmk_firmware` directory, and compile the firmware. Details about
compilation/setup are on the `README` page for the specific keymap.

## Handy Links

- [QMK Keycodes][] (what keycodes are currently available to you)
- [QMK Config Options][] (Helps determine what can go in the `config.h` file)
- [QMK Customizing Functionality][]
  (how to define new keycodes and process them)

[Install Build Tools - Mac OS section]: https://docs.qmk.fm/install-build-tools#macos
[QMK Config Options]: https://docs.qmk.fm/#/config_options
[QMK Customizing Functionality]: https://docs.qmk.fm/#/custom_quantum_functions
[QMK Firmware]: https://qmk.fm/
[QMK Keycodes]: https://docs.qmk.fm/#/keycodes
[Teensy Loader for Mac OS]: https://pjrc.com/teensy/loader_mac.html
