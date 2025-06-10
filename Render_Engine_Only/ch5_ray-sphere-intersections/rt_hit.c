/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:34:35 by pberset           #+#    #+#             */
/*   Updated: 2025/06/02 20:27:15 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Returns the hit between all intersections t values
/// @param xs t_xs collection of scene intersections
/// @return The smallest positive t value as the hit, or -1 if both are invalid
t_inter	rt_hit(t_xs xs)
{
	int		i;
	t_inter	hit;

	hit.t = INFINITY;
	i = 0;
	while (i < xs.count)
	{
		if (xs.inter[i].t > 0)
		{
			if (xs.inter[i].t < hit.t)
				hit = xs.inter[i];
		}
		i++;
	}
	if (hit.t == INFINITY)
		return (rt_intersect(0, rt_sphere(rt_point(0, 0, 0), 2, \
			rt_color(0, 0, 0))));
	return (hit);
}
