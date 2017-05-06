#include "driver.h"
#include "vision.h"
#include "hopper.h"
#include "Servo.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  Serial.println("Hi there!");
}
