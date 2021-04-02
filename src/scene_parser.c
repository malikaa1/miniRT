/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:32:03 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/02 22:37:26 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

// int parse_scene(t_minirt *minirt) {

//   int fd;
//   int buffer_size;
//   buffer_size = 100;
//   char buffer[buffer_size];

//   fd = open(minirt->scene_file, O_RDONLY);
//   if (fd == -1) {
//     printf("Cannot open file %s. error % d\n", minirt->scene_file, errno);
//     return -1;
//   }

//   while (read(fd, buffer, buffer_size) > 0) {
//     for (int i = 0; i < buffer_size; i++) {
//       printf("%c", buffer[i]);
//     }
//   }
// }