/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_rt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:13:36 by pberset           #+#    #+#             */
/*   Updated: 2025/05/07 11:11:07 by pberset          ###   ########.fr       */
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

typedef enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_shape;

typedef struct s_object
{
	t_shape		shape;
	t_tuple		origin;
	t_tuple		norm;
	t_tuple		color;
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
	int			count;
	float		first;
	float		last;
}	t_intersect;

//CH1 Tuples

t_tuple		rt_point(float x, float y, float z);
t_tuple		rt_vector(float x, float y, float z);
t_tuple		rt_color(float r, float g, float b);
void		rt_print_tuple(t_tuple t);
t_tuple		rt_add_tuple(t_tuple a, t_tuple b);
t_tuple		rt_sub_tuple(t_tuple a, t_tuple b);
t_tuple		rt_negate_tuple(t_tuple	a);
t_tuple		rt_scale_vector(t_tuple a, float s);
t_tuple		rt_divide_vector(t_tuple a, float d);
float		rt_magnitude(t_tuple vector);
t_tuple		rt_normalize(t_tuple vector);
float		rt_dot_product(t_tuple a, t_tuple b);
t_tuple		rt_cross_product(t_tuple a, t_tuple b);

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
void		rt_draw(t_env *env, t_object sp, t_ray ray);
void		my_mlx_pixel_put(t_env *env, int x, int y, int color);
int			key_handler(int keycode, t_env *env);
int			window_closed(t_env *env);


/* and then minilibx */

//CH3 Matrices

# define ENOTINVERTIBLE 132

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
t_object	rt_sphere(t_tuple color);
t_intersect	rt_intersect(t_object object, t_ray ray);
t_tuple		rt_sphere_to_ray(t_tuple ray_origin, t_tuple sphere_origin);
void		rt_discriminant(t_ray ray, t_object object, t_intersect *intersect);
float		rt_hit(float t1, float t2);
t_ray		rt_ray_transform(t_matrix m, t_ray r);
t_matrix	rt_set_transform(t_object object, t_matrix transform);

//CH6 Light and Shadows

t_tuple		rt_normal_at(t_object obj, t_tuple point);
t_tuple		rt_reflect(t_tuple in, t_tuple normal);


#endif
