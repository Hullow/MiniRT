/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_interion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:43:50 by pberset           #+#    #+#             */
/*   Updated: 2025/05/17 18:10:06 by fallan           ###   ########.fr       */
=======
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:43:50 by pberset           #+#    #+#             */
/*   Updated: 2025/05/11 19:26:13 by francis          ###   ########.fr       */
>>>>>>> aa4f48d (Fixes to compile on MacOS: Makefile + rt_intersections)
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

<<<<<<< HEAD
<<<<<<< HEAD
/// @brief Compute a point from a distance d traveled along the ray
/// @return position (t_tuple of type POINT)
t_tuple	rt_position(t_ray ray, float d)
=======
t_intersect	rt_intersect(t_object object, t_ray ray)
=======
t_inter	rt_intersect(float t, t_object obj)
{
	t_inter	i;

	i.object = obj;
	i.t = t;
	return (i);
}

void	rt_intersects(t_object object, t_ray ray, t_xs *xs, int *i)
>>>>>>> 31eda3a (corrected ch6 xs and intersect)
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
>>>>>>> aa4f48d (Fixes to compile on MacOS: Makefile + rt_intersections)
{
	t_tuple	position;

	position = rt_add_tuple(ray.origin, rt_scale_vector(ray.direction, d));
	return (position);
}

t_tuple	rt_sphere_to_ray(t_tuple ray_origin, t_tuple sphere_origin)
{
	t_tuple	distance;

	distance = rt_sub_tuple(ray_origin, sphere_origin);
	return (distance);
}

<<<<<<< HEAD
t_intersect	rt_init_intersect(float t_value, t_object *obj)
{
	t_intersect	i;

	i.t = t_value;
	i.object = *obj;
	return (i);
}

///	@brief computes the ray<->sphere-intersection
/// @param ray		 n.b.: already transformed
/// @param sphere	 the sphere	
/// @param intersect a pointer to the t_intersect struct to be filled
///
/// n.b.: d -> discriminant
/// @returns nothing, everything is stored in intersect
void	rt_discriminant(t_ray ray, t_object *sp, \
	t_intersect_coll *xs, int i)
{
	float	d;
=======
void	rt_discriminant(t_ray ray, t_object sphere, t_xs *xs, int *i)
{
	float	discr;
>>>>>>> 31eda3a (corrected ch6 xs and intersect)
	float	a;
	float	b;
	float	c;
	t_tuple	sp_ray;

	errno = 0;
<<<<<<< HEAD
	sp_ray = rt_sphere_to_ray(ray.origin, sp->origin);
	a = rt_dot_product(ray.direction, ray.direction);
	b = 2 * rt_dot_product(ray.direction, sp_ray);
	c = rt_dot_product(sp_ray, sp_ray) - 1;
	d = b * b - 4 * a * c;
	if (d < 0)
		errno = EDISCRIMINANT;
	else
	{
		xs->count++;
		xs->intersections[i] = rt_init_intersect((-b + sqrtf(d)) / (2 * a), sp);
		if (d > 0)
		{
			xs->count++;
			xs->intersections[i + 1] = \
				rt_init_intersect((-b - sqrtf(d)) / (2 * a), sp);
		}
	}
}
=======
	sp_ray = rt_sphere_to_ray(ray.origin, sphere.origin);
	a = rt_dot_product(ray.direction, ray.direction);
	b = 2 * rt_dot_product(ray.direction, sp_ray);
	c = rt_dot_product(sp_ray, sp_ray) - 1;
	discr = b * b - 4 * a * c;
	if (discr < 0)
	{
		errno = EDISCRIMINANT;
		xs->count += 0;
	}
	else
	{
		xs->count += 2;
		xs->inter[*i] = rt_intersect((-b - sqrtf(discr)) / (2 * a), sphere);
		(*i)++;
		xs->inter[*i] = rt_intersect((-b + sqrtf(discr)) / (2 * a), sphere);
		(*i)++;
	}
}

>>>>>>> 31eda3a (corrected ch6 xs and intersect)
