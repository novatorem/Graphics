#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  
  // get rotated pixel row by row
  int idx = 0;
  
  // which is to loop the input column by column start from last column
  for (int j=width-1; j>=0; j--){
    for (int i=0; i<height; i++){
      
      // copy rgb pixel values
      rotated[idx] = input[(width*i + j)*num_channels];
      rotated[idx + 1] = input[(width*i + j)*num_channels + 1];
      rotated[idx + 2] = input[(width*i + j)*num_channels + 2];
      
      idx += 3;
      
    }
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
