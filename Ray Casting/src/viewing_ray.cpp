#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  // Origin
  ray.origin = camera.e;
  
  // Edges
  double r = 0.5 * camera.width;
  double l = -0.5 * camera.width;
  double t = -0.5 * camera.height;
  double b = 0.5 * camera.height;
  
  // Position u/v
  double u = l + (r - l) * (j + 0.5) / width;
  double v = b + (t - b) * (i + 0.5) / height;
  
  // Direction
  ray.direction = - camera.d * camera.w + camera.u * u + camera.v * v;
}

