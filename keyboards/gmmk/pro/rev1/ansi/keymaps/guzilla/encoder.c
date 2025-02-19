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
#include "encoder.h"
#include "guzilla.h"
#include "print.h"
#include "utils.h"
#include "process_record.h"
#include "rgb_matrix_ledmaps.h"

static uint8_t state = ENCODER_DEFAULT;

// clang-format off
const encoder_callback encoder_mapping[][2] = {
    [ENCODER_VOLUME] = {&volume_up, &volume_down},
    [ENCODER_NAVIGATION] = {&page_up, &page_down},
#ifdef RGB_MATRIX_ENABLE
    [ENCODER_RGB_HUE] = {&rgb_matrix_increase_hue_noeeprom, &rgb_matrix_decrease_hue_noeeprom},
    [ENCODER_RGB_SAT] = {&rgb_matrix_increase_sat_noeeprom, &rgb_matrix_decrease_sat_noeeprom},
    [ENCODER_RGB_VAL] = {&rgb_matrix_increase_val_noeeprom, &rgb_matrix_decrease_val_noeeprom},
    [ENCODER_RGB_EFFECT] = {&rgb_matrix_step_noeeprom, &rgb_matrix_step_reverse_noeeprom},
    [ENCODER_RGB_EFFECT_SPEED] = {&rgb_matrix_increase_speed_noeeprom, &rgb_matrix_decrease_speed_noeeprom},
#endif // RGB_MATRIX_ENABLE
};

// clang-format on

void volume_up() {
    tap_code(KC_VOLU);
}

void volume_down() {
    tap_code(KC_VOLD);
}

void page_up() {
    tap_code(KC_PGUP);
}

void page_down() {
    tap_code(KC_PGDN);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    dprintf("current encoder state is: %d\n", state);

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case SHORTCUTS:
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
            break;
        default:
            if (clockwise) {
                (*encoder_mapping[state][0])();
            } else {
                (*encoder_mapping[state][1])();
            }
    }

    return false;
}

void handle_rgb_key(bool pressed) {
    dprintf("handle_rgb_key %d\f", pressed);

    if (pressed) {
        rgb_matrix_layers_disable();
    } else {
        rgb_matrix_layers_enable();
    }
}

static KeyPressState *rgb_state;

void keyboard_post_init_encoder() {
    rgb_state = NewKeyPressState(handle_rgb_key);
}

bool process_record_encoder(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef RGB_MATRIX_ENABLE
        case KC_RGB_ENC_HUE ... KC_RGB_ENC_EFFECT:
            if (record->event.pressed) {
#    ifdef RGB_MATRIX_LEDMAPS_ENABLED
                // disable layers so we can adjust RGB effects
                rgb_state->press(rgb_state);
#    endif // RGB_MATRIX_LEDMAPS_ENABLED

                switch (keycode) {
                    case KC_RGB_ENC_HUE:
                        state = ENCODER_RGB_HUE;
                        break;
                    case KC_RGB_ENC_SAT:
                        state = ENCODER_RGB_SAT;
                        break;
                    case KC_RGB_ENC_VAL:
                        state = ENCODER_RGB_VAL;
                        break;
                    case KC_RGB_ENC_EFFECT_SPEED:
                        state = ENCODER_RGB_EFFECT_SPEED;
                        break;
                    case KC_RGB_ENC_EFFECT:
                        state = ENCODER_RGB_EFFECT;
                        break;
                }
            } else {
#    ifdef RGB_MATRIX_LEDMAPS_ENABLED
                rgb_state->release(rgb_state);
#    endif // RGB_MATRIX_LEDMAPS_ENABLED
                state = ENCODER_DEFAULT;
                store_rgb_state_to_eeprom();
            }
            break;
#endif // RGB_MATRIX_ENABLE

            return false;
    }

    return true;
}
