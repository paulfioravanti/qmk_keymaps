# QMK Keymaps

Custom keymaps I have made for mechanical keyboards running [QMK Firmware][].

## Dependencies

In order to create a build environment, I followed the instructions on the
[Setting Up Your QMK Environment][] page of the [QMK Documentation][].

I use Mac OS, so the tools needed to compile the layout are listed in the
[macOS section][macOS build tools], and are installed using [Homebrew][]:

```sh
brew tap qmk/qmk
brew install qmk
qmk setup
```

## Install

```sh
git clone git@github.com:qmk/qmk_firmware.git
git clone git@github.com:paulfioravanti/qmk_keymaps.git
```

Then, copy the relevant keymap folder from the `qmk_keymaps` directory
into the `qmk_firmware` directory, and compile the firmware. Details about
compilation/setup are on the `README` page for the specific keymap layout.

## Flashing Firmware

QMK has its own tool, [QMK Toolbox][], for flashing firmware, but for Ergodox
firmware flashing, I had better luck with other tools. See Ergodox EZ layout
README file for details.

## Handy Links

- [Escape the defaults and Control your keyboard with QMK][] - A blog post I
  wrote on getting started with creating a QMK layout
- [QMK Keycodes][] - what keycodes are currently available to you
- [QMK Config Options][] - Helps determine what can go in the `config.h` file
- [QMK Customizing Functionality][] - how to define new keycodes and process
  them

[Escape the defaults and Control your keyboard with QMK]: https://paulfioravanti.com/blog/2018/07/30/escape-the-defaults-and-control-your-keyboard-with-qmk/
[Homebrew]: https://brew.sh/
[macOS build tools]: https://docs.qmk.fm/#/getting_started_build_tools?id=macos
[QMK Config Options]: https://docs.qmk.fm/#/config_options
[QMK Customizing Functionality]: https://docs.qmk.fm/#/custom_quantum_functions
[QMK documentation]: https://docs.qmk.fm/#/
[QMK Firmware]: https://qmk.fm/
[QMK Keycodes]: https://docs.qmk.fm/#/keycodes
[QMK Toolbox]: https://github.com/qmk/qmk_toolbox
[Setting Up Your QMK Environment]: https://docs.qmk.fm/#/newbs_getting_started
