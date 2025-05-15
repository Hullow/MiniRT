/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:43:50 by pberset           #+#    #+#             */
/*   Updated: 2025/05/15 15:46:54 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

/* t_intersect_coll	rt_intersect_object(t_object object, t_ray ray, t_intersect_coll *xs)
{
	t_matrix			ray_transform;

	// ray transformation
	rt_inversion(object.transform, &ray_transform);
	ray.origin = rt_mul_tuple_matrix(ray_transform, ray.origin);
	ray.direction = rt_mul_tuple_matrix(ray_transform, ray.direction);
	xs.count = 0;
	
	if (object.shape == SPHERE)
		rt_ray_sphere_intersects(ray, &object, &xs);
	else
		xs = (t_intersect_coll) {.count = 0};
	return (xs);
}
 */
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

t_intersect	rt_init_intersect(float t_value, t_object *obj)
{
	t_intersect	i;
	
	i.t = t_value;
	i.object = obj;
	return (i);
}

///	@brief computes the ray<->sphere-intersection
/// @param ray		 n.b.: already transformed
/// @param sphere	 the sphere	
/// @param intersect a pointer to the t_intersect struct to be filled
/// @returns nothing, everything is stored in intersect
void	rt_ray_sphere_intersects(t_ray ray, t_object *sphere, t_intersect_coll *xs, int i)
{
	float	discriminant;
	float	a;
	float	b;
	float	c;
	t_tuple	sp_ray;

	errno = 0;
	sp_ray = rt_sphere_to_ray(ray.origin, sphere->origin);
	a = rt_dot_product(ray.direction, ray.direction);
	b = 2 * rt_dot_product(ray.direction, sp_ray);
	c = rt_dot_product(sp_ray, sp_ray) - 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		errno = EDISCRIMINANT;
	else
	{
		xs->count++;
		xs->intersections[i] = rt_init_intersect((-b + sqrtf(discriminant)) / (2 * a), sphere);
		if (discriminant > 0)
		{
			xs->count++;
			xs->intersections[i + 1] = rt_init_intersect((-b - sqrtf(discriminant)) / (2 * a), sphere);
		}
	}
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
