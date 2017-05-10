#ifndef Hopper_h
#define Hopper_h

#include "Arduino.h"
#include "Servo.h"

class Hopper {
public:
  Hopper(int releaseMotorPin, int lockMotorPin);
  void init();
  void update();
  void load();
private:
  int _releaseMotorPin;
  int _lockMotorPin;
  Servo _releaseMotor;
  Servo _lockMotor;

  // Keep track of hopper loading state
  void _loadUpdate();
  int _loadState;
  unsigned long _nextLoadTime;
};

#endif
