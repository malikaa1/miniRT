/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:31:38 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/02 22:59:59 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "stdlib.h"
#include <stdio.h>

int main(int argc, char **argv) {

  t_minirt minirt;

  if (parse_args(argc, argv, &minirt) == -1) {
    return 1;
  }

  // parse_scene(&minirt);
  // minirt_init(&minirt);
  // create_window(500, 500, "MiniRT", &minirt);
  // mlx_loop(minirt.mlx);
}
