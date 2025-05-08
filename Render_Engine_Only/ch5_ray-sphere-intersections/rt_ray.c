/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:48:00 by pberset           #+#    #+#             */
/*   Updated: 2025/05/06 16:09:48 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_ray	rt_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

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
