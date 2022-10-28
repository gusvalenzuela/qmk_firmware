/* Copyright 2021 Mikael Manukyan <arm.localhost@gmail.com>
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

#define COMBO_COUNT 3
#define COMBO_TERM 150

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_DISABLE_TIMEOUT 1200000     // 20 minutes (20 * 60 * 1000ms)
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

#define MACRO_TIMER 5

#define TAPPING_TOGGLE 3

// TAP DANCE
// #define TAPPING_TERM 175
// #define TAPPING_TERM_PER_KEY

#define WPM_SMOOTHING 0.1

// this is for macOS so keyboard can work after sleep
#define NO_USB_STARTUP_CHECK


// #define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 3000  /* Time (in ms) before the one shot key is released */
