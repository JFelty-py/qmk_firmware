#include QMK_KEYBOARD_H

/*Return to this later
 *#define LAYOUT_Orion_base( \
 *  K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, K12, \
 *  K13, K14, K15, K16, K17, K18, K19, K20, K21, K22, K23, K24, \
 *  K25, K26, K27, K28, K29, K30, K31, K32, K33, K34, K35, K36, \
 *  K37, K38, K39, K40, K41, K42, K43, K44, K45, K46, K47, K48, \
 *       K49, K50, K51, K52, K53, K54, K55, K56, K57, K58, \
 *       K59, K60, K61, K62, K63, K64, K65, K66, K67, K68 \
 *
 * ) \
 * LAYOUT_wrapper( \
 *       K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, K11, K12, \
 *       K13, K14, K15, K16, K17, K18, K19, K20, K21, K22, K23, K24, \
 *       K25, K26, K27, K28, K29, K30, K31, K32, K33, K34, K35, K36, \
 *       K37, K38, K39, K40, K41, K42, K43, K44, K45, K46, K47, K48, \
 *       K49, K50, K51, K52, K53, K54, K55, K56 \
 *   )
 *   / Re-pass though to allow templates to be used /
 *   //#define LAYOUT_Orion_base_wrapper(...)       LAYOUT_Orion_base(__VA_ARGS__)
 */
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



/* Qwerty
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | MUTE |     | spot |LOWER| Enter| Del |    |BckSpc| Space| RAISE| spot|         | MUTE |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |Mouse3|Mouse1|Mouse2| xxx | xxx |    |  xxx | xxx |Vol- | Mute | Vol+ |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_Orion(
  KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,    KC_0,         KC_0,         KC_0,         KC_0,            KC_0,
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                KC_MUTE,      KC_0          LOWER,        KC_ENT,       KC_DEL,       KC_BSPC, KC_SPC,       RAISE,        KC_0          KC_MUTE,
                KC_0          KC_0          KC_MS_BTN3,   KC_MS_BTN1,   KC_MS_BTN2,   KC_0,    KC_0,         KC_VOLD,      KC_MUTE,      KC_VOLU
),

/* Colemak
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | MUTE |     | spot |LOWER| Enter| Del |    |BckSpc| Space| RAISE| spot|         | MUTE |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |Mouse3|Mouse1|Mouse2| xxx | xxx |    |  xxx | xxx |Vol- | Mute | Vol+ |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_Orion(
  KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,    KC_0,         KC_0,         KC_0,         KC_0,            KC_0,
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                KC_MUTE,      KC_0          LOWER,        KC_ENT,       KC_DEL,       KC_BSPC, KC_SPC,       RAISE,        KC_0          KC_MUTE,
                KC_0          KC_0          KC_MS_BTN3,   KC_MS_BTN1,   KC_MS_BTN2,   KC_0,    KC_0,         KC_VOLD,      KC_MUTE,      KC_VOLU
),

/* Raise
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | MUTE |     | spot |LOWER| Enter| Del |    |BckSpc| Space| RAISE| spot|         | MUTE |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |Mouse3|Mouse1|Mouse2| xxx | xxx |    |  xxx | xxx |Vol- | Mute | Vol+ |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */
[_RAISE] = LAYOUT_Orion(
  KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,    KC_0,         KC_0,         KC_0,         KC_0,            KC_0,
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                KC_MUTE,      KC_0          LOWER,        KC_ENT,       KC_DEL,       KC_BSPC, KC_SPC,       RAISE,        KC_0          KC_MUTE,
                KC_0          KC_0          KC_MS_BTN3,   KC_MS_BTN1,   KC_MS_BTN2,   KC_0,    KC_0,         KC_VOLD,      KC_MUTE,      KC_VOLU
),

/* Lower
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | MUTE |     | spot |LOWER| Enter| Del |    |BckSpc| Space| RAISE| spot|         | MUTE |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |Mouse3|Mouse1|Mouse2| xxx | xxx |    |  xxx | xxx |Vol- | Mute | Vol+ |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */
[_LOWER] = LAYOUT_Orion(
  KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,    KC_0,         KC_0,         KC_0,         KC_0,            KC_0,
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                KC_MUTE,      KC_0          LOWER,        KC_ENT,       KC_DEL,       KC_BSPC, KC_SPC,       RAISE,        KC_0          KC_MUTE,
                KC_0          KC_0          KC_MS_BTN3,   KC_MS_BTN1,   KC_MS_BTN2,   KC_0,    KC_0,         KC_VOLD,      KC_MUTE,      KC_VOLU
),

/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | MUTE |     | spot |LOWER| Enter| Del |    |BckSpc| Space| RAISE| spot|         | MUTE |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |Mouse3|Mouse1|Mouse2| xxx | xxx |    |  xxx | xxx |Vol- | Mute | Vol+ |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */
[_ADJUST] =  LAYOUT_Orion(
  KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,         KC_0,    KC_0,         KC_0,         KC_0,         KC_0,            KC_0,
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                KC_MUTE,      KC_0          LOWER,        KC_ENT,       KC_DEL,       KC_BSPC, KC_SPC,       RAISE,        KC_0          KC_MUTE,
                KC_0          KC_0          KC_MS_BTN3,   KC_MS_BTN1,   KC_MS_BTN2,   KC_0,    KC_0,         KC_VOLD,      KC_MUTE,      KC_VOLU
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        default:
            break;
    }

    return true;
}
