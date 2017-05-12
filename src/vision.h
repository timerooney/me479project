#ifndef Vision_h
#define Vision_h

#include "Arduino.h"
#include "Pixy.h"

class Vision {
public:
  Vision(Pixy pixy);
  void init();
  int get_x_pos();
  unsigned long last_seen_time;
  
private:
  unsigned int _blocks;
  Pixy _pixy;
};

#endif
