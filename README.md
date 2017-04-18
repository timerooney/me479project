# Mechatronics Project

This is a repository of code for the ME479 mechatronics project for group 10.

## Notes

`/home/trooney/dev/tools/arduino-1.8.2/hardware/tools/avr/bin/avrdude -C/home/trooney/dev/tools/arduino-1.8.2/hardware/tools/avr/etc/avrdude.conf -v -patmega2560 -cwiring -P/dev/ttyACM0 -b115200 -D -Uflash:w:/tmp/arduino_build_368738/ballistabot.ino.hex:i`

`~/dev/tools/arduino-1.8.2/arduino-builder -hardware ~/dev/tools/arduino-1.8.2/hardware -tools ~/dev/tools/arduino-1.8.2/hardware/tools -tools ~/dev/tools/arduino-1.8.2/tools-builder -fqbn=arduino:avr:mega:cpu=atmega2560 -libraries ~/dev/tools/arduino-1.8.2/libraries -verbose ballistabot.ino`

