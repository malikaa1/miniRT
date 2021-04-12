#include "libft.h"
#include "minirt.h"

int set_camera_origin(char *value, t_camera *camera) {
  if (create_vector(value, &camera->origin) == -1) {
    printf("wrong orgin %s for camera", value);
    return (-1);
  }
  return (0);
}

int set_camera_direction(char *value, t_camera *camera) {
  if (create_vector(value, &camera->direction) == -1) {
    printf("wrong direction %s for camera", value);
    return (-1);
  }
  return (0);
}

int set_camera_fied_of_view(char *value, t_camera *camera) {

  double fov;
  if (is_valid_float(value) == -1) {
    printf("wrong field of view %s for camera", value);
    return (-1);
  }
  fov = ft_atof(value);
  camera->horizontal_field_of_view = fov;

  return (0);
}

int create_camera(char *value, t_camera *camera) {
  char **values;

  values = ft_split(value, ' ');
  if (get_length(values) != 3) {
    printf("wrong values %s for camera", value);
    return (-1);
  }

  if (set_camera_origin(values[0], camera) == -1)
    return (-1);

  if (set_camera_direction(values[1], camera) == -1)
    return (-1);

  if (set_camera_fied_of_view(values[2], camera) == -1)
    return -1;

  return (0);
}