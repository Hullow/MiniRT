/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:03:54 by pberset           #+#    #+#             */
/*   Updated: 2025/05/17 19:51:35 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

void	rt_default_scene(t_scene *scene)
{
	t_object	sphere_1;
	t_object	sphere_2;
	t_light		light;

	sphere_1 = rt_sphere(rt_color(0.8 * 255, 1.0 * 255, 0.6 * 255), \
		rt_material(0.1, 0.7, 0.2, 200));
	sphere_2 = rt_sphere(rt_color(255, 255, 255), \
		rt_material(0.1, 0.7, 0.2, 200));
	sphere_2.transform = rt_scaling(rt_vector(0.5, 0.5, 0.5));
	light = rt_light (rt_color(255, 255, 255), rt_point(-10, 10, -10), 1);
	scene->objects[0] = sphere_1;
	scene->objects[1] = sphere_2;
	scene->lux = light;
	rt_print_sphere(sphere_1);
}

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
		rt_intersects(scene.objects[i], ray, xs, &index);
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

	color = rt_lighting(comp.object, scene.lux, comp.point, comp.eyev, comp.normalv);
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
