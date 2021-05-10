/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:32:03 by mrahmani          #+#    #+#             */
/*   Updated: 2021/05/06 22:44:55 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void init_supported_objects(const char **objects)
{

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

int get_length(char **values)
{
  int length = 0;
  while (*values != NULL)
  {
    values++;
    length++;
  }
  return length;
}

int is_empty(char *line) { return ft_strlen(line) == 0; }

int is_valid_line(char *line)
{
  const char *objs[9];
  char *obj;
  unsigned int i;
  i = 0;
  init_supported_objects(objs);
  while (i < sizeof(objs) / sizeof(char *))
  {
    obj = ft_substr(line, 0, ft_strlen(objs[i]));
    if (obj == NULL)
      return (0);
    if (ft_strcmp(obj, objs[i]) == 0)
    {
      free(obj);
      return (1);
    }
    free(obj);
    i++;
  }
  return (0);
}

int is_space(char c)
{
  if (c == ' ')
    return 1;
  return 0;
}

int set_scene_resolution(t_minirt *minirt, char *value)
{
  int x;
  int y;
  x = 0;
  y = 0;
  t_resolution resolution;
  if (get_resolution(value, &resolution) == -1)
    return -1;
  mlx_get_screen_size(minirt->mlx, &x, &y);
  if (resolution.width > x)
    resolution.width = x;
  if (resolution.height > y)
    resolution.height = y;
  minirt->scene->resolution = resolution;
  return (0);
}

int set_ambiant_ligntning(t_minirt *minirt, char *value)
{
  t_ambiant_ligntning ambiant_ligntning;
  if (parse_ambiant_ligntning(value, &ambiant_ligntning) == -1)
  {
    return -1;
  }

  minirt->scene->ambiant_ligntning = ambiant_ligntning;

  return (0);
}

int add_camera(t_minirt *minirt, char *value)
{
  t_camera *camera;
  t_list *camera_list;

  camera = malloc(sizeof(t_camera));
  if (camera == NULL)
  {
    printf("unable to create camera\n");
    return -1;
  }
  if (parse_camera(value, camera) == -1)
  {
    return -1;
  }
  camera->image = malloc(sizeof(t_image));
  if (camera->image == NULL)
    return (handle_error("Unable to create camera image"));
  camera->image->image = NULL;
  camera->image->address = NULL;
  camera->id = minirt->scene->number_of_cameras + 1;
  camera_list = ft_lstnew(camera);
  ft_lstadd_back(&minirt->scene->cameras, camera_list);
  minirt->scene->number_of_cameras = minirt->scene->number_of_cameras + 1;
  return (0);
}

int add_light(t_minirt *minirt, char *value)
{
  t_light *light;
  t_list *light_list;

  light = malloc(sizeof(t_light));
  if (light == NULL)
  {
    printf("unable to create light\n");
    return -1;
  }
  if (parse_light(value, light) == -1)
  {
    return -1;
  }
  light_list = ft_lstnew(light);
  ft_lstadd_back(&minirt->scene->lights, light_list);
  return (0);
}

int add_plane(t_minirt *minirt, char *value)
{
  t_plane *plane;
  t_list *plane_list;

  plane = malloc(sizeof(t_plane));
  if (plane == NULL)
  {
    printf("unable to create plane\n");
    return -1;
  }
  if (create_plane(value, plane) == -1)
  {
    return -1;
  }
  plane_list = ft_lstnew(plane);
  ft_lstadd_back(&minirt->scene->planes, plane_list);
  return (0);
}

int add_square(t_minirt *minirt, char *value)
{
  t_square *square;
  t_list *square_list;

  square = malloc(sizeof(t_square));
  if (square == NULL)
  {
    printf("unable to create square\n");
    return -1;
  }
  if (create_square(value, square) == -1)
  {
    return -1;
  }
  square_list = ft_lstnew(square);
  ft_lstadd_back(&minirt->scene->squares, square_list);
  return (0);
}

int add_sphere(t_minirt *minirt, char *value)
{
  t_sphere *sphere;
  t_list *sphere_list;

  sphere = malloc(sizeof(t_sphere));
  if (sphere == NULL)
  {
    printf("unable to create sphere\n");
    return -1;
  }
  if (create_sphere(value, sphere) == -1)
  {
    return -1;
  }
  sphere_list = ft_lstnew(sphere);
  ft_lstadd_back(&minirt->scene->spheres, sphere_list);
  return (0);
}

int add_cylinder(t_minirt *minirt, char *value)
{
  t_cylinder *cylinder;
  t_list *cylinder_list;

  cylinder = malloc(sizeof(t_cylinder));
  if (cylinder == NULL)
  {
    printf("unable to create cylinder\n");
    return -1;
  }
  if (parse_cylinder(value, cylinder) == -1)
  {
    return -1;
  }
  cylinder_list = ft_lstnew(cylinder);
  ft_lstadd_back(&minirt->scene->cylinders, cylinder_list);
  return (0);
}

int add_triangle(t_minirt *minirt, char *value)
{
  t_triangle *triangle;
  t_list *triangle_list;

  triangle = malloc(sizeof(t_triangle));
  if (triangle == NULL)
  {
    printf("unable to create triangle\n");
    return -1;
  }
  if (create_triangle(value, triangle) == -1)
  {
    return -1;
  }
  triangle_list = ft_lstnew(triangle);
  ft_lstadd_back(&minirt->scene->triangles, triangle_list);
  return (0);
}

int create_scene_object(t_minirt *minirt, char *key, char *value)
{
  if (strcmp(key, "R") == 0)
    return (set_scene_resolution(minirt, value));
  if (strcmp(key, "A") == 0)
    return (set_ambiant_ligntning(minirt, value));
  if (strcmp(key, "c") == 0)
    return (add_camera(minirt, value));
  if (strcmp(key, "l") == 0)
    return (add_light(minirt, value));
  if (strcmp(key, "pl") == 0)
    return (add_plane(minirt, value));
  if (strcmp(key, "sq") == 0)
    return (add_square(minirt, value));
  if (strcmp(key, "sp") == 0)
    return (add_sphere(minirt, value));
  if (strcmp(key, "cy") == 0)
    return (add_cylinder(minirt, value));
  if (strcmp(key, "tr") == 0)
    return (add_triangle(minirt, value));
  return (-1);
}

int parse_scene_line(t_minirt *minirt, char *line)
{
  char *key;
  char *value;
  int i;
  int j;
  i = 0;
  if (is_valid_line(line) == 0)
  {
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

int parse_scene(t_minirt *minirt)
{

  int fd;
  char *line;
  int line_read;
  int result;
  line_read = 1;
  fd = open(minirt->scene_file, O_RDONLY);
  if (fd == -1)
  {
    perror("Cannot open scene file");
    return -1;
  }

  while (line_read == 1)
  {
    line_read = get_next_line(fd, &line);
    if (is_empty(line) == 1 || line[0] == '#')
      continue;
    result = parse_scene_line(minirt, line);
    if (result == -1)
    {
      free_value(line);
      return -1;
    }
  }
  return 0;
}
