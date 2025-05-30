/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:43:50 by pberset           #+#    #+#             */
/*   Updated: 2025/05/11 19:26:13 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_intersect	rt_intersect(t_object object, t_ray ray)
{
	t_intersect	intersect;
	t_matrix	ray_transform;

	rt_inversion(object.transform, &ray_transform);
	ray.origin = rt_mul_tuple_matrix(ray_transform, ray.origin);
	ray.direction = rt_mul_tuple_matrix(ray_transform, ray.direction);
	if (object.shape == SPHERE)
		rt_discriminant(ray, object, &intersect);
	else
		intersect = (t_intersect) {.count = 0};
	return (intersect);
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

void	rt_discriminant(t_ray ray, t_object sphere, t_intersect *intersect)
{
	float	discriminant;
	float	a;
	float	b;
	float	c;
	t_tuple	sp_ray;

	errno = 0;
	intersect->object = sphere;
	sp_ray = rt_sphere_to_ray(ray.origin, sphere.origin);
	a = rt_dot_product(ray.direction, ray.direction);
	b = 2 * rt_dot_product(ray.direction, sp_ray);
	c = rt_dot_product(sp_ray, sp_ray) - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		errno = EDISCRIMINANT;
		intersect->count = 0;
		return ;
	}
	intersect->count = 2;
	intersect->first = (-b - sqrtf(discriminant)) / (2 * a);
	intersect->last = (-b + sqrtf(discriminant)) / (2 * a);
}

/// @brief Returns the hit between two t values
/// @param t1 
/// @param t2 
/// @return The smallest positive t value as the hit, or -1 if both are invalid
float	rt_hit(float t1, float t2)
{
	if (errno == EDISCRIMINANT)
		return (-1.0f);
	if ((t1 < t2 || t2 < 0) && t1 >= 0)
		return (t1);
	if ((t2 < t1 || t1 < 0) && t2 >= 0)
		return (t2);
	if (t1 == t2 && t1 >= 0)
		return (t1);
	return (-1.0f);
}
