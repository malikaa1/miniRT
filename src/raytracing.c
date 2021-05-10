#include "minirt.h"

t_color compute_ambiant_color(t_minirt *minirt, t_intersection *inersection)
{

  t_color object_color;
  t_color ambiant_light_color;
  t_color color;

  // object_color*ambiant_color*ratio
  object_color = divide_color(inersection->object_color, 255);
  ambiant_light_color =
      divide_color(minirt->scene->ambiant_ligntning.color, 255);

  color = multiply_colors(
      object_color, multiply_color(ambiant_light_color,
                                   minirt->scene->ambiant_ligntning.ratio));
  return color;
}

int intersect(t_minirt *minirt, t_intersection *intersection)
{
  if (intersect_spheres(minirt, intersection) == 1)
  {
    return (1);
  }

  return (0);
}

t_intersection is_in_shadow(t_minirt *minirt, t_intersection *inersection, t_light *light)
{
  t_ray light_ray;
  t_intersection light_intersection;

  light_ray = (t_ray){.origin = {0, 0, 0}, .direction = {0, 0, 0}};
  light_intersection = (t_intersection){.t = MAX_VALUE, .ray = light_ray, .normal = V_ZERO, .position = V_ZERO, .object_type = 0};
  light_ray.origin = light->position;
  light_ray.direction = normalize_vector(substract_vector(inersection->position, light->position));
  light_intersection.ray = light_ray;
  intersect(minirt, &light_intersection);
  return (light_intersection);
}

t_color compute_diffuse_color(t_minirt *minirt, t_intersection *inersection)
{
  t_list *lights;
  t_light *light;
  t_intersection light_intersection;
  float diffuse;
  t_color color;

  lights = minirt->scene->lights;
  color = BLACK;

  while (lights != NULL)
  {
    light = lights->content;
    // check shadow
    light_intersection = is_in_shadow(minirt, inersection, light);
    if (light_intersection.does_intersect == 0)
    {
      diffuse = dot_vector(light_intersection.ray.direction, inersection->normal);
      color = add_color(color, multiply_color(divide_color(light->color, 255), light->brightness * diffuse));
    }

    lights = lights->next;
  }
  return (color);
}

t_color compute_color(t_minirt *minirt, t_intersection *intersection)
{

  t_color ambiant;
  t_color diffuse;
  t_color color;

  // ambiant
  ambiant = compute_ambiant_color(minirt, intersection);
  //diffuse
  diffuse = compute_diffuse_color(minirt, intersection);

  color = add_color(ambiant, diffuse);

  color = clamp_color(color);

  return multiply_color(color, 255);
}

t_color raytrace(t_minirt *minirt, t_intersection *intersection)
{

  t_color color = BLACK;
  if (intersect(minirt, intersection) == 1)
  {
    color = (t_color){255, 255, 255}; //compute_color(minirt, intersection);
    //printf("color = %f %f %f\n", color.r, color.g, color.b);
  }
  return color;
}