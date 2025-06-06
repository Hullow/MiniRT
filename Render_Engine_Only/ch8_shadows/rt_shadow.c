/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:00:49 by francis           #+#    #+#             */
/*   Updated: 2025/06/06 15:26:45 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	rt_is_shadowed(t_scene *scene, t_tuple point)
{
	t_tuple	point_to_light;
	float	distance;
	t_ray	ray;
	t_xs	xs;
	t_inter	hit;

	point_to_light = rt_sub_tuple(scene->lux.coord, point);
	distance = rt_magnitude(point_to_light);
	ray = rt_ray(point, rt_normalize(point_to_light));
	rt_intersect_scene(scene, &ray, &xs);
	hit = rt_hit(xs);
	if (hit.t != 0 && hit.t < distance)
		return (true);
	return (false);
}
