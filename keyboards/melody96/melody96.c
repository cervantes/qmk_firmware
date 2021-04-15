#include "melody96.h"
void led_set_user(uint8_t usb_led) {

	// Make the num pad always a num pad.
	if (!(usb_led & (1 << USB_LED_NUM_LOCK))) {
		register_code(KC_NUMLOCK);
		unregister_code(KC_NUMLOCK);
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRC |= (1 << 7); PORTC &= ~(1 << 7);
		backlight_enable();
	} else {
		DDRC &= ~(1 << 7); PORTC &= ~(1 << 7);
		backlight_disable();
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		DDRB |= (1 << 5); PORTB &= ~(1 << 5);
	} else {
		DDRB &= ~(1 << 5); PORTB &= ~(1 << 5);
	}
}
