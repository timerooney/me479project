#ifndef WindingMotor_h
#define WindingMotor_h

#include "Arduino.h"
#include "Servo.h"

class WindingMotor {
public:
  WindingMotor(int dir1Pin, int dir2Pin, int enablePin);
  void windBack();
  void init();
private:
  void _setMotor(int speed, int reverse);
  int _dir1Pin;
  int _dir2Pin;
  int _enablePin;
  unsigned long _stopTime;
  unsigned long _currentTime;
};

#endif