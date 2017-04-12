#ifndef Hopper_h
#define Hopper_h

#include "Arduino.h"
#include "Servo.h"

#include "System.h"

class Hopper {
public:
  Hopper(int releaseMotorPin, int lockMotorPin);
  void init(System &system);
  void load();
private:
  int _releaseMotorPin;
  int _lockMotorPin;
  int _loadStepLevel;
  Servo _releaseMotor;
  Servo _lockMotor;
  System _system;
};

#endif
