/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 00:54:29 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/02 22:38:21 by mrahmani         ###   ########.fr       */
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

int close_window(t_minirt *minirt) {
  mlx_destroy_window(minirt->mlx, minirt->window);
  exit(EXIT_SUCCESS);
  return 0;
}

int on_key_press(int key_code, t_minirt *minirt) {
  if (key_code == ESC) {
    close_window(minirt);
  }
  return 0;
}

void create_window(int x, int y, char *title, t_minirt *minirt) {
  minirt->window = mlx_new_window(minirt->mlx, x, y, title);
  mlx_hook(minirt->window, 33, 1L << 17, &close_window, minirt);
  mlx_hook(minirt->window, 2, 1L << 0, &on_key_press, minirt);
}
