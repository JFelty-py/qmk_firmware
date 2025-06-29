/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// NOTE: All logic for the modules can be found in:
// keyboards/fingerpunch/src/vik/config.vik.pre.h
// keyboards/fingerpunch/src/vik/config.vik.post.h
// keyboards/fingerpunch/src/vik/rules.mk

#pragma once

#include "keyboards/fingerpunch/src/config_pre.h"

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6



// VIK pin config
#define VIK_SPI_DRIVER    SPID1
#define VIK_SPI_SCK_PIN   GP14
#define VIK_SPI_MOSI_PIN  GP15
#define VIK_SPI_MISO_PIN  GP12
#define VIK_SPI_CS        GP13
#define VIK_I2C_DRIVER    I2CD1
#define VIK_I2C_SDA_PIN   GP10
#define VIK_I2C_SCL_PIN   GP11
#ifdef FP_SVLINKY_V01
#define VIK_GPIO_1        GP18 // svlinky v0.1
#define VIK_GPIO_2        GP24 // svlinky v0.1
#else // svlinky v0.2
#define VIK_GPIO_1        GP26 // svlinky v0.2
#define VIK_GPIO_2        GP27 // svlinky v0.2
#endif
#define VIK_WS2812_DI_PIN GP16

// Used only if you have a display with RESET unconnected, set to unused pin
//#define VIK_DISPLAY_RST_UNUSED_PIN GP13

// All the through hole pins from the controller
#ifdef FP_SVLINKY_V01
#define MATRIX_ROW_PINS { GP29, GP28, GP27, GP26, GP22, GP20, GP23, GP21 } // svlinky v0.1
#else
#define MATRIX_ROW_PINS { GP6, GP7, GP8, GP9, GP21, GP23  } // svlinky v0.2
#endif
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP4, GP5 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { GP29 }
#define ENCODERS_PAD_B { GP28 }

// For VIK modules with encoders
/*
#ifdef ENCODER_ENABLE
#ifdef FP_SVLINKY_V01
#define ENCODERS_PAD_A { GP18 } // svlinky v0.1
#define ENCODERS_PAD_B { GP24 } // svlinky v0.1
#else
#define ENCODERS_PAD_A { GP26 } // svlinky v0.2
#define ENCODERS_PAD_B { GP27 } // svlinky v0.2
#endif
#endif
*/


//### Review this
// Got help from https://www.eisbahn.jp/yoichiro/2022/08/luankey_pico_qmk_firmware.html
#define MASTER_LEFT
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_POINTING_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_HAPTIC_ENABLE
#define SERIAL_PIO_USE_PIO1
#define SERIAL_USART_HALF_DUPLEX   // Enable half duplex operation mode.
#define SERIAL_USART_TX_PIN GP20     // USART TX pin


#ifdef CIRQUE_ENABLE
    // cirque trackpad config
    // This is for I2C only, which is not the default
    #define CIRQUE_PINNACLE_ADDR 0x2A
    // This is for SPI only, which is the default
    #define CIRQUE_PINNACLE_SPI_CS_PIN GP13
    
    // Uncomment 2 lines below to switch to relative mode and enable right click
    // Note that tap to click doesn't work on the slave side unless you enable relative mode
    // #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
    // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
    #define CIRQUE_PINNACLE_TAP_ENABLE
    #define POINTING_DEVICE_TASK_THROTTLE_MS 5
#endif

#ifdef FP_TRACKBALL_ENABLE
    // Trackball config
    #define PMW33XX_CS_PIN GP9
    #define PMW33XX_CPI 1000
    #define PMW33XX_CS_DIVISOR 8
#endif

// All the possible configurations of pointing devices
#if defined(FP_TRACKBALL_BOTH)
    #define POINTING_DEVICE_COMBINED            // two pointing devices
    #define POINTING_DEVICE_INVERT_Y            // for trackball on the left
    #define POINTING_DEVICE_INVERT_X_RIGHT      // for trackball on the right
#endif
#if defined(FP_CIRQUE_BOTH)
    #define POINTING_DEVICE_COMBINED            // two pointing devices
    #define POINTING_DEVICE_ROTATION_90         // for cirque on the left
    #define POINTING_DEVICE_ROTATION_90_RIGHT   // for cirque on the right
#endif
#if defined(FP_TRACKBALL_LEFT_ONLY)
    #define POINTING_DEVICE_LEFT                // one pointing device, on the left
    #define POINTING_DEVICE_INVERT_Y            // for trackball on the left
#endif
#if defined(FP_TRACKBALL_RIGHT_ONLY)
    #define POINTING_DEVICE_RIGHT               // one pointing device, on the right
    #define POINTING_DEVICE_INVERT_X_RIGHT      // for trackball on the right
#endif
#if defined(FP_CIRQUE_LEFT_ONLY)
    #define POINTING_DEVICE_LEFT                // one pointing device, on the left
    #define POINTING_DEVICE_ROTATION_90         // for cirque on the left
#endif
#if defined(FP_CIRQUE_RIGHT_ONLY)
    #define POINTING_DEVICE_RIGHT               // one pointing device, on the right
    #define POINTING_DEVICE_ROTATION_90_RIGHT   // for cirque on the right
#endif
#if defined(FP_TRACKBALL_LEFT_CIRQUE_RIGHT)
    #define POINTING_DEVICE_COMBINED            // two pointing devices
    #define POINTING_DEVICE_INVERT_Y            // for trackball on the left
    #define POINTING_DEVICE_ROTATION_90_RIGHT   // for cirque on the right

#endif
#if defined(FP_CIRQUE_LEFT_TRACKBALL_RIGHT)
    #define POINTING_DEVICE_COMBINED            // two pointing devices
    #define POINTING_DEVICE_ROTATION_90         // for cirque on the left
    #define POINTING_DEVICE_INVERT_X_RIGHT      // for trackball on the right
#endif



#define WS2812_DI_PIN GP22
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_SPLIT
    #define RGBLED_SPLIT { 28, 28 }
    #define RGBLIGHT_LED_COUNT 56
    #define RGBLIGHT_HUE_STEP 16
    #define RGBLIGHT_SAT_STEP 16
    #define RGBLIGHT_VAL_STEP 16
    #define RGBLIGHT_LIMIT_VAL 130 /* The maximum brightness level for RGBLIGHT_ENABLE */
    #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_TWINKLE
#endif

#ifdef RGB_MATRIX_ENABLE
    #define SPLIT_TRANSPORT_MIRROR
    #define RGB_MATRIX_LED_COUNT 56 // Number of LEDs
    #define RGB_MATRIX_SPLIT { 28, 28 }
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 130
    #define RGB_MATRIX_STARTUP_HUE 35
    #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_SLEEP
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYREACTIVE_ENABLED
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_BAND_SAT
    #define ENABLE_RGB_MATRIX_BAND_VAL
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define ENABLE_RGB_MATRIX_SPLASH
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#include "keyboards/fingerpunch/src/config_post.h"
