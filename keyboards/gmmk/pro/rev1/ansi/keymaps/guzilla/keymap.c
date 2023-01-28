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

// TAP DANCE FUNCTIONS //

void td_pscr_fn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (!state->pressed) {
            tap_code16(A(KC_PSCR));
        } else {
            tap_code16(SGUI(KC_S));
        }
    } else if (state->count == 2) {
        tap_code(KC_PSCR);
    } else {
        reset_tap_dance(state);
    }
};

void td_media_fn(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_MPLY);
    } else if (state->count == 2) {
        tap_code(KC_MNXT);
    } else if (state->count == 3) {
        tap_code(KC_MPRV);
    } else {
        reset_tap_dance(state);
    }
};

// TAP DANCE ACTIONS //

qk_tap_dance_action_t tap_dance_actions[] = {
    [PSCR_SNAP] = ACTION_TAP_DANCE_FN(td_pscr_fn),
    [MEDIA_TD] = ACTION_TAP_DANCE_FN(td_media_fn),
    [RSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS)
};

// C O M B O S //

const uint16_t PROGMEM jk_combo[]    = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM fnl_combo[]   = {MO_FKEY, KC_L, COMBO_END};
const uint16_t PROGMEM sec_combo[]   = {OS_SEC, MO_FKEY, COMBO_END};
const uint16_t PROGMEM lcgui_combo[] = {KC_LCTL, KC_LGUI, COMBO_END};
const uint16_t PROGMEM lgui_alt_b_combo[] = {KC_LALT, KC_LGUI, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [JK_ESC]         = COMBO(jk_combo, KC_ESC),
    [FNL_TOGFNLAYER] = COMBO(fnl_combo, TG(FN_KEYS)), // FN + L = Toggle FN Layer
    [SEC_TT]         = COMBO(sec_combo, RCS(KC_ESC)), // Task Manager
    [LG_SNAP]        = COMBO(lcgui_combo, SWIN(KC_S)) // windows snapshot menu
    [LALT_GUI_HDR]        = COMBO(lgui_alt_b_combo, LAG(KC_B)) // toggle HDR for windows
};

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 300;
        default:
            return TAPPING_TERM;
    }
}

