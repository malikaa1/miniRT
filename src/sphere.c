#include "libft.h"
#include "minirt.h"
#include <math.h>

int set_sphere_origin(char *value, t_sphere *sphere) {
  if (create_vector(value, &sphere->origin) == -1) {
    printf("wrong orgin %s for sphere", value);
    return (-1);
  }
  return (0);
}

int set_sphere_color(char *value, t_sphere *sphere) {
  if (parse_color(value, &sphere->color) == -1) {
    printf("wrong color %s for sphere", value);
    return (-1);
  }
  return (0);
}

int set_sphere_raduis(char *value, t_sphere *sphere) {
  double size;
  if (is_valid_float(value) == 0) {
    printf("wrong size value %s for sphere", value);
    return (-1);
  }

  size = ft_atof(value);
  sphere->raduis = size;

  return (0);
}

int create_sphere(char *value, t_sphere *sphere) {
  char **values;

  values = ft_split(value, ' ');
  if (get_length(values) != 3) {
    printf("wrong values '%s' for sphere\n", value);
    return (-1);
  }

  if (set_sphere_origin(values[0], sphere) == -1)
    return (-1);

  if (set_sphere_raduis(values[1], sphere) == -1)
    return (-1);

  if (set_sphere_color(values[2], sphere) == -1)
    return -1;

  return (0);
}

int intersect_sphere(t_sphere *s, t_ray *r, double *t) {
  // t_vector v;
  // v = substract_vector(ray->origin, sphere->origin);
  // float a = dot_vector(ray->direction, ray->direction);
  // float b = 2.0 * dot_vector(v, ray->direction);
  // float c = dot_vector(v, v) - sphere->raduis * sphere->raduis;
  // float discriminant = b * b - 4 * a * c;
  // if (discriminant < 0) {
  //   return (0);
  // } else {
  //   *t = (-b - sqrt(discriminant)) / (2.0 * a);
  //   return (1);
  // }
  t_ray *l_ray = r;
  l_ray->origin = substract_vector(l_ray->origin, s->origin);
  float a, b, c, discriminant, t1, t2;

  a = l_ray->direction.x * l_ray->direction.x +
      l_ray->direction.y * l_ray->direction.y +
      l_ray->direction.z * l_ray->direction.z;

  b = 2 * dot_vector(l_ray->direction, l_ray->origin);
  c = l_ray->origin.x * l_ray->origin.x + l_ray->origin.y * l_ray->origin.y +
      l_ray->origin.z * l_ray->origin.z - s->raduis * s->raduis;

  discriminant = b * b - 4 * a * c;
  if (discriminant < 0)
    return (0);
  t1 = (-b - sqrt(discriminant)) / (2 * a);
  t2 = (-b + sqrt(discriminant)) / (2 * a);
  if (t1 > 0) {
    *t = t1;
    return (1);
  }
  if (t2 > 0) {
    *t = t2;
    return (1);
  }
  return (0);
}

int intersect_spheres(t_minirt *minirt, t_ray *ray) {
  t_list *spheres;
  t_sphere *sphere;
  double t;
  int does_interset;
  does_interset = 0;
  spheres = minirt->scene->spheres;

  while (spheres != NULL) {
    sphere = spheres->content;
    if (intersect_sphere(sphere, ray, &t) == 1 && t > MIN_VALUE &&
        t < minirt->t) {
      minirt->t = t;
      does_interset = 1;
    }
    spheres = spheres->next;
  }

  return (does_interset);
}