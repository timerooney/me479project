#ifndef Vision_h
#define Vision_h

#include "Arduino.h"

struct TargetLocation {
  float x;
  float y;
  float z;
  float distance;
};

struct Target {
  int targetID;
};

class Vision {
public:
  Vision();
  TargetLocation findTarget(Target target);

// private:

};

#endif
