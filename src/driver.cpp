#include "Arduino.h"
#include "Servo.h"
#include "driver.h"

// Directional cosntants
int CLOCKWISE = -1;
int COUNTERCLOCKWISE = 1;
int FORWARD = 1;
int BACKWARD = -1;

// Declaration function
Driver::Driver(int leftMotorPin, int rightMotorPin) {
  _leftMotorPin = leftMotorPin;
  _rightMotorPin = rightMotorPin;

  // Always set the motors to not move on bootup
  Driver::stop();
}

void Driver::init() {
  // Attach the motors to the servo implementation
  _leftMotor.attach(_leftMotorPin, 1000, 2000);
  _rightMotor.attach(_rightMotorPin, 1000, 2000);
}

int Driver::_floatToSpeed(int direction, float speed) {
  // Internal function to convert floats from 0.0 to 1.0
  // to a servo speed
  int integerSpeed = (int) (speed * 90.0);
  if (direction == 1) {
    return integerSpeed + 90;
  } else {
    return 90 - integerSpeed;
  }
}

void Driver::stop() {
  // Function to stop the motors
  _leftMotor.write(90);
  _rightMotor.write(90);

  _currentCommand = 0;
  _currentSpeed = 0;
}

void Driver::forward(float speed) {
  // function to drive the motors forward
  int integerSpeed = Driver::_floatToSpeed(FORWARD, speed);
  // First, convert the speed to the speed that the servos recognize,
  // then update the servo implementation
  _leftMotor.write(integerSpeed);
  _rightMotor.write(integerSpeed);
}

void Driver::backward(float speed) {
  // function to drive the motors backward
  int integerSpeed = Driver::_floatToSpeed(BACKWARD, speed);
  // First, convert the speed to the speed that the servos recognize,
  // then update the servo implementation
  _leftMotor.write(integerSpeed);
  _rightMotor.write(integerSpeed);
}

void Driver::turn(int direction, float speed) {
  int leftSpeed, rightSpeed;
  // determine the motor speeds for turning
  leftSpeed = _floatToSpeed(direction, speed);
  rightSpeed = _floatToSpeed(-1*direction, speed);
  // Implement the turning
  _leftMotor.write(leftSpeed);
  _rightMotor.write(rightSpeed);
}
