/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 20

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0

#define FIRMWARE_VERSION u8"aezmv/deQZn"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#define MOUSE_EXTENDED_REPORT
