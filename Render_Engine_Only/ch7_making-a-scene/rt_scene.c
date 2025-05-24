/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:03:54 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 18:59:23 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_intersect_scene(t_scene scene, t_ray ray, t_xs *xs)
{
	int		i;
	int		index;
	t_inter	inter_array[MAX_OBJECTS * 2];

	index = 0;
	i = 0;
	xs->count = 0;
	xs->inter = inter_array;
	while (i < scene.n_obj)
	{
		rt_intersects(&(scene.objects[i]), ray, xs, &index);
		i++;
	}
}

t_comps	rt_prepare_computations(t_inter intersect, t_ray ray)
{
	t_comps	comps;

	comps.t = intersect.t;
	comps.object = intersect.object;
	comps.point = rt_position(ray, comps.t);
	comps.eyev = rt_negate_vector(ray.direction);
	comps.normalv = rt_normal_at(comps.object, comps.point);
	if (rt_dot_product(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = rt_negate_vector(comps.normalv);
	}
	else
		comps.inside = 0;
	return (comps);
}

t_tuple	rt_shade_hit(t_scene scene, t_comps comp)
{
	t_tuple	color;

	color = rt_lighting(
			comp.object, scene.lux, comp.point, comp.eyev, comp.normalv);
	return (color);
}

t_tuple	rt_color_at(t_scene scene, t_ray ray)
{
	t_tuple	color;
	t_comps	comps;
	t_xs	xs;
	t_inter	inter;

	rt_intersect_scene(scene, ray, &xs);
	inter = rt_hit(xs);
	comps = rt_prepare_computations(inter, ray);
	color = rt_shade_hit(scene, comps);
	return (color);
}
