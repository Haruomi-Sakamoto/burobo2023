#ifndef CONTROLL_H
#define CONTROLL_H

#include "setting.h"

class controll {
  private:
    
  public:
    omni();

    void drive(){
      for (int i = 0; i < 2; i++) {
        dircomponent[i] = map(DUALSHOCK[i+3], JOYSTICKMIN, JOYSTICKMAX, -1, 1);
      }
      dircomponent[2] = (map(DUALSHOCK[1], JOYSTICKMIN, JOYSTICKMAX, -1, 1))*(-1);
      for (int i = 0; i < 4; i++) {
        velocity[i] = dircomponent[0]*OMUNUS[i]+dircomponent[1]*OMUNUS[i+4]+dircomponent[2]*TURNING_COEFFICIENT;
      }
      velmax = velocity[0];
      for (int i = 0; i < 4; i++) {
        if (velocity[i] > velmax) {
          velmax = velocity[i];
        }
      }
      for (int i = 0; i < 4; i++) {
        mdpulse[i] = map(velocity[i], -velmax, velmax, MDPLSMIN, MDPLSMAX);
        rot(mdpulse[i],DIR[i],PWM[i]);
      }
    }

    void pinsetting(){
      for (int i = 0; i < 4; i++) {
        pinMode(DIR[i], OUTPUT);
      }
    }
    
    void rot(int pulse, int dir_pin, int pwm_pin) {
    float power = (pulse - 1500)*0.002;
    if(abs(power) < 0.1) power = 0.0;
    analogWrite(pwm_pin, abs(power)*255);
    digitalWrite(pwm_pin,power < 0.0 ? HIGH : LOW); 
    }
};
#endif