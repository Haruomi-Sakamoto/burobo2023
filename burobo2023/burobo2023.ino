#include <SoftwareSerial.h>

#include "serial.h"

serial transmit;

void(* resetFunc) (void) = 0;

void setup() {
  transmit.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  transmit.update();
  if (ry == 127){
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}

