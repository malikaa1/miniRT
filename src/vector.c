#include "libft.h"
#include "minirt.h"

int create_vector(char *value, t_vector *vector) {
  char **values;
  values = ft_split(value, ',');
  if (get_length(values) != 3) {
    return (-1);
  }

  if (is_valid_float(values[0]) == 0 || is_valid_float(values[1]) == 0 ||
      is_valid_float(values[2]) == 0)
    return (-1);

  vector->x = ft_atof(values[0]);
  vector->y = ft_atof(values[1]);
  vector->z = ft_atof(values[2]);

  return (0);
}