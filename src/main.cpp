#include "driver.h"
#include "vision.h"
#include "hopper.h"
#include "distancesensormock.h"
#include "windingmotor.h"
#include "Servo.h"

// Set up hopper
Hopper hopper(10, 12);

// Set up ultrasonic range sensors
DistanceSensorMock safety_sensor(7);
DistanceSensorMock winding_sensor(8);
long safety_distance = 100;
long winding_distance = 100;

WindingMotor windingmotor(10, 9, 11);

void setup() {
  Serial.begin(9600);
  // Initialize the hopper
  hopper.init();
  windingmotor.init();
}

void loop() {
  // Read distance sensors
  safety_distance = safety_sensor.read();
  winding_distance = winding_sensor.read();
  Serial.println(safety_distance);
  Serial.println(winding_distance);

  // hopper.update();
  // windingmotor.windBack();
  // delay(5000);
}

