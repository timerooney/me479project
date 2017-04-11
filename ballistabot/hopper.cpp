#include "Arduino.h"
#include "Servo.h"
#include "hopper.h"

Hopper::Hopper(int releaseMotorPin, int lockMotorPin) {
  _releaseMotorPin = releaseMotorPin;
  _lockMotorPin = lockMotorPin;
}

void Hopper::init() {
  _releaseMotor.attach(_releaseMotorPin);
  _lockMotor.attach(_lockMotorPin);

  _releaseMotor.write(0);
  _lockMotor.write(0);
}

void Hopper::load() {
  _releaseMotor.write(90);
  delay(1000);
  _releaseMotor.write(0);
  delay(1000);
  _lockMotor.write(90);
  delay(1000);
  _lockMotor.write(0);
}

