/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:03:54 by pberset           #+#    #+#             */
/*   Updated: 2025/06/12 11:56:22 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter	rt_intersect_scene(t_scene *scene, t_ray *ray, t_xs *xs)
{
	int			i;
	int			index;
	t_inter		inter_array[MAX_OBJECTS * 2];
	t_matrix	ray_transform;
	t_inter		hit;

	index = 0;
	i = 0;
	xs->count = 0;
	xs->inter = inter_array;
	while (i < scene->n_obj)
	{
		ray_transform = rt_inversion(scene->objects[i].transform);
		scene->objects[i].saved_ray.origin = rt_mul_tuple_matrix(ray_transform, ray->origin);
		scene->objects[i].saved_ray.direction = \
			rt_mul_tuple_matrix(ray_transform, ray->direction);
		rt_intersects(&(scene->objects[i]), xs, &index);
		i++;
	}
	hit = rt_hit(xs);
	return (hit);
}

t_comps	rt_prepare_computations(t_inter intersect, t_ray *ray)
{
	t_comps	comps;

	comps.t = intersect.t;
	comps.object = intersect.object;
	comps.point = rt_position(ray, comps.t);
	comps.eyev = rt_negate_vector(ray->direction);
	comps.normalv = rt_normal_at(comps.object, comps.point);
	if (rt_dot_product(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.normalv = rt_negate_vector(comps.normalv);
	}
	else
		comps.inside = 0;
	comps.over_point = \
		rt_add_tuple(comps.point, rt_scale_vector(comps.normalv, EPSILON));
	return (comps);
}

t_tuple	rt_shade_hit(t_scene *scene, t_comps comp)
{
	t_tuple	color;

	comp.in_shadow = rt_is_shadowed(scene, comp.over_point);
	color = rt_lighting(scene->lux, comp);
	return (color);
}

t_tuple	rt_color_at(t_scene *scene, t_ray *ray)
{
	t_tuple	color;
	t_comps	comps;
	t_xs	xs;
	t_inter	hit;

	hit = rt_intersect_scene(scene, ray, &xs);
	if (hit.t == 0)
		return (rt_color(0, 0, 0));
	comps = rt_prepare_computations(hit, ray);
	color = rt_shade_hit(scene, comps);
	return (color);
}

void	rt_render(t_scene *scene, t_env *env)
{
	t_ray	ray;
	int		x;
	int		y;
	t_tuple	color;

	y = 0;
	while (y < scene->cam.vsize - 1)
	{
		x = 0;
		while (x < scene->cam.hsize - 1)
		{
			ray = rt_ray_for_pixel(&scene->cam, x, y);
			color = rt_color_at(scene, &ray);
			color = rt_reinhard_tonemap(color);
			my_mlx_pixel_put(env, x, y, rgb_to_int(color));
			x++;
		}
		y++;
		if ((y + 1) % 100 == 0)
			ft_printf("Progressing: %f\n", (float)((float)(y + 1) / (float)WINDOW_HEIGHT * 100.0f));
	}
}
