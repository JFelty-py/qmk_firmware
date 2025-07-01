#include QMK_KEYBOARD_H

//Advanced Tap Dance
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    G_LBRK,
    H_RBRK,
    SOME_OTHER_DANCE
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the g tap dance. Put it here so it can be used in any keymap
void g_finished(tap_dance_state_t *state, void *user_data);
void g_reset(tap_dance_state_t *state, void *user_data);

// For the h tap dance. Put it here so it can be used in any keymap
void h_finished(tap_dance_state_t *state, void *user_data);
void h_reset(tap_dance_state_t *state, void *user_data);

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
    _GAMER,
    _PROG,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    GAMER,
    PROG,
    LOWER,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



/* Qwerty
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |   -  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | `(H) |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  | \(M) |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |ctsft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | MUTE |     |LOWER| Ctrl |BckSpc|Space|    | Enter| Shft | Alt  |RAISE|         | SShot|
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |^rec1 |<rec2|vply1|>ply2 |pMac S|    |Pwin  |>end |vpdn |<home |^pup  |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_Orion(
  KC_ESC,         KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,   KC_F7,        KC_F8,        KC_F9,        KC_F10,          KC_MINS,
  HYPR_T(KC_GRV), KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            MEH_T(KC_BSLS),
  KC_TAB,         LCTL_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,         KC_H,    RGUI_T(KC_J), RALT_T(KC_K), RSFT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  C(KC_LSFT),     KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                  KC_MUTE,      LOWER,        SC_LCPO,      KC_BSPC,      KC_SPC,       KC_ENT,  KC_RSFT,      SC_RAPC,      RAISE,        RSG(KC_S),
                  DM_REC1,      DM_REC2,      DM_PLY1,      DM_PLY2,      DM_RSTP,      KC_LWIN, KC_END,       KC_PGDN,      KC_HOME,      KC_PGUP
),

/* GAMER
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   10 |   -  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  sft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | LLOK |     |LOWER| Ctrl |BckSpc|Space|    | Enter| Shft | Alt  |RAISE|         | SShot|
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |^     |<    |v    |>     |pALT  |    |PSNIPE|>end |vpdn |<home |^pup  |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */

[_GAMER] = LAYOUT_Orion(
  KC_ESC,       KC_1,         KC_F,         KC_3,         KC_4,         KC_5,         KC_6,    KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,
  KC_GRV,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,         KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                QK_LLCK,      LOWER,        KC_LCTL,      KC_BSPC,      KC_SPC,       KC_ENT,  KC_RSFT,      KC_RALT,      RAISE,        RSG(KC_S),
                KC_UP,        KC_LEFT,      KC_DOWN,      KC_RIGHT,     KC_RALT, FP_SNIPE_TOG, KC_END,       KC_PGDN,      KC_HOME,      KC_PGUP
),

/* Raise
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |PAUSE | MUTE |VDown | VUP  | PREV | NEXT |           | BRID | BRIU | MAIL | CALC | MYCP | CTPL |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           | PTSC | INS  | DEL  |      |      |  \   |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |   !  |  @   |  #   |  $   |  %   |           |   ^  |   &  |  *   |  (   |  )   |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |  {   |   [  |   (  |   <  |           |   >  |   )  |   ]  |  }   |      |      |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | LLOCK|     |LOWER| Ctrl |BckSpc|Space|    | Enter| Shft | Alt  |RAISE|         | LEAD |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |^rec1 |<rec2|vply1|>ply2 |pMac S|    |PMCTL |>ASST|vpdn |<home |^pup  |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */

// Symbols Layer
[_RAISE] = LAYOUT_Orion(
  KC_MPLY,      KC_MUTE,      KC_VOLD,      KC_VOLU,      KC_MPRV,      KC_MNXT,      KC_BRID, KC_BRIU,      KC_MAIL,      KC_CALC,      KC_MYCM,         KC_CPNL,
  ______,       ______,       ______,       ______,       ______,       ______,       KCPSCR,  KC_INS,       KC_DEL,       ______,       ______,          KC_BSLS,
  ______,       KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,      KC_CIRC, KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,         ______,
  ______,       ______,       KC_LCBR,      KC_LBRC,      KC_LPRN,      KC_LT,        KC_GT,   KC_RPRN,      KC_RBRC,      KC_RCBR,      ______,          ______,  
                QK_LLCK,      LOWER,        SC_LCPO,      KC_BSPC,      KC_SPC,       KC_ENT,  KC_RSFT,      SC_RAPC,      RAISE,        QK_LEAD,
                DM_REC1,      DM_REC2,      DM_PLY1,      DM_PLY2,      DM_RSTP,    G(KC_TAB), KC_ASST,      KC_PGDN,      KC_HOME,      KC_PGUP
),

