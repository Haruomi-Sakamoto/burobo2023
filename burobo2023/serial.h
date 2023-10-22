#ifndef SERIAL_H
#define SERIAL_H

#include "setting.h"

class serial {
  private:

  public:
    transmit();

    void begin() {
      Serial.begin(COMSPEED);
      //Serial.println("Startup 9600baud");
      while (!Serial) {
      }
    }

    void establishcontact() {
      //Serial.print("EstablishContact");
      while (Serial.available() <= 0) {
      Serial.print('.');
      delay(10);
      }
      Serial.println("");
    }

    void update() {
      while (Serial.available() > 0) {
      Serial.read();
      }
      if (Serial.available() >= DIGITS) {
        buttonStatus = Serial.parseInt();
        lx = Serial.parseInt();
        ly = Serial.parseInt();
        rx = Serial.parseInt();
        ry = Serial.parseInt();
      }
    }
    
};
#endif