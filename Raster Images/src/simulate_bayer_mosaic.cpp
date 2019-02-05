#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  
  // pixel index of bayer
  int bayer_idx = 0;
  
  // loop through each pixel in rgb
  for (int i=0; i<height; i++){
    for (int j=0; j<width; j++){
      
      int idx = (width*i + j)*3;
      int row = i % 2;
      int col = j % 2;
      
      // blue in Bayer mosaic, copy blue channel into bayer
      if(row == 1 & col == 0){
        bayer[bayer_idx] = rgb[idx + 2];
      }
      // red in Bayer mosaic, copy red channel into bayer
      else if(row == 0 & col == 1){
        bayer[bayer_idx] = rgb[idx];
      }
      // green in Bayer mosaic, copy green channel into bayer
      else{
        bayer[bayer_idx] = rgb[idx + 1];
      }
      
      bayer_idx++;
    }
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
