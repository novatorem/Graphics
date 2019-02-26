#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  // initialize
  bool hit = false;
  t = std::numeric_limits<double>::max();
  double curr_t;
  Eigen::Vector3d curr_n;

  // loop through each object
  for (int i=0; i<objects.size(); i++){
    // if such object intersect
    if(objects[i]->intersect(ray, min_t, curr_t, curr_n)){
      
      // update if it's an earlier hit
      if(curr_t < t){
        t = curr_t;
        hit = true;
        n = curr_n;
        hit_id = i;
      }
    }
  }

  return hit;

}