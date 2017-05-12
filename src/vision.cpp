#include "vision.h"

Vision::Vision(Pixy pixy) {
  _pixy = pixy;
}

void Vision::init() {
  _pixy.init();
  last_seen_time = 0;
}

int Vision::get_x_pos() {
  _blocks = _pixy.getBlocks();
  if (_blocks > 0) {
    last_seen_time = millis();
    return _pixy.blocks[0].x;
  } else {
    return -1;
  }
}
