#include "driver.h"
#include "vision.h"
#include "dev/hopper.h"
#include "mocks/distancesensormock.h"
#include "dev/windingmotor.h"
#include "vision.h"
#include "driver.h"
#include "SPI.h"
#include "Servo.h"

// Set up hopper
Hopper hopper(6, 7);

// Set up pixycam
Pixy pixy;
Vision vision(pixy);
// Pixycam positions
int x_pos;

// Set up driver
Driver driver(2, 3);

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
  vision.init();
  driver.init();
}

void loop() {
  windingmotor.windBack();
  // delay(100);
  // x_pos = vision.get_x_pos();
  // Serial.println(x_pos);
  // if (x_pos < 160 && x_pos >= 0) {
  //   driver.turn(CLOCKWISE, 0.3);
  // } else if (x_pos > 200) {
  //   driver.turn(COUNTERCLOCKWISE, 0.3);
  // } else if (x_pos >= 0) {
  //   driver.forward(0.25);
  //   // Fire if possible
  //   if (hopper.is_loaded == 1) {
  //     driver.stop();
  //     Serial.println("Fire!");
  //     hopper.is_loaded = 0;
  //   }
  // } else {
  //   driver.stop();
  // }
  // 
  // // Reload the hopper if it is not loaded
  // if (hopper.is_loaded == 0 && hopper.is_reloading == 0) {
  //   Serial.println("Reloading...");
  //   hopper.load();
  // }

  // // Refresh devices as needed
  // hopper.update();
}

