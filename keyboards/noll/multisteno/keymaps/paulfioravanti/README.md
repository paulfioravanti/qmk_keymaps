# Multisteno Personal Configuration

The major changes in this layout from the [default Multisteno QMK layout][]
are based on the changes I made for [my Georgi configuration][], and consist of
the following:

- Change the QMK key mnemonics in the QWERTY layers from using shorter aliases
  to longer, and, in my opinion more legible, [key names][]
- Change some of the keys used in the QWERTY layer to more closely resemble the
  QWERTY layer in my [Ergodox EZ keymap][]
- Add configuration for USB [Human Interface Device][] (HID) class
  communications. Specifically, the intention is to use [QMK][]'s [Raw HID][]
  functionality to allow external devices, like a pedal, to perform actions
  internal to the keyboard, like switching keyboard layers
- Use complex hotkey combinations during [Typist][] dash commands that call
  [Alfred][] workflows which log out to [Tapey Tape][]. See [my Dotfiles][] for
  the workflows.

## Dependencies

The HID-related functionality requires [HIDAPI][] to be installed. If you
are on macOS, this can be done with [Homebrew][] with:

```sh
brew install hidapi
```

### Multisteno Firmware

The base Multisteno firmware is not hosted in the [QMK GitHub repo][], and hence
needs to be downloaded directly from its own [Multisteno firmware GitHub
repo][], and then copied into the QMK directory:

```sh
git clone git@github.com:nkotech/Multisteno-Firmware.git
rsync --recursive Multisteno-Firmware/keyboards/ qmk_firmware/keyboards/
```

## Compile

```sh
cd qmk_firmware
make git-submodule
qmk compile -kb noll/multisteno -km paulfioravanti
```

This should result in an `noll_multisteno_paulfioravanti.bin` file being
generated in the `qmk_firmware` root directory.

## Stenography

If you are using a Multisteno, I will assume you already know about stenography
and [Plover][].

## Flash Firmware

See the [Multisteno docs][] for details.

## Steno Tape Custom Entries Architecture

