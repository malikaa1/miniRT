/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:31:47 by mrahmani          #+#    #+#             */
/*   Updated: 2021/04/20 17:34:16 by mrahmani         ###   ########.fr       */
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

typedef struct s_image{
    void* image;
    char* address;
    int bits_per_pixel;
    int size_line;
    int endian;

} t_image;

typedef struct	s_camera
{
    int id;
	t_vector origin;
    t_vector direction;
    t_vector up;
	t_vector forward;
    t_vector right;

    // t_vector horizontal;
    // t_vector vertical;
    // t_vector lower_left_corner;
    double fov;
    double w;
    double h;
    t_image* image;
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


typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;


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
    int current_camera_id;
    int number_of_cameras;
    t_camera* current_camera;
    
} t_scene;

typedef struct s_minirt
{
    void* window;
    void* mlx;
    char* scene_file;
    int save;
    t_scene* scene;
    double t;
    
} t_minirt;


#define ESC 65307
#define TAB 65289
#define PI 3.141592653589793
#define MAX_VALUE 1E99
#define MIN_VALUE 0.0001F
int handle_error(char *message);
//window
void minirt_init(t_minirt *minirt);
void create_window(char *title, t_minirt *minirt);
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
t_vector cross_vector(t_vector v1, t_vector v2);
float dot_vector(t_vector v1, t_vector v2);
t_vector normalize_vector(t_vector v);
t_vector negative_vector(t_vector v1);
t_vector divide_vector(t_vector v1, float f);
t_vector multiply_vector(t_vector v1, float f);
t_vector substract_vector(t_vector v1, t_vector v2);
t_vector add_vector(t_vector v1, t_vector v2);
t_vector multiply_vectors(t_vector v1, t_vector v2);
float get_vector_length(t_vector v);

//camera
int parse_camera(char *value, t_camera *camera);
int setup_cameras(t_minirt *minirt);
int switch_camera(t_minirt *minirt);

//minirt
int init_minirt(t_minirt *minirt);
int run_minirt(t_minirt *minirt);

//colors
int parse_color(char *value, t_color *color);
int parse_ambiant_ligntning(char *value, t_ambiant_ligntning *ambiant_ligntning);
int parse_light(char *value, t_light *light);
int create_plane(char *value, t_plane *plane);
int create_square(char *value, t_square *square);
int create_sphere(char *value, t_sphere *sphere);
int parse_cylinder(char *value, t_cylinder *cylinder);
int create_triangle(char *value, t_triangle *triangle);

int get_resolution(char *value, t_resolution *resolution);

int draw_scene(t_minirt *minirt);

void my_mlx_pixel_put(t_image *data, int x, int y, int color);

t_ray get_ray_direction(int x, int y, t_camera camera);

int create_rgb(t_color c, int endian);

t_color raytrace(t_minirt *minirt, t_ray *ray);
int intersect_spheres(t_minirt *minirt, t_ray *ray);
void print_config(t_minirt minirt);



#endif
