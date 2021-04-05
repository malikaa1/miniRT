/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:31:38 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/05 19:36:28 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  t_minirt minirt;

  if (parse_args(argc, argv, &minirt) == -1) {
    return 1;
  }

  if (parse_scene(&minirt) == -1) {
    // return 1;
  }

  printf("%-20s=> width : %d, heigh : %d\n", "Resolution",
         minirt.scene->resolution.wdith, minirt.scene->resolution.height);

  printf("%-20s=> ratio : %f, color : (%f,%f,%f)\n", "ambiant lightning",
         minirt.scene->ambiant_ligntning.ratio,
         minirt.scene->ambiant_ligntning.color.r,
         minirt.scene->ambiant_ligntning.color.g,
         minirt.scene->ambiant_ligntning.color.b);

  // minirt_init(&minirt);
  // create_window(500, 500, "MiniRT", &minirt);
  // mlx_loop(minirt.mlx);
}
