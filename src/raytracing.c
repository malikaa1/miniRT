#include "minirt.h"

t_color raytrace(t_minirt *minirt, t_ray *ray) {

  if (intersect_sphere(minirt, ray)) {

    return (t_color){255, 255, 255};
  }
}