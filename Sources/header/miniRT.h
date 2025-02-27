/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:11:14 by pberset           #+#    #+#             */
/*   Updated: 2025/02/27 10:28:35 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/header/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>

# define VECTOR 0
# define POINT 1
# define COLOR 2

# define EPSILON 0.00001

/* A tuple:
	- has a type (int): either a vector (0) or a point (1)
	- has three coordinates:
		- x (float): lateral->to the right || RED
		- y (float): vertical->up || GREEN
		- z (float): depth->away from us || BLUE*/
typedef struct s_tuple {
	float	x;
	float	y;
	float	z;
	int		type;
}	t_tuple;

typedef struct s_ambient
{
	float	ratio;
	t_tuple	*color;
}	t_ambient;

typedef struct s_camera
{
	t_tuple	*coord;
	t_tuple	*orient;
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
	t_ambient	*amb;
	t_camera	*cam;
	t_light		*lux;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}	t_scene;

// Utils
	// Math
		// Basic bricks
		
int			is_equal_float(float a, float b);
float		abs_float(float a);

		// Tuples and tuple operations

t_tuple		*point(float x, float y, float z);
t_tuple		*vector(float x, float y, float z);
int			is_equal_tuple(t_tuple *a, t_tuple *b);
t_tuple		*add_tuple(t_tuple *a, t_tuple *b);
t_tuple		*subtract_tuple(t_tuple *minuend, t_tuple *subtrahend);
t_tuple		*negate_tuple(t_tuple *a);
t_tuple		*multiply_tuple_by_scalar(t_tuple *a, float scalar);
t_tuple		*divide_tuple_by_scalar(t_tuple *a, float scalar);
float		magnitude(t_tuple *tuple);
t_tuple		*normalize(t_tuple *tuple);
float		*dot_product(t_tuple *a, t_tuple *b);
t_tuple		*cross_product(t_tuple *a, t_tuple *b);
// Returns 1 if the file extension is wrong. Otherwise 0
int	rt_check_ext(char *file);
// Returns 1 if the sccene.rt file contains wrong data. Otherwise 0
int	rt_check_scene(char *file);
// Extracts the values contained in .rt file and stores them in a struct
// Returns 1 if the struct is successfully created. Otherwise 0
int	rt_extract_scene(char *file, t_scene *scene);

#endif
