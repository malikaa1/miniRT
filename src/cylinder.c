#include "libft.h"
#include "minirt.h"

int set_cylinder_origin(char *value, t_cylinder *cylinder) {
  if (create_vector(value, &cylinder->origin) == -1) {
    printf("wrong orgin %s for cylinder\n", value);
    return (-1);
  }
  return (0);
}

int set_cylinder_direction(char *value, t_cylinder *cylinder) {
  if (create_vector(value, &cylinder->direction) == -1) {
    printf("wrong direction value '%s' for cylinder\n", value);
    return (-1);
  }
  return (0);
}

int set_cylinder_color(char *value, t_cylinder *cylinder) {
  if (parse_color(value, &cylinder->color) == -1) {
    printf("wrong color %s for cylinder", value);
    return (-1);
  }
  return (0);
}

int set_cylinder_diameter(char *value, t_cylinder *cylinder) {
  double size;
  if (is_valid_float(value) == 0) {
    printf("wrong diameter value '%s' for cylinder\n", value);
    return (-1);
  }

  size = ft_atof(value);
  cylinder->diameter = size;

  return (0);
}

int set_cylinder_height(char *value, t_cylinder *cylinder) {
  double size;
  if (is_valid_float(value) == 0) {
    printf("wrong height value '%s' for cylinder\n", value);
    return (-1);
  }

  size = ft_atof(value);
  cylinder->height = size;

  return (0);
}

int parse_cylinder(char *value, t_cylinder *cylinder) {
  char **values;

  values = ft_split(value, ' ');
  if (get_length(values) != 5) {
    printf("wrong values '%s' for cylinder\n", value);
    return (-1);
  }

  if (set_cylinder_origin(values[0], cylinder) == -1)
    return (-1);

  if (set_cylinder_direction(values[1], cylinder) == -1)
    return (-1);

  if (set_cylinder_diameter(values[2], cylinder) == -1)
    return (-1);

  if (set_cylinder_height(values[3], cylinder) == -1)
    return -1;

  if (set_cylinder_color(values[4], cylinder) == -1)
    return -1;

  return (0);
}