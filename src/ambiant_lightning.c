
#include "minirt.h"

int create_ambiant_ligntning(char *value,
                             t_ambiant_ligntning *ambiant_ligntning) {
  char **values;
  values = ft_split(value, ' ');
  if (get_length(values) != 2 ||
      get_ratio(values[0], &ambiant_ligntning->ratio) == 0 ||
      get_color(values[1], &ambiant_ligntning->color) == 0) {
    printf("Ambiant lightning invalid value '%s'\n", value);
    free_values((void **)values);
    return -1;
  }

  return (0);
}