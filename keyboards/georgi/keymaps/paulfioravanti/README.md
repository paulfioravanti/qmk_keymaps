# Georgi Personal Configuration

This layout does not contain any major changes from the [default Georgi QMK
layout][]. The only reason that I keep a copy is so I can compile it with the
steno firmware override changes contained in the `quantum` directory in this
repository.

## Compile

```sh
cd qmk_firmware
make git-submodule
qmk compile -kb georgi -km paulfioravanti
```

This should result in an `georgi_paulfioravanti.hex` file being generated
in the `qmk_firmware` root directory.

## Stenography

If you are using a Georgi, I will assume you already know about stenography and
[Plover][].

## Flash Firmware

The tiny button on the left side of the Georgi puts it into bootloader mode so
you can load firmware into it. More details in the [Georgi docs][].

Then, open up QMK Toolbox and follow their instructions.

[default Georgi QMK layout]: https://github.com/qmk/qmk_firmware/tree/master/keyboards/georgi
[Georgi docs]: http://docs.gboards.ca/docs/Georgi-Firmwares/
[Plover]: https://www.openstenoproject.org/plover/
