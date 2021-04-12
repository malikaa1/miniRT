/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:31:47 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/11 01:58:03 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"

// objects
typedef struct s_resolution
{
    int width;
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


typedef struct	s_light
{
	double		brightness;
	t_color		color;
	t_vector	position;
}				t_light;

typedef struct	s_camera
{
	t_vector origin;
    t_vector direction;
    double horizontal_field_of_view;
}				t_camera;

typedef struct	s_plane
{
	t_vector	origin;
	t_vector	direction;
	t_color		color;
} t_plane;

typedef struct	s_square
{
	double		size;
	t_vector	origin;
	t_vector	direction;
	t_color		color;
}				t_square;

typedef struct	s_sphere
{
	double		raduis;
	t_vector	origin;
	t_color		color;
}				t_sphere;

typedef struct	s_cylinder
{
	double		height;
	double		diameter;
	t_vector	origin;
	t_vector	direction;
	t_color		color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	t_color		color;
}				t_triangle;


typedef struct s_scene
{
    t_resolution resolution;
    t_ambiant_ligntning ambiant_ligntning;
    t_list* cameras;
    t_list* lights;
    t_list* planes;
    t_list* squares;
    t_list* spheres;
    t_list* cylinders;
    t_list* triangles;

    
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

//window
void minirt_init(t_minirt *minirt);
void create_window(int x, int y, char *title, t_minirt * minirt);
int close_window(t_minirt *minirt);
int parse_args(int argc, char **argv, t_minirt *minirt);
int parse_scene(t_minirt *minirt);

//numbers
int is_valid_int(char *value);
int is_valid_float(char *value);
double ft_atof(char* value);
int is_in_range(double num, double start, double end);
int get_ratio(char *value, double *ratio);

//memory
void free_values(void** values);
void free_value(void* value);
void free_linked_list(t_list *list);


int get_length(char **values);

//vector
int create_vector(char *value, t_vector *vector);

//camera
int create_camera(char *value, t_camera *camera);

//minirt
int init_minirt(t_minirt *minirt);

//colors
int get_color(char *value, t_color *color);
int create_ambiant_ligntning(char *value, t_ambiant_ligntning *ambiant_ligntning);
int create_light(char *value, t_light *light);
int create_plane(char *value, t_plane *plane);
int create_square(char *value, t_square *square);
int create_sphere(char *value, t_sphere *sphere);
int create_cylinder(char *value, t_cylinder *cylinder);
int create_triangle(char *value, t_triangle *triangle);



#endif
