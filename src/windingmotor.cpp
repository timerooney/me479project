#include "Arduino.h"
#include "Servo.h"
#include "windingmotor.h"

WindingMotor::WindingMotor(int dir1Pin, int dir2Pin, int enablePin) {
  _dir1Pin = dir1Pin;
  _dir2Pin = dir2Pin;
  _enablePin = enablePin;
}

void WindingMotor::windBack() {

}

int WindingMotor::isReleaseReady() {

}

void WindingMotor::release() {

}
void WindingMotor::update() {

}

void WindingMotor::_setMotor(int speed, int reverse) {

}
