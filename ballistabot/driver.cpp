#include "Arduino.h"
#include "Servo.h"
#include "driver.h"

Driver::Driver(int leftMotorPin, int rightMotorPin) {
  _leftMotor.attach(leftMotorPin, 1000, 2000);
  _rightMotor.attach(rightMotorPin, 1000, 2000);

  _leftMotorPin = leftMotorPin;
  _rightMotorPin = rightMotorPin;

  Driver::stop();
}

int _floatToSpeed(int direction, float speed) {
  int integerSpeed;
  integerSpeed = map(speed, 0.0, 1.0, 0, 90);
  if (direction == 1) {
    return (int) integerSpeed + 90;
  } else {
    return 90 - (int) integerSpeed;
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
