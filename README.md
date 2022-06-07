# QMK Keymaps

Custom keymaps I have made for mechanical keyboards running [QMK Firmware][].

## Blog Posts

Lots of tinkering with keyboard layouts has resulted in what I learned taking up
a fair share of content on [my blog][].

I wrote a post about getting started with creating a QMK keyboard layout.
Although it is quite [Ergodox][]-centric, I think there is still enough general
QMK content in there to be of use if you use any other type of keyboard:

- _[Escape the defaults and Control your keyboard with QMK][]_

The creation of the [`GS_TIMESTAMP`][] custom keycode, which inserts a current
timestamp into a [Google Sheets][] cell, ended up being far more involved that
I originally thought, so I wrote up a blog post about that:

- _[All I want is a Timestamp][]_

Compilation and customisation of the Georgi layout, in particular its [Gaming
mode][Georgi Gaming Mode], was the subject of the following blog post:

- _[Flashing Georgi Firmware][]_

Getting the [Georgi][] to play [Doom Typist][Typist.pk3] was the subject of the
following blog post:

- _[Steno Gaming: Doom Typist][]_

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

### Copy Keymaps

Use [rsync][] to merge the `keyboards` directory into the QMK Firmware
repository's `keyboards` directory:

```sh
rsync --recursive qmk_keymaps/keyboards/ qmk_firmware/keyboards/
```

### Copy Steno Firmware Overrides

If you plan to use the stenography firmware overrides that allow you to:

- auto-repeat chords
- hold down common keys between chords

then merge over the contents in the `quantum` directory as well:

```sh
rsync --recursive qmk_keymaps/quantum/ qmk_firmware/quantum/
```

> Many thanks go to [Joshua Grams][] for putting up the code for this in his
> [steno-firmware][] repo!

Details about firmware compilation and setup are on the `README` page for the
specific keymap layout.

## Flashing Firmware

QMK has its own tool, [QMK Toolbox][], for flashing firmware. If it seems a bit
too technical for you, and you own an Ergodox EZ, you may have luck with other
tools. See Ergodox EZ layout README file for details.

## Handy Links

- [QMK Keycodes][] - what keycodes are currently available to you
- [QMK Config Options][] - Helps determine what can go in the `config.h` file
- [QMK Customizing Functionality][] - how to define new keycodes and process
  them

[All I want is a Timestamp]: https://www.paulfioravanti.com/blog/google-sheets-timestamp/
[Ergodox]: https://ergodox-ez.com/
[Escape the defaults and Control your keyboard with QMK]: https://www.paulfioravanti.com/blog/escape-defaults-control-keyboard-qmk/
[Flashing Georgi Firmware]: https://www.paulfioravanti.com/blog/flashing-georgi-firmware/
[Georgi]: https://www.gboards.ca/product/georgi
[Georgi Gaming Mode]: http://docs.gboards.ca/docs/Unboxing-Georgi/#entering-qmk-gaming-mode
[Google Sheets]: https://www.google.com/sheets/about/
[`GS_TIMESTAMP`]: https://github.com/paulfioravanti/qmk_keymaps/blob/master/keyboards/ergodox_ez/keymaps/paulfioravanti/user/process_record_user.c#L104
[Homebrew]: https://brew.sh/
[Joshua Grams]: https://github.com/JoshuaGrams
[macOS build tools]: https://docs.qmk.fm/#/getting_started_build_tools?id=macos
[my blog]: https://www.paulfioravanti.com/
[QMK Config Options]: https://docs.qmk.fm/#/config_options
[QMK Customizing Functionality]: https://docs.qmk.fm/#/custom_quantum_functions
[QMK documentation]: https://docs.qmk.fm/#/
[QMK Firmware]: https://qmk.fm/
[QMK Keycodes]: https://docs.qmk.fm/#/keycodes
[QMK Toolbox]: https://github.com/qmk/qmk_toolbox
[rsync]: http://en.wikipedia.org/wiki/Rsync
[Setting Up Your QMK Environment]: https://docs.qmk.fm/#/newbs_getting_started
[steno-firmware]: https://github.com/JoshuaGrams/steno-firmware
[Steno Gaming: Doom Typist]: https://www.paulfioravanti.com/blog/steno-gaming-doom-typist/
[Typist.pk3]: https://github.com/mmaulwurff/typist.pk3
