#include "vision.h"

// Declaration function
Vision::Vision(Pixy pixy) {
  _pixy = pixy;
}

// Initialization function
void Vision::init() {
  // Initialize the pixy class
  _pixy.init();
  // Update the last seen time to immediately start a search
  last_seen_time = 0;
}

// Function to get the position of the target
int Vision::get_x_pos() {
  _blocks = _pixy.getBlocks();
  if (_blocks > 0) {
    // Update the last seen time if the target is seen
    last_seen_time = millis();
    // Get the x position
    return _pixy.blocks[0].x;
  } else {
    // Otherwise, return -1
    return -1;
  }
}

// Function to get the size of the last seen block
uint16_t Vision::get_size() {
  if (_blocks > 0) {
    // Get the height and width of the target
    _width = _pixy.blocks[0].width;
    _height = _pixy.blocks[0].height;
    // Multiply them together to get the area
    return _width * _height;
  } else {
    // Otherwise, return -1
    return -1;
  }
}
