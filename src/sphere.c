#include "libft.h"
#include "minirt.h"

int set_sphere_origin(char *value, t_sphere *sphere) {
  if (create_vector(value, &sphere->origin) == -1) {
    printf("wrong orgin %s for sphere", value);
    return (-1);
  }
  return (0);
}

int set_sphere_color(char *value, t_sphere *sphere) {
  if (get_color(value, &sphere->color) == -1) {
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