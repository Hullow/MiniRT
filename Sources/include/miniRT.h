/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:11:14 by pberset           #+#    #+#             */
/*   Updated: 2025/04/04 18:50:22 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/header/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 800
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 600
# endif

# define VECTOR 0.0
# define POINT 1.0
# define COLOR 2.0

# define EPSILON 0.00005

/* function names for error prints */
# define UNSPECIFIED 	" – unspecified function\n"
# define MAT_MALLOC 	" – malloc_matrix_columns\n"
# define INIT_MATRIX 	" – init_matrix\n"
# define CONV_TUP_MAT 	" – convert_tuple_to_matrix\n"
# define ID_MATRIX 		" – identity_matrix\n"
# define MAT_MINOR		" – matrix_minor\n"
# define MAT_MUL		" – matrix_multiplication\n"
# define MAT_TUP_MUL	" – matrix_tuple_multiplication\n"
# define MAT_TRANSP		" – matrix_transposition\n"
# define MAT_INV		" – matrix_inversion\n"
# define DET			" – determinant\n"
# define SUBMATRIX 		" – submatrix\n"
# define RT_VALID_COORD	" – rt_valid_coord\n"
# define RT_RAY			" – rt_ray\n"
# define RT_POSITION	" – rt_position\n"
# define RT_RAY_OBJ_X	" – rt_ray_object_intersect\n"

# define SUB_ERROR		"Invalid input: null matrix, or row or column count too small (< 2)"

//  	EDOM 	Math argument out of domain of func
//  	ERANGE 	Math result not representable

typedef enum {
	ROT_X,
	ROT_Y,
	ROT_Z,
	SCALE,
	SHEAR,
	TRANSLATION
}	t_transform;

typedef enum {
	SPHERE,
	PLANE,
	CYLINDER
}	t_objtype;

/* A tuple:
	- has a type (w): either a vector (0.0) or a point (1.0)
	- has three coordinates:
		- x (float): lateral->to the right || RED
		- y (float): vertical->up || GREEN
		- z (float): depth->away from us || BLUE*/
typedef struct s_tuple {
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef struct s_matrix {
	int		rows;
	int		columns;
	float 	**m;
}	t_matrix;

typedef struct s_ray {
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_ambient
{
	float	ratio;
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
	float	ratio;
	t_tuple	color;
}	t_light;

typedef struct s_object {
    t_objtype	type;
    t_matrix	transform;
    t_tuple		color;
    t_tuple		coord;
    t_tuple		norm;
    float		diameter;
    float		height;
}	t_object;

typedef struct s_intersect
{
	t_object	object;
	t_ray		ray;
	float		x_distances[2];
	int			x_count;
}	t_intersect;

typedef struct s_scene
{
	int			n_A;
	int			n_L;
	int			n_C;
	int			n_sp;
	int			n_pl;
	int			n_cy;
	int			n_obj;
	t_ambient	amb;
	t_camera	cam;
	t_light		lux;
	t_object	*objects;
	t_list		*intersects;
	t_ray		*rays;
}	t_scene;

// Input handling

int			rt_check_ext(const char *file);
int			rt_read_id(const char *file, t_scene *scene);
int			rt_count_object(const char *line, t_scene *scene);
int			rt_malloc_objects(t_scene *scene);
int			rt_init_scene(const char *file, t_scene *scene);
void		rt_assign_light(t_scene *scene, char **needle);
void		rt_assign_ambient(t_scene *scene, char **needle);
void		rt_assign_camera(t_scene *scene, char **needle);
void		rt_assign_object(t_object *object, char **needle, char type);
void		rt_assign_sphere(t_object *sphere, char **needle);
void		rt_assign_plane(t_object *plane, char **needle);
void		rt_assign_cylinder(t_object *cylinder, char **needle);

// Utils
	// General

void	*handle_error(char *function, int errno_value, char *message);

	// Math
		// Basic bricks

int			is_equal_float(float a, float b);
float		abs_float(float a);

		// Tuples and tuple operations

t_tuple		rt_point(float x, float y, float z);
t_tuple		rt_vector(float x, float y, float z);
t_tuple		rt_color(float r, float g, float b);
int			is_equal_tuple(t_tuple a, t_tuple b);
t_tuple		add_tuple(t_tuple a, t_tuple b);
t_tuple		subtract_tuple(t_tuple minuend, t_tuple subtrahend);
t_tuple		negate_tuple(t_tuple a);
t_tuple		multiply_tuple_by_scalar(t_tuple a, float scalar);
t_tuple		divide_tuple_by_scalar(t_tuple a, float scalar);
float		magnitude(t_tuple tuple);
t_tuple		normalize(t_tuple tuple);
float		dot_product(t_tuple a, t_tuple b);
t_tuple		cross_product(t_tuple a, t_tuple b);

		// Matrices
			// General functions
		
t_matrix	init_matrix(int rows, int columns);
t_matrix	malloc_matrix_columns(t_matrix mat, int rows, int columns);
t_matrix	identity_matrix(int rows, int columns);
t_matrix	convert_tuple_to_matrix(t_tuple tuple);
t_tuple		matrix_tuple_multiplication(t_matrix m, t_tuple t);
int			print_matrix(t_matrix mat);

			// Basic operations
		
t_matrix	matrix_multiplication(t_matrix a, t_matrix b);
t_matrix	matrix_transposition(t_matrix mat);
t_matrix	matrix_inversion(t_matrix mat);
int			matrix_equality(t_matrix a, t_matrix b);

			// Sub, determinant, cofactor

int			submatrix_errors(t_matrix mat);
t_matrix	submatrix(t_matrix mat, int row, int column, t_matrix sub);
float		matrix_minor(t_matrix mat, int row, int column);
float		matrix_cofactor(t_matrix mat, int row, int column);
float		determinant(t_matrix mat);

		// Color

t_tuple		rt_hadamard(t_tuple color1, t_tuple color2);

		// Transformations

t_matrix	rt_translation(t_tuple t);
t_matrix	rt_scaling(t_tuple t);
t_matrix	rt_shear(float *shear_factors);
t_matrix	rt_rotation_x(float angle);
t_matrix	rt_rotation_y(float angle);
t_matrix	rt_rotation_z(float angle);

		// Ray - Objects intersections

t_ray		rt_ray(t_tuple origin, t_tuple direction);
t_tuple		rt_position(t_ray ray, float d);
t_intersect	rt_ray_plane_x(t_ray ray, t_object plane, t_intersect *x);
t_intersect	rt_ray_cylinder_x(t_ray ray, t_object cylinder, t_intersect *x);
t_intersect	rt_ray_sphere_x(t_ray ray, t_object sphere, t_intersect *x);
t_intersect	rt_ray_object_x(t_ray ray, t_object object);
void		rt_compute_intersect(t_scene *scene);

#endif
