#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/sleep.h>

static void enable(uint8_t e) {
	cli();
	uint8_t b = e? _BV(WDIE) | e: 0;
	WDTCSR = _BV(WDCE) | _BV(WDE);
	WDTCSR = b;
	sei();
}

ISR(WDT_vect) {
	enable(0);
}

void setup() {
}

void loop() {

	uint8_t adcsra = ADCSRA;
	ADCSRA &= ~_BV(ADEN);

	enable(_BV(WDP3) | _BV(WDP0));

	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	cli();
	sleep_enable();
	sleep_bod_disable();
	sei();
	sleep_cpu();
	sleep_disable();

	ADCSRA = adcsra;
}
