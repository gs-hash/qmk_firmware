/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

// Enabling this option changes the startup behavior to listen for an
// active USB communication to delegate which part is master and which
// is slave. With this option enabled and theres’s USB communication,
// then that half assumes it is the master, otherwise it assumes it
// is the slave.
//
// I've found this helps with some ProMicros where the slave does not boot
#define SPLIT_USB_DETECT

#define RGB_MATRIX_SLEEP       // turn off effects when suspended
#define SPLIT_TRANSPORT_MIRROR // If LED_MATRIX_KEYPRESSES or LED_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
// --- RGB MATRIX ---
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs (max 255). Higher may cause the controller to crash.
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_STARTUP_VAL 60

#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_WHEN_USB_SUSPENDED

// --- Layer-Tap ---
#define TAPPING_TERM 250
#define PERMISSIVE_HOLD
// #define HOLD_ON_OTHER_KEY_PRESS
#define COMBO_TERM 60
#define COMBO_ONLY_FROM_LAYER 0

// Wyłącz animacje
#define RGB_MATRIX_EFFECTS
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT

// wyłącz WSZYSTKO co się da
// #define DISABLE_RGB_MATRIX_ALPHAS_MODS
// #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #define DISABLE_RGB_MATRIX_BREATHING
// #define DISABLE_RGB_MATRIX_BAND_SAT
// #define DISABLE_RGB_MATRIX_BAND_VAL
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define DISABLE_RGB_MATRIX_CYCLE_ALL
// #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define DISABLE_RGB_MATRIX_PIXEL_RAIN
// #define DISABLE_RGB_MATRIX_PIXEL_FLOW
// #define DISABLE_RGB_MATRIX_PIXEL_FRACTAL
