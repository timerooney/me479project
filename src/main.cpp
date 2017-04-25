#include "driver.h"
#include "vision.h"
#include "hopper.h"
#include "Servo.h"

//Servo _leftMotor;
//Servo _rightMotor;

// Driver driver(2, 3);
Hopper hopper(10, 12);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  Serial.println("Hi there!");
}
