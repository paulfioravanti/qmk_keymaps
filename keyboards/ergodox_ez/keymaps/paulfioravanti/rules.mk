STENO_ENABLE = yes
# Needed for Steno
VIRTSER_ENABLE = yes
FORCE_NKRO = yes
# Mouse keys can't be used if Steno is enabled, so Steno gets priority for now.
# Attempting to compile with steno and mouse keys enabled results in the
# following error:
# `"There are not enough available endpoints to support all functions.
# Remove some in the rules.mk file.
# (MOUSEKEY, EXTRAKEY, CONSOLE, NKRO, MIDI, SERIAL, STENO)"`
MOUSEKEY_ENABLE = no