/* Lower
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |      |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |SCRLFT|   ^  |SCRRIT|SCRUP |           |   *  |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |  SFT |   <  |   v  |   >  |SCRDN |           |   /  |   4  |   5  |   6  | CTSFT|  ALT |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |ctsft |      |      |      |      |      |           |   +  |   1  |   2  |   3  |      | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | LLOCK|     |LOWER| PROG |BckSpc|Space|    |   =  |  -  |   0   |RAISE|         |      |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |^ MB5 |<MB1 |vMB4 |>MB2  |p MB3 |    |PMCTL |>ASST|vpdn |<home |^pup  |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */
// Number Pad Layer with directions
[_LOWER] = LAYOUT_Orion(
  KC_ESC,       ______,       ______,       ______,       ______,       ______,       ______,  ______,       ______,       ______,       ______,         ______,
  ______,       ______,       MS_WHLL,      KC_UP,        MS_WHLR,      MS_WHLU,      KC_PAST, KC_7,         KC_8,         KC_9,         ______,         ______,
  KC_TAB,       KC_LSFT,      KC_LEFT,      KC_DOWN,      KC_RGHT,      MS_WHLD,      KC_SLSH, KC_4,         KC_5,         KC_6,         C(KC_LSFT),     KC_RALT,
  C(KC_LSFT),   ______,       ______,       ______,       ______,       ______,       KC_PPLS, KC_1,         KC_2,         KC_3,         ______,         KC_RCTL,
                QK_LLCK,      LOWER,        PROG,         KC_BSPC,      KC_SPC,       KC_EQL,  KC_MINS,      KC_0,         RAISE,        ______,
                MS_BTN5,      MS_BTN1,      MS_BTN4,      MS_BTN2,      MS_BTN3,    G(KC_TAB), KC_ASST,      KC_PGDN,      KC_HOME,      KC_PGUP
),

/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |SATDN |SARUP |HUEDN |HUEUP |      |LEDTOG|           |      |      |      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |SPDDN |SPDUP |BRIDN |BRIUP |ANIPRV|ANINEX|           | ACEL | DPIUP|      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           | ZOOM | DPIDN|      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |AUTO C|      |      |      |      |      |           |      |      |      |      |      |      |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | LLOCK|     | LOW |      |      |     |    |GAME  |      |      |RAISE|         | BOOT |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |^DTUP |<    |vDTDN|>     |pDTPNT|    |PMCTL |>    |v    |<     |^     |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */

[_ADJUST] = LAYOUT_Orion(
  RM_SATD,      RM_SATU,      RM_HUED,      RM_HUEU,      ______,       RM_TOGG,      ______,  ______,          ______,       ______,       ______,          ______,
  RM_SPDD,      RM_SPDU,      RM_BRID,      RM_VALU,      RM_PREV,      RM_NEXT, FP_ACCEL_TOG, FP_POINT_DPI_UP, ______,       ______,       ______,          ______,
  ______,       ______,       ______,       ______,       ______,       ______,   FP_ZOOM_TOG, FP_POINT_DPI_DN, ______,       ______,       ______,          ______,
  AC_TOGG,      ______,       ______,       ______,       ______,       ______,       ______,  ______,          ______,       ______,       ______,          ______,
                QK_LLCK,      LOWER,        ______,       ______,       ______,       GAME,    ______,          ______,       RAISE,        QK_BOOT,
                DT_UP,        ______,       DT_DOWN,      ______,       DT_PRNT,    G(KC_TAB), KC_ASST,         ______,       ______,       ______
)
};

/* PROG - This is a blank layer that can be used to create custom keymaps
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |      |      |      |      |      |      |           |  PG1 |  PG2 |  PG3 |  PG4 |  PG5 |  PG6 |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |  PG7 |  PG8 |  PG9 | PG10 | PG11 | PG12 |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      | CTL  | SFT  | ALT  | GUI  |      |           | PG13 | PG14 | PG15 | PG16 | PG17 | PG18 |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           | PG19 | PG20 | PG21 | PG22 | PG23 | PG24 |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        | LLOCK|     |     | PROG |      |     |    | PG25 | PG26 | PG27 | PG28|         |      |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |^     |<    |v    |>     |p     |    |P     |>    |v    |<     |^     |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 */

[_PROG] = LAYOUT_Orion(
  ______,       ______,       ______,       ______,       ______,       ______,       PB_1,    PB_2,         PB_3,         PB_4,         PB_5,            PB_6,  
  ______,       ______,       ______,       ______,       ______,       ______,       PB_7,    PB_8,         PB_9,         PB_10,        PB_11,           PB_12, 
  ______,       KC_LCTL,      KC_LSFT,      KC_LALT,      KC_LGUI,      ______,       PB_13,   PB_14,        PB_15,        PB_16,        PB_17,           PB_18, 
  ______,       ______,       ______,       ______,       ______,       ______,       PB_19,   PB_20,        PB_21,        PB_22,        PB_23,           PB_24, 
                QK_LLCK,      ______,       PROG,         ______,       ______,       PB_25,   PB_26,        PB_27,        PB_28,        ______,
                ______,       ______,       ______,       ______,       ______,       ______,  ______,       ______,       ______,       ______
)
};

