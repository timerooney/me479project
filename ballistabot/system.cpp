#include "Arduino.h"
#include "Servo.h"

#include "driver.h"
#include "hopper.h"


int HOPPER_LOAD = 1;

System::System(Driver driver, Hopper hopper) {
  _driver = driver;
  _hopper = hopper;
}

System::init() {
  _driver.init();
  _hopper.init();
}