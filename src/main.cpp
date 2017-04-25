#include "driver.h"
#include "vision.h"
#include "hopper.h"
#include "Servo.h"
#include "SPI.h"
#include "Pixy.h"

Hopper hopper(10, 12);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
}
