/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analog_clock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:05:55 by fallan            #+#    #+#             */
/*   Updated: 2025/04/04 17:17:47 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "fdf.h"
/*

t_tuple	*fit_coordinates(t_tuple *cart_coord)
{
	// zoom to fit window by multiplying coordinates 
}


t_tuple	*center_coordinates(t_tuple *cart_coord)
{
	t_tuple *mlx_coord = rt_point(
		cart_coord->x + (WINDOW_WIDTH / 2), // x
		0, // y
		cart_coord->z + (WINDOW_HEIGHT / 2)); // z
	free(cart_coord);
	return (mlx_coord);
}


// transforms a tuple by multiplying it with a given transform 
//(rotation, scale, shear, translation) 
void	transform_tuple(t_tuple *tuple, void *data, t_transform transform)
{
	t_tuple	*temp;

	temp = tuple;
	if (transform == ROT_X)
		tuple = matrix_tuple_multiplication(rt_rotation_x(*((float *)data)), tuple);
	else if (transform == ROT_Y)
		tuple = matrix_tuple_multiplication(rt_rotation_y(*((float *)data)), tuple);
	else if (transform == ROT_Z)
		tuple = matrix_tuple_multiplication(rt_rotation_z(*((float *)data)), tuple);
	else if (transform == SCALE)
		tuple = matrix_tuple_multiplication(rt_translation((t_tuple *)data), tuple);
	else if (transform == SHEAR)
		tuple = matrix_tuple_multiplication(rt_translation((t_tuple *)data), tuple);
	else if (transform == TRANSLATION)
		tuple = matrix_tuple_multiplication(rt_translation((t_tuple *)data), tuple);
	else
		return ;
	free (temp);
}


void	draw_clock()
{
	t_tuple	*origin = point(0, 0, 0);
	t_tuple	*clock_hand = rt_vector(1, 0, 0);
	t_tuple	*point_to_draw = add_tuple(origin, clock_hand);
	float	angle = 0;

	while(angle < 2 * M_PI)
	{
		transform_tuple(clock_hand, &angle, ROT_Y);
		angle += M_PI / 6;
	}
	// transform_function(clock_hand, &origin, TRANSLATION);
}


int main()
{
	draw_clock()
}


// draws a pixel
// the if checks if a pixel is outside the window,
// and ignores it (to avoid a segfault)
void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;
	int		mem_offset;

	if (y > WINDOW_HEIGHT || x > WINDOW_WIDTH)
		return ;
	mem_offset = y * env->line_length + x * (env->bits_per_pixel / 8);
	dst = env->addr + mem_offset;
	*(unsigned int *)dst = color;
}

// DDA line drawing algorithm
// 1. calculate steps required for generating pixels
// 2. put pixels for each step
// 2.1 increment in x at each step
// 2.2 increment in y at each step
void	ft_line_put(t_env *env, double *coord)
{
	double	x_put;
	double	y_put;
	double	steps;
	int		i;

	if (fabs(coord[2] - coord[0]) > fabs(coord[3] - coord[1]))
		steps = fabs(coord[2] - coord[0]);
	else
		steps = fabs(coord[3] - coord[1]);
	x_put = coord[0];
	y_put = coord[1];
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(env, round(x_put), round(y_put), coord[6]);
		x_put += (coord[2] - coord[0]) / steps;
		y_put += (coord[3] - coord[1]) / steps;
		i++;
	}
}

void	ft_clear_pixels(t_env *env)
{
	int	x;
	int	y;
	int	lines;
	int	columns;

	x = -1;
	y = -1;
	lines = ((int *)env->point_list->content)[3];
	columns = ((int *)env->point_list->content)[4];
	while (env->point_list && ++x < lines)
	{
		while (env->point_list && ++y < columns)
		{
			my_mlx_pixel_put(env, x, y, 0);
			env->point_list = env->point_list->next;
		}
		y = 0;
	}
}

*/