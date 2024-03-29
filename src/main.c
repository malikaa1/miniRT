/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:31:38 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/18 22:20:37 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

void print_config(t_minirt minirt) {
  printf("%-20s=> width : %d, heigh : %d\n", "Resolution",
         minirt.scene->resolution.width, minirt.scene->resolution.height);

  printf("%-20s=> ratio : %.1f, color : (%.1f,%.1f,%.1f)\n",
         "ambiant lightning", minirt.scene->ambiant_ligntning.ratio,
         minirt.scene->ambiant_ligntning.color.r,
         minirt.scene->ambiant_ligntning.color.g,
         minirt.scene->ambiant_ligntning.color.b);

  t_list *camera_list = minirt.scene->cameras;
  while (camera_list != NULL) {
    t_camera *camera = camera_list->content;

    printf("%-20s=> origin: (%.1f,%.1f,%.1f) direction: (%.1f,%.1f,%.1f) fov: "
           "%.1f\n",
           "camera", camera->origin.x, camera->origin.y, camera->origin.z,
           camera->direction.x, camera->direction.y, camera->direction.z,
           camera->fov);
    camera_list = camera_list->next;
  }

  t_list *light_list = minirt.scene->lights;
  while (light_list != NULL) {
    t_light *light = light_list->content;

    printf("%-20s=> position: (%.1f,%.1f,%.1f) ratio: %.1f color: "
           "(%.1f,%.1f,%.1f)\n",
           "light", light->position.x, light->position.y, light->position.z,
           light->brightness, light->color.r, light->color.g, light->color.b);
    light_list = light_list->next;
  }

  t_list *plane_list = minirt.scene->planes;
  while (plane_list != NULL) {
    t_plane *plane = plane_list->content;

    printf(
        "%-20s=> position: (%.1f,%.1f,%.1f) direction: (%.1f,%.1f,%.1f) color: "
        "(%.1f,%.1f,%.1f)\n",
        "plane", plane->origin.x, plane->origin.y, plane->origin.z,
        plane->direction.x, plane->direction.y, plane->direction.z,
        plane->color.r, plane->color.g, plane->color.b);
    plane_list = plane_list->next;
  }

  t_list *square_list = minirt.scene->squares;
  while (square_list != NULL) {
    t_square *square = square_list->content;

    printf("%-20s=> origin: (%.1f,%.1f,%.1f) direction: (%.1f,%.1f,%.1f) size: "
           "%.1f color: "
           "(%.1f,%.1f,%.1f)\n",
           "square", square->origin.x, square->origin.y, square->origin.z,
           square->direction.x, square->direction.y, square->direction.z,
           square->size, square->color.r, square->color.g, square->color.b);
    square_list = square_list->next;
  }

  t_list *sphere_list = minirt.scene->spheres;
  while (sphere_list != NULL) {
    t_sphere *sphere = sphere_list->content;

    printf("%-20s=> origin: (%.1f,%.1f,%.1f) raduis: %.1f color: "
           "(%.1f,%.1f,%.1f)\n",
           "sphere", sphere->origin.x, sphere->origin.y, sphere->origin.z,
           sphere->raduis, sphere->color.r, sphere->color.g, sphere->color.b);
    sphere_list = sphere_list->next;
  }

  t_list *cylinder_list = minirt.scene->cylinders;
  while (cylinder_list != NULL) {
    t_cylinder *cylinder = cylinder_list->content;

    printf("%-20s=> origin: (%.1f,%.1f,%.1f) direction: (%.1f,%.1f,%.1f) "
           "diameter: %.1f "
           "height: %.1f  color: (%.1f,%.1f,%.1f)\n",
           "cylinder", cylinder->origin.x, cylinder->origin.y,
           cylinder->origin.z, cylinder->direction.x, cylinder->direction.y,
           cylinder->direction.z, cylinder->diameter, cylinder->height,
           cylinder->color.r, cylinder->color.g, cylinder->color.b);
    cylinder_list = cylinder_list->next;
  }

  t_list *triangle_list = minirt.scene->triangles;
  while (triangle_list != NULL) {
    t_triangle *triangle = triangle_list->content;

    printf("%-20s=> p1: (%.1f,%.1f,%.1f) p2: (%.1f,%.1f,%.1f) p3: "
           "(%.1f,%.1f,%.1f) color: "
           "(%.1f,%.1f,%.1f)\n",
           "triangle", triangle->p1.x, triangle->p1.y, triangle->p1.z,
           triangle->p2.x, triangle->p2.y, triangle->p2.z, triangle->p3.x,
           triangle->p3.y, triangle->p3.z, triangle->color.r, triangle->color.g,
           triangle->color.b);
    triangle_list = triangle_list->next;

    printf("Number of cameras => %d\n", minirt.scene->number_of_cameras);
  }
}

int main(int argc, char **argv) {

  t_minirt minirt;

  if (init_minirt(&minirt) == -1) {
    return (1);
  }

  if (parse_args(argc, argv, &minirt) == -1) {
    return (1);
  }

  if (parse_scene(&minirt) == -1) {
    return (1);
  }

  print_config(minirt);
  run_minirt(&minirt);
}
