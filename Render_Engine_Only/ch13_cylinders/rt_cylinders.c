/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylinders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:14:19 by pberset           #+#    #+#             */
/*   Updated: 2025/06/03 22:50:18 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static float	cy_t(float a, float b, float discriminant, int signe)
{
	float	t;

	t = (-b + signe * sqrtf(discriminant)) / (2 * a);
	return (t);
}

static float	cy_b(t_ray ray, char axis)
{
	if (axis == 'x')
		return ( ray.origin.x * ray.direction.x);
	else
		return (ray.origin.z * ray.direction.z);
}

static void	cy_swap(t_xs *xs, int i)
{
	float	buffer;

	buffer = xs->inter[i].t;
	xs->inter[i].t = xs->inter[i + 1].t;
	xs->inter[i + 1].t = buffer;
}

static void	cy_post_process(t_object cylinder, t_ray ray, t_xs *xs, t_cyl_val *val)
{
	float	y0;
	float	y1;
	float	t0;
	float	t1;

	t0 = cy_t(val->a, val->b, val->discr, -1);
	t1 = cy_t(val->a, val->b, val->discr, 1);
	y0 = ray.origin.y + t0 * ray.direction.y;
	if (cylinder.min < y0 && y0 < cylinder.max)
	{
		xs->inter[val->i] = rt_intersect(t0, cylinder);
		(xs->count)++;
		(val->i)++;
	}
	y1 = ray.origin.y + t1 * ray.direction.y;
	if (cylinder.min < y1 && y1 < cylinder.max)
	{
		xs->inter[val->i] = rt_intersect(t1, cylinder);
		(xs->count)++;
		(val->i)++;
	}
}

void	rt_ray_cylinder_x(t_object cylinder, t_ray ray, t_xs *xs, int *i)
{
	t_cyl_val	val;

	errno = 0;
	val.a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (is_equal_float(val.a, 0))
		val.discr = -1;
	else
	{
		val.b = 2 * (ray.origin.x * ray.direction.x + ray.origin.z * ray.direction.z);
		val.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
		val.discr = val.b * val.b - 4 * val.a * val.c;
	}
	if (val.discr < 0)
		errno = EDISCRIMINANT;
	else
	{
		val.i = *i;
		cy_post_process(cylinder, ray, xs, &val);
		*i = val.i;
	}
	rt_intersect_caps(cylinder, ray, xs, i);
}
