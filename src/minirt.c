#include "minirt.h"
#include "mlx.h"

int init_minirt(t_minirt *minirt) {

  minirt->save = 0;
  minirt->mlx = mlx_init();
  minirt->scene_file = NULL;
  minirt->window = NULL;
  minirt->scene = malloc(sizeof(t_scene));
  if (minirt->scene == NULL) {
    return (handle_error("unable to create scene"));
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
  minirt->scene->current_camera = NULL;
  minirt->scene->number_of_cameras = 0;
  minirt->scene->current_camera_id = 0;
  return (0);
}

int run_minirt(t_minirt *minirt) {
  printf("Rendering ...\n");
  setup_cameras(minirt);
  draw_scene(minirt);
  return (0);
}