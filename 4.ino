#include <avr/power.h>
#include <avr/sleep.h>

void setup() {

	ADCSRA &= ~_BV(ADEN);
	power_all_disable();

	sei();
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	cli();
	sleep_enable();
	sleep_bod_disable();
	sei();
	sleep_cpu();
	sleep_disable();

}

void loop() {
}
