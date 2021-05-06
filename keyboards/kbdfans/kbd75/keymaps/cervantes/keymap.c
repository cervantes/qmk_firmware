#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define FN_ESC LT(1,KC_ESC)
#define MS_TAB LT(2,KC_TAB)
#define MS_SPC LT(2,KC_SPC)
#define CAPSCTL CTL_T(KC_CAPS)
#define KC_LCA LCA(KC_NO)

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_init();
#endif
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    FN_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_PAUS,  KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    MS_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    CAPSCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  MO(1),    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    MO(1),    KC_LALT,  KC_LGUI,                      MS_SPC,   MS_SPC,   MS_SPC,                       KC_RALT,  MO(1),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [1] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_NLCK,  KC_SLCK,  KC_INS,
    _______,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_M_T,  _______,  _______,  _______,  _______,  RESET,    KC_MPLY,
    _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,            _______,
    KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_STEP,  _______,  _______,  _______,  _______,  _______,            KC_VOLU,  KC_MUTE,
    _______,  _______,  KC_LCA,                       _______,  _______,  _______,                      _______,  _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT
  ),

  // Mouse layer
  [2] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  KC_MS_U,  _______,  KC_WH_U,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  _______,  KC_BTN1,  KC_BTN2,  KC_BTN3,  _______,  _______,                      _______,  _______,
    _______,  _______,  _______,  KC_BTN3,  KC_BTN2,  KC_BTN1,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_MS_U,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_R
  ),
};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
        rgblight_disable();
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
        rgblight_enable();
    }
}
