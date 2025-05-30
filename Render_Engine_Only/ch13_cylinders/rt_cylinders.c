/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylinders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:14:19 by pberset           #+#    #+#             */
/*   Updated: 2025/05/30 14:14:20 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_ray_cylinder_x(t_object cylinder, t_ray ray, t_xs *xs, int *i)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;

	errno = 0;
	a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (a < EPSILON)
		errno = ERAYPARALLEL;
	else
	{
		b = 2 * ray.origin.x * ray.direction.x + \
			2 * ray.origin.z * ray.direction.z;
		c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
		discriminant = b * b - 4 * a * c;
		if (discriminant < 0)
			errno = EDISCRIMINANT;
		else
		{
			xs->count += 2;
			xs->inter[*i] = rt_intersect((-b - sqrtf(discriminant)) / (2 * a), \
				cylinder);
			(*i)++;
			xs->inter[*i] = rt_intersect((-b + sqrtf(discriminant)) / (2 * a), \
				cylinder);
			(*i)++;
		}
	}
}
