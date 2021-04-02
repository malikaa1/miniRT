/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:31:47 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/02 22:38:52 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINIRT_H
# define MINIRT_H

typedef struct s_minirt
{
    void* window;
    void* mlx;
    char* scene_file;
    int save;
    
} t_minirt;


#define ESC 65307

void minirt_init(t_minirt *minirt);
void create_window(int x, int y, char *title, t_minirt * minirt);
int close_window(t_minirt *minirt);
int parse_args(int argc, char **argv, t_minirt *minirt);
int parse_scene(t_minirt *minirt);

#endif
