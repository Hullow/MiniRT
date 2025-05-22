/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_rt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:13:36 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 19:14:58 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_RT_H
# define MICRO_RT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "./mlx/mlx.h"

//test
void	test_tuples(void);
void	test_matrix(void);
void	test_transform(void);
void	test_intersect(void);
void	test_mlx(void);
void	test_light(void);
void	test_light_render(void);
void	test_scene(void);
void	test_rgb_to_int(void);
void	test_view_transform(void);

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
#  define WINDOW_WIDTH 800
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 600
# endif

# ifndef WINDOW_NAME
#  define WINDOW_NAME "micro_rt"
# endif

# ifndef MAX_OBJECTS
#  define MAX_OBJECTS 100
# endif

//Constants

# define EPSILON 0.00005

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

# ifndef MAX_OBJECTS
#  define MAX_OBJECTS 100
# endif

//Constants

# define EPSILON 0.00005

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

/// @brief Object struct. Color and material separated because norminette
typedef struct s_object
{
	t_shape		shape;
	t_tuple		origin;
	t_tuple		norm;
	t_tuple		color;
	t_material	material;
	t_matrix	transform;
	float		diameter;
	float		height;

}	t_object;

//Rays

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_intersect
{
	t_object	object;
	float		t;
}	t_inter;

typedef struct s_xs
{
	int			count;
	t_inter	*inter;
}	t_xs;

//Light

typedef struct s_ambient
{
	float	intensity;
	t_tuple	color;
}	t_ambient;

typedef struct s_camera
{
	t_tuple	coord;
	t_tuple	orient;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_tuple	coord;
	float	intensity;
	t_tuple	color;
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
	t_ambient	amb;
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
}	t_comps;


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
t_ray		rt_define_ray_to_wall(t_ray ray, float x_mlx, float y_mlx, float wall_z);
int			rgb_to_int(t_tuple c);
//void		rt_draw(t_env *env, t_object sp, t_ray ray);
void		my_mlx_pixel_put(t_env *env, int x, int y, int color);
int			key_handler(int keycode, t_env *env);
int			window_closed(t_env *env);


/* and then minilibx */

//CH3 Matrices

# define ENOTINVERTIBLE 132
# define EPSILON 1e-9

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
void		rt_inversion(t_matrix m, t_matrix *invert);

//CH4 Transforms

t_matrix	rt_translation(t_tuple t);
t_matrix	rt_scaling(t_tuple t);
t_matrix	rt_rotation(t_tuple norm);
t_matrix	rt_rotation_x(float angle);
t_matrix	rt_rotation_y(float angle);
t_matrix	rt_rotation_z(float angle);

//CH5 Ray-Sphere intersections

# define EDISCRIMINANT 133

t_ray		rt_ray(t_tuple origin, t_tuple direction);
void		rt_print_ray(t_ray ray);
t_tuple		rt_position(t_ray ray, float t);
t_object	rt_sphere(t_tuple color, t_material material);
void		rt_print_sphere(t_object sphere);
t_inter		rt_intersect(float t, t_object obj);
void		rt_intersects(t_object object, t_ray ray, t_xs *xs, int *i);
t_tuple		rt_sphere_to_ray(t_tuple ray_origin, t_tuple sphere_origin);
void		rt_discriminant(t_ray ray, t_object object, t_xs *xs, int *i);
t_inter		rt_hit(t_xs xs);
t_ray		rt_ray_transform(t_matrix m, t_ray r);
t_matrix	rt_set_transform(t_object object, t_matrix transform);

//CH6 Light and Shadows

t_tuple		rt_normal_at(t_object obj, t_tuple point);
t_tuple		rt_reflect(t_tuple in, t_tuple normal);
t_light		rt_light(t_tuple color, t_tuple coord, float intensity);
void		rt_print_light(t_light light);
t_material	rt_material(float amb, float dif, float spec, float shine);
void		rt_print_material(t_material mat);
t_camera	rt_camera(t_tuple coord, t_tuple orient, float fov);
t_tuple		rt_lighting(t_object o, t_light l, t_tuple point, \
	t_tuple eyev, t_tuple normalv);
t_tuple		rt_reinhard_tonemap(t_tuple color);
t_tuple		rt_normalize_color(t_tuple color);
t_tuple 	rt_filmic_tonemap(t_tuple color);

//CH7 Scene

void		rt_default_scene(t_scene *scene);
void		rt_intersect_scene(t_scene scene, t_ray ray, t_xs *xs);
t_comps		rt_prepare_computations(t_inter intersection, t_ray ray);
t_tuple		rt_shade_hit(t_scene scene, t_comps comp);
t_tuple		rt_color_at(t_scene scene, t_ray ray);
t_matrix	rt_view_transform(t_tuple from, t_tuple to, t_tuple up);

//Utils

void		*rt_handle_error(char *function, int errno_value, char *message);
int			is_equal_float(float a, float b);

#endif
