/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:13:36 by pberset           #+#    #+#             */
/*   Updated: 2025/06/02 18:29:55 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>
# include "./mlx/mlx.h"
# include "./libft/header/libft.h"

//Structs

//tuples

typedef enum e_type
{
	VECTOR,
	POINT,
	COLOR
}	t_type;

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	t_type	w;
}	t_tuple;

//Canvas

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 300
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 200
# endif

# ifndef WINDOW_NAME
#  define WINDOW_NAME "micro_rt"
# endif

# ifndef MAX_OBJECTS
#  define MAX_OBJECTS 100
# endif

/* function names for error prints */
# define RT_COUNT_OBJECT		" – rt_count_object\n"
# define RT_VALID_COORD			" – rt_valid_coord\n"
# define RT_VALID_COLOR			" – rt_valid_color\n"
# define RT_VALID_ORIENT		" – rt_valid_orient\n"
# define RT_MAGNITUDE			" – rt_magnitude\n"
# define RT_NORMALIZE			" – rt_normalize\n"
# define RT_COLOR				" – rt_color\n"
# define RT_NEGATE_VECTOR		" – rt_negate_vector\n"
# define RT_SCALE_VECTOR		" – rt_scale_vector\n"
# define RT_SUB_TUPLE			" - rt_sub_tuple\n"
# define RT_ADD_TUPLE			" - rt_add_tuple\n"
# define RT_DIVIDE_TUPLE		" – rt_divide_tuple\n"
# define RT_DOT_PRODUCT			" – rt_dot_product\n"
# define RT_CROSS_PRODUCT		" – rt_cross_product\n"
# define RT_SUB_COLOR			" - rt_sub_color\n"
# define RT_ADD_COLOR			" - rt_add_color\n"
# define RT_SCALE_COLOR			" - rt_scale_color\n"
# define RT_MUL_COLOR			" - rt_mul_color\n"
# define RT_RAY					" - rt_ray\n"

# define UNSPECIFIED 			" – unspecified function\n"

//  	EDOM 	Math argument out of domain of func
//  	ERANGE 	Math result not representable

