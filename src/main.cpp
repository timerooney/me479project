#include "driver.h"
#include "vision.h"
#include "hopper.h"
#include "safetysensor.h"
#include "Servo.h"

// Set up ultrasonic range sensor
int pingPin = 7;
SafetySensor safetysensor(pingPin);
long safety_distance = 100;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  safety_distance = safetysensor.read();
  Serial.println(safety_distance);
}

