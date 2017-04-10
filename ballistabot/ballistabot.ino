#include "driver.h"
#include "vision.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Loop completed");
  delay(5000);
}