```mermaid
---
title: Steno Tape Custom Entries
---
flowchart BT
  FirmwareRawHID["Raw HID"]
  FirmwareProcessRecordUser["Process Record User"]
  HIDHost["HID Host"]
  HIDHostClient["HID Host Client"]
  StenoTapeLibrary["Steno Tape Library"]
  StenoTapeClient["Steno Tape Client"]
  StenoTapeCustomEntriesWorkflow["Steno Tape Custom Entries Workflow"]
  StreamDeck["Stream Deck"]
  StreamDeckPedal[/"STREAM DECK PEDAL"\]
  TapeyTape[Tapey Tape]
  TapeLogFile["Tape Log\n(tapey_tape.txt)"]
  TapeFilterScript["Tape Filter Script"]

  classDef current fill:#ffb3b3, stroke:#333, stroke-width:4px, color:black

  subgraph Computer["COMPUTER"]
    subgraph Alfred["Alfred"]
      StenoTapeCustomEntriesWorkflow
    end

    subgraph Elgato["Elgato"]
      StreamDeck
    end

    subgraph HIDHosts["HID Hosts"]
      HIDHost
      HIDHostClient -- "`./hid_host`" --> HIDHost
    end

    subgraph Plover["Plover"]
      subgraph Plugins
        TapeLogFile
        TapeyTape -- outputs to --> TapeLogFile
      end
    end

    subgraph StenoTape["Steno Tape"]
      StenoTapeLibrary
      StenoTapeClient -- "calls API" --> StenoTapeLibrary
      TapeFilterScript
    end

    Terminal(Terminal)
  end

  subgraph Keyboard["KEYBOARD"]
    subgraph QMKFirmware["QMK Firmware"]
      FirmwareProcessRecordUser:::current
      FirmwareRawHID:::current
    end
    class QMKFirmware current
  end

  Terminal -- "`./run-tape-feed.sh --filter`" --> TapeFilterScript
  TapeFilterScript -- filters --> TapeLogFile
  StenoTapeLibrary -- outputs to --> TapeLogFile
  StenoTapeCustomEntriesWorkflow -- "`./steno_tape_client`" --> StenoTapeClient
  FirmwareProcessRecordUser -- "SEND_STRING(...)" --> StenoTapeCustomEntriesWorkflow
  HIDHost -- "calls API" --> StenoTapeLibrary
  FirmwareRawHID -. "hid_read/\nraw_hid_send" .-> HIDHost
  HIDHost -- "hid_write/\nraw_hid_receive" --> FirmwareRawHID
  StreamDeck -- "`./hid_host_client.sh`" --> HIDHostClient
  StreamDeckPedal -- connects --> StreamDeck

  click Dictionaries href "https://github.com/paulfioravanti/steno-dictionaries" "Steno Dictionaries" _blank
  click FirmwareRawHID href "https://github.com/paulfioravanti/qmk_keymaps/blob/master/keyboards/gboards/georgi/keymaps/paulfioravanti/user/hid.c" "Georgi HID" _blank
  click FirmwareProcessRecordUser href "https://github.com/paulfioravanti/qmk_keymaps/blob/master/keyboards/gboards/georgi/keymaps/paulfioravanti/user/process_record_user.c" "Georgi Process Record User" _blank
  click HIDHost href "https://github.com/paulfioravanti/hid_hosts/blob/main/hid_host.c" "HID Host" _blank
  click HIDHostClient href "https://github.com/paulfioravanti/hid_hosts/blob/main/hid_host_client.sh" "HID Host Client" _blank
  click StenoTapeClient href "https://github.com/paulfioravanti/steno_tape/blob/main/clients/steno_tape_client.c" "Steno Tape Client" _blank
  click StenoTapeCustomEntriesWorkflow href "https://github.com/paulfioravanti/dotfiles/tree/master/macos/alfred" "Steno Tape Custom Entries Workflow" _blank
  click StenoTapeLibrary href "https://github.com/paulfioravanti/steno_tape/blob/main/src/steno_tape.c" "Steno Tape" _blank
  click StreamDeck href "https://www.elgato.com/us/en/s/welcome-to-stream-deck" "Stream Deck" _blank
  click StreamDeckPedal href "https://www.elgato.com/us/en/p/stream-deck-pedal" "Stream Deck Pedal" _blank
  click TapeyTape href "https://github.com/rabbitgrowth/plover-tapey-tape" "Tapey Tape" _blank
  click TapeFilterScript href "https://github.com/paulfioravanti/steno_tape/blob/main/bin/run-tape-feed.sh" "Tape Filter Script" _blank
```

[Alfred]: https://www.alfredapp.com/
[default Multisteno QMK layout]: https://github.com/nkotech/Multisteno-Firmware/blob/main/keyboards/noll/multisteno/keymaps/default/keymap.c
[Ergodox EZ keymap]: ../../../../ergodox_ez/keymaps/paulfioravanti/keymap.c
[HIDAPI]: https://github.com/libusb/hidapi
[Homebrew]: https://brew.sh/
[Human Interface Device]: https://en.wikipedia.org/wiki/USB_human_interface_device_class
[key names]: https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
[Multisteno docs]: https://github.com/nkotech/Multisteno-Firmware
[Multisteno firmware GitHub repo]: https://github.com/nkotech/Multisteno-Firmware
[my Dotfiles]: https://github.com/paulfioravanti/dotfiles/tree/master/macos/alfred
[my Georgi configuration]: ../../../../gboards/georgi/keymaps/paulfioravanti/
[Plover]: https://www.openstenoproject.org/plover/
[QMK]: https://qmk.fm/
[QMK GitHub repo]: https://github.com/qmk/qmk_firmware
[Raw HID]: https://docs.qmk.fm/#/feature_rawhid
[Tapey Tape]: https://github.com/rabbitgrowth/plover-tapey-tape
[Typist]: https://github.com/mmaulwurff/typist.pk3
