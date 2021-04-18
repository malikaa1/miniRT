#include "minirt.h"
t_ray get_ray_direction(int x, int y, t_camera camera) {
  t_ray ray;
  t_vector h;
  t_vector v;
  t_vector a;

  h = multiply_vector(camera.horizontal, x);
  v = multiply_vector(camera.vertical, y);
  a = add_vector(v, h);
  a = add_vector(a, camera.lower_left_corner);
  ray.origin = camera.origin;
  // lower_left_corner + x* horz + y * vertical - origin;
  ray.direction = substract_vector(a, camera.origin);
}
