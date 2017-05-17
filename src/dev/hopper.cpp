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

  _releaseMotor.write(90);
  _lockMotor.write(45);
  is_loaded = 0;
  is_reloading = 0;
}

void Hopper::update() {
  _loadUpdate();
}

void Hopper::load() {
  _loadState = 1;
  is_reloading = 1;
}

void Hopper::_loadUpdate() {
  unsigned long currentTime = millis();
  if (_loadState == 1) {
    Serial.println("Hopper: opening release");
    _releaseMotor.write(180);
    _nextLoadTime = currentTime + 1000;
    _loadState = 2;
  } else if (_loadState == 2 && currentTime >= _nextLoadTime) {
    Serial.println("Hopper: closing release");
    _releaseMotor.write(90);
    _nextLoadTime = currentTime + 1000;
    _loadState = 3;
  } else if (_loadState == 3 && currentTime >= _nextLoadTime) {
    Serial.println("Hopper: closing lock");
    _lockMotor.write(135);
    _nextLoadTime = currentTime + 1000;
    _loadState = 4;
  } else if (_loadState == 4 && currentTime >= _nextLoadTime) {
    Serial.println("Hopper: closing lock");
    _lockMotor.write(45);
    _nextLoadTime = currentTime + 1000;
    _loadState = 0;
    is_loaded = 1;
    is_reloading = 0;
  }
}
