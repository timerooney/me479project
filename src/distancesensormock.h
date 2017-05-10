#ifndef DistanceSensorMock_h
#define DistanceSensorMock_h

#include "Arduino.h"
#include "Servo.h"
#include "distancesensor.h"

class DistanceSensorMock : DistanceSensor {
public:
  DistanceSensorMock(int pingPin);
  long read() override; // Override the base function
};

#endif
