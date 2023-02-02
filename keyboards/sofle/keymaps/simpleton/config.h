#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define USB_POLLING_INTERVAL_MS 1
#undef DEBOUNCE
#define DEBOUNCE 5

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX, UNICODE_MODE_WINCOMPOSE

// Don't remember the last used mode, always start with the first
#define UNICODE_CYCLE_PERSIST false
