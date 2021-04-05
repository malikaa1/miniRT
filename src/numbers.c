#include "libft.h"
#include "minirt.h"
#include <math.h>

int is_valid_int(char *value) {
  int i;
  i = 0;
  if (value[i] == '-' || value[i] == '+')
    i++;

  while (value[i] != '\0') {
    if (ft_isdigit(value[i]) == 0)
      return 0;
    i++;
  }
  return 1;
}

int is_valid_float(char *value) {

  char **parts;
  char *decimal_part;
  char *floating_part;

  parts = ft_split(value, '.');
  decimal_part = *parts++;
  floating_part = *parts;

  if (decimal_part == NULL || is_valid_int(decimal_part) == 0) {
    free_values((void **)parts);
    return (0);
  }

  if (floating_part != NULL && is_valid_int(floating_part) == 0) {
    free_values((void **)parts);
    return (0);
  }

  return (1);
}

double ft_atof(char *value) {
  double result;
  char **parts;
  int int_value;
  char *digits_only_value;
  int floating_part_length;
  result = 0;
  if (is_valid_int(value)) {
    result = ft_atoi(value);
    return result;
  }

  parts = ft_split(value, '.');
  floating_part_length = ft_strlen(parts[1]);
  digits_only_value = ft_strjoin(parts[0], parts[1]);
  int_value = ft_atoi(digits_only_value);
  result = int_value * pow(10, floating_part_length * -1);

  free_values((void **)parts);
  free_value((void *)digits_only_value);

  return result;
}