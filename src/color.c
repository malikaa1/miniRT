#include "minirt.h"

int is_valid_color_component(char *color_component)
{
  int color;
  if (is_valid_int(color_component) == 0)
    return 0;

  color = ft_atoi(color_component);

  return color >= 0 && color <= 255;
}

int parse_color(char *value, t_color *color)
{
  char **parts;
  parts = ft_split(value, ',');
  if (get_length(parts) != 3)
    return 0;
  if (is_valid_color_component(parts[0]) == 0 ||
      is_valid_color_component(parts[1]) == 0 ||
      is_valid_color_component(parts[2]) == 0)
    return 0;

  color->r = ft_atoi(parts[0]);
  color->g = ft_atoi(parts[1]);
  color->b = ft_atoi(parts[2]);
  return 1;
}

int create_rgb(t_color c, int endian)
{
  int t;

  t = 0;
  if (endian == 0)
    return (t << 24 | (int)c.r << 16 | (int)c.g << 8 | (int)c.b);
  return ((int)c.b << 24 | (int)c.g << 16 | (int)c.r << 8 | t);
}

t_color multiply_colors(t_color c1, t_color c2)
{
  t_color c;

  c.r = c1.r * c2.r;
  c.g = c1.g * c2.g;
  c.b = c1.b * c2.b;
  return (c);
}

t_color multiply_color(t_color color, double a)
{
  t_color c;

  c.r = color.r * a;
  c.g = color.g * a;
  c.b = color.b * a;
  return (c);
}

t_color divide_color(t_color color, double a)
{
  t_color c;

  c.r = color.r / a;
  c.g = color.g / a;
  c.b = color.b / a;
  return (c);
}

t_color add_color(t_color c1, t_color c2)
{
  t_color c;

  c.r = c1.r + c2.r;
  c.g = c1.g + c2.g;
  c.b = c1.b + c2.b;
  return (c);
}

t_color clamp_color(t_color color)
{
  t_color c;

  c.r = fmax(fmin(color.r, 0.999), 0.);
  c.g = fmax(fmin(color.g, 0.999), 0.);
  c.b = fmax(fmin(color.b, 0.999), 0.);
  return (c);
}
