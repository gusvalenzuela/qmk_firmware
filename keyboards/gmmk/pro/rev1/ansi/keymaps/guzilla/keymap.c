/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>, Mikael Manukyan <arm.localhost@gmail.com>
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

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM sec_combo[] = {OS_SEC, TT_FN, COMBO_END};
const uint16_t PROGMEM lg_combo[] = {KC_LCTL, KC_LGUI, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
    [SEC_TT] = COMBO(sec_combo, RCS(KC_ESC)), // Task Manager
    [LG_SNAP] = COMBO(lg_combo, SWIN(KC_S)) // windows snapshot menu
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right
     [_BASE] = LAYOUT(
         KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_DEL,           KC_MUTE,
         KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,          KC_PSCR,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,          KC_CCCV,
          MO_FN,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,           KC_ENT,          KC_HOME,
        KC_LSPO,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,          KC_RSPC,   KC_UP,  KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                              OS_SEC,   TT_FN, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MACOS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, KC_LALT, KC_LGUI,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [_FN1] = LAYOUT(
        TT_DSBL, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, KC_MPLY,          _______,
        _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______, KC_EQDV, _______,          KC_SNAP,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_RST,          _______,
        _______, _______, KC_SCRL, _______, C(KC_F), _______, _______, _______, _______, _______, _______, _______,          _______,          KC_PGUP,
        _______,          _______, _______, KC_CALC, _______, _______, KC_NLCK,  KC_MAC, _______, _______, _______,          KC_CAPS, _______, KC_PGDN,
        _______, KC_WLCK, _______,                            _______,                            _______, _______, _______, KC_SWNL, _______, KC_SWNR
    ),

   [NO_KEYS] = LAYOUT(
        _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          _______,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
        _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,            KC_NO,
          KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,
          KC_NO,   KC_NO,   KC_NO,                              KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

    [FUNCTIONS] = LAYOUT(
        _______, KC_RGBH, KC_RGBS, KC_RGBV, KC_RGBE, KC_RGBP, KC_WRGB, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,  KC_CAD,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
          KC_NO, _______, RGB_VAD, _______, _______,  OS_GIT, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            RGB_TOG,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [GIT] = LAYOUT(
        _______,   MI_ON,  MI_OFF,  MI_TOG, _______,  MI_C_3, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,  G_DIFF, _______, _______, _______, _______, _______, _______,  G_PULL,  G_PUSH, _______, _______,          _______,
        _______,   G_ADD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, G_CHECK, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [SECRETS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_SEC1, _______, _______, _______, _______, _______, _______, KC_SEC5, KC_SEC4, _______, _______, _______,          _______,
        _______, _______, KC_SEC2, _______, _______, KC_SEC3, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
};

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

#define ______ {0, 0, 0}

const ledmap PROGMEM ledmaps[] = {
         //  LU = Left Underglow, RU = Right Underglow
         //  LU_1    ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)  RU_1
         //  LU_2    ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del       RU_2
         //  LU_3    Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp         RU_3
         //  LU_4    Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn         RU_4
         //  LU_5    Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End          RU_5
         //  LU_6    Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right        RU_6
    [_BASE] = RGB_MATRIX_LAYOUT_LEDMAP(
        GREEN,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GREEN,
        GREEN,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GREEN,
        GREEN,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GREEN,
        GREEN,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ______,    GREEN,
        GREEN,    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    GREEN,
        GREEN,    ______, ______, ______,                         ______,                           BLUE,   CYAN, ______, ______, ______, ______,    GREEN
    ),
    [MACOS] = RGB_MATRIX_LAYOUT_LEDMAP(
         BLUE,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    BLUE,
         BLUE,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    BLUE,
         BLUE,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    BLUE,
         BLUE,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ______,    BLUE,
         BLUE,    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    BLUE,
         BLUE,    ______, ______,    RED,                         ______,                         ______, ______, ______, ______, ______, ______,    BLUE
    ),
    [_FN1] = RGB_MATRIX_LAYOUT_LEDMAP(
        YELLOW,       RED, ______, ______, ______, ______, ______, ______, ______, ______, YELLOW, YELLOW, ______, ______,  GREEN,         ______,    YELLOW,
        YELLOW,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,   GOLD, ______,         MAGENT,    YELLOW,
        YELLOW,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    YELLOW,
        YELLOW,    ______, ______,    RED, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,           PINK,    YELLOW,
        YELLOW,    ______,         ______, ______, SPRING, ______, ______,    RED, SPRING, ______, ______, ______,            RED, SPRING,   PINK,    YELLOW,
        YELLOW,    ______,    RED, ______,                         ______,                         ______, ______, ______, SPRING, SPRING, SPRING,    YELLOW
    ),
    [NO_KEYS] = RGB_MATRIX_LAYOUT_LEDMAP(
           RED,       RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,      RED,
           RED,       RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,      RED,
           RED,       RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,      RED,
           RED,       RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,            RED,      RED,
           RED,       RED,            RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,    RED,    RED,      RED,
           RED,       RED,    RED,    RED,                            RED,                            RED,    RED,    RED,    RED,    RED,    RED,      RED
    ),

    [FUNCTIONS] = RGB_MATRIX_LAYOUT_LEDMAP(
          CYAN,   ______,  TEAL,   TEAL,   TEAL, SPRING, SPRING,  CHART, ______, ______, ______,  GREEN,  GREEN,  GREEN,     RED,         ______,    CYAN,
          CYAN,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    CYAN,
          CYAN,   ______, ______,   GOLD, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    CYAN,
          CYAN,   ______, ______,   GOLD, ______, ______,   TURQ, ______, ______, ______, ______, ______, ______,         ______,         ______,    CYAN,
          CYAN,   ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,   CYAN, ______,    CYAN,
          CYAN,   ______, ______, ______,                           TURQ,                         ______, ______, ______,   CYAN,   CYAN,   CYAN,    CYAN
    ),
    [SECRETS] = RGB_MATRIX_LAYOUT_LEDMAP(
         GOLD,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GOLD,
         GOLD,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GOLD,
         GOLD,    ______, ______,   GOLD, ______, ______, ______, ______, ______, ______,   GOLD,   GOLD,   GOLD, ______, ______,         ______,    GOLD,
         GOLD,    ______, ______,   GOLD, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ______,    GOLD,
         GOLD,    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    GOLD,
         GOLD,    ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,    GOLD
    ),
    [GIT] = RGB_MATRIX_LAYOUT_LEDMAP(
        GOLD,     ______,    RED,    RED,    RED, ______,  GREEN, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GOLD,
         GOLD,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GOLD,
         GOLD,    ______, ______, ______,   GOLD, ______, ______, ______, ______, ______, ______,   GOLD,   GOLD, ______, ______,         ______,    GOLD,
         GOLD,    ______,   GOLD, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ______,    GOLD,
         GOLD,    ______,         ______, ______,   GOLD, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    GOLD,
         GOLD,    ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,    GOLD
    ),
};

#endif // RGB_MATRIX_LEDMAPS_ENABLED
// clang-format on
