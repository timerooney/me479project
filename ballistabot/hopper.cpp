#include "Arduino.h"
#include "Servo.h"
#include "hopper.h"

Hopper::Hopper(int releaseMotorPin, int lockMotorPin) {
  _releaseMotorPin = releaseMotorPin;
  _lockMotorPin = lockMotorPin;
}

void Hopper::init(System &system) {
  _system = system;
  _releaseMotor.attach(_releaseMotorPin);
  _lockMotor.attach(_lockMotorPin);

  _releaseMotor.write(0);
  _lockMotor.write(0);
}

void Hopper::load() {
  _loadStep = 0;
  system.
}

void Hopper::loadStep() {
  switch (_loadStepLevel) {
    case 0:
      _releaseMotor.write(90);
      _loadStepLevel += 1;
      break;
    case 1:
      _releaseMotor.write(90);
      _loadStepLevel += 1;
      break;
    case 2:
      _lockMotor.write(90);
      _loadStepLevel += 1;
      break;
    case 3:
      _lockMotor.write(0);
      _loadStepLevel += 1;
      break;
  }
}
