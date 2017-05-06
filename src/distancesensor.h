#ifndef DistanceSensor_h
#define DistanceSensor_h

#include "Arduino.h"
#include "Servo.h"

class DistanceSensor {
public:
  DistanceSensor(int pingPin);
  long read();
private:
  long _microsecondsToInches(long microseconds);
  int _pingPin;
  long _duration;
  long _inches;
};

#endif
