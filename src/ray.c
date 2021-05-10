#include "minirt.h"

t_vector calculate_rot(t_vector *c2, t_vector *c3, t_vector rot, t_vector to)
{
  t_vector c1;
  t_vector v;
  float c;
  float s;
  float r;

  v = cross_vector(to, rot);
  c = dot_vector(rot, to);
  s = pow(get_vector_length(v), 2);
  r = ((1 - c) / s);
  c1 = (t_vector){-r * (pow(v.y, 2) + pow(v.z, 2)) + 1, r * v.x * v.y - v.z, r * v.x * v.z + v.y};
  (*c2) = (t_vector){r * v.x * v.y + v.z, -r * (pow(v.x, 2) + pow(v.z, 2)) + 1, r * v.y * v.x - v.x};
  (*c3) = (t_vector){r * v.x * v.z - v.y, r * v.y * v.z - v.x, -r * (pow(v.x, 2) + pow(v.y, 2)) + 1};
  return (c1);
}

t_vector apply_rot(t_vector pos, t_vector dir, t_vector rot)
{
  t_vector c1;
  t_vector c2;
  t_vector c3;
  t_vector prev;

  if (dir.x == 0 && dir.y < 0 && dir.z == 0)
    pos = (t_vector){pos.x, pos.y, -pos.z};
  else if (!(dir.x == 0 && dir.y != 0 && dir.z == 0))
  {
    prev = pos;
    c1 = calculate_rot(&c2, &c3, rot, dir);
    pos = (t_vector){dot_vector(c1, prev), dot_vector(c2, prev), dot_vector(c3, prev)};
  }
  return (pos);
}

t_ray get_ray_direction(double x, double y, t_camera camera, t_minirt minirt)
{
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

  // double w = x * camera.w;
  // float h = y * camera.h;
  // t_vector vw = multiply_vector(camera.right, w);
  // t_vector vh = multiply_vector(camera.up, h);

  // ray.origin = camera.origin;
  // ray.direction =
  //     normalize_vector(add_vector(add_vector(vh, vw), camera.forward));

  // return (ray);

  // float imageAspectRatio = (float)minirt.scene->resolution.width / (float)minirt.scene->resolution.height; // assuming width > height
  // float Px = (2 * ((x + 0.5) / minirt.scene->resolution.width) - 1) * tan(camera.fov / 2 * PI / 180) * imageAspectRatio;
  // float Py = (1 - 2 * ((y + 0.5) / minirt.scene->resolution.height) * tan(camera.fov / 2 * PI / 180));
  // t_vector rayOrigin = camera.origin;
  // t_vector rayDirection = {Px, Py, 1}; // note that this just equal to Vec3f(Px, Py, -1);
  // rayDirection = substract_vector(rayDirection, rayOrigin);
  // rayDirection = normalize_vector(rayDirection); // i

  // ray.origin = rayOrigin;
  // ray.direction = rayDirection;

  float w;
  float h;
  float fov;
  t_vector pixel;
  //t_vector axis;

  //axis = (t_vector){0, 1, 0};
  fov = camera.fov;
  w = minirt.scene->resolution.width;
  h = minirt.scene->resolution.height;
  pixel.x = (2 * (((float)x + 0.5) / w) - 1) * (w / h) * tan((fov / 2) * (PI / 180));
  pixel.y = (1 - 2 * (((float)y + 0.5) / h)) * tan((fov / 2) * (PI / 180));
  pixel.z = 1;
  // if (!(camera.direction.x == 0 && camera.direction.y > 0 &&
  //       camera.direction.z == 0))
  //   pixel = apply_rot(pixel, camera.direction, axis);
  ray.direction = normalize_vector(pixel);
  ray.origin = camera.origin;
  if (y == 1)
    printf("x=%.0f, y=%.0f, ray o = (%.2f,%.2f,%.2f) ray d = (%.2f,%.2f,%.2f)\n", x, y, ray.origin.x, ray.origin.y, ray.origin.z, ray.direction.x, ray.direction.y, ray.direction.z);
  return (ray);
}

// ray to (249,96) direction => origin (0.0,0.0,0.0) direction (0.6,-0.1,0.8)
// ray to (249,96) direction => origin (0.0,0.0,0.0) direction (0.6,-0.1,0.8)