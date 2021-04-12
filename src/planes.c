#include "libft.h"
#include "minirt.h"

int set_plane_origin(char *value, t_plane *plane) {
  if (create_vector(value, &plane->origin) == -1) {
    printf("wrong orgin %s for plane", value);
    return (-1);
  }
  return (0);
}

int set_plane_direction(char *value, t_plane *plane) {
  if (create_vector(value, &plane->direction) == -1) {
    printf("wrong direction %s for plane", value);
    return (-1);
  }
  return (0);
}

int set_plane_color(char *value, t_plane *plane) {
  if (get_color(value, &plane->color) == -1) {
    printf("wrong color %s for plane", value);
    return (-1);
  }
  return (0);
}

int create_plane(char *value, t_plane *plane) {
  char **values;

  values = ft_split(value, ' ');
  if (get_length(values) != 3) {
    printf("wrong values %s for plane", value);
    return (-1);
  }

  if (set_plane_origin(values[0], plane) == -1)
    return (-1);

  if (set_plane_direction(values[1], plane) == -1)
    return (-1);

  if (set_plane_color(values[2], plane) == -1)
    return -1;

  return (0);
}