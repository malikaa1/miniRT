#include "libft.h"
#include "minirt.h"

int set_light_position(char *value, t_light *light) {
  if (create_vector(value, &light->position) == -1) {
    printf("wrong position %s for light", value);
    return (-1);
  }
  return (0);
}

int set_light_color(char *value, t_light *light) {
  if (parse_color(value, &light->color) == -1) {
    printf("wrong color %s for light", value);
    return (-1);
  }
  return (0);
}

int set_light_brightness(char *value, t_light *light) {

  double ratio;
  if (is_valid_float(value) == -1) {
    printf("wrong brightness value %s for light", value);
    return (-1);
  }
  ratio = ft_atof(value);
  if (is_in_range(ratio, -1, 1) == -1) {
    printf("wrong brightness range %s for light", value);
    return (-1);
  }
  light->brightness = ratio;

  return (0);
}

int parse_light(char *value, t_light *light) {
  char **values;

  values = ft_split(value, ' ');
  if (get_length(values) != 3) {
    printf("wrong values %s for light", value);
    return (-1);
  }

  if (set_light_position(values[0], light) == -1)
    return (-1);

  if (set_light_brightness(values[1], light) == -1)
    return (-1);

  if (set_light_color(values[2], light) == -1)
    return -1;

  return (0);
}