#include "libft.h"
#include "minirt.h"

int set_triangle_p1(char *value, t_triangle *triangle) {
  if (create_vector(value, &triangle->p1) == -1) {
    printf("wrong point value '%s' for triangle\n", value);
    return (-1);
  }
  return (0);
}

int set_triangle_p2(char *value, t_triangle *triangle) {
  if (create_vector(value, &triangle->p2) == -1) {
    printf("wrong point value '%s' for triangle\n", value);
    return (-1);
  }
  return (0);
}

int set_triangle_p3(char *value, t_triangle *triangle) {
  if (create_vector(value, &triangle->p3) == -1) {
    printf("wrong point value '%s' for triangle\n", value);
    return (-1);
  }
  return (0);
}

int set_triangle_color(char *value, t_triangle *triangle) {
  if (get_color(value, &triangle->color) == -1) {
    printf("wrong color %s for triangle", value);
    return (-1);
  }
  return (0);
}

int create_triangle(char *value, t_triangle *triangle) {
  char **values;

  values = ft_split(value, ' ');
  if (get_length(values) != 4) {
    printf("wrong values '%s' for triangle\n", value);
    return (-1);
  }

  if (set_triangle_p1(values[0], triangle) == -1)
    return (-1);

  if (set_triangle_p2(values[1], triangle) == -1)
    return (-1);

  if (set_triangle_p3(values[2], triangle) == -1)
    return (-1);

  if (set_triangle_color(values[3], triangle) == -1)
    return (-1);

  return (0);
}