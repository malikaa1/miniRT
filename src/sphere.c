#include "libft.h"
#include "minirt.h"
#include <math.h>

int set_sphere_origin(char *value, t_sphere *sphere)
{
  if (create_vector(value, &sphere->origin) == -1)
  {
    printf("wrong orgin %s for sphere", value);
    return (-1);
  }
  return (0);
}

int set_sphere_color(char *value, t_sphere *sphere)
{
  if (parse_color(value, &sphere->color) == -1)
  {
    printf("wrong color %s for sphere", value);
    return (-1);
  }
  return (0);
}

int set_sphere_raduis(char *value, t_sphere *sphere)
{
  double size;
  if (is_valid_float(value) == 0)
  {
    printf("wrong size value %s for sphere", value);
    return (-1);
  }

  size = ft_atof(value);
  sphere->raduis = size;

  return (0);
}

int create_sphere(char *value, t_sphere *sphere)
{
  char **values;

  values = ft_split(value, ' ');
  if (get_length(values) != 3)
  {
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

int intersect_sphere(t_sphere *s, t_intersection *intersection)
{
  // t_ray l_ray = intersection->ray;
  // l_ray.origin = substract_vector(l_ray.origin, s->origin);
  // float a, b, c, discriminant, t1, t2;

  // a = l_ray.direction.x * l_ray.direction.x +
  //     l_ray.direction.y * l_ray.direction.y +
  //     l_ray.direction.z * l_ray.direction.z;

  // b = 2 * dot_vector(l_ray.direction, l_ray.origin);
  // c = l_ray.origin.x * l_ray.origin.x + l_ray.origin.y * l_ray.origin.y +
  //     l_ray.origin.z * l_ray.origin.z - s->raduis * s->raduis;

  // discriminant = b * b - 4 * a * c;
  // if (discriminant < 0)
  //   return (0);
  // t1 = (-b - sqrt(discriminant)) / (2 * a);
  // t2 = (-b + sqrt(discriminant)) / (2 * a);
  // if (t1 > MIN_VALUE && t1 < intersection->t)
  // {
  //   intersection->t = t1;
  //   return (1);
  // }
  // if (t2 > MIN_VALUE && t2 < intersection->t)
  // {
  //   intersection->t = t2;
  //   return (1);
  // }
  // return (0);

  // float a, b, c, d, t1, t2;
  // a = dot_vector(intersection->ray.origin, intersection->ray.direction);
  // b = 2 * dot_vector(intersection->ray.direction, substract_vector(intersection->ray.origin, s->origin));
  // c = get_vector_length(substract_vector(intersection->ray.origin, s->origin)) - (s->raduis * s->raduis);
  // d = b * b - 4 * a * c;
  // if (d < 0)
  //   return (0);
  // t1 = (-b - sqrt(d)) / (2 * a);
  // t2 = (-b + sqrt(d)) / (2 * a);
  // if (t1 > MIN_VALUE && t1 < intersection->t)
  // {
  //   intersection->t = t1;
  //   return (1);
  // }
  // if (t2 > MIN_VALUE && t2 < intersection->t)
  // {
  //   intersection->t = t2;
  //   return (1);
  // }
  // return (0);

  float a, b, c, d, t1, t2;
  t_vector sub = substract_vector(intersection->ray.origin, s->origin);
  a = dot_vector(intersection->ray.direction, intersection->ray.direction);
  b = 2 * dot_vector(intersection->ray.direction, sub);
  c = dot_vector(sub, sub) - s->raduis * s->raduis;
  d = b * b - (4 * a * c);
  if (d < 0)
    return (0);
  d = sqrt(d);
  a = 2 * a;
  t1 = (-b - d) / a;
  t2 = (-b + d) / a;
  if (t1 > MIN_VALUE && t1 < intersection->t)
  {
    intersection->t = t1;
    return (1);
  }
  if (t2 > MIN_VALUE && t2 < intersection->t)
  {
    intersection->t = t2;
    return (1);
  }
  return (0);
}

int intersect_spheres(t_minirt *minirt, t_intersection *intersection)
{
  t_list *spheres;
  t_sphere *sphere;
  int does_interset;
  does_interset = 0;
  spheres = minirt->scene->spheres;

  while (spheres != NULL)
  {
    sphere = spheres->content;
    if (intersect_sphere(sphere, intersection) == 1)
    {
      intersection->object_type = SPHERE;
      intersection->position = add_vector(
          intersection->ray.origin,
          multiply_vector(intersection->ray.direction, intersection->t));
      intersection->normal = normalize_vector(
          substract_vector(intersection->position, sphere->origin));
      intersection->object_color = sphere->color;

      does_interset = 1;
      intersection->does_intersect = does_interset;
    }
    spheres = spheres->next;
  }

  return (does_interset);
}