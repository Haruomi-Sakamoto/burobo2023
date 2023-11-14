#ifndef SERVANT_H
#define SERVANT_H

#include "setting.h"

#include <Servo.h>

Servo aoyama;
Servo nakashima;

class servant {
  private:
    
  public:
    claw();

    void home(){
      nakashima.attach(13);
      aoyama.attach(32);
      move(HOME);
    }

    void drive(){
      int btn = DUALSHOCK[0];
      switch(btn){
        case 0:
          break;
        case 11:
          move(CATCH1);
          break;
        case 9:
          move(CATCH2);
          break;
        case 10:
          move(CATCH3);
          break;
        case 12:
          move(CATCH4);
          break;
        case 4:
          move(HOME);
          break;
      }
    }

    void move(int position[2]){
      nakashima.write(position[0]);
      aoyama.write(position[1]);
      for (int i = 0; i < 2; i++) {
        current[i] = position[i];
      }
    }
  
};
#endif