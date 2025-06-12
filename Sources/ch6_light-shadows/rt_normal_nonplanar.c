/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_normal_nonplanar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:22:59 by pberset           #+#    #+#             */
/*   Updated: 2025/06/12 19:16:48 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tuple	rt_local_normal_capped_cylinder(t_object cylinder, t_tuple point)
{
	t_tuple	normal;
	float	dist;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= cylinder.max - EPSILON)
		normal = rt_vector(0, 1, 0);
	else if (dist < 1 && point.y <= cylinder.min + EPSILON)
		normal = rt_vector(0, -1, 0);
	else
		normal = rt_vector(point.x, 0, point.z);
	return (normal);
}

t_tuple	rt_local_normal_at(t_object obj, t_tuple point)
{
	t_tuple	normal;

	if (obj.shape == SPHERE)
		normal = rt_vector(point.x, point.y, point.z);
	else if (obj.shape == PLANE)
		normal = rt_vector(0,1,0);
	else if (obj.shape == CYLINDER)
		normal = rt_local_normal_capped_cylinder(obj, point);
	else
		normal = rt_vector(0, 0, 0);
	return (rt_normalize(normal));
}

t_tuple	rt_normal_at(t_object obj, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	invert;

	invert = rt_inversion(obj.transform);
	object_point = rt_mul_tuple_matrix(invert, world_point);
	object_point.w = POINT;
	object_normal = rt_local_normal_at(obj, object_point);
	world_normal = \
		rt_mul_tuple_matrix(rt_matrix_transpose(invert), object_normal);
	return (rt_normalize(world_normal));
}

t_tuple	rt_reflect(t_tuple in, t_tuple normal)
{
	float	dot;
	t_tuple	scale;
	t_tuple	reflect;

	scale = rt_scale_vector(normal, 2);
	dot = rt_dot_product(in, normal);
	scale = rt_scale_vector(scale, dot);
	reflect = rt_sub_tuple(in, scale);
	return (reflect);
}
