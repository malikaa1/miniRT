#include "minirt.h"
t_ray get_ray_direction(double x, double y, t_camera camera) {
  // t_ray ray;
  // t_vector h;
  // t_vector v;
  // t_vector a;

  // h = multiply_vector(camera.horizontal, x);
  // v = multiply_vector(camera.vertical, y);
  // a = add_vector(v, h);
  // a = add_vector(a, camera.lower_left_corner);
  // ray.origin = camera.origin;
  // // lower_left_corner + x* horz + y * vertical - origin;
  // ray.direction = substract_vector(a, camera.origin);

  // return ray;

  t_ray ray;

  // ray.origin = camera.origin;
  // ray.direction = normalize_vector(substract_vector(
  //     add_vector(
  //         camera.lower_left_corner,
  //         add_vector(
  //             multiply_vector(camera.horizontal, (double)x / (double)width),
  //             multiply_vector(camera.vertical, (double)y / (double)height))),
  //     camera.origin));
  // printf("ray to (%d,%d) direction => origin (%.1f,%.1f,%.1f) direction "
  //        "(%.1f,%.1f,%.1f)\n",
  //        x, y, ray.origin.x, ray.origin.y, ray.origin.z, ray.direction.x,
  //        ray.direction.y, ray.direction.z);

  // forward + ((point.u * w) * right) + ((point.v * h) * up);

  double w = x * camera.w;
  float h = y * camera.h;
  t_vector vw = multiply_vector(camera.right, w);
  t_vector vh = multiply_vector(camera.up, h);

  ray.origin = camera.origin;
  ray.direction =
      normalize_vector(add_vector(add_vector(vh, vw), camera.forward));

  return (ray);
}

// ray to (249,96) direction => origin (0.0,0.0,0.0) direction (0.6,-0.1,0.8)
// ray to (249,96) direction => origin (0.0,0.0,0.0) direction (0.6,-0.1,0.8)