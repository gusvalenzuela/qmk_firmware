/* Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>,
    Mikael Manukyan <arm.localhost@gmail.com>
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
#include "guzilla.h"
#include "print.h"
#include "process_record.h"

uint16_t copy_paste_timer;

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) bool process_record_encoder(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) bool process_record_fun(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) void keyboard_post_init_encoder(void) {
    return;
}
static const char *git_commands[] = {
    "git init ", "git clone ", "git config --global ", "git add ", "git diff ", "git reset ", "git rebase ", "git branch -b \"", "git checkout ", "git merge ", "git remote add ", "git fetch ", "git pull ", "git push ", "git commit -m \"", "git status ", "git log ",
};
static const char *text_blocks[] = {
    "==============================","\\^_^/", "OneDrive/opt/qmk_firmware_prime", ".en", ".en.sdh", ".com", "https://", "localhost:", "gpupdate /force",
};
static const char *unicode_blocks[] = {
    "( ͡° ͜ʖ ͡°)",
    "ಠ_ಠ",
    "¯\\_(ツ)_/¯",
};

bool _isWinKeyDisabled = false;
bool _CaffeineStatus   = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef KEYLOGGER_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %b, time: %5u, int: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif // KEYLOGGER_ENABLE
    switch (keycode) {
        case KC_WLCK:
            if (record->event.pressed) {
                _isWinKeyDisabled = !_isWinKeyDisabled; // toggle status
                if (_isWinKeyDisabled) {
                    process_magic(GUI_OFF, record);
                } else {
                    process_magic(GUI_ON, record);
                }
            } else {
                unregister_code16(keycode);
            }
            break;

        case KC_CCCV ... KC_CZCY: // One key tap/hold
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    // HOLD
                    switch (keycode) {
                        case KC_CCCV:
                            tap_code16(LCTL(KC_C));
                            break;
                        case KC_CZCY:
                            tap_code16(LCTL(KC_Y));
                            break;
                        case KC_WDOT:
                            tap_code16(G(KC_DOT));
                            break;
                        case KC_CAFF:
                            // Stop Caffeine Status
                            copy_paste_timer = 0;
                            // _CaffeineStatus = false; // stops caffeine macro

                            break;
                    }
                } else {
                    // TAP
                    switch (keycode) {
                        case KC_CCCV:
                            tap_code16(LCTL(KC_V));
                            break;
                        case KC_CZCY:
                            tap_code16(LCTL(KC_Z));
                            break;
                        case KC_WDOT:
                            tap_code(KC_DOT);
                            break;
                        case KC_CAFF:
                            // Tap  every 3 sec until stopped
                            while (copy_paste_timer > 0) {
                                SEND_STRING("A" SS_DELAY(3000));
                                // _CaffeineStatus = true; // toggle status
                            }
                            unregister_code(keycode);

                            break;
                    }
                }
            }
            return false;
            break;

        case KC_EQDV ... KC_QTEX:
            if (record->event.pressed) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                send_string_with_delay(text_blocks[keycode - KC_EQDV], MACRO_TIMER);
                return false;
            }
            break;

        case UC_LENN ... UC_SHRG:
            if (record->event.pressed) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                send_unicode_string(unicode_blocks[keycode - UC_LENN]);
                return false;
            }
            break;

        case G_INIT ... G_LOG:
            if (record->event.pressed) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                send_string_with_delay(git_commands[keycode - G_INIT], MACRO_TIMER);
                return false;
            }
            break;
#ifdef RGB_MATRIX_ENABLE
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
                        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    case LED_FLAG_UNDERGLOW: {
                        // This line is for LED idle timer. It disables the toggle so you can turn
                        // off LED completely if you like
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable();
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable();
                    } break;
                }
            }
            return false;
#endif // RGB_MATRIX_ENABLE
    }

    return process_record_encoder(keycode, record) && process_record_secrets(keycode, record) && process_record_fun(keycode, record);
}

void keyboard_post_init_user() {
    keyboard_post_init_encoder();
}
