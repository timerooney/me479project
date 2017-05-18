#include "Arduino.h"
#include "Servo.h"
#include "windingmotor.h"

// Declaration function
WindingMotor::WindingMotor(int dir1Pin, int dir2Pin, int enablePin) {
  _dir1Pin = dir1Pin;
  _dir2Pin = dir2Pin;
  _enablePin = enablePin;
}

// Initialization function - set all of the pins
void WindingMotor::init() {
  pinMode(_dir1Pin, OUTPUT);
  pinMode(_dir2Pin, OUTPUT);
  pinMode(_enablePin, OUTPUT);
}

// Windback function
void WindingMotor::windBack() {
  Serial.println("Winding back");
  // Start winding backwards
  _setMotor(255, 0);
  _windState = -1;
  // Set the time to stop the windback
  _stopTime = millis() + 5000;
}

// Release/windforward function
void WindingMotor::windForward() {
  Serial.println("Winding forward");
  // Start winding forward
  _setMotor(255, 1);
  _windState = 1;
  // Set the time to stop the wind
  _stopTime = millis() + 3000;
}

// Stop wind function
void WindingMotor::stop() {
  Serial.println("Stopping");
  // Stop the motor
  _setMotor(0, 0);
  _windState = 0;
}

// Update function to act "asynchronously"
void WindingMotor::update() {
  Serial.print("Load state: ");
  Serial.println(loadState);
  Serial.print("Wind state: ");
  Serial.println(_windState);
  // Get the current time
  _currentTime = millis();
  if (_currentTime >= _stopTime && _windState != 0) {
    // If we are passed the expected stop time and we are currently winding
    if (_windState == -1) {
      // If we were winding backward, say that we are now loaded
      Serial.println("Updating loadstate to 1");
      loadState = 1;
    } else {
      // Otherwise, we are not loaded
      loadState = 0;
    }
    // Stop the motor
    stop();
  }
}

void WindingMotor::_setMotor(int speed, int reverse) {
  Serial.print("Setting motor - speed: ");
  Serial.print(speed);
  Serial.print(" direction: ");
  Serial.println(reverse);
  analogWrite(_enablePin, speed);
  digitalWrite(_dir1Pin, !reverse);
  digitalWrite(_dir2Pin, reverse);
}
