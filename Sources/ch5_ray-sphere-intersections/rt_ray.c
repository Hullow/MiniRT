/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:48:00 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	rt_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	if (origin.w != POINT)
		rt_handle_error(RT_RAY, EINVAL, "origin is not a point");
	if (direction.w != VECTOR)
		rt_handle_error(RT_RAY, EINVAL, "direction is not a vector");
	ray.origin = origin;
	ray.dir = direction;
	return (ray);
}
