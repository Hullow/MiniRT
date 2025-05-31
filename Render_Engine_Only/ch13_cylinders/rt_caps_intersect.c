/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_caps_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:00:16 by pberset           #+#    #+#             */
/*   Updated: 2025/05/31 16:00:17 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Checks it t value is within a radius of 1 from the y axis
/// @param ray t_ray
/// @param t float t value
/// @return bool true (1) or false (0)
int	rt_check_cap(t_ray ray, float t)
{
	float	x;
	float	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return ((x * x + z * z) <= 1 + EPSILON);
}

/// @brief Only matters if the cylinder is closed
/// @param object 
/// @param ray 
/// @param xs 
void	rt_intersect_caps(t_object cylinder, t_ray ray, t_xs *xs, int *i)
{
	float	t;
	int		j;

	if (cylinder.closed == 0 || \
			(ray.direction.y > -EPSILON && ray.direction.y < EPSILON))
		return ;
	j = 0;
	t = (cylinder.min - ray.origin.y) / ray.direction.y;
	if (rt_check_cap(ray, t))
	{
		xs->inter[(*i) + j] = rt_intersect(t, cylinder);
		j++;
		(xs->count)++;
	}
	t = (cylinder.max - ray.origin.y) / ray.direction.y;
	if (rt_check_cap(ray, t))
	{
		xs->inter[(*i) + j] = rt_intersect(t, cylinder);
		j++;
		(xs->count)++;
	}
	(*i) += j;
}
