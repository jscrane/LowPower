#include <avr/power.h>
#include <avr/sleep.h>

void setup() {

	sei();
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	cli();
	sleep_enable();
	sei();
	sleep_cpu();
	sleep_disable();

}

void loop() {
}
