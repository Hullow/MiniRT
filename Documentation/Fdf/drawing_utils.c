/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:00:08 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 15:28:35 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// draws a pixel
// the if checks if a pixel is outside the window,
// and ignores it (to avoid a segfault)
void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	if (y > WINDOW_HEIGHT || x > WINDOW_WIDTH)
		return ;
	dst = env->addr + (y * env->line_length + x * (env->bits_per_pixel / 8));
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
