#include "Arduino.h"
#include "Servo.h"
#include "windingmotor.h"

WindingMotor::WindingMotor(int dir1Pin, int dir2Pin, int enablePin) {
  _dir1Pin = dir1Pin;
  _dir2Pin = dir2Pin;
  _enablePin = enablePin;
}

void WindingMotor::init() {
  pinMode(_dir1Pin, OUTPUT);
  pinMode(_dir2Pin, OUTPUT);
  pinMode(_enablePin, OUTPUT);
}

void WindingMotor::windBack() {
  Serial.println("Winding back");
  _setMotor(255, 0);
  _windState = -1;
  _stopTime = millis() + 15000;
}

void WindingMotor::windForward() {
  Serial.println("Winding forward");
  _setMotor(255, 1);
  _windState = 1;
  _stopTime = millis() + 5000;
  loadState = 0;
  Serial.println("Updating loadstate to 0");
}

void WindingMotor::stop() {
  Serial.println("Stopping");
  _setMotor(0, 0);
  _windState = 0;
}

void WindingMotor::update() {
  _currentTime = millis();
  if (_currentTime >= _stopTime && _windState != 0) {
    if (_windState == -1) {
      Serial.println("Updating loadstate to 1");
      loadState = 1;
    }
    stop();
  }
}

void WindingMotor::_setMotor(int speed, int reverse) {
  analogWrite(_enablePin, speed);
  digitalWrite(_dir1Pin, !reverse);
  digitalWrite(_dir2Pin, reverse);
}
