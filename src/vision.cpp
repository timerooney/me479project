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

uint16_t Vision::get_size() {
  if (_blocks > 0) {
    _width = _pixy.blocks[0].width;
    _height = _pixy.blocks[0].height;
    return _width * _height;
  } else {
    return -1;
  }
}
