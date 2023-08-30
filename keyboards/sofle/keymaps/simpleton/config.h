#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// Latency
#undef  DEBOUNCE
#define DEBOUNCE 7
#define USB_POLLING_INTERVAL_MS 1

// Unicode
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE
#define UNICODE_CYCLE_PERSIST false  // Don't remember the last used mode, always start with the first

// Split
#define EE_HANDS

// Tap-Hold
#undef  TAPPING_TERM
#define TAPPING_TERM 225
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 120

// debug usb
#define SPLIT_WATCHDOG_ENABLE
