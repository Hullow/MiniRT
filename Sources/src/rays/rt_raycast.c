/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:15:47 by pberset           #+#    #+#             */
/*   Updated: 2025/03/13 16:22:26 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

t_ray		*rt_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*ray;

	ray = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}