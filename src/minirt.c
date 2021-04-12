#include "minirt.h"

int init_minirt(t_minirt *minirt) {

  minirt->save = 0;
  minirt->mlx = NULL;
  minirt->scene_file = NULL;
  minirt->window = NULL;

  minirt->scene = malloc(sizeof(t_scene));
  if (minirt->scene == NULL) {
    printf("an error occured");
    return -1;
  }

  minirt->scene->ambiant_ligntning = (t_ambiant_ligntning){0, {0, 0, 0}};
  minirt->scene->resolution = (t_resolution){0, 0};
  minirt->scene->cameras = NULL;
  minirt->scene->lights = NULL;
  minirt->scene->planes = NULL;
  minirt->scene->squares = NULL;
  minirt->scene->spheres = NULL;
  minirt->scene->cylinders = NULL;
  minirt->scene->triangles = NULL;

  return (0);
}