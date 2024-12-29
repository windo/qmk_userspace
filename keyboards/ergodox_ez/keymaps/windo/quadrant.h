#include QMK_KEYBOARD_H

#define MIN_SCALE 0.01
#define MOVE_FACTOR (2.0 / 3.0)
#define RESCALE_FACTOR (1.0 / 3.0)
#define QUADRANT_SCALE_LOCAL 0.125
#define ANIMATION_SLEEP 5
#define ANIMATION_STEP 75

enum quadrant_keycodes {
    MSQ_RESET = SAFE_RANGE + 1,
    MSQ_LOCAL, MSQ_DANCE,

    MSQ_TL, MSQ_T, MSQ_TR,
    MSQ_L,  MSQ_C, MSQ_R,
    MSQ_BL, MSQ_B, MSQ_BR,
};

void quadrant_cursor_init(void);
bool process_quadrant(uint16_t keycode, keyrecord_t *record);
