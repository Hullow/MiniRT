/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:11:14 by pberset           #+#    #+#             */
/*   Updated: 2025/03/07 09:13:27 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/header/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>

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
int			rt_check_ext(const char *file);
// Extracts the values contained in .rt file for counting objects
// Returns 1 if file open failed. Otherwise 0
int			rt_read_id(const char *file, t_scene *scene);
// Checks the line for an object identifier and increments the counter
int			rt_count_object(const char *line, t_scene *scene);
// Mallocs the amount of object structs in the scene
// Returns 1 if a unique object is missing or more than once in the scene
// Returns 2 if a malloc failed
// Otherwise 0
int			rt_malloc_objects(t_scene *scene);
// Reads file to assign values in scene
int			rt_init_scene(const char *file, t_scene *scene);
void		rt_assign_light(t_scene *scene, char **needle);
void		rt_assign_sphere(t_scene *scene, char **needle);
void		rt_assign_ambient(t_scene *scene, char **needle);
void		rt_assign_camera(t_scene *scene, char **needle);
void		rt_assign_plane(t_scene *scene, char **needle);
void		rt_assign_cylinder(t_scene *scene, char **needle);

#endif
