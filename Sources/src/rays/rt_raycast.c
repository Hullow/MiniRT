/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:15:47 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 15:40:46 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Allocates memory for a ray with an origin and a direction
t_ray	*rt_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*ray;

	ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (errno)
		return (handle_error(RT_RAY, ENOMEM, "ft_calloc fail"));
	if (origin->w != POINT)
		return (handle_error(RT_RAY, EINVAL, "origin is not a point"));
	if (direction->w != VECTOR)
		return (handle_error(RT_RAY, EINVAL, "direction is not a vector"));
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

// Compute a point from a distance d traveled along the ray
t_tuple	*rt_position(t_ray *ray, float d)
{
	t_tuple	*point;

	point = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	if(errno)
		return(handle_error(RT_POSITION, ENOMEM, "ft_calloc fail"));
	point = add_tuple(ray->origin, multiply_tuple_by_scalar(ray->direction, d));
	return (point);
}
