#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  
  // loop through each pixel
  for (int i=0; i<height; i++){
    for (int idx1 = 0; idx1 < width; idx1++){
      
      // find its reflected point
      int idx2 = width - (idx1 + 1);
      
      // copying reflected pixels 
      reflected[(width*i + idx1)*num_channels] = input[(width*i + idx2)*num_channels];
      reflected[(width*i + idx1)*num_channels + 1] = input[(width*i + idx2)*num_channels + 1];
      reflected[(width*i + idx1)*num_channels + 2] = input[(width*i + idx2)*num_channels + 2];
      
    }
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
