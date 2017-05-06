#ifndef SafetySensor_h
#define SafetySensor_h

#include "Arduino.h"
#include "Servo.h"

class SafetySensor {
public:
  SafetySensor(int pingPin);
  long read();
private:
  long _microsecondsToInches(long microseconds);
  int _pingPin;
  long _duration;
  long _inches;
};

#endif
