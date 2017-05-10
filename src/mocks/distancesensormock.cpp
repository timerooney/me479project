#include "Arduino.h"
#include "Servo.h"
#include "distancesensormock.h"

DistanceSensorMock::DistanceSensorMock(int pingPin) : DistanceSensor(pingPin) {}

long DistanceSensorMock::read() {
  // Fake the reading delay
  delayMicroseconds(10);

  _duration = ((float) random(0, 10000)) / 1000.0;

  // convert the time into a distance
  _inches = _microsecondsToInches(_duration);
  return _inches;
}
