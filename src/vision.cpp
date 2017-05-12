#include "vision.h"

Vision::Vision(Pixy pixy) {
  _pixy = pixy;
}

void Vision::init() {
  _pixy.init();
}

int Vision::get_x_pos() {
  _blocks = _pixy.getBlocks();
  if (_blocks > 0) {
    return _pixy.blocks[0].x;
  } else {
    return -1;
  }
}
