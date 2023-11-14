#ifndef OMNUS_H
#define OMNUS_H

#include "setting.h"

class omnus {
  private:
    
  public:
    omni();

    void drive(){
      velmax = 0;
      for (int i = 0; i < 2; i++) {
        dircomponent[i] = map(DUALSHOCK[i+1], JOYSTICKMIN, JOYSTICKMAX, -1, 1);
      }
      rollcomponent[0] = map(DUALSHOCK[3], JOYSTICKMIN, JOYSTICKMAX, -1, 1);
      for (int i = 0; i < 4; i++) {
        velocity[i] = (dircomponent[0]*OMUNUS[i]+dircomponent[1]*OMUNUS[i+4])*(1-abs(rollcomponent[0]))+rollcomponent[0];
      }
      for (int i = 0; i < 4; i++) {
        if(abs(velmax) < velocity[i]){
          velmax = velocity[i];
        }
      }
      for (int i = 0; i < 4; i++) {
        mdpulse[i] = map(velocity[i], -1, 1, MDPLSMIN, MDPLSMAX);
        rot(mdpulse[i],DIR[i],PWM[i]);
      }
        
      /*if(DUALSHOCK[1] != 127){
        rollcomponent[0] = map(DUALSHOCK[1], JOYSTICKMIN, JOYSTICKMAX, -1, 1);
        for (int i = 0; i < 4; i++) {
          mdpulse[i] = map(rollcomponent[0], -1, 1, MDPLSMIN, MDPLSMAX);
          rot(mdpulse[i],DIR[i],PWM[i]);
        }
      }else{
        for (int i = 0; i < 2; i++) {
          dircomponent[i] = map(DUALSHOCK[i+3], JOYSTICKMIN, JOYSTICKMAX, -1, 1);
        }
        for (int i = 0; i < 4; i++) {
          velocity[i] = dircomponent[0]*OMUNUS[i]+dircomponent[1]*OMUNUS[i+4];
        }
        for (int i = 0; i < 4; i++) {
          mdpulse[i] = map(velocity[i], -1, 1, MDPLSMIN, MDPLSMAX);
          rot(mdpulse[i],DIR[i],PWM[i]);
        }
      }*/
    }

    void pinsetting(){
      for (int i = 0; i < 4; i++) {
        pinMode(DIR[i], OUTPUT);
      }
    }
    
  void rot(int pulse, int dir_pin, int pwm_pin) {
    if (pulse < 1495) {
      pulse = pulse < 1000 ? 1000 : pulse;
      digitalWrite(dir_pin, LOW);
      analogWrite(pwm_pin, map(pulse, 1500, 1000, 1, 255));
    } else if (pulse > 1505) {
      pulse = pulse > 2000 ? 2000 : pulse;
      digitalWrite(dir_pin, HIGH);
      analogWrite(pwm_pin, map(pulse, 1500, 2000, 1, 255));
    } else {
      analogWrite(pwm_pin, 0);
    }
  }
  
};
#endif