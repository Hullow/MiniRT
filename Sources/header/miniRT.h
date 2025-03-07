/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:11:14 by pberset           #+#    #+#             */
/*   Updated: 2025/03/07 20:20:41 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/header/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>

# define VECTOR 0.0
# define POINT 1.0
# define COLOR 2.0

# define EPSILON 0.00005

typedef enum ERROR_TYPE {
	NULL_INPUT,
	MALLOC_FAIL,
	INVALID_MATRIX_SIZE,
	MATRIX_NOT_INVERTIBLE
}	t_error;

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

typedef struct s_ambient
{
	float	ratio;
	t_tuple	*color;
}	t_ambient;

typedef struct s_camera
{
	t_tuple	*coord;
	t_tuple	*orient;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_tuple	*coord;
	float	ratio;
	t_tuple	*color;
}	t_light;

typedef struct s_sphere
{
	t_tuple	*coord;
	float	diameter;
	t_tuple	*color;
}	t_sphere;

typedef struct s_plane
{
	t_tuple	*coord;
	t_tuple	*norm;
	t_tuple	*color;
}	t_plane;

typedef struct s_cylinder
{
	t_tuple	*coord;
	t_tuple	*norm;
	float	diameter;
	float	height;
	t_tuple	*color;
}	t_cylinder;

typedef struct s_scene
{
	int			n_A;
	int			n_L;
	int			n_C;
	int			n_sp;
	int			n_pl;
	int			n_cy;
	t_ambient	*amb;
	t_camera	*cam;
	t_light		*lux;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}	t_scene;

// Input handling

int			rt_check_ext(const char *file);
int			rt_read_id(const char *file, t_scene *scene);
int			rt_count_object(const char *line, t_scene *scene);
int			rt_malloc_objects(t_scene *scene);
int			rt_init_scene(const char *file, t_scene *scene);
void		rt_assign_light(t_scene *scene, char **needle);
void		rt_assign_sphere(t_scene *scene, char **needle);
void		rt_assign_ambient(t_scene *scene, char **needle);
void		rt_assign_camera(t_scene *scene, char **needle);
void		rt_assign_plane(t_scene *scene, char **needle);
void		rt_assign_cylinder(t_scene *scene, char **needle);

// Utils
	// General

void		*handle_error(t_error error_type);

	// Math
		// Basic bricks

int			is_equal_float(float a, float b);
float		abs_float(float a);

		// Tuples and tuple operations

t_tuple		*point(float x, float y, float z);
t_tuple		*vector(float x, float y, float z);
t_tuple		*color(float r, float g, float b);
int			is_equal_tuple(t_tuple *a, t_tuple *b);
t_tuple		*add_tuple(t_tuple *a, t_tuple *b);
t_tuple		*subtract_tuple(t_tuple *minuend, t_tuple *subtrahend);
t_tuple		*negate_tuple(t_tuple *a);
t_tuple		*multiply_tuple_by_scalar(t_tuple *a, float scalar);
t_tuple		*divide_tuple_by_scalar(t_tuple *a, float scalar);
float		magnitude(t_tuple *tuple);
t_tuple		*normalize(t_tuple *tuple);
float		dot_product(t_tuple *a, t_tuple *b);
t_tuple		*cross_product(t_tuple *a, t_tuple *b);

		// Matrices
			// General functions
		
t_matrix	*init_matrix(int rows, int columns);
t_matrix	*malloc_matrix_contents(t_matrix *mat, int rows, int columns);
t_matrix	*identity_matrix(int rows, int columns);
t_matrix	*convert_tuple_to_matrix(t_tuple *tuple);
int			print_matrix(t_matrix *mat);

			// Basic operations
		
t_matrix	*matrix_multiplication(t_matrix *a, t_matrix *b);
t_matrix	*matrix_transposition(t_matrix *mat);
t_matrix	*matrix_inversion(t_matrix *mat);
int			matrix_equality(t_matrix *a, t_matrix *b);

			// Sub, determinant, cofactor

int			submatrix_errors(t_matrix *mat, t_matrix *sub);
t_matrix	*submatrix(t_matrix *mat, int row, int column, t_matrix *sub);
float		matrix_minor(t_matrix *mat, int row, int column);
float		matrix_cofactor(t_matrix *mat, int row, int column);
float		determinant(t_matrix *mat);

		// Color
t_tuple		rt_hadamard(t_tuple color1, t_tuple color2);

#endif
