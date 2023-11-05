#pragma once

#include <math.h>

const int COMSPEED = 9600;
const unsigned int DIGITS = 10;
const unsigned int CONTENTS = 6;

int builtin = 0;

int DIR[4] = {22,18,14,37};
int PWM[4] = {23,19,15,36};

int buttonStatus;
int DUALSHOCK[5];
double dircomponent[2];
double rollcomponent[1];

double OMUNUS[8] = {
  (-sin(M_PI/4)),
  (-cos(M_PI/4)),
  (sin(M_PI/4)),
  (cos(M_PI/4)),
  (cos(M_PI/4)),
  (-sin(M_PI/4)),
  (-cos(M_PI/4)),
  (sin(M_PI/4))
};

double velocity[4];
int mdpulse[4];

const double TURNING_COEFFICIENT = 0.5;

const int JOYSTICKMAX = 255;
const int JOYSTICKMIN = 0;
const int MDPLSMAX = 2000;
const int MDPLSMIN = 1000;
