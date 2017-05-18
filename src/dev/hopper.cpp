#include "Arduino.h"
#include "Servo.h"
#include "hopper.h"

// Declaration function
Hopper::Hopper(int releaseMotorPin, int lockMotorPin) {
  _releaseMotorPin = releaseMotorPin;
  _lockMotorPin = lockMotorPin;
  _loadState = 0;
}

// Initialization function
void Hopper::init() {
  // Attach to the motors in a servo implementation
  _releaseMotor.attach(_releaseMotorPin);
  _lockMotor.attach(_lockMotorPin);

  // Set the initial positions
  _releaseMotor.write(90);
  _lockMotor.write(45);

  // Set the initial state
  is_loaded = 0;
  is_reloading = 0;
}

// Update function to be run every loop
// To allow "asynchronus" code
void Hopper::update() {
  _loadUpdate();
}

// Start the loading section
void Hopper::load() {
  _loadState = 1;
  is_reloading = 1;
}

// Function to handle loading states and moving the servos
void Hopper::_loadUpdate() {
  unsigned long currentTime = millis();
  // If we have just started a new load sequence
  if (_loadState == 1) {
    // Open the release servo
    Serial.println("Hopper: opening release");
    _releaseMotor.write(180);
    _nextLoadTime = currentTime + 1000;
    // Update to the next state
    _loadState = 2;
  // If we're on the next state
  } else if (_loadState == 2 && currentTime >= _nextLoadTime) {
    // Close the release motor
    Serial.println("Hopper: closing release");
    _releaseMotor.write(90);
    _nextLoadTime = currentTime + 1000;
    // Update to hte next state
    _loadState = 3;
  } else if (_loadState == 3 && currentTime >= _nextLoadTime) {
    // Open the back lock motor
    Serial.println("Hopper: closing lock");
    _lockMotor.write(135);
    _nextLoadTime = currentTime + 1000;
    // Update to the next state
    _loadState = 4;
  } else if (_loadState == 4 && currentTime >= _nextLoadTime) {
    // Close the back lock motor
    Serial.println("Hopper: closing lock");
    _lockMotor.write(45);
    _nextLoadTime = currentTime + 1000;
    // Reset the tracking states
    _loadState = 0;
    is_loaded = 1;
    is_reloading = 0;
  }
}
