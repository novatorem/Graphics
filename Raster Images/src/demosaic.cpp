#include "demosaic.h"
#include <iostream>

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  
  // pixel index of rgb
  int rgb_idx = 0;
  
  // loop through each pixel in bayer
  for (int i=0; i<height; i++){
    for (int j=0; j<width; j++){
      
      int idx = width*i + j;
      int row = i % 2;
      int col = j % 2;
      
      int r, g, b;
      int curr, n1, n2, n3, n4, n5, n6, n7, n8;
      
      // initialize current value and all 8 neighbors
      curr = bayer[idx];
      n1 = bayer[idx-width-1];
      n2 = bayer[idx-width];
      n3 = bayer[idx-width+1];
      n4 = bayer[idx-1];
      n5 = bayer[idx+1];
      n6 = bayer[idx+width-1];
      n7 = bayer[idx+width];
      n8 = bayer[idx+width+1];
      
      // if on edges or corners, set undefined neighbor to -1
      if(i == 0){
        n1 = n2 = n3 = -1;
        if(j == 0){
          n4 = -1;
          n6 = -1;
        }
        else if(j == width-1){
          n5 = -1;
          n8 = -1;
        }
      }
      else if(i == height-1){
        n6 = n7 = n8 = -1;
        if(j == 0){
          n1 = -1;
          n4 = -1;
        }
        else if(j == width-1){
          n3 = -1;
          n5 = -1;
        }
      }
      else if(j == 0){
        n1 = n4 = n6 = -1;
      }
      else if(j == width-1){
        n3 = n5 = n8 = -1;
      }
      
      // for each pixel, averaged its neighbors to get missing channels
      
      // blue in Bayer mosaic, structure:
      // r g r
      // g b g
      // r g r
      if(row == 1 & col == 0){
        b = curr;
        r = (n1 + n3 + n6 + n8) / ((n1!=-1) + (n3!=-1) + (n6!=-1) + (n8!=-1));
        g = (n2 + n4 + n5 + n7) / ((n2!=-1) + (n4!=-1) + (n5!=-1) + (n7!=-1));
      }
      
      // red in Bayer mosaic, structure:
      // b g b
      // g r g
      // b g b
      else if(row == 0 & col == 1){
        r = curr;
        b = (n1 + n3 + n6 + n8) / ((n1!=-1) + (n3!=-1) + (n6!=-1) + (n8!=-1));
        g = (n2 + n4 + n5 + n7) / ((n2!=-1) + (n4!=-1) + (n5!=-1) + (n7!=-1));
      }
      
      // one green case in Bayer mosaic, structure:
      // g b g
      // r g r
      // g b g
      else if(row == 0 & col == 0){
        g = curr;
        b = (n2 + n7) / ((n2!=-1) + (n7!=-1));
        r = (n4 + n5) / ((n4!=-1) + (n5!=-1));
      }
      
      // another green case in Bayer mosaic, structure:
      // g r g
      // b g b
      // g r g
      else{
        g = curr;
        r = (n2 + n7) / ((n2!=-1) + (n7!=-1));
        b = (n4 + n5) / ((n4!=-1) + (n5!=-1));
      }
      
      // copy rgb values
      rgb[rgb_idx*3] = r;
      rgb[rgb_idx*3+1] = g;
      rgb[rgb_idx*3+2] = b;
      
      rgb_idx++;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