/* BLANK - This is a blank layer that can be used to create custom keymaps
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.     ,-------------------------.    ,--------------------------.         ,------.
 *        |      |     |     |      |      |     |    |      |      |      |     |         |      |
 *        `------'     `-------------------------'    `--------------------------.         `------'
 *              ,--------------------------------.    ,--------------------------------.
 *              |^     |<    |v    |>     |p     |    |P     |>    |v    |<     |^     |    // 5 way hat switch
 *              `--------------------------------'    `--------------------------------.
 

[_BLANK] = LAYOUT_Orion(
  ______,       ______,       ______,       ______,       ______,       ______,       ______,  ______,       ______,       ______,       ______,          ______,
  ______,       ______,       ______,       ______,       ______,       ______,       ______,  ______,       ______,       ______,       ______,          ______,
  ______,       ______,       ______,       ______,       ______,       ______,       ______,  ______,       ______,       ______,       ______,          ______,
  ______,       ______,       ______,       ______,       ______,       ______,       ______,  ______,       ______,       ______,       ______,          ______,
                ______,       ______,       ______,       ______,       ______,       ______,  ______,       ______,       ______,       ______,
                ______,       ______,       ______,       ______,       ______,       ______,  ______,       ______,       ______,       ______
)
};
*/



//Combos
enum combo_events {
    LS_PROG,
    LS_GAME,
};

const uint16_t PROGMEM prog_combo[] = {KC_P, KC_R, KC_O, KC_G, COMBO_END};
const uint16_t PROGMEM game_combo[] = {KC_G, KC_A, KC_M, KC_E, COMBO_END};

combo_t key_combos[] = {
    [LS_PROG] = COMBO_ACTION(prog_combo),
    [LS_GAME] = COMBO_ACTION(game_combo),
};

void process_combo_event(unit16_t combo_index, bool pressed) {
    switch (combo_index) {
        case LS_PROG:
            if (pressed) {
                layer_on(_PROG);
                tap_code16(QL_LLCK); // Lock the layer
            } 
            break;
        case LS_GAME:
            if (pressed) {
                layer_on(_GAMER);
                tap_code16(QL_LLCK); // Lock the layer
            }
            break;
    }
}
// COMBO BREAKER!!!


//Set number of taps to toggle a layer instead of hold
#define TAPPING_TOGGLE 2



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
};


//Encoder Logic
// Uncomment the following lines to use custom 
/*
bool encoder_update_user(uint8_t index, bool clockwise) {
    // Your encoder logic goes here
    #define ENCODER_MAP_ENABLE

    #if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
        [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
        [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
        [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    };
    #endif
    // return false to avoid processing the encoder_update_kb() function that fingerpunch uses
    return false;
}
*/

// Key Overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t insert_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ENT, KC_PGUP);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override
    &insert_key_override
};



// Tap Dance Definitions
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicative that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currently not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustrating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'g' tap dance.
static td_tap_t gtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void g_finished(tap_dance_state_t *state, void *user_data) {
    gtap_state.state = cur_dance(state);
    switch (gtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_G); break;
        case TD_SINGLE_HOLD: register_code(KC_LPRN); break;
        case TD_DOUBLE_TAP: register_code(KC_LBRC); break;
        case TD_DOUBLE_HOLD: register_code(KC_LCBR); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_G); register_code(KC_G); break;
        default: break;
    }
}

void g_reset(tap_dance_state_t *state, void *user_data) {
    switch (gtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_G); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LPRN); break;
        case TD_DOUBLE_TAP: unregister_code(KC_LBRC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LCBR); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_G); break;
        default: break;
    }
    gtap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [G_LBRK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, g_finished, g_reset)
};

// Create an instance of 'td_tap_t' for the 'h' tap dance.
static td_tap_t htap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void h_finished(tap_dance_state_t *state, void *user_data) {
    htap_state.state = cur_dance(state);
    switch (htap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_H); break;
        case TD_SINGLE_HOLD: register_code(KC_RPRN); break;
        case TD_DOUBLE_TAP: register_code(KC_RBRC); break;
        case TD_DOUBLE_HOLD: register_code(KC_RCBR); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_H); register_code(KC_H); break;
        default: break;
    }
}

void h_reset(tap_dance_state_t *state, void *user_data) {
    switch (htap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_H); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RPRN); break;
        case TD_DOUBLE_TAP: unregister_code(KC_RBRC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_RCBR); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_H); break;
        default: break;
    }
    htap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [H_LBRK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, h_finished, h_reset)
};

//Leader Key
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_H)) {
        // Leader, h => Types the below string
        SEND_STRING("Please submit a ticket at https://educationisfreedom.atlassian.net/servicedesk/customer/portals or email support@educationisfreedom.atlassian.net");
    } else if (leader_sequence_two_keys(KC_S)) {
        // Leader, s => Types the below string
        SEND_STRING("Please contact Sannaptx for assistance. Email: support@sanapptx.com Phone: 1-972-591-0151");
    }
}