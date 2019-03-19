#include "TriangleSoup.h"
#include "Ray.h"
#include "first_hit.h"

bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  // Multi-triangular forumuation
  int hit_id = 0;
  bool result = first_hit(ray, min_t, triangles, hit_id, t, n);
  
  return result;
}



