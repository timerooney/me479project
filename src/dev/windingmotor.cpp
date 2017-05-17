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
  _setMotor(255, 1);
  delay(30000);
  _setMotor(0, 1);
  delay(1000);
}

void WindingMotor::_setMotor(int speed, int reverse) {
  analogWrite(_enablePin, speed);
  digitalWrite(_dir1Pin, !reverse);
  digitalWrite(_dir2Pin, reverse);
}
