/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:34:35 by pberset           #+#    #+#             */
/*   Updated: 2025/05/16 13:34:37 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

/// @brief Returns the hit between all intersections t values
/// @param xs t_xs collection of scene intersections
/// @return The smallest positive t value as the hit, or -1 if both are invalid
t_inter	rt_hit(t_xs xs)
{
	int		i;
	t_inter	hit;

	hit.t = INFINITY;
	if (errno == EDISCRIMINANT)
		return (rt_intersect(0, (t_object){}));
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

