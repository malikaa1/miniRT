#include "minirt.h"

t_color raytrace(t_minirt *minirt, t_ray *ray, int *intersect) {
  *intersect = 0;
  if (intersect_spheres(minirt, ray) == 1) {
    *intersect = 1;
    return (t_color){255, 255, 255};
  }

  return (t_color){130, 0, 0};
}