/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 00:54:29 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/18 16:48:08 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
void minirt_init(t_minirt *minirt) {
  minirt->mlx = mlx_init();
  minirt->window = NULL;
}

void free_cameras(t_list *cameras) {
  t_list *camera = cameras;
  t_camera *cam;
  while (camera != NULL) {
    cam = camera->content;
    free_value(cam->image);
    camera = camera->next;
  }
  free_linked_list(cameras);
}

int close_window(t_minirt *minirt) {
  mlx_destroy_window(minirt->mlx, minirt->window);
  free_cameras(minirt->scene->cameras);
  free_linked_list(minirt->scene->lights);
  free_linked_list(minirt->scene->planes);
  free_linked_list(minirt->scene->squares);
  free_linked_list(minirt->scene->spheres);
  free_linked_list(minirt->scene->cylinders);
  free_linked_list(minirt->scene->triangles);
  free_value(minirt->scene);
  exit(EXIT_SUCCESS);
  return 0;
}

int on_key_press(int key_code, t_minirt *minirt) {
  if (key_code == ESC) {
    print_config(*minirt);
    close_window(minirt);
  }
  if (key_code == TAB) {
    switch_camera(minirt);
  }
  printf("Key %d pressed", key_code);
  return 0;
}

void my_mlx_pixel_put(t_image *data, int x, int y, int color) {
  char *dst;

  dst = data->address + (y * data->size_line + x * (data->bits_per_pixel / 8));
  *(unsigned int *)dst = color;
}

void create_window(char *title, t_minirt *minirt) {

  minirt->window = mlx_new_window(minirt->mlx, minirt->scene->resolution.width,
                                  minirt->scene->resolution.height, title);
  mlx_hook(minirt->window, 33, 1L << 17, &close_window, minirt);
  mlx_hook(minirt->window, 2, 1L << 0, &on_key_press, minirt);
  mlx_put_image_to_window(minirt->mlx, minirt->window,
                          minirt->scene->current_camera->image->image, 0, 0);
  mlx_loop(minirt->mlx);
}
