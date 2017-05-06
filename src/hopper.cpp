#include "Arduino.h"
#include "Servo.h"
#include "hopper.h"

Hopper::Hopper(int releaseMotorPin, int lockMotorPin) {
  _releaseMotorPin = releaseMotorPin;
  _lockMotorPin = lockMotorPin;
  _loadState = 0;
}

void Hopper::init() {
  _releaseMotor.attach(_releaseMotorPin);
  _lockMotor.attach(_lockMotorPin);

  _releaseMotor.write(0);
  _lockMotor.write(0);
}

void Hopper::update() {
  _loadUpdate();
}

void Hopper::load() {
  _loadState = 1;
}

void Hopper::_loadUpdate() {
  unsigned long currentTime = millis();
  if (_loadState == 1) {
    _releaseMotor.write(90);
    _nextLoadTime = currentTime + 1000;
    _loadState = 2;
  } else if (_loadState == 2 && currentTime >= _nextLoadTime) {
    _releaseMotor.write(0);
    _nextLoadTime = currentTime + 1000;
    _loadState = 3;
  } else if (_loadState == 3 && currentTime >= _nextLoadTime) {
    _lockMotor.write(90);
    _nextLoadTime = currentTime + 1000;
    _loadState = 4;
  } else if (_loadState == 4 && currentTime >= _nextLoadTime) {
    _lockMotor.write(0);
    _nextLoadTime = currentTime + 1000;
    _loadState = 0;
  }
}

