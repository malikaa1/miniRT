#include "libft.h"
#include "math.h"
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
  if (is_valid_float(value) == 0) {
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

int init_camera(t_camera *camera, float aspect_ratio) {
  // t_vector u;
  // t_vector v;
  // t_vector w;
  // float vh;
  // float vw;

  // vh = tan((camera->fov * PI / 180) / 2);
  // vw = aspect_ratio * vh;
  // camera->up = (t_vector){0, 1, 0};
  // w = normalize_vector(substract_vector(camera->origin, camera->direction));
  // u = normalize_vector(cross_vector(camera->up, w));
  // v = cross_vector(w, u);
  // // camera->lower_left_corner = (t_vector) { -vw, -vh, -1.0 };
  // camera->lower_left_corner = substract_vector(
  //     camera->origin,
  //     substract_vector(
  //         (substract_vector(multiply_vector(u, vw), multiply_vector(v, vh))),
  //         w));

  // camera->horizontal = multiply_vector(u, 2 * vw);
  // camera->vertical = multiply_vector(v, 2 * vw);
  // return (1);

  // double vh;
  // double vw;
  // t_vector u;
  // t_vector w;

  // if (camera->direction.x == 0 && camera->direction.z == 0 &&
  //     camera->direction.y != 0)
  //   camera->up = (t_vector){-1, 0, 0};
  // else
  //   camera->up = (t_vector){0, -1, 0};
  // vh = 2 * tan((camera->fov * PI / 180) / 2);
  // vw = aspect_ratio * vh;
  // w = normalize_vector(substract_vector(
  //     camera->origin,
  //     add_vector(camera->origin, normalize_vector(camera->direction))));
  // u = normalize_vector(cross_vector(camera->up, w));
  // camera->horizontal = multiply_vector(u, vw);
  // camera->vertical =
  //     multiply_vectors(multiply_vector(cross_vector(w, u), vh), camera->up);
  // camera->lower_left_corner = substract_vector(
  //     camera->origin, multiply_vector(camera->horizontal, 0.5));
  // camera->lower_left_corner =
  //     substract_vector(substract_vector(camera->lower_left_corner,
  //                                       multiply_vector(camera->vertical,
  //                                       0.5)),
  //                      w);

  // printf("%-20s=> origin: (%.1f,%.1f,%.1f) direction: (%.1f,%.1f,%.1f) fov: "
  //        "%.1f up(%.1f,%.1f,%.1f) horz (%.1f,%.1f,%.1f) vert (%.1f,%.1f,%.1f)
  //        " "left (%.1f,%.1f,%.1f)\n", "camera", camera->origin.x,
  //        camera->origin.y, camera->origin.z, camera->direction.x,
  //        camera->direction.y, camera->direction.z, camera->fov, camera->up.x,
  //        camera->up.y, camera->up.z, camera->horizontal.x,
  //        camera->horizontal.y, camera->horizontal.z, camera->vertical.x,
  //        camera->vertical.y, camera->vertical.z, camera->lower_left_corner.x,
  //        camera->lower_left_corner.y, camera->lower_left_corner.z);

  // camera->origin = (t_vector){-5.0f, 1.0f, 0.0f};
  // camera->direction = (t_vector){0.0f, 1.0f, 0.0f};
  camera->up = (t_vector){0.0f, 1.0f, 0.0f};
  camera->forward =
      normalize_vector(substract_vector(camera->direction, camera->origin));
  camera->right = normalize_vector(cross_vector(camera->forward, camera->up));

  camera->up = cross_vector(camera->right, camera->forward);

  camera->h = tan(camera->fov * PI / 180.0f);
  camera->w = camera->h * aspect_ratio;
  printf("vw %f,vh %f\n", camera->w, camera->h);

  return (1);
}

int setup_cameras(t_minirt *minirt) {

  t_list *cameras_list;
  t_camera *current_camera;
  cameras_list = minirt->scene->cameras;
  while (cameras_list != NULL) {

    current_camera = cameras_list->content;
    init_camera(current_camera, (double)minirt->scene->resolution.width /
                                    (double)minirt->scene->resolution.height);
    current_camera->image->image =
        mlx_new_image(minirt->mlx, minirt->scene->resolution.width,
                      minirt->scene->resolution.height);

    current_camera->image->address = mlx_get_data_addr(
        current_camera->image->image, &current_camera->image->bits_per_pixel,
        &current_camera->image->size_line, &current_camera->image->endian);
    if (minirt->scene->current_camera == NULL) {
      minirt->scene->current_camera = current_camera;
    }
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
                          minirt->scene->current_camera->image->image, 0, 0);
  return (0);
}
