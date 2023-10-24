#include <SoftwareSerial.h>

#include "serial.h"
#include "controll.h"

serial transmit;
controll omni;

void(* resetFunc) (void) = 0;

void setup() {
  transmit.begin();
  omni.pinsetting();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  transmit.update();
  omni.drive();
  if(DUALSHOCK[2] == 127){
    digitalWrite(LED_BUILTIN,HIGH);
  }else{
    digitalWrite(LED_BUILTIN,LOW);
  }
}

