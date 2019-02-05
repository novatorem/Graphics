#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  
  // loop through each pixel
  for (int i=0; i<height*width; i++){
    
    // condense rgb in range [0, 1]
    double r = rgb[i*3] / 255.0;
    double g = rgb[i*3 + 1] / 255.0;
    double b = rgb[i*3 + 2] / 255.0;
    
    // find hsv representation
    double h, s, v;
    rgb_to_hsv(r, g, b, h, s, v);
    
    // change the hue by shift amount, and restrict range within [0, 360]
    h = h + shift;
    if(h > 360){
      h = h - 360;
    }
    
    // change hue representation back to rgb
    double sr, sg, sb;
    hsv_to_rgb(h, s, v, sr, sg, sb);
    
    // wrote rgb value to shifted
    shifted[i*3] = (int)(sr * 255.0);
    shifted[i*3 + 1] = (int)(sg * 255.0);
    shifted[i*3 + 2] = (int)(sb * 255.0);
    
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
