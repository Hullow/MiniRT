/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vectors_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:29:51 by pberset           #+#    #+#             */
/*   Updated: 2025/05/01 14:29:53 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_tuple	rt_scale_vector(t_tuple a, float s)
{
	t_tuple	mul;
	float	mul_x;
	float	mul_y;
	float	mul_z;

	errno = 0;
	if (a.w != VECTOR)
	{
		errno = EINVAL;
		mul = rt_vector(0, 0, 0);
		return (mul);
	}
	mul_x = a.x * s;
	mul_y = a.y * s;
	mul_z = a.z * s;
	mul = rt_vector(mul_x, mul_y, mul_z);
	return (mul);
}

t_tuple	rt_divide_vector(t_tuple a, float d)
{
	t_tuple	div;
	float	div_x;
	float	div_y;
	float	div_z;

	errno = 0;
	div.w = VECTOR;
	if (a.w != VECTOR)
	{
		errno = EINVAL;
		div = rt_vector(0, 0, 0);
		return (div);
	}
	div_x = a.x / d;
	div_y = a.y / d;
	div_z = a.z / d;
	div = rt_vector(div_x, div_y, div_z);
	return (div);
}

float rt_dot_product(t_tuple a, t_tuple b)
{
	float	dot;

	dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (dot);
}

t_tuple	rt_cross_product(t_tuple a, t_tuple b)
{
	t_tuple	cross;
	float	cross_x;
	float	cross_y;
	float	cross_z;

	errno = 0;
	if (a.w != VECTOR || b.w != VECTOR)
	{
		errno = EINVAL;
		cross = rt_vector(0, 0, 0);
		return (cross);
	}
	cross_x = a.y * b.z - a.z * b.y;
	cross_y = a.z * b.x - a.x * b.z;
	cross_z = a.x * b.y - a.y * b.x;
	cross = rt_vector(cross_x, cross_y, cross_z);
	return (cross);
}
