/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:32:03 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/05 21:01:22 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void init_supported_objects(const char **objects) {

  objects[0] = "R";
  objects[1] = "A";
  objects[2] = "c";
  objects[3] = "l";
  objects[4] = "pl";
  objects[5] = "sp";
  objects[6] = "sq";
  objects[7] = "cy";
  objects[8] = "tr";
}

int get_length(char **values) {
  int length = 0;
  while (*values != NULL) {
    values++;
    length++;
  }
  return length;
}

int is_empty(char *line) { return ft_strlen(line) == 0; }

int is_valid_line(char *line) {
  const char *objs[9];
  char *obj;
  unsigned int i;
  i = 0;
  init_supported_objects(objs);
  while (i < sizeof(objs) / sizeof(char *)) {
    obj = ft_substr(line, 0, ft_strlen(objs[i]));
    if (obj == NULL)
      return (0);
    if (ft_strcmp(obj, objs[i]) == 0) {
      free(obj);
      return (1);
    }
    free(obj);
    i++;
  }
  return (0);
}

int is_space(char c) {
  if (c == ' ')
    return 1;
  return 0;
}

int is_valid_color_component(char *color_component) {
  int color;
  if (is_valid_int(color_component) == 0)
    return 0;

  color = ft_atoi(color_component);

  return color >= 0 && color <= 255;
}

int try_get_ratio(char *value, double *ratio) {
  double v;
  if (is_valid_float(value) == 0) {
    return 0;
  }

  v = ft_atof(value);
  if (v >= 0 && v <= 1) {
    *ratio = v;
    return 1;
  }

  return 0;
}

int try_get_color(char *value, t_color *color) {
  char **parts;
  parts = ft_split(value, ',');
  if (get_length(parts) != 3)
    return 0;
  if (is_valid_color_component(parts[0]) == 0 ||
      is_valid_color_component(parts[1]) == 0 ||
      is_valid_color_component(parts[2]) == 0)
    return 0;

  color->r = ft_atoi(parts[0]);
  color->g = ft_atoi(parts[0]);
  color->b = ft_atoi(parts[0]);
  return 1;
}

int create_scene_resolution(t_minirt *minirt, char *value) {
  t_resolution resolution;
  char **split;
  char *width;
  char *height;
  split = ft_split(value, ' ');
  if (split == NULL) {
    printf("Wrong resolution value '%s'", value);
    return (-1);
  }
  width = *split++;
  height = *split;
  if (is_valid_int(width) == 0 || is_valid_int(height) == 0) {
    printf("Wrong resolution value '%s'", value);
    return (-1);
  }
  resolution.height = ft_atoi(height);
  resolution.wdith = ft_atoi(width);
  minirt->scene->resolution = resolution;
  return (0);
}

int create_ambiant_ligntning(t_minirt *minirt, char *value) {
  t_ambiant_ligntning ambiant_ligntning;
  char **values;
  values = ft_split(value, ' ');
  if (get_length(values) != 2 ||
      try_get_ratio(values[0], &ambiant_ligntning.ratio) == 0 ||
      try_get_color(values[1], &ambiant_ligntning.color) == 0) {
    printf("Ambiant lightning invalid value '%s'\n", value);
    free_values((void **)values);
    return -1;
  }
  minirt->scene->ambiant_ligntning = ambiant_ligntning;

  return (0);
}

int create_scene_object(t_minirt *minirt, char *key, char *value) {
  if (strcmp(key, "R") == 0)
    return (create_scene_resolution(minirt, value));
  if (strcmp(key, "A") == 0)
    return (create_ambiant_ligntning(minirt, value));
  return (-1);
}

int parse_scene_line(t_minirt *minirt, char *line) {
  char *key;
  char *value;
  int i;
  int j;
  i = 0;
  if (is_valid_line(line) == 0) {
    printf("Invalid data '%s' \n", line);
    return -1;
  }
  while (line[i] != '\n' && is_space(line[i]) == 0)
    i++;
  key = ft_substr(line, 0, i);
  j = i;
  while (line[i] != '\0')
    i++;
  value = ft_strtrim(ft_substr(line, j, i), " ");
  i = create_scene_object(minirt, key, value);
  free_value(key);
  free_value(value);
  return i;
}

int parse_scene(t_minirt *minirt) {

  int fd;
  char *line;
  int line_read;
  int result;
  line_read = 1;
  fd = open(minirt->scene_file, O_RDONLY);
  if (fd == -1) {
    perror("Cannot open scene file");
    return -1;
  }

  while (line_read == 1) {
    line_read = get_next_line(fd, &line);
    if (is_empty(line) == 1)
      continue;
    result = parse_scene_line(minirt, line);
    if (result == -1) {
      free_value(line);
      return -1;
    }
  }
  return 0;
}