const uint32_t PROGMEM unicode_map[] = {
    [INDEX_UP]     = 0x261D, // 👆
    [THUMB_UP]     = 0x1F44D, // 👍
    [INDEX_DOWN]   = 0x261F, // 👇
    [THUMB_DOWN]   = 0x1F44E, // 👎
    [THINK_FACE]   = 0x1F914, // 🤔
    [FACE_TEARS]   = 0x1F602, // 😂
    [ROFL_FACE]    = 0x1F923, // 🤣
    [PERSON_SHRUG] = 0x1F937, // 🤷‍♂️
    [RED_HEART]    = 0x2764,  // ❤
    [HEART_EYES]   = 0x1F60D, // 😍
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
         KC_ESC, TD_PLAY,   KC_F2, KC_CCCV,   KC_F4,   KC_F5,   KC_F6,  TT_RGB, TD_SNAP, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,  KC_DEL,          KC_MUTE,
         KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,          OS_LOCK,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,          OS_UNIC,
        MO_SCUT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, MO_QUOT,           KC_ENT,           OS_GIT,
        OS_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_WDOT, KC_SLSH,          TD_CAPS,   KC_UP, KC_CCCV,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                              OS_SEC, MO_FKEY, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MACOS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, KC_LALT, KC_LGUI,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [FN_KEYS] = LAYOUT(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_END,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_PGUP,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_PGDN,
        _______, _______, _______,                            _______,                            _______, _______, OS_LOCK, _______, _______, _______
    ),

    [LOCK] = LAYOUT(
        TT_DSBL, _______, _______, _______, _______, _______, _______,  DF_WIN, _______, _______, _______, _______, _______,  KC_CAD,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, OS_TOGG, _______, _______, _______, _______,          _______,
        _______, _______, KC_SCRL, _______, _______, _______, _______, _______, _______, G(KC_L), _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, KC_NLCK,  DF_MAC, _______, _______, _______,          KC_CAPS, _______, _______,
        _______, KC_WLCK, _______,                            _______,                            _______,   DF_FN, _______, _______, _______, _______
    ),

    [SHORTCUTS] = LAYOUT(
        TT_DSBL, DM_PLY1, DM_PLY2, _______,A(KC_F4), _______, _______, _______, KC_SNAP, _______, _______, _______, _______,  KC_INS,          TD_PLAY,
        _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______, _______, _______,          _______,
        _______, _______, _______, C(KC_Z), C(KC_Y), _______, _______, _______, _______, _______, _______, _______, _______,  KC_RST,          G(KC_V),
        _______, _______, C(KC_S), KC_SWNL, C(KC_F), _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, KC_CALC, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [TEXT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EQDV, _______,          _______,
        _______, KC_QTEX, KC_SEC1, _______, _______, _______, _______, _______, _______, KC_SEC4, KC_SEC6, _______, _______, _______,          _______,
        _______, _______, KC_SEC2, _______, _______, KC_SEC3, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [UNIC_LAYER] = LAYOUT(
        _______, UC_M_WC, UC_M_LN, UC_M_MA, _______, _______, _______, X_HEART, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
         UC_MOD, _______, _______, _______,  X_ROFL, X_THINK, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        UC_SHRG, _______, X_SHRUG, UC_DISS, _______, _______, _______, _______, _______, UC_LENN, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, X_FINUP, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, X_FINDN, _______
    ),

    [GIT] = LAYOUT(
        _______,   MI_ON,  MI_OFF,  MI_TOG, _______,  MI_C_3, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,  G_STAT,  G_DIFF, G_FETCH, _______, G_CHECK, _______, _______, _______,  G_PULL,  G_PUSH, _______, _______,          _______,
        _______,   G_ADD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______,  G_COMM, _______, G_BRANH, _______, G_MERGE, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [RGB_LAYER] = LAYOUT(
        XXXXXXX, DM_REC1, DM_REC2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  TT_RGB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, KC_WRGB, KC_RGBE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGBP, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, KC_RGBS, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGBH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, KC_RGBV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, RGB_MOD, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            RGB_TOG,                            XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD,RGB_RMOD, RGB_SPI
    ),

   [NO_KEYS] = LAYOUT(
        TT_DSBL,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          _______,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,            KC_NO,
          KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,
          KC_NO,   KC_NO,   KC_NO,                              KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
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
        GREEN,    ______,  GREEN, ______, SPRING, ______, ______, ______,   BLUE,  GREEN, SPRING, SPRING, SPRING, SPRING, ______,         ______,    GREEN,
        GREEN,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,            RED,    GREEN,
        GREEN,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,           CYAN,    GREEN,
        GREEN,     AZURE, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  AZURE,         ______,         PURPLE,    GREEN,
        GREEN,    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______,  BLACK,    GREEN,
        GREEN,    ______,   BLUE, ______,                         ______,                           GOLD, ORANGE, ______, ______, ______, ______,    GREEN
    ),
    [MACOS] = RGB_MATRIX_LAYOUT_LEDMAP(
         BLUE,    ______,  GREEN, ______, SPRING, ______, ______, ______,   BLUE,  GREEN, SPRING, SPRING, SPRING, SPRING, ______,         ______,     BLUE,
         BLUE,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,            RED,     BLUE,
         BLUE,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,           CYAN,     BLUE,
         BLUE,     AZURE, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  AZURE,         ______,         PURPLE,     BLUE,
         BLUE,    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______,  BLACK,     BLUE,
         BLUE,    ______, ______,   BLUE,                         ______,                           GOLD, ORANGE, ______, ______, ______, ______,     BLUE
    ),
    [FN_KEYS] = RGB_MATRIX_LAYOUT_LEDMAP(
        ORANGE,   ______, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ______,         SPRING,   ORANGE,
        ORANGE,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         SPRING,   ORANGE,
        ORANGE,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         SPRING,   ORANGE,
        ORANGE,    AZURE, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  AZURE,         ______,         SPRING,   ORANGE,
        ORANGE,   ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,   ORANGE,
        ORANGE,   ______,   BLUE, ______,                         ______,                           GOLD, ORANGE,    RED, ______, ______, ______,   ORANGE
    ),
    [LOCK] = RGB_MATRIX_LAYOUT_LEDMAP(
           RED,      RED, ______, ______, ______, ______, ______, ______,  GREEN, ______, ______, ______, ______, ______,    RED,         ______,      RED,
           RED,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,      RED,
           RED,   ______, ______, ______, ______, ______, ______, ______, ______, ______,    RED, ______, ______, ______, ______,         ______,      RED,
           RED,   ______, ______,    RED, ______, ______, ______, ______, ______, ______,    RED, ______, ______,         ______,         ______,      RED,
           RED,   ______,         ______, ______, ______, ______, ______,    RED, YELLOW, ______, ______, ______,            RED, ______, ______,      RED,
           RED,   ______,    RED, ______,                         ______,                         ______, YELLOW, ______, ______, ______, ______,      RED
    ),
    [SHORTCUTS] = RGB_MATRIX_LAYOUT_LEDMAP(
        GREEN,   ______, SPRING, SPRING, ______,    RED, ______, ______, ______, YELLOW, ______, ______, ______, ______, YELLOW,         ______,    GREEN,
        GREEN,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GREEN,
        GREEN,   ______, ______, ______,   PINK,   PINK, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GREEN,
        GREEN,   ______, ______,   GOLD,   TURQ,   GOLD, ______, ______, ______, ______, ______, ______, ______,         ______,         ______,    GREEN,
        GREEN,   ______,         ______, ______,   TURQ, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    GREEN,
        GREEN,   ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,    GREEN
    ),
    [TEXT] = RGB_MATRIX_LAYOUT_LEDMAP(
         GOLD,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    GOLD,
         GOLD,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,   GOLD, ______,         ______,    GOLD,
         GOLD,    ______, ______,   GOLD, ______, ______, ______, ______, ______, ______,   GOLD,   GOLD, ______, ______, ______,         ______,    GOLD,
         GOLD,    ______, ______,   GOLD, ______, ______, PURPLE, ______, ______, ______, ______, ______, ______,         ______,         ______,    GOLD,
         GOLD,    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    GOLD,
         GOLD,    ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,    GOLD
    ),
    [UNIC_LAYER] = RGB_MATRIX_LAYOUT_LEDMAP(
         CYAN,    ______,    RED,    RED,    RED, ______, ______, ______,   CYAN, ______, ______, ______, ______, ______, ______,         ______,    CYAN,
         CYAN,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    CYAN,
         CYAN,      PINK, ______, ______, ______,   CYAN,   CYAN, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    CYAN,
         CYAN,      CYAN, ______,   CYAN,   CYAN, ______, ______, ______, ______, ______,   CYAN, ______, ______,         ______,         ______,    CYAN,
         CYAN,    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,   CYAN, ______,    CYAN,
         CYAN,    ______, ______, ______,                         ______,                         ______, ______, ______, ______,   CYAN, ______,    CYAN
    ),
    [GIT] = RGB_MATRIX_LAYOUT_LEDMAP(
        PURPLE,    ______,    RED,    RED,    RED, ______,  GREEN, ______, ______, ______, ______, ______, ______, ______, ______,         ______,   PURPLE,
        PURPLE,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,   PURPLE,
        PURPLE,    ______, ______, PURPLE, PURPLE, PURPLE, ______, PURPLE, ______, ______, ______, PURPLE, PURPLE, ______, ______,         ______,   PURPLE,
        PURPLE,    ______, PURPLE, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ______,   PURPLE,
        PURPLE,    ______,         ______, ______, PURPLE, ______, PURPLE, ______, PURPLE, ______, ______, ______,         ______, ______, ______,   PURPLE,
        PURPLE,    ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,   PURPLE
    ),
    [RGB_LAYER] = RGB_MATRIX_LAYOUT_LEDMAP(
          RED,    ______,   PINK,   PINK, ______, ______, ______, ______,   BLUE, ______, ______, ______, ______, ______, ______,         ______,      RED,
        GREEN,    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,   PINK,   PINK, ______,         ______,    GREEN,
         BLUE,    ______, ______,   PINK,   PINK, ______, ______, ______, ______, ______, ______,   PINK, ______, ______, ______,         ______,     BLUE,
          RED,    ______, ______,   PINK, ______, ______, ______,   PINK, ______, ______, ______, ______, ______,         ______,         ______,      RED,
        GREEN,    ______,         ______, ______, ______,   PINK, ______, ______, ______, ______, ______, ______,         ______,   PINK, ______,    GREEN,
         BLUE,    ______, ______, ______,                           PINK,                         ______, ______, ______,   PINK,   PINK,   PINK,     BLUE
    ),
    [NO_KEYS] = RGB_MATRIX_LAYOUT_LEDMAP(
           RED,      RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,      RED,
           RED,      RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,      RED,
           RED,      RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,      RED,
           RED,      RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,            RED,      RED,
           RED,      RED,            RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,    RED,            RED,    RED,    RED,      RED,
           RED,      RED,    RED,    RED,                            RED,                            RED,    RED,    RED,    RED,    RED,    RED,      RED
    ),
};

#endif // RGB_MATRIX_LEDMAPS_ENABLED
// clang-format on
