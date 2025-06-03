/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_cylinders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:14:19 by pberset           #+#    #+#             */
/*   Updated: 2025/06/02 19:53:45 by pberset          ###   ########.fr       */
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

static void	cy_post_process(t_object cylinder, t_ray ray, t_xs *xs, int *i)
{
	float	y0;
	float	y1;
	int		increment;

	increment = 0;
	if (xs->inter[*i].t > xs->inter[(*i) + 1].t)
		cy_swap(xs, *i);
	y0 = ray.origin.y + xs->inter[*i].t * ray.direction.y;
	if (cylinder.min - EPSILON < y0 && y0 < cylinder.max + EPSILON)
	{
		(xs->count)++;
		increment++;
	}
	y1 = ray.origin.y + xs->inter[(*i) + 1].t * ray.direction.y;
	if (cylinder.min - EPSILON < y1 && y1 < cylinder.max + EPSILON)
	{
		(xs->count)++;
		increment++;
	}
	(*i) += increment;
}

void	rt_ray_cylinder_x(t_object cylinder, t_ray ray, t_xs *xs, int *i)
{
	float	a;
	float	b;
	float	c;
	float	discr;

	errno = 0;
	a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (a == 0)
		discr = -1;
	else
	{
		b = 2 * cy_b(ray, 'x') + 2 * cy_b(ray, 'z');
		c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
		discr = b * b - 4 * a * c;
	}
	if (discr < 0)
		errno = EDISCRIMINANT;
	else
	{
		xs->inter[*i] = rt_intersect(cy_t(a, b, discr, -1), cylinder);
		xs->inter[(*i) + 1] = rt_intersect(cy_t(a, b, discr, 1), cylinder);
		cy_post_process(cylinder, ray, xs, i);
	}
	rt_intersect_caps(cylinder, ray, xs, i);
}
