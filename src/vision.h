#ifndef Vision_h
#define Vision_h

#include "Arduino.h"
#include "Pixy.h"

class Vision {
public:
  Vision(Pixy pixy);
  void init();
  int get_x_pos();
  uint16_t get_size();
  unsigned long last_seen_time;
private:
  unsigned int _blocks;
  Pixy _pixy;
  uint16_t _width;
  uint16_t _height;
};

#endif
