#include "hsv_to_rgb.h"
#include <cmath>
#include <iostream>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  
  // reference: https://en.wikipedia.org/wiki/HSL_and_HSV
  
  // calculate chroma
  double c = v * s;
  
  // calculate hue prime and intermediate value x
  double hp = h / 60.0;
  double x = c * (1 - fabs(fmod(hp, 2.0) - 1.0));
  
  // calculate r1 g1 b1
  double r1;
  double g1;
  double b1;
  
  if(hp >= 0 & hp <= 1){
    r1 = c;
    g1 = x;
    b1 = 0;
  }
  else if(hp > 1 & hp <= 2){
    r1 = x;
    g1 = c;
    b1 = 0;
  }
  else if(hp > 2 & hp <= 3){
    r1 = 0;
    g1 = c;
    b1 = x;
  }
  else if(hp > 3 & hp <= 4){
    r1 = 0;
    g1 = x;
    b1 = c;
  }
  else if(hp > 4 & hp <= 5){
    r1 = x;
    g1 = 0;
    b1 = c;
  }
  else if(hp > 5 & hp <= 6){
    r1 = c;
    g1 = 0;
    b1 = x;
  }
  else{
    r1 = 0;
    g1 = 0;
    b1 = 0;
  }
  
  // find rgb by adding amount on each component
  double m = v - c;
  r = r1 + m;
  g = g1 + m;
  b = b1 + m;
  
  ////////////////////////////////////////////////////////////////////////////
}
