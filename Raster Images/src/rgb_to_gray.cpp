#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  
  // loop through each pixel
  for (int i=0; i<height*width; i++){
    
    // extract rgb value
    int r = rgb[i*3];
    int g = rgb[i*3 + 1];
    int b = rgb[i*3 + 2];
    
    // weight rgb and assign to gray
    int gray_val = 0.2126*r + 0.7152*g + 0.0722*b;
    gray[i] = gray_val;
    
  }
  ////////////////////////////////////////////////////////////////////////////
}


