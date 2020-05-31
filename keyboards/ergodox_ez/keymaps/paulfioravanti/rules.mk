# Steno needs to be explicitly enabled
STENO_ENABLE = yes
# If steno is enabled, then the USB serial driver for the firmware
# needs to be enabled as well
VIRTSER_ENABLE = yes
# NOTE: NKRO is, apparently, "disabled by default because some bioses aren't
# compatible with NKRO", which is why it needs to be specifically enabled here
# as well as in the `config.h` file.
FORCE_NKRO = yes
# Mouse keys can't be used if Steno is enabled, so Steno gets priority for now.
# Attempting to compile with steno and mouse keys enabled results in the
# following error:
# `"There are not enough available endpoints to support all functions.
# Remove some in the rules.mk file.
# (MOUSEKEY, EXTRAKEY, CONSOLE, NKRO, MIDI, SERIAL, STENO)"`
MOUSEKEY_ENABLE = no
# Needed for QWERTY chord layer to explictly enable combos
COMBO_ENABLE = yes
