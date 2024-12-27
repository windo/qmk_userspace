#include QMK_KEYBOARD_H
#include "version.h"

#define KC_TR KC_TRNS

enum layers {
    BASE,
    SYMB,
    MOTION,
    EST,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

enum unicode_names {
  EURO,
  OTIL, COTIL,
  ADIA, CADIA,
  ODIA, CODIA,
  UDIA, CUDIA,
  SCAR, CSCAR,
  ZCAR, CZCAR,
};

const uint32_t PROGMEM unicode_map[] = {
  [EURO] = 0x20AC,
  [OTIL] = 0x00F5, [COTIL] = 0x00D5,
  [ADIA] = 0x00E4, [CADIA] = 0x00C4,
  [ODIA] = 0x00F6, [CODIA] = 0x00D6,
  [UDIA] = 0x00FC, [CUDIA] = 0x00DC,
  [SCAR] = 0x0161, [CSCAR] = 0x0160,
  [ZCAR] = 0x017E, [CZCAR] = 0x017D,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty(
    KC_EQUAL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS,                      KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS,                      KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
    MT(MOD_LGUI, KC_ESCAPE),KC_A, KC_S, KC_D, KC_F, KC_G,                          KC_H, KC_J, KC_K, KC_L, LT(MOTION, KC_SCLN), MT(MOD_LGUI, KC_QUOTE),
    KC_LSFT, MT(MOD_LCTL, KC_Z),KC_X, KC_C, KC_V, KC_B, KC_TRNS,          KC_TRNS, KC_N, KC_M, KC_COMMA, KC_DOT, MT(MOD_RCTL, KC_SLSH), KC_RSFT,

    LT(SYMB,KC_GRAVE), KC_TRNS, KC_TRNS, MO(MOTION), KC_LALT,                            KC_LALT, KC_TRNS, KC_LBRC, KC_RBRC, MO(SYMB),

                                                KC_DELETE, KC_INS,        KC_TRNS, KC_TRNS,
                                                           KC_TRNS,       KC_PGUP,
                                          KC_SPC, KC_BSPC, MO(EST),       KC_PGDN, KC_TAB, KC_ENTER
  ),

  [SYMB] = LAYOUT_ergodox_pretty(
    KC_ESCAPE, KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,              KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    KC_TRNS,   KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,        KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_SLSH, KC_F12,
    KC_TRNS,   KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRAVE,                        KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_TRNS,
    KC_TRNS,   KC_PERC, KC_CIRC,KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,       KC_TRNS, KC_AMPR, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_MINUS, KC_TRNS,

    KC_TRNS,   KC_EQUAL, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_KP_0, KC_KP_0, KC_KP_COMMA, KC_KP_PLUS, KC_TRNS,

                                                  KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                                           KC_TRNS,       KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [MOTION] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,         KC_TRNS, KC_HOME,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,    KC_TRNS,    KC_MS_WH_UP, KC_TRNS,         KC_TRNS, KC_PGUP,   KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,   KC_MS_UP,   KC_MS_WH_DOWN,                         KC_PGDN,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS,         KC_TRNS, KC_END,    KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRNS, KC_TRNS,

    KC_TRNS, WEBUSB_PAIR, KC_TRNS, KC_TRNS, KC_TRNS,                                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                         KC_MS_BTN3, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,        KC_TRNS,
                                             KC_MS_BTN1, KC_MS_BTN2, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [EST] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, KC_TRNS, KC_TRNS, UM(EURO), KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UP(UDIA, CUDIA), UP(OTIL, COTIL), KC_TRNS,
    KC_TRNS, KC_TRNS, UP(SCAR, CSCAR), KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, UP(ODIA, CODIA), UP(ADIA, CADIA), KC_TRNS,
    KC_TRNS, UP(ZCAR, CZCAR), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                          KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,          KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case BASE:
            break;
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MOTION:
            ergodox_right_led_2_on();
            break;
        case EST:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};
