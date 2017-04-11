#include "Arduino.h"
#include "Servo.h"
#include "driver.h"

int CLOCKWISE = 1;
int COUNTERCLOCKWISE = -1;
int FORWARD = 1;
int BACKWARD = -1;

Driver::Driver(int leftMotorPin, int rightMotorPin) {
  _leftMotorPin = leftMotorPin;
  _rightMotorPin = rightMotorPin;

  Driver::stop();
}

void Driver::init() {
  _leftMotor.attach(_leftMotorPin, 1000, 2000);
  _rightMotor.attach(_rightMotorPin, 1000, 2000);
}

int Driver::_floatToSpeed(int direction, float speed) {
  int integerSpeed = (int) (speed * 90.0);
  if (direction == 1) {
    return integerSpeed + 90;
  } else {
    return 90 - integerSpeed;
  }
}

void Driver::stop() {
  _leftMotor.write(90);
  _rightMotor.write(90);

  _currentCommand = 0;
  _currentSpeed = 0;
}

void Driver::forward(float speed) {
  int integerSpeed = Driver::_floatToSpeed(1, speed);
  _leftMotor.write(integerSpeed);
  _rightMotor.write(integerSpeed);
}

void Driver::backward(float speed) {
  int integerSpeed = Driver::_floatToSpeed(-1, speed);
  _leftMotor.write(integerSpeed);
  _rightMotor.write(integerSpeed);
}

void Driver::turn(int direction, float speed) {
  int leftSpeed, rightSpeed;
  leftSpeed = _floatToSpeed(direction, speed);
  rightSpeed = _floatToSpeed(-1*direction, speed);
  _leftMotor.write(leftSpeed);
  _rightMotor.write(rightSpeed);
}
