#include "driver.h"
#include "vision.h"
#include "dev/hopper.h"
#include "dev/distancesensor.h"
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

// Set up ultrasonic range sensor
DistanceSensor safety_sensor(13);
long safety_distance = 100;

// Set up windback mechanism
WindingMotor windingmotor(10, 9, 11);

void setup() {
  Serial.begin(9600);
  // Initialize the hopper
  hopper.init();
  windingmotor.init();
  vision.init();
  driver.init();
  windingmotor.windBack();
}

void loop() {
  // Delay for timing
  delay(100);
  safety_distance = 10; //safety_sensor.read();
  Serial.println(safety_distance);

  // Get x position of target
  x_pos = vision.get_x_pos();
  Serial.println(x_pos);

  // Driver logic
  if (x_pos < 160 && x_pos >= 0) {
    driver.turn(COUNTERCLOCKWISE, 0.3);
  } else if (x_pos > 200) {
    driver.turn(CLOCKWISE, 0.3);
  } else if (x_pos >= 0) {
    driver.forward(0.3);
    // Fire if possible
    if (hopper.is_loaded == 1) {
      driver.stop();
      Serial.println("Fire!");
      windingmotor.windForward();
      hopper.is_loaded = 0;
    }
  } else {
    // Search if more than 5 seconds have passed since the last time seen
    if (vision.last_seen_time < (millis() - 5000)) {
      driver.turn(CLOCKWISE, 0.3);
    } else {
      driver.stop();
    }
  }

  if (safety_distance <= 5) {
    Serial.println("Avoiding obstacle");
    driver.backward(0.6);
    delay(3000);
    driver.turn(COUNTERCLOCKWISE, 0.3);
    delay(3000);
  }

  // Reload the hopper if it is not loaded
  if (hopper.is_loaded == 0 && hopper.is_reloading == 0) {
    Serial.println("Reloading...");
    hopper.load();
  }

  // Refresh devices as needed
  hopper.update();
  windingmotor.update();
}

