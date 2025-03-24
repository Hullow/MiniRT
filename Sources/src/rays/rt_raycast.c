/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:15:47 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 14:45:15 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Allocates memory for a ray with an origin and a direction
t_ray		*rt_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*ray;

	ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (errno)
	{
		perror("Error\nray allocation");
		return (NULL);
	}
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}