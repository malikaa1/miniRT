#include "libft.h"
#include "minirt.h"
#include "mlx.h"

int set_camera_origin(char *value, t_camera *camera) {
  if (create_vector(value, &camera->origin) == -1) {
    return (handle_error("bad camera origin value"));
  }
  return (0);
}

int set_camera_direction(char *value, t_camera *camera) {
  if (create_vector(value, &camera->direction) == -1) {
    return (handle_error("bad camera direction value"));
  }
  return (0);
}

int set_camera_fied_of_view(char *value, t_camera *camera) {

  double fov;
  if (is_valid_float(value) == -1) {
    return (handle_error("bad camera field of view value"));
  }
  fov = ft_atof(value);
  camera->fov = fov;

  return (0);
}

int parse_camera(char *value, t_camera *camera) {
  char **values;

  values = ft_split(value, ' ');
  if (get_length(values) != 3) {
    return (handle_error("bad camera values"));
  }

  if (set_camera_origin(values[0], camera) == -1)
    return (-1);

  if (set_camera_direction(values[1], camera) == -1)
    return (-1);

  if (set_camera_fied_of_view(values[2], camera) == -1)
    return (-1);

  return (0);
}

int setup_cameras(t_minirt *minirt) {

  t_list *cameras_list;
  t_camera *current_camera;
  cameras_list = minirt->scene->cameras;
  while (cameras_list != NULL) {

    current_camera = cameras_list->content;
    if (minirt->scene->current_camera == NULL) {
      minirt->scene->current_camera = current_camera;
    }

    current_camera->image.image =
        mlx_new_image(minirt->mlx, minirt->scene->resolution.width,
                      minirt->scene->resolution.height);

    current_camera->image.address = mlx_get_data_addr(
        current_camera->image.image, &current_camera->image.bits_per_pixel,
        &current_camera->image.size_line, &current_camera->image.endian);

    cameras_list = cameras_list->next;
  }
  return (0);
}

int switch_camera(t_minirt *minirt) {
  t_camera *current_camera;
  t_list *temp;
  t_list *list;
  current_camera = NULL;
  list = minirt->scene->cameras;
  temp = minirt->scene->cameras;
  while (list != NULL) {
    if (list->content == minirt->scene->current_camera) {
      if (list->next != NULL)
        current_camera = list->next->content;
      break;
    }
    list = list->next;
  }

  if (current_camera == NULL)
    current_camera = temp->content;

  minirt->scene->current_camera = current_camera;
  mlx_put_image_to_window(minirt->mlx, minirt->window,
                          minirt->scene->current_camera->image.image, 0, 0);
  return (0);
}

int init_camera(t_camera *camera, float aspect_ratio) {
  t_vector u;
  t_vector v;
  t_vector w;
  float vh;
  float vw;

  vh = tan((camera->fov * PI / 180) / 2);
  vw = aspect_ratio * vh;
  camera->up = (t_vector){0, 1, 0};
  w = normalize_vector(substract_vector(camera->origin, camera->direction));
  u = normalize_vector(cross_vector(camera->up, w));
  v = cross_vector(w, u);
  // camera->lower_left_corner = (t_vector) { -vw, -vh, -1.0 };
  camera->lower_left_corner = substract_vector(
      camera->origin,
      substract_vector(
          (substract_vector(multiply_vector(u, vw), multiply_vector(v, vh))),
          w));

  camera->horizontal = multiply_vector(u, 2 * vw);
  camera->vertical = multiply_vector(v, 2 * vw);
}