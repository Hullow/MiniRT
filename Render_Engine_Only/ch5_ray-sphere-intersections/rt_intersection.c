/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:43:50 by pberset           #+#    #+#             */
/*   Updated: 2025/05/17 19:53:10 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_inter	rt_intersect(float t, t_object obj)
{
	t_inter	i;

	i.object = obj;
	i.t = t;
	return (i);
}

void	rt_intersects(t_object object, t_ray ray, t_xs *xs, int *i)
{
	t_matrix	ray_transform;

	rt_inversion(object.transform, &ray_transform);
	ray.origin = rt_mul_tuple_matrix(ray_transform, ray.origin);
	ray.direction = rt_mul_tuple_matrix(ray_transform, ray.direction);
	if (object.shape == SPHERE)
		rt_discriminant(ray, object, xs, i);
	else
		xs->count = 0;
}

t_tuple	rt_position(t_ray ray, float t)
{
	t_tuple	position;

	position = rt_add_tuple(ray.origin, rt_scale_vector(ray.direction, t));
	return (position);
}

t_tuple	rt_sphere_to_ray(t_tuple ray_origin, t_tuple sphere_origin)
{
	t_tuple	distance;

	distance = rt_sub_tuple(ray_origin, sphere_origin);
	return (distance);
}

void	rt_discriminant(t_ray ray, t_object sphere, t_xs *xs, int *i)
{
	float	discr;
	float	a;
	float	b;
	float	c;
	t_tuple	sp_ray;

	errno = 0;
	sp_ray = rt_sphere_to_ray(ray.origin, sphere.origin);
	a = rt_dot_product(ray.direction, ray.direction);
	b = 2 * rt_dot_product(ray.direction, sp_ray);
	c = rt_dot_product(sp_ray, sp_ray) - 1;
	discr = b * b - 4 * a * c;
	if (discr < 0)
		errno = EDISCRIMINANT;
	else
	{
		xs->count += 2;
		xs->inter[*i] = rt_intersect((-b - sqrtf(discr)) / (2 * a), sphere);
		(*i)++;
		xs->inter[*i] = rt_intersect((-b + sqrtf(discr)) / (2 * a), sphere);
		(*i)++;
	}
}

