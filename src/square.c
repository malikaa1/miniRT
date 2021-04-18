#include "libft.h"
#include "minirt.h"

int set_square_origin(char *value, t_square *square) {
  if (create_vector(value, &square->origin) == -1) {
    printf("wrong orgin %s for square", value);
    return (-1);
  }
  return (0);
}

int set_square_direction(char *value, t_square *square) {
  if (create_vector(value, &square->direction) == -1) {
    printf("wrong direction %s for square", value);
    return (-1);
  }
  return (0);
}

int set_square_color(char *value, t_square *square) {
  if (parse_color(value, &square->color) == -1) {
    printf("wrong color %s for square", value);
    return (-1);
  }
  return (0);
}

int set_square_size(char *value, t_square *square) {
  double size;
  if (is_valid_float(value) == 0) {
    printf("wrong size value %s for square", value);
    return (-1);
  }

  size = ft_atof(value);
  square->size = size;

  return (0);
}

int create_square(char *value, t_square *square) {
  char **values;

  values = ft_split(value, ' ');
  if (get_length(values) != 4) {
    printf("wrong values %s for square", value);
    return (-1);
  }

  if (set_square_origin(values[0], square) == -1)
    return (-1);

  if (set_square_direction(values[1], square) == -1)
    return (-1);

  if (set_square_size(values[2], square) == -1)
    return -1;
  if (set_square_color(values[3], square) == -1)
    return -1;

  return (0);
}