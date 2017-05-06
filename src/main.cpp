#include "driver.h"
#include "vision.h"
#include "hopper.h"
#include "distancesensor.h"
#include "Servo.h"

// Set up ultrasonic range sensors
DistanceSensor safety_sensor(7);
DistanceSensor winding_sensor(8);
long safety_distance = 100;
long winding_distance = 100;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  safety_distance = safety_sensor.read();
  winding_distance = winding_sensor.read();
  Serial.println(safety_distance);
  Serial.println(winding_distance);
}

