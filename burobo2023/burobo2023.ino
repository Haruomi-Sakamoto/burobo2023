#include "serial.h"
#include "omnus.h"
#include "servant.h"

serial transmit;
omnus omni;
servant claw;

void setup() {
  transmit.begin();
  omni.pinsetting();
  claw.home();
}

void loop() {
  transmit.update();
  omni.drive();
  claw.drive();
}

