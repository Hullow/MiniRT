/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_normal_nonplanar_ok.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:22:59 by pberset           #+#    #+#             */
/*   Updated: 2025/05/16 18:39:57 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_tuple	rt_normal_at(t_object obj, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	invert;

	rt_inversion(obj.transform, &invert);
	object_point = rt_mul_tuple_matrix(invert, world_point);
	object_normal = rt_sub_tuple(object_point, rt_point(0, 0, 0));
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
