// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"

enum custom_layers {
     _QWERTY,
     _NAV,
     _SYM,
     _NUM
};

const uint16_t PROGMEM combo_single_quote[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo_double_quote[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM combo_colon[] = {ALT_T(KC_S), CTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_semicolon[] = {CTL_T(KC_J), ALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {KC_M, NO_DOT, COMBO_END};
const uint16_t PROGMEM combo_caps_word[] = {ALT_T(KC_S), ALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {ALT_T(KC_S), SFT_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {SFT_T(KC_K), ALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_qmk_boot_left[] = {KC_Z, KC_X, KC_C, KC_V, KC_LALT, COMBO_END};
const uint16_t PROGMEM combo_qmk_boot_right[] = {NO_MINS, NO_DOT, NO_COMM, KC_M, KC_BSPC, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_single_quote, NO_QUOT),
    COMBO(combo_double_quote, NO_DQUO),
    COMBO(combo_colon, S(NO_DOT)),
    COMBO(combo_semicolon, S(NO_COMM)),
    COMBO(combo_underscore, S(NO_MINS)),
    COMBO(combo_caps_word, CW_TOGG),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_del, KC_DEL),
    COMBO(combo_enter, KC_ENT),
    COMBO(combo_qmk_boot_left, QK_BOOT),
    COMBO(combo_qmk_boot_right, QK_BOOT)
};

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
      // Keycodes that continue Caps Word, with shift applied.
      case KC_A ... KC_Z:
      case KC_SLSH:
          add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
          return true;
      // Keycodes that continue Caps Word, without shifting.
      case KC_1 ... KC_0:
      case KC_BSPC:
      case KC_DEL:
      case KC_UNDS:
          return true;

      default:
          return false;  // Deactivate Caps Word.
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬──────────┬────────────┬────────────┬───────────┬────────┐                          ┌────────┬────────────┬────────────┬────────────┬────────────┬────────┐
     KC_ESC,  KC_1,      KC_2,        KC_3,        KC_4,       KC_5,                               KC_6,    KC_7,        KC_8,        KC_9,        KC_0,        NO_PLUS,
  //├────────┼──────────┼────────────┼────────────┼───────────┼────────┤                          ├────────┼────────────┼────────────┼────────────┼────────────┼────────┤
     KC_TAB,  KC_Q,      KC_W,        KC_E,        KC_R,       KC_T,                               KC_Y,    KC_U,        KC_I,        KC_O,        KC_P,        NO_ARNG,
  //├────────┼──────────┼────────────┼────────────┼───────────┼────────┤                          ├────────┼────────────┼────────────┼────────────┼────────────┼────────┤
     KC_LSFT, GUI_T(KC_A),ALT_T(KC_S),SFT_T(KC_D), CTL_T(KC_F),KC_G,                               KC_H,    CTL_T(KC_J), SFT_T(KC_K), ALT_T(KC_L),GUI_T(NO_OSTR),NO_AE,
  //├────────┼──────────┼────────────┼────────────┼───────────┼────────┼────────┐        ┌────────┼────────┼────────────┼────────────┼────────────┼────────────┼────────┤
     KC_LCTL, KC_Z,      KC_X,        KC_C,        KC_V,       KC_B,    KC_LGUI,          KC_MEH,  KC_N,    KC_M,        NO_COMM,     NO_DOT,      NO_MINS,     KC_RCTL,
  //└────────┴──────────┴────────────┴──┬────────┬┴───────┬───┴────┬───┴────────┘        └───┬────┴───┬────┴───┬────────┴───────────┴────────────┴────────────┴────────┘
                                         KC_LALT, MO(_NAV),KC_LSFT,                           KC_SPC,  MO(_SYM),KC_BSPC
                                     // └────────┴────────┴────────┘                         └────────┴────────┴────────┘
  ),
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, UG_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_MUTE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_VOLU,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   QK_LLCK, XXXXXXX, KC_BSPC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, NO_RABK, NO_RBRC, NO_RCBR, NO_RPRN, NO_BSLS,                            NO_PIPE, NO_AMPR, NO_EXLM, NO_QUES, NO_GRV,  NO_TILD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, NO_LABK, NO_LBRC, NO_LCBR, NO_LPRN, NO_SLSH,                            NO_RABK, NO_EQL,  NO_MINS, NO_PLUS, NO_ASTR, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, NO_AT,   NO_HASH, NO_DLR,  NO_PERC, XXXXXXX, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, MO(_NUM),_______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