typedef struct s_env {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	char	*color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_env;

//Matrix

typedef struct s_matrix
{
	int		rows;
	int		columns;
	float	cell[4][4];
}	t_matrix;

//Objects

/// @brief Material contains light effects. Not color because norminette
typedef struct s_material
{
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

typedef enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_shape;

//Rays

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

/// @brief Object struct. Color and material separated because norminette
typedef struct s_object
{
	t_shape		shape;
	t_tuple		origin;
	t_tuple		norm;
	t_tuple		color;
	t_material	material;
	t_ray		saved_ray;
	t_matrix	transform;
	float		diameter;
	float		height;
	float		min;
	float		max;
	int			closed;

}	t_object;

typedef struct s_intersect
{
	t_object	object;
	float		t;
}	t_inter;

typedef struct s_xs
{
	int			count;
	t_inter		*inter;
}	t_xs;

//Light

typedef struct s_ambient
{
	float	intensity;
	t_tuple	color;
}	t_ambient;

typedef struct s_camera
{
	t_tuple		coord;
	t_tuple		orient;
	int			hsize;
	int			vsize;
	float		field_of_view;
	t_matrix	transform;
	float		half_width;
	float		half_height;
	float		pixel_size;
}	t_camera;

typedef struct s_light
{
	t_tuple		coord;
	float		intensity;
	t_tuple		color;
	t_ambient	ambient;
}	t_light;

//Scene

typedef struct s_scene
{
	int			n_a;
	int			n_l;
	int			n_cam;
	int			n_sp;
	int			n_pl;
	int			n_cy;
	int			n_obj;
	t_camera	cam;
	t_light		lux;
	t_object	*objects;
}	t_scene;

typedef struct s_comps
{
	float		t;
	t_object	object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	int			inside;
	bool		in_shadow;
	t_tuple		over_point;
}	t_comps;

// Variables for final calculation

typedef struct s_intermediate_vars {
	t_tuple	color;
	t_tuple	dir_to_light;
	float	light_dot_normal;
	t_tuple	reflect;
	float	reflect_dot_camera;
	float	factor;
}	t_intermediate_vars;

typedef struct s_lighting_params {
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
}	t_lighting_params;

//test

void		test_tuples(void);
void		test_matrix(void);
void		test_transform(void);
void		test_intersect(void);
void		test_mlx(void);
void		test_light(void);
void		test_light_render(void);
void		test_scene(void);
void		test_rgb_to_int(void);
void		test_view_transform(void);
void		test_camera(void);
void		test_planes(void);
void		test_render_plane(void);
void		test_cylinder(void);
void		test_cylinder_render(void);
void		test_shadows(void);
void		test_example_scene(void);
t_scene		*test_default_scene(t_scene *scene);
void		test_example_scene_planes(void);
void		test_example_scene_with_flat_spheres(void);

//CH0 Parsing

int			rt_check_ext(const char *file);
int			rt_read_id(const char *file, t_scene *scene);
int			rt_init_scene(const char *file, t_scene *scene);
int			rt_count_object(const char *line, t_scene *scene);
int			rt_valid_color(char **color);
int			rt_valid_coord(char **coord);
int			rt_valid_orient(char **orient);
int			rt_check_uniques(t_scene *scene);
void		rt_assign_light(t_scene *scene, char **needle);
void		rt_assign_ambient(t_scene *scene, char **needle);
t_matrix	rt_camera_transform(t_camera camera);
void		rt_assign_camera(t_scene *scene, char **needle);
void		rt_assign_sphere(t_object *sphere, char **needle);
void		rt_assign_plane(t_object *plane, char **needle);
void		rt_assign_cylinder(t_object *cylinder, char **needle);

//CH1 Tuples

t_tuple		rt_point(float x, float y, float z);
t_tuple		rt_vector(float x, float y, float z);
t_tuple		rt_color(float r, float g, float b);
void		rt_print_tuple(t_tuple t);
t_tuple		rt_add_tuple(t_tuple a, t_tuple b);
t_tuple		rt_sub_tuple(t_tuple a, t_tuple b);
t_tuple		rt_negate_vector(t_tuple	a);
t_tuple		rt_scale_vector(t_tuple a, float s);
t_tuple		rt_divide_tuple(t_tuple a, float d);
float		rt_magnitude(t_tuple vector);
t_tuple		rt_normalize(t_tuple vector);
float		rt_dot_product(t_tuple a, t_tuple b);
t_tuple		rt_cross_product(t_tuple a, t_tuple b);
t_tuple		rt_hadamard(t_tuple color1, t_tuple color2);
int			rt_is_equal_tuple(t_tuple a, t_tuple b);

//CH2 Drawing on canvas

t_tuple		rt_add_color(t_tuple c1, t_tuple c2);
t_tuple		rt_sub_color(t_tuple c1, t_tuple c2);
t_tuple		rt_scale_color(t_tuple c1, float s);
t_tuple		rt_mul_color(t_tuple c1, t_tuple c2);
void		rt_set_mlx_env(t_env *env);
t_env		mlx_set_env(void);
void		mlx_run_window(t_env *env);
t_ray		rt_define_ray_to_wall(t_ray ray, \
				float x_mlx, float y_mlx, float wall_z);
int			rgb_to_int(t_tuple c);
void		rt_draw(t_env *env, t_object sp, t_ray ray);
void		my_mlx_pixel_put(t_env *env, int x, int y, int color);
int			key_handler(int keycode, t_env *env);
int			window_closed(t_env *env);

/* and then minilibx */

//CH3 Matrices

# ifndef ENOTINVERTIBLE
#  define ENOTINVERTIBLE 132
# endif

# ifndef EPSILON
#  define EPSILON 0.00005
# endif

t_matrix	rt_identity_matrix(void);
void		rt_print_matrix(t_matrix m);
int			rt_matrix_equality(t_matrix a, t_matrix b);
t_matrix	rt_mul_matrix(t_matrix a, t_matrix b);
t_tuple		rt_mul_tuple_matrix(t_matrix m, t_tuple t);
t_matrix	rt_matrix_transpose(t_matrix m);
float		rt_determinant(t_matrix m);
void		rt_sub_matrix(t_matrix m, int row, int col, t_matrix *sub);
float		rt_minor(t_matrix m, int row, int col);
float		rt_cofactor(t_matrix m, int row, int col);
t_matrix	rt_inversion(t_matrix m);

//CH4 Transforms

# ifndef M_PI
#  define M_PI 3.141592f
# endif

t_matrix	rt_translation(t_tuple t);
t_matrix	rt_scaling(t_tuple t);
t_matrix	rt_rotation_x(float angle);
t_matrix	rt_rotation_y(float angle);
t_matrix	rt_rotation_z(float angle);
t_matrix	rt_rotation(t_tuple norm);
t_matrix	rt_set_transform(t_object object);

//CH5 Ray-Sphere intersections

# ifndef EDISCRIMINANT
#  define EDISCRIMINANT 133
# endif

t_ray		rt_ray(t_tuple origin, t_tuple direction);
void		rt_print_ray(t_ray ray);
t_tuple		rt_position(t_ray ray, float t);
t_object	rt_sphere(t_tuple color);
void		rt_print_sphere(t_object sphere);
t_inter		rt_intersect(float t, t_object obj);
void		rt_intersects(t_object object, t_xs *xs, int *i);
t_tuple		rt_sphere_to_ray(t_tuple ray_origin, t_tuple sphere_origin);
void		rt_discriminant(t_ray ray, t_object object, t_xs *xs, int *i);
t_inter		rt_hit(t_xs xs);
t_ray		rt_ray_transform(t_matrix m, t_ray r);

//CH6 Light and Shadowing

t_tuple		rt_normal_at(t_object obj, t_tuple point);
t_tuple		rt_reflect(t_tuple in, t_tuple normal);
t_light		rt_light(t_tuple color, t_tuple coord, float intensity);
void		rt_print_light(t_light light);
t_material	rt_material(float amb, float dif, float spec, float shine);
void		rt_print_material(t_material mat);
t_tuple		rt_lighting(t_light l, t_comps comp);
t_lighting_params	rt_dark_diffuse_specular(t_lighting_params v);
t_lighting_params	rt_colorize_diffuse_specular(t_light l, t_comps comp,
	t_intermediate_vars in, t_lighting_params v);
t_tuple		rt_reinhard_tonemap(t_tuple color);
t_tuple		rt_normalize_color(t_tuple color);
t_tuple		rt_filmic_tonemap(t_tuple color);

//CH7 Scene

void		rt_print_scene(t_scene scene);
void		rt_intersect_scene(t_scene scene, t_ray ray, t_xs *xs);
t_comps		rt_prepare_computations(t_inter intersection, t_ray ray);
t_tuple		rt_shade_hit(t_scene scene, t_comps comp);
t_tuple		rt_color_at(t_scene scene, t_ray ray);
t_matrix	rt_view_transform(t_tuple from, t_tuple to, t_tuple up);
t_matrix	rt_orientation_matrix(t_tuple left, t_tuple true_up, \
				t_tuple forward);
t_camera	rt_calculate_camera_values(t_camera camera);
t_ray		rt_ray_for_pixel(t_camera camera, int pixel_x, int pixel_y);
void		rt_print_camera(t_camera camera);
void		rt_render(t_camera camera, t_scene scene, t_env *env);

//CH8 Shadows
bool		rt_is_shadowed(t_scene scene, t_tuple point);


//CH9 Planes

# ifndef ERAYPARALLEL
#  define ERAYPARALLEL 134
# endif

t_object	rt_plane(t_tuple color);
void		rt_print_plane(t_object plane);
void		rt_ray_plane_x(t_object plane, t_ray ray, t_xs *xs, int *i);
t_tuple		rt_local_normal_at(t_object obj, t_tuple point);

//CH13 Cylinders

t_object	rt_cylinder(t_tuple color);
void		rt_print_cylinder(t_object cylinder);
void		rt_ray_cylinder_x(t_object cylinder, t_ray ray, t_xs *xs, int *i);
int			rt_check_cap(t_ray ray, float t);
void		rt_intersect_caps(t_object cylinder, t_ray ray, t_xs *xs, int *i);
t_tuple		rt_local_normal_capped_cylinder(t_object cylinder, t_tuple point);

//Utils

void		*rt_handle_error(char *function, int errno_value, char *message);
int			is_equal_float(float a, float b);


#endif
