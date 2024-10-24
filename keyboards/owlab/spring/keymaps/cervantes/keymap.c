/* 
Copyright 2021 qwertykeys

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
#include QMK_KEYBOARD_H

#define CAPSCTL CTL_T(KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_spring(
		KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_BSPC, 
		KC_PGUP, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, 
		KC_PGDN, CAPSCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT, KC_ENT, 
		         KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    MO(1),   KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT, 
		         MO(1),   KC_LCTL,          KC_LALT, KC_LGUI,  KC_SPC,  KC_RGUI,                                      KC_LEFT, KC_DOWN, KC_RGHT
	),

	[1] = LAYOUT_spring(
		_______, _______, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL, 
	        KC_HOME, _______, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,  KC_PSCR, KC_SLCK, KC_PAUS, RESET, 
		KC_END,  KC_CAPS, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  KC_INS,  _______, _______, 
		         _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, KC_VOLU, _______, 
		         _______, _______,          _______, _______,  _______, _______,                                      _______, KC_VOLD, _______
	)

};

// LIGHT all the LEDS red when caps lock is active
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 14, HSV_RED});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] =
  RGBLIGHT_LAYERS_LIST(my_capslock_layer);

void keyboard_post_init_user(void) {
  // Enable the LED layers
  rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}
