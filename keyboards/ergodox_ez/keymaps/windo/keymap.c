#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,
    SYM,
    MOTION,
    EST,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    MSQ_TL, MSQ_T, MSQ_TR,
    MSQ_L,  MSQ_C, MSQ_R,
    MSQ_BL, MSQ_B, MSQ_BR,
    MSQ_RESET, MSQ_LOCAL, MSQ_DANCE,
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

/* Visual layout.
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty(
    KC_EQUAL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS,                     KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    KC_TAB,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS,                     KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
    MT(MOD_LGUI, KC_ESCAPE),KC_A, KC_S, KC_D, KC_F, KC_G,                         KC_H, KC_J, KC_K, KC_L, LT(MOTION, KC_SCLN), MT(MOD_LGUI, KC_QUOTE),
    KC_LSFT, MT(MOD_LCTL, KC_Z),KC_X, KC_C, KC_V, KC_B, KC_TRNS,         KC_TRNS, KC_N, KC_M, KC_COMMA, KC_DOT, MT(MOD_RCTL, KC_SLSH), KC_RSFT,

    LT(SYM,KC_GRAVE), KC_TRNS, KC_TRNS, MO(MOTION), KC_LALT,                            KC_LALT, KC_TRNS, KC_LBRC, KC_RBRC, MO(SYM),

                                                KC_DELETE, KC_INS,       KC_TRNS, KC_TRNS,
                                                           KC_TRNS,      KC_PGUP,
                                          KC_SPC, KC_BSPC, MO(EST),      KC_PGDN, KC_TAB, KC_ENTER
  ),

  [SYM] = LAYOUT_ergodox_pretty(
    KC_ESCAPE, KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,       KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,       KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_SLSH, KC_F12,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRAVE,                        KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_TRNS,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,       KC_TRNS, KC_AMPR, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_MINUS, KC_TRNS,

    KC_TRNS, KC_EQUAL, KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_KP_0, KC_KP_0, KC_KP_COMMA, KC_KP_PLUS, KC_TRNS,

                                                 KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                                          KC_TRNS,       KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [MOTION] = LAYOUT_ergodox_pretty(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, MSQ_LOCAL,MSQ_TL, MSQ_T,   MSQ_TR,  MSQ_RESET,  KC_TRNS,    KC_TRNS, KC_PGUP, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,
    KC_TRNS, MSQ_C,   MSQ_L,   MSQ_B,   MSQ_R,   KC_MS_BTN1,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, MSQ_BL, MSQ_DANCE,MSQ_BR,  KC_MS_BTN2, KC_TRNS,    KC_TRNS, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, WEBUSB_PAIR, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_MS_BTN3, KC_TRNS,      KC_TRNS, KC_TRNS,
                                                           KC_TRNS,      KC_TRNS,
                                   KC_MS_BTN1, KC_MS_BTN2, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
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

#define SCREEN_WIDTH 10000
#define SCREEN_HEIGHT 10000
#define MIN_SCALE 0.01
#define MOVE_FACTOR (2.0 / 3.0)
#define RESCALE_FACTOR (1.0 / 3.0)
#define QUADRANT_SCALE_LOCAL 0.125
#define ANIMATION_STEP 50

typedef struct {
    int16_t x, y;
    float scale;
} quadrant_cursor_t;
static quadrant_cursor_t quadrant_cursor;
static report_mouse_t mouse_report;
static uint16_t quadrant_animation_start;

quadrant_cursor_t quadrant_cursor_init(void) {
    quadrant_cursor_t cursor;
    cursor.x = SCREEN_WIDTH / 2;
    cursor.y = SCREEN_HEIGHT / 2;
    cursor.scale = 0.5;
    return cursor;
}

quadrant_cursor_t make_quadrant_cursor(int16_t x, int16_t y, float scale) {
    quadrant_cursor_t cursor;
    cursor.x = x;
    cursor.y = y;
    cursor.scale = scale;
    return cursor;
}

quadrant_cursor_t quadrant_cursor_direction(quadrant_cursor_t cursor, int8_t dx, int8_t dy) {
    cursor = make_quadrant_cursor(
        cursor.x + (int16_t)(cursor.scale * (float)(dx) * MOVE_FACTOR * SCREEN_WIDTH),
        cursor.y + (int16_t)(cursor.scale * (float)(dy) * MOVE_FACTOR * SCREEN_HEIGHT),
        cursor.scale * RESCALE_FACTOR
    );
    if (cursor.x < 0) {
        cursor.x = 0;
    }
    if (cursor.x > SCREEN_WIDTH) {
        cursor.x = SCREEN_WIDTH;
    }
    if (cursor.y < 0) {
        cursor.y = 0;
    }
    if (cursor.y > SCREEN_HEIGHT) {
        cursor.y = SCREEN_HEIGHT;
    }
    if (cursor.scale < MIN_SCALE) {
        cursor.scale = MIN_SCALE;
    }
    return cursor;
}

uint32_t quadrant_animation(uint32_t trigger_time, void *cb_arg) {
    uprintf("Animation start=%d\n", quadrant_animation_start);
    if (quadrant_animation_start == 0) {
        return 0;
    }
    uint8_t step = (timer_read() - quadrant_animation_start) / ANIMATION_STEP;
    uprintf("Animation step=%d\n", step);

    int8_t dx, dy;
    switch (step) {
        case 0:
            dx = 0;
            dy = -1;
            break;
        case 1:
            dx = 1;
            dy = -1;
            break;
        case 2:
            dx = 1;
            dy = 0;
            break;
        case 3:
            dx = 1;
            dy = 1;
            break;
        case 4:
            dx = 0;
            dy = 1;
            break;
        case 5:
            dx = -1;
            dy = 1;
            break;
        case 6:
            dx = -1;
            dy = 0;
            break;
        case 7:
            dx = -1;
            dy = -1;
            break;
        case 8:
        default:
            dx = 0;
            dy = 0;
            quadrant_animation_start = 0;
            break;
    }
    quadrant_cursor_t animation_cursor = quadrant_cursor_direction(quadrant_cursor, dx, dy);
    mouse_report.x = (mouse_xy_report_t)(animation_cursor.x);
    mouse_report.y = (mouse_xy_report_t)(animation_cursor.y);
    host_mouse_send(&mouse_report);
    return 10;
}

bool process_mouse_quadrant(uint16_t keycode, keyrecord_t *record) {
    bool msq = true;
    if (record->event.pressed) {
        switch (keycode) {
            case MSQ_RESET:
                quadrant_cursor = quadrant_cursor_init();
                break;
            case MSQ_LOCAL:
                quadrant_cursor.scale = QUADRANT_SCALE_LOCAL;
                break;
            case MSQ_DANCE:
                quadrant_animation_start = timer_read();
                uprintf("defer_exec(quadrant_animation)");
                defer_exec(1, &quadrant_animation, NULL);
                return true;

            case MSQ_TL:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, -1, -1);
                break;
            case MSQ_T:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, 0, -1);
                break;
            case MSQ_TR:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, 1, -1);
                break;
            case MSQ_L:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, -1, 0);
                break;
            case MSQ_C:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, 0, 0);
                break;
            case MSQ_R:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, 1, 0);
                break;
            case MSQ_BL:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, -1, 1);
                break;
            case MSQ_B:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, 0, 1);
                break;
            case MSQ_BR:
                quadrant_cursor = quadrant_cursor_direction(quadrant_cursor, 1, 1);
                break;

            case KC_MS_BTN1:
                mouse_report.buttons |= QK_MOUSE_BUTTON_1;
                break;
            case KC_MS_BTN2:
                mouse_report.buttons |= QK_MOUSE_BUTTON_2;
                break;
            case KC_MS_BTN3:
                mouse_report.buttons |= QK_MOUSE_BUTTON_3;
                break;

            default:
                msq = false;
                break;
        }
    } else {
        switch (keycode) {
            case KC_MS_BTN1:
                mouse_report.buttons &= ~QK_MOUSE_BUTTON_1;
                break;
            case KC_MS_BTN2:
                mouse_report.buttons &= ~QK_MOUSE_BUTTON_2;
                break;
            case KC_MS_BTN3:
                mouse_report.buttons &= ~QK_MOUSE_BUTTON_3;
                break;

            default:
                msq = false;
                break;
        }
    }

    if (msq) {
        quadrant_animation_start = 0;
        mouse_report.x = (mouse_xy_report_t)(quadrant_cursor.x);
        mouse_report.y = (mouse_xy_report_t)(quadrant_cursor.y);
        // uprintf("Cursor: x=%u, y=%u scale=%u\n", quadrant_cursor.x, quadrant_cursor.y, (uint16_t)(quadrant_cursor.scale * 1000));
        host_mouse_send(&mouse_report);
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    if (layer_state_is(MOTION)) {
      if (process_mouse_quadrant(keycode, record) == false) {
            return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    quadrant_cursor = quadrant_cursor_init();
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
        case SYM:
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
