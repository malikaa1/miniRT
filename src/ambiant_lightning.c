
#include "minirt.h"

int parse_ambiant_ligntning(char *value,
                            t_ambiant_ligntning *ambiant_ligntning) {
  char **values;
  values = ft_split(value, ' ');
  if (get_length(values) != 2 ||
      get_ratio(values[0], &ambiant_ligntning->ratio) == 0 ||
      parse_color(values[1], &ambiant_ligntning->color) == 0) {
    free_values((void **)values);
    return (handle_error("invalid value for ambiant lightning"));
  }

  return (0);
}