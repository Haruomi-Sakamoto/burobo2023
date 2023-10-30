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
  if(builtin == 0){
    digitalWrite(LED_BUILTIN,HIGH);
    builtin == 1;
  }else{
    digitalWrite(LED_BUILTIN,LOW);
    builtin == 0;
  }
}

