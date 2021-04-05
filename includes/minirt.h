/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:31:47 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/05 21:18:20 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINIRT_H
# define MINIRT_H

typedef struct s_resolution
{
    int wdith;
    int height;
} t_resolution;

typedef struct s_color
{
    double r;
    double g;
    double b;
    
} t_color;

typedef struct s_ambiant_ligntning
{
    double ratio;
    t_color color;
} t_ambiant_ligntning;

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct	s_camera
{
	t_vector origin;
    t_vector orientation;
    double field_of_view;
}				t_camera;

typedef struct s_scene
{
    t_resolution resolution;
    t_ambiant_ligntning ambiant_ligntning;
} t_scene;

typedef struct s_minirt
{
    void* window;
    void* mlx;
    char* scene_file;
    int save;
    t_scene* scene;
    
} t_minirt;


#define ESC 65307

void minirt_init(t_minirt *minirt);
void create_window(int x, int y, char *title, t_minirt * minirt);
int close_window(t_minirt *minirt);
int parse_args(int argc, char **argv, t_minirt *minirt);
int parse_scene(t_minirt *minirt);

int is_valid_int(char *value);
int is_valid_float(char *value);
double ft_atof(char* value);

void free_values(void** values);
void free_value(void* value);

#endif
