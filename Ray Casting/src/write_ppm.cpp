#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
// File initialization clause
  std::ofstream file;
  file.open(filename, std::ios::out);
  if(!file){
    std::cout << "Can't open ppm file\n";
    return false;
  }
  
  // PPM header
  file << "P3 " << '\n' << width << '\n' << height << '\n' << "255\n";
  
  // Go through every pixel
  for (int index = 0; index < width * height; index++){
    // RGB image
    if (num_channels == 3){
      file << (int)data[index * 3] << ' ';
      file << (int)data[index * 3 + 1] << ' ';
      file << (int)data[index * 3 + 2] << ' ';
    }
    // grayscale image
    else {
      file << (int)data[index] << ' ';
      file << (int)data[index] << ' ';
      file << (int)data[index] << ' ';
    }
  }
  file.close();
  return true;
}
