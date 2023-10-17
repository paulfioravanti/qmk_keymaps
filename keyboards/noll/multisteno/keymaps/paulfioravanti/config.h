#include "../../config.h"

// Set Unicode mode to Mac OS. More information:
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_unicode.md
#define UNICODE_SELECTED_MODES UC_MAC

// NOTE: Only use these if the process_steno overrides are in place!
#define STENO_1UP
#define STENO_REPEAT

// Top level config.h file defines COMBO_COUNT, so we need to redefine it for
// custom values.
#undef COMBO_COUNT
#define COMBO_COUNT 43
