#include "libft.h"
#include "math.h"
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

t_vector add_vector(t_vector v1, t_vector v2) {
  t_vector v;

  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  v.z = v1.z + v2.z;
  return (v);
}

t_vector substract_vector(t_vector v1, t_vector v2) {
  t_vector v;

  v.x = v1.x - v2.x;
  v.y = v1.y - v2.y;
  v.z = v1.z - v2.z;
  return (v);
}

t_vector multiply_vector(t_vector v1, float f) {
  t_vector v;

  v.x = v1.x * f;
  v.y = v1.y * f;
  v.z = v1.z * f;
  return (v);
}

t_vector divide_vector(t_vector v1, float f) {
  t_vector v;

  v.x = v1.x / f;
  v.y = v1.y / f;
  v.z = v1.z / f;
  return (v);
}

t_vector negative_vector(t_vector v1) {
  t_vector v;

  v.x = -v1.x;
  v.y = -v1.y;
  v.z = -v1.z;
  return (v);
}

float get_vector_length(t_vector v) {
  float length;

  length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
  return (length);
}

t_vector normalize_vector(t_vector v) {
  float length;
  length = get_vector_length(v);
  return (divide_vector(v, length));
}

float dot_vector(t_vector v1, t_vector v2) {
  return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector cross_vector(t_vector v1, t_vector v2) {
  t_vector v;

  v.x = v1.y * v2.z - v1.z * v2.y;
  v.y = v1.z * v2.x - v1.x * v2.z;
  v.z = v1.x * v2.y - v1.y * v2.x;
  return (v);
}

t_vector multiply_vectors(t_vector v1, t_vector v2) {
  t_vector v;

  v.x = v1.x * v2.x;
  v.y = v1.y * v2.y;
  v.z = v1.z * v2.z;
  return (v);
}