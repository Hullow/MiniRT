/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:34:35 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 10:03:55 by fallan           ###   ########.fr       */
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
	if (errno == EDISCRIMINANT)
		return (rt_intersect(0, \
				rt_sphere(rt_color(0, 0, 0))));
	i = 0;
	while (i < xs.count)
	{
		if (xs.inter[i].t >= 0)
		{
			if (xs.inter[i].t < hit.t)
				hit = xs.inter[i];
		}
		i++;
	}
	return (hit);
}
