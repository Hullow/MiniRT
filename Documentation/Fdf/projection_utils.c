/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:24:47 by francis           #+#    #+#             */
/*   Updated: 2024/05/07 17:16:16 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// z_rotation (try with 45 degrees)
void	ft_z_rotation(t_list *point_list)
{
	double	pt[3];
	float	a;

	a = -45 * (M_PI / 180);
	while (point_list)
	{
		pt[0] = ((double *)(point_list->content))[0];
		pt[1] = ((double *)(point_list->content))[1];
		pt[2] = ((double *)(point_list->content))[2];
		((double *)(point_list->content))[0] = \
			(cos(a) * pt[0] - sin(a) * pt[1]);
		((double *)(point_list->content))[1] = \
			(sin(a) * pt[0] + cos(a) * pt[1]);
		((double *)(point_list->content))[2] = pt[2];
		point_list = point_list->next;
	}
}

// x_rotation (try with arctan(sqrt2))
void	ft_x_rotation(t_list *point_list)
{
	double	a;
	double	rotation[3];
	double	pt[5];

	a = atan(1 / sqrt(2)) * 1.8;
	while (point_list)
	{
		pt[0] = ((double *)point_list->content)[0];
		pt[1] = ((double *)point_list->content)[1];
		pt[2] = ((double *)point_list->content)[2];
		rotation[0] = pt[0];
		rotation[1] = cos(a) * pt[1] - sin(a) * pt[2];
		rotation[2] = sin(a) * pt[1] + cos(a) * pt[2];
		((double *)point_list->content)[0] = rotation[0];
		((double *)point_list->content)[1] = rotation[1];
		((double *)point_list->content)[2] = rotation[2];
		point_list = point_list->next;
	}
}
