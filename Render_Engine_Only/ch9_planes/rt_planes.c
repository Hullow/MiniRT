/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_planes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:06:07 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 15:06:09 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_ray_plane_x(t_object plane, t_ray ray, t_xs *xs, int *i)
{
	float		t;

	errno = 0;
	if (fabs(ray.direction.y) < EPSILON)
		errno = ERAYPARALLEL;
	else
	{
		t = -ray.origin.y / ray.direction.y;
		xs->count++;
		xs->inter[*i] = rt_intersect(t, plane);
		(*i)++;
	}
}
