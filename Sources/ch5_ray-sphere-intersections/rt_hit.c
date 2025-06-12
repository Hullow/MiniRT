/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:34:35 by pberset           #+#    #+#             */
/*   Updated: 2025/06/12 11:56:24 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Returns the hit between all intersections t values
/// @param xs t_xs collection of scene intersections
/// @return The smallest positive t value as the hit, or -1 if both are invalid
t_inter	rt_hit(t_xs *xs)
{
	int		i;
	t_inter	hit;

	hit.object = rt_sphere(rt_point(0,0,0), 2.0f, rt_color(255, 255, 255));
	hit.object.transform = rt_identity_matrix(4);
	hit.t = INFINITY;
	hit.is_present = false;
	i = 0;
	while (i < xs->count)
	{
		if (xs->inter[i].t > EPSILON)
		{
			if (xs->inter[i].t < hit.t)
			{
				hit = xs->inter[i];
				hit.is_present = true;
			}
		}
		i++;
	}
	return (hit);
}
