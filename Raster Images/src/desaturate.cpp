#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
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
    
    // reduce saturation by factor amount
    s = s * (1 - factor);
    
    // change hue representation back to rgb
    double sr, sg, sb;
    hsv_to_rgb(h, s, v, sr, sg, sb);
    
    // wrote rgb value to desaturated
    desaturated[i*3] = (int)(sr * 255.0);
    desaturated[i*3 + 1] = (int)(sg * 255.0);
    desaturated[i*3 + 2] = (int)(sb * 255.0);
    
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
