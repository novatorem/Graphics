#include "over.h"
#include <iostream>

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  
  // want come up with C by overlay A onto B (i.e. B is background)
  // reference: http://ssp.impulsetrain.com/porterduff.html
  
  // loop through each pixel in A and B, as they are of same size
  for (int i=0; i<width*height; i++){
    
    // get corresponding rgba value in A and B
    double ar = A[i*4];
    double ag = A[i*4 + 1];
    double ab = A[i*4 + 2];
    double aa = A[i*4 + 3];
    
    double br = B[i*4];
    double bg = B[i*4 + 1];
    double bb = B[i*4 + 2];
    double ba = B[i*4 + 3];
    
    // condense alpha values into range [0, 1]
    aa = aa / 255.0;
    ba = ba / 255.0;
    
    // C's alpha value is combination of A's alpha and B's alpha
    double a = aa + (1 - aa) * ba;
    
    // get rgb value with respect to each alpha
    double r = aa * ar + (1 - aa) * ba * br;
    double g = aa * ag + (1 - aa) * ba * bg;
    double b = aa * ab + (1 - aa) * ba * bb;

    // wrote rgba channels into C
    C[i*4] = (int)r;
    C[i*4 + 1] = (int)g;
    C[i*4 + 2] = (int)b;
    C[i*4 + 3] = (int)a * 255;
    
  }
  
  ////////////////////////////////////////////////////////////////////////////
}
