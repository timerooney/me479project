#include "driver.h"
#include "vision.h"
#include "hopper.h"
#include "Servo.h"


Hopper hopper(10, 12);

void setup() {
  Serial.begin(9600);
  hopper.init();
  hopper.load();
}

void loop() {
  hopper.update();
  Serial.println("Hi");
  delay(250);
}
