#include "minirt.h"

int parse_resolution(char *value, int *x, int *y) {
  char **split;
  char *width;
  char *height;
  split = ft_split(value, ' ');
  if (split == NULL) {
    printf("Wrong resolution value '%s'\n", value);
    return (-1);
  }
  width = *split++;
  height = *split;
  if (is_valid_int(width) == 0 || is_valid_int(height) == 0) {
    printf("Wrong resolution value '%s'\n", value);
    return (-1);
  }

  *x = ft_atoi(width);
  *y = ft_atoi(height);
  return 0;
}

int get_resolution(char *value, t_resolution *resolution) {
  int x;
  int y;

  if (parse_resolution(value, &x, &y) == -1)
    return -1;

  resolution->width = x;
  resolution->height = y;

  return (0);
}