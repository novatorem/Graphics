#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>


bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  // Traingle vertices
  Eigen::Vector3d pa = std::get<0>(corners);
  Eigen::Vector3d pb = std::get<1>(corners);
  Eigen::Vector3d pc = std::get<2>(corners);
  
  // Find normal vector using vertices
  n = (pb - pa).cross(pc - pa).normalized();
  if(ray.direction.dot(n) == 0){
    return false;
  }
  
  // Construct linear system
  double a, b, c, d, e, f, g, h, i, j, k, l;
  
  a = pa[0] - pb[0];
  b = pa[1] - pb[1];
  c = pa[2] - pb[2];
  d = pa[0] - pc[0];
  e = pa[1] - pc[1];
  f = pa[2] - pc[2];
  g = ray.direction[0];
  h = ray.direction[1];
  i = ray.direction[2];
  
  j = pa[0] - ray.origin[0];
  k = pa[1] - ray.origin[1];
  l = pa[2] - ray.origin[2];
  
  // Vompute reuse terms
  double ei_hf, gf_di, dh_eg, ak_jb, jc_al, bl_kc;
  
  ei_hf = e * i - h * f;
  gf_di = g * f - d * i;
  dh_eg = d * h - e * g;
  ak_jb = a * k - j * b;
  jc_al = j * c - a * l;
  bl_kc = b * l - k * c;
  
  // Using Cramer's rule to solve linear systems
  double M = a * ei_hf + b * gf_di + c * dh_eg;
  
  // Compute t
  t = -(f * ak_jb + e * jc_al + d * bl_kc) / M;
  if(t < min_t){
    return false;
  }
  
  // Compute gamma
  double gamma = (i * ak_jb + h * jc_al + g * bl_kc) / M;
  if(gamma < 0 || gamma > 1){
    return false;
  }
  
  // Compute beta
  double beta = (j * ei_hf + k * gf_di + l * dh_eg) / M;
  if(beta < 0 || beta > 1-gamma){
    return false;
  }
  
  
  return true;
}