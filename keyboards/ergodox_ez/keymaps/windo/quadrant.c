#include QMK_KEYBOARD_H
#include "quadrant.h"

typedef struct {
    float x, y;
    float scale;
} quadrant_cursor_t;
static quadrant_cursor_t quadrant_cursor;
static uint16_t quadrant_animation_start;

void quadrant_cursor_init(void) {
    quadrant_cursor.x = 0.5;
    quadrant_cursor.y = 0.5;
    quadrant_cursor.scale = 0.5;
}

quadrant_cursor_t make_quadrant_cursor(float x, float y, float scale) {
    quadrant_cursor_t cursor;
    cursor.x = x;
    cursor.y = y;
    cursor.scale = scale;
    return cursor;
}

quadrant_cursor_t quadrant_cursor_direction(quadrant_cursor_t cursor, int8_t dx, int8_t dy) {
    cursor = make_quadrant_cursor(
        cursor.x + cursor.scale * (float)(dx) * MOVE_FACTOR,
        cursor.y + cursor.scale * (float)(dy) * MOVE_FACTOR,
        cursor.scale * RESCALE_FACTOR
    );
    if (cursor.x < 0) {
        cursor.x = 0;
    }
    if (cursor.x > 1) {
        cursor.x = 1;
    }
    if (cursor.y < 0) {
        cursor.y = 0;
    }
    if (cursor.y > 1) {
        cursor.y = 1;
    }
    if (cursor.scale < MIN_SCALE) {
        cursor.scale = MIN_SCALE;
    }
    return cursor;
}

uint32_t quadrant_animation(uint32_t trigger_time, void *cb_arg) {
    if (quadrant_animation_start == 0) {
        return 0;
    }
    uint8_t step = (timer_read() - quadrant_animation_start) / ANIMATION_STEP;
    int8_t dx, dy;
    switch (step) {
        case 0:
        case 8:
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
        default:
            dx = 0;
            dy = 0;
            quadrant_animation_start = 0;
            break;
    }
    quadrant_cursor_t animation_cursor = quadrant_cursor_direction(quadrant_cursor, dx, dy);
    digitizer_set_position(animation_cursor.x, animation_cursor.y);
    return ANIMATION_SLEEP;
}

bool process_quadrant(uint16_t keycode, keyrecord_t *record) {
    bool msq = true;
    if (record->event.pressed) {
        switch (keycode) {
            case MSQ_RESET:
                quadrant_cursor_init();
                break;
            case MSQ_LOCAL:
                quadrant_cursor.scale = QUADRANT_SCALE_LOCAL;
                break;
            case MSQ_DANCE:
                quadrant_animation_start = timer_read();
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
            default:
                msq = false;
                break;
        }
    } else {
      msq = false;
    }

    if (msq) {
        quadrant_animation_start = 0;
        digitizer_in_range_on();
        digitizer_set_position(quadrant_cursor.x, quadrant_cursor.y);
        // uprintf("Cursor: x=%u, y=%u scale=%u\n", quadrant_cursor.x, quadrant_cursor.y, (uint16_t)(quadrant_cursor.scale * 1000));
        return false;
    }
    return true;
}

