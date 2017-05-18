#include "Arduino.h"
#include "Servo.h"
#include "distancesensor.h"

// Declaration function
DistanceSensor::DistanceSensor(int pingPin) {
  _pingPin = pingPin;
}

long DistanceSensor::read() {
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(_pingPin, OUTPUT);
  digitalWrite(_pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(_pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(_pingPin, INPUT);
  _duration = pulseIn(_pingPin, HIGH);

  // convert the time into a distance
  _inches = _microsecondsToInches(_duration);
  return _inches;
}

long DistanceSensor::_microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
