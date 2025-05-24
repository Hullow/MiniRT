/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:03:54 by pberset           #+#    #+#             */
/*   Updated: 2025/05/24 15:34:42 by fallan         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_default_scene(t_scene *scene)
{
	t_object	plane_1;
	t_object	plane_2;
	t_object	sphere_1;
	t_object	sphere_2;
	t_object	sphere_3;
	t_object	sphere_4;
	t_object	sphere_5;
	t_light		light;

	plane_1 = rt_plane(rt_color(255, 0.2 * 255, 255));
	plane_1.transform = rt_translation(rt_vector(0, -5, 0));
	plane_1.transform = rt_set_transform(plane_1, rt_rotation_z(M_PI / 12));

	plane_2 = rt_plane(rt_color(255, 0.5 * 255, 255));
	plane_2.transform = rt_translation(rt_vector(0, 5, 0));
	plane_2.transform = rt_set_transform(plane_2, rt_rotation_z(M_PI / 12));
	
	sphere_1 = rt_sphere(rt_color(0.8 * 255, 1.0 * 255, 0.6 * 255));
	sphere_1.transform = rt_translation(rt_vector(0, 3, 0));
	
	sphere_2 = rt_sphere(rt_color(255, 255, 255));
 	sphere_2.transform = rt_translation(rt_vector(3, 1, 0));

	sphere_3 = rt_sphere(rt_color(255, 0, 0));
	sphere_3.transform = rt_translation(rt_vector(2, -2, 0));

	sphere_4 = rt_sphere(rt_color(0, 0, 255));
	sphere_4.transform = rt_translation(rt_vector(-2, -2, 0));

	sphere_5 = rt_sphere(rt_color(0, 255, 0));
	sphere_5.transform = rt_translation(rt_vector(-3, 1, 0));

	light = rt_light (rt_color(255, 255, 255), rt_point(0, 0, 2), 1);
	scene->n_obj = 6;
	scene->objects[0] = sphere_1;
	scene->objects[1] = sphere_2;
	scene->objects[2] = sphere_3;
	scene->objects[3] = sphere_4;
	scene->objects[4] = sphere_5;
	scene->objects[5] = plane_1;
	scene->objects[6] = plane_2;
	scene->lux = light;
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

	color = rt_lighting(scene.lux, comp);
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
