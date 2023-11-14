#ifndef SERIAL_H
#define SERIAL_H

#include "setting.h"

class serial {
  private:

  public:
    transmit();
    
    void begin() {
      Serial.begin(COMSPEED);
      while (!Serial) {
      }
    }

    void update() {
      while (Serial.available() > 0) {
      Serial.read();
      }
      if (Serial.available() >= DIGITS) {
        for (int i = 0; i < CONTENTS; i++) {
          DUALSHOCK[i] = Serial.parseInt();
        }
      }
    }
    
};
#endif