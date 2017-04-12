#ifndef System_h
#define System_h

#include "Arduino.h"
#include "Servo.h"
#include "driver.h"
#include "hopper.h"

extern int HOPPER_LOAD;

class System {
public:
  System(Driver driver, Hopper hopper);
  void init();
  void run();
  void driverCommand(DriverCommand command);
  void hopperCommand(HopperCommand command);
private:
  Driver _driver;
  Hopper _hopper;
  _LoadHopper();
  int _hopperCommands[16];
  int _hopperTiming[16];
};

#endif
