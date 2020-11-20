# 8MHz ATTiny84 with Optiboot

These sketches are compiled with [uC-Makefile](https://github.com/jscrane/uC-Makefile) 
against [ATTinyCore](https://github.com/SpenceKonde/ATTinyCore).

A valuable source of information was Nick Gammon's 
[Power saving techniques for microprocessors](https://www.gammon.com.au/power).

## Timings

| sketch | current | description |
| ------ | ---- | ----------- |
| [0](0.ino) |	2.36m |	blank sketch |
| [1](1.ino) |	226u |		sleep_mode_pwr_down |
| [2](2.ino) | 	219u |		2 + bod disabled |
| [3](3.ino) | 	<218u |	2 + power_all_disable |
| [4](4.ino) | 	<1u |		3 + ADCSRA = 0 |
| [5](5.ino) | 	5u |		2 + ADCSRA = 0 + WDT(8s) |
| [6](6.ino) |	5u |		3 + ADCSRA = 0 + WDT(8s) |

## Notes

- `SLEEP_MODE_PWR_DOWN` reduces idle current by 90%
- disabling the Brown-out Detector and all other devices saves about 7uA
- disabling the Analog comparator saves almost all of the remaining current draw
- enabling the Watchdog timer costs about 5uA
