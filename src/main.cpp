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
uint16_t size;
uint16_t max_size = 18000;

int shots_fired = 0;

// Set up driver
Driver driver(2, 3);

// Set up ultrasonic range sensor
DistanceSensor safety_sensor(13);
long safety_distance = 100;

// Set up windback mechanism
WindingMotor windingmotor(4, 5, 12);

void setup() {
  Serial.begin(9600);
  // Initialize the hopper
  hopper.init();
  windingmotor.init();
  vision.init();
  driver.init();
  windingmotor.windBack();
  hopper.is_loaded = 1;
}

void loop() {
  // Delay for timing
  delay(100);
  safety_distance = 15;//safety_sensor.read();

  // Get x position of target
  x_pos = vision.get_x_pos();
  size = vision.get_size();

   Driver logic
   if (shots_fired == 3) {
     driver.turn(CLOCKWISE, 0.7);
     delay(4500);
     shots_fired += 1;
   } else if (shots_fired > 3) {
     driver.forward(0.7);
   }

  if (size >= max_size) {
    Serial.println(size);
    Serial.println(max_size);
    driver.stop();
    Serial.println("Too big, stopping");
  } else if (x_pos < 140 && x_pos >= 0) {
    Serial.println("CCW turn");
    driver.turn(COUNTERCLOCKWISE, 0.7);
  } else if (x_pos > 220) {
    Serial.println("CW turn");
    driver.turn(CLOCKWISE, 0.7);
  } else if (x_pos >= 0) {
    Serial.println("Forward");
    driver.forward(0.7);
  }
  // Fire if possible
  if (hopper.is_loaded == 1 && x_pos >= 140 && x_pos <= 220) {
    Serial.println("Stopping because can fire");
    driver.stop();
    Serial.println("Fire!");
    shots_fired += 1;
    windingmotor.windForward();
    hopper.is_loaded = 0;
  }
  
  if (x_pos == -1) {
    // Search if more than 5 seconds have passed since the last time seen
    if (vision.last_seen_time < (millis() - 5000)) {
      driver.turn(CLOCKWISE, 0.7);
    } else {
      driver.stop();
    }
  }

  if (safety_distance <= 10) {
    Serial.println("Avoiding obstacle");
    driver.backward(0.6);
    delay(3000);
    driver.turn(COUNTERCLOCKWISE, 0.7);
    delay(3000);
  }

  // Reload the hopper if it is not loaded
  if (hopper.is_loaded == 0 && hopper.is_reloading == 0 && windingmotor._windState == 0) {
    Serial.println("Reloading...");
    hopper.load();
    windingmotor.windBack();
  }

  // Refresh devices as needed
  hopper.update();
  windingmotor.update();
}

