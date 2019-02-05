#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <string>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  
  // initialize the file needed
  std::ofstream file;
  file.open(filename, std::ios::out);
  if(!file){
    std::cout << "Can't open ppm file\n";
    return false;
  }
  
  // PPM header
  file << "P3 " << '\n' << width << '\n' << height << '\n' << "255\n";
  
  // loop through each pixel
  for (int idx=0; idx<width*height; idx++){
    // rgb image
    if (num_channels == 3){
      file << (int)data[idx*3] << ' ';
      file << (int)data[idx*3 + 1] << ' ';
      file << (int)data[idx*3 + 2] << ' ';
    }
    // grayscale image
    else{
      file << (int)data[idx] << ' ';
      file << (int)data[idx] << ' ';
      file << (int)data[idx] << ' ';
    }
  }
  
  // close the file
  file.close();
  return true;
  
  ////////////////////////////////////////////////////////////////////////////
}
