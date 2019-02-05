#include "rgb_to_hsv.h"
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  
  // reference: https://en.wikipedia.org/wiki/HSL_and_HSV
  
  // find maximum, minimum of rgb channels and calculate difference
  double maximum = std::max(std::max(r, g), b);
  double minimum = std::min(std::min(r, g), b);
  double diff = maximum - minimum;
  
  // calculate hue
  if(maximum == minimum){
    h = 0;
  }
  else if(maximum == r){
    h = 60 * ((g - b) / diff);
  }
  else if(maximum == g){
    h = 60 * (2 + (b - r) / diff);
  }
  else{
    h = 60 * (4 + (r - g) / diff);
  }
  
  // constrain h in range [0, 360]
  if(h < 0){
    h = h + 360.0;
  }
  
  // calculate saturation
  if(maximum == 0){
    s = 0;
  }
  else{
    s = diff / maximum; 
  }
  
  // calculate value
  v = maximum;
  
  ////////////////////////////////////////////////////////////////////////////
}
