# 8MHz ATTiny84 with Optiboot

These sketches are compiled with [uC-Makefile](jscrane/uC-Makefile) 
against [ATTinyCore](SpenceKonde/ATTinyCore).

A valuable source of information was Nick Gammon's 
[Power saving techniques for microprocessors](http://www.gammon.com.au/power).

## Timings

| sketch | time	| description |
| ------ | ---- | ----------- |
|0 |	2.36mA |	blank sketch |
|1 |	226uA |		sleep_mode_pwr_down |
|2 | 	219uA |		2 + bod disabled |
|3 | 	<218uA |	2 + power_all_disable |
|4 | 	<1uA |		3 + ADCSRA = 0 |
|5 | 	5uA |		2 + ADCSRA = 0 + WDT(8s) |
|6 |	5uA |		3 + ADCSRA = 0 + WDT(8s) |

## Notes

- `SLEEP_MODE_PWR_DOWN` reduces idle current by 90%
- disabling the Brown-out Detector and all other devices saves about 7uA
- disabling the Analog comparator saves almost all of the remaining current draw
- enabling the Watchdog timer costs about 5uA
