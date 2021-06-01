# Steno needs to be explicitly enabled
STENO_ENABLE = yes
# If steno is enabled, then the USB serial driver for the firmware
# needs to be enabled as well
VIRTSER_ENABLE = yes
# NOTE: NKRO is, apparently, "disabled by default because some bioses aren't
# compatible with NKRO", which is why it needs to be specifically enabled here
# as well as in the `config.h` file.
FORCE_NKRO = yes
# Enable mouse key movements
MOUSEKEY_ENABLE = yes
# Needed for QWERTY chord layer to explictly enable combos
COMBO_ENABLE = yes
# Merge virtual serial ports into shared endpoints so that steno can be enabled
# with mouse and other media keys.
# REF: https://docs.qmk.fm/#/config_options?id=usb-endpoint-limitations
KEYBOARD_SHARED_EP = yes
