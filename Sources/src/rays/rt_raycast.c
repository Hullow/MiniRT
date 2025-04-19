/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:15:47 by pberset           #+#    #+#             */
/*   Updated: 2025/04/19 15:45:29 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Allocates memory for a ray with an origin and a direction
// Intersects set to NULL
// 
// Returns:
// a pointer to the ray
t_ray	rt_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	if (origin.w != POINT)
		rt_handle_error(RT_RAY, EINVAL, "origin is not a point");
	if (direction.w != VECTOR)
		rt_handle_error(RT_RAY, EINVAL, "direction is not a vector");
	ray.origin = origin;
	ray.direction = direction;
	ray.intersects = NULL;
	return (ray);
}

// Compute a point from a distance d traveled along the ray
t_tuple	rt_position(t_ray ray, float d)
{
	t_tuple	point;

	point = add_tuple(ray.origin, multiply_tuple_by_scalar(ray.direction, d));
	return (point);
}
