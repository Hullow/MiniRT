/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_planes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:06:07 by pberset           #+#    #+#             */
/*   Updated: 2025/06/12 19:16:51 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_ray_plane_x(t_object plane, t_ray ray, t_xs *xs, int *i)
{
	float		t;

	errno = 0;
	if (is_equal_float(ray.dir.y, 0.0f))
		errno = ERAYPARALLEL;
	else
	{
		t = -ray.origin.y / ray.dir.y;
		xs->count++;
		xs->inter[*i] = rt_intersect(t, plane);
		(*i)++;
	}
}
