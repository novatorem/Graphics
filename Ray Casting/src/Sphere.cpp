#include "Sphere.h"
#include "Ray.h"
#include <algorithm>

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  Eigen::Vector3d d = ray.direction;
  Eigen::Vector3d e = ray.origin;
  Eigen::Vector3d c = center;
  
  // construct linear system
  double A = d.dot(d);
  double B = 2 * d.dot(e - c);
  double C = (e - c).dot(e - c) - radius * radius;
  
  double discriminant = B * B - 4 * A * C;
  
  // no soln
  if(discriminant < 0){
    return false;
  }
  // one soln
  if(discriminant == 0){
    t = (-B) / (2 * A);
  }
  // two soln
  else{
    double t1 = (-B + sqrt(discriminant)) / (2 * A);
    double t2 = (-B - sqrt(discriminant)) / (2 * A);
    
    // select the smaller solution above thresholds
    t = std::min(t1, t2);
    if(t <= min_t){
      t = std::max(t1, t2);
    }
  }
  
  // check t above thresholds
  if(t > min_t){
    n = (e + t * d - c) / radius;
    return true;
  }
  
  return false;
  
}