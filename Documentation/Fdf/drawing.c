/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:33:23 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 17:37:12 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// applies all transformations
// 1. isometric projection:
// 1.1 z-rotation (45 deg)
// 1.2 x-rotation (arctan(1/sqrt(2)) radians)
// 2. zoom:
// 2.2 calculates zoom (using x,y min and max values)
// 2.3 applies zoom to each point of the list
// 3. centers points in the image
// 4. draws lines (using DDA algorithm)
// 4.4 draws "horizontal" lines of grid
// 4.4 draws "vertical" lines of grid
// other variables:
// coord[4]: #lines of grid
// coord[5]: #columns of grid
void	ft_draw(t_env *env)
{
	t_list	*anchor;
	double	*coord;
	double	*minmax;
	double	*minmax2;
	double	zoom;

	anchor = env->point_list;
	coord = (double *)malloc(sizeof(double) * 7);
	coord[5] = ((double *) env->point_list->content)[4];
	ft_z_rotation(env->point_list);
	ft_x_rotation(env->point_list);
	minmax = ft_min_max(env->point_list);
	zoom = ft_calculate_zoom(minmax, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_apply_zoom(env->point_list, zoom);
	minmax2 = ft_min_max(env->point_list);
	ft_center_points(env->point_list, minmax2);
	ft_draw_horizontal(env, coord, 0);
	env->point_list = anchor;
	ft_draw_vertical(env, coord, coord[5]);
	ft_free((void **)&coord);
	ft_free((void **)&minmax);
	ft_free((void **)&minmax2);
}

// draws horizontal lines of the grid, iteratively over the linked list
// go through all columns
void	ft_draw_horizontal(t_env *env, double *coord, int i)
{
	while (env->point_list)
	{
		if (i < coord[5] - 1)
		{
			i++;
			coord[0] = ((double *) env->point_list->content)[0];
			coord[1] = ((double *) env->point_list->content)[1];
			coord[6] = ((double *) env->point_list->content)[5];
			env->point_list = env->point_list->next;
			coord[2] = ((double *) env->point_list->content)[0];
			coord[3] = ((double *) env->point_list->content)[1];
			ft_line_put(env, coord);
		}
		else
		{
			i = 0;
			env->point_list = env->point_list->next;
		}
	}
}

// draws vertical lines of the grid, iteratively over the linked list
// for each point, checks if there is a point one line underneath
// before drawing a line, by iterating #columns point ahead:
// coord[4]: #lines
// coord[5]: #columns
// coord[6]: color
void	ft_draw_vertical(t_env *env, double *coord, int columns)
{
	t_list	*anchor;

	anchor = env->point_list;
	while (env->point_list)
	{
		coord[0] = ((double *)(env->point_list->content))[0];
		coord[1] = ((double *)(env->point_list->content))[1];
		coord[6] = ((double *)(env->point_list->content))[5];
		while (columns && env->point_list->next)
		{
			columns--;
			env->point_list = env->point_list->next;
		}
		if (columns)
			break ;
		else
		{
			coord[2] = ((double *)(env->point_list->content))[0];
			coord[3] = ((double *)(env->point_list->content))[1];
			ft_line_put(env, coord);
		}
		columns = coord[5];
		anchor = anchor->next;
		env->point_list = anchor;
	}
}
