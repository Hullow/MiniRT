/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_ok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:48:00 by pberset           #+#    #+#             */
/*   Updated: 2025/05/16 18:32:29 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_ray	rt_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	if (origin.w != POINT)
		rt_handle_error(RT_RAY, EINVAL, "origin is not a point");
	if (direction.w != VECTOR)
		rt_handle_error(RT_RAY, EINVAL, "direction is not a vector");
	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

void	rt_print_ray(t_ray ray)
{
	printf("Ray origin\n");
	rt_print_tuple(ray.origin);
	printf("Ray direction\n");
	rt_print_tuple(ray.direction);
}
