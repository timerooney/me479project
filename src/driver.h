#ifndef Driver_h
#define Driver_h

#include "Arduino.h"
#include "Servo.h"

extern int CLOCKWISE, COUNTERCLOCKWISE;
extern int FORWARD, BACKWARD;

class Driver {
public:
  Driver(int leftMotorPin, int rightMotorPin);
  void forward(float speed);
  void backward(float speed);
  void turn(int direction, float speed);
  void init();
  void stop();

private:
  int _floatToSpeed(int direction, float speed);
  int _leftMotorPin, _rightMotorPin;
  int _currentCommand, _currentSpeed;
  Servo _leftMotor;
  Servo _rightMotor;
};

#endif
