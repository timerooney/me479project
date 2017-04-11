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
  // driver.init();
  hopper.init();
}

void loop() {
//  driver.forward(0.5);
//  delay(3000);
//  driver.backward(0.5);
//  delay(3000);
//  driver.turn(CLOCKWISE, 0.5);
//  delay(3000);
  delay(5000);
  hopper.load();
}
