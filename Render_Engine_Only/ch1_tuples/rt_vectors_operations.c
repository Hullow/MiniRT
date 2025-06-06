/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vectors_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:29:51 by pberset           #+#    #+#             */
/*   Updated: 2025/06/05 17:38:41 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief multiplies a vector's coordinates by a scalar
/// @return the scaled vector
t_tuple	rt_scale_vector(t_tuple a, float s)
{
	t_tuple	mul;

	if (a.w != VECTOR)
	{
		rt_handle_error(RT_SCALE_VECTOR, EINVAL, "\n input is not a vector");
		return (a);
	}
	mul.x = a.x * s;
	mul.y = a.y * s;
	mul.z = a.z * s;
	mul.w = VECTOR;
	return (mul);
}

t_tuple	rt_divide_tuple(t_tuple a, float d)
{
	t_tuple	div;

	div.x = 0;
	if (is_equal_float(d, 0.0))
	{
		rt_handle_error(RT_DIVIDE_TUPLE, EINVAL, "\ncannot divide by 0");
		return (div);
	}
	div.x = a.x / d;
	div.y = a.y / d;
	div.z = a.z / d;
	div.w = a.w / d;
	return (div);
}

/// @brief returns the dot product for two (3d) vectors;
/// n.b.: only use with vectors
float	rt_dot_product(t_tuple a, t_tuple b)
{
	float	dot;

	if (a.w != VECTOR || b.w != VECTOR)
	{
		rt_handle_error(RT_DOT_PRODUCT, EINVAL, "\none of the inputs\
			 is not a vector");
		return (-1);
	}
	dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (dot);
}

/// @brief returns the cross product (3d) vector
/// n.b.: only use with vectors
t_tuple	rt_cross_product(t_tuple a, t_tuple b)
{
	t_tuple	cross;
	float	cross_x;
	float	cross_y;
	float	cross_z;

	errno = 0;
	if (a.w != VECTOR || b.w != VECTOR)
	{
		rt_handle_error(RT_CROSS_PRODUCT, EINVAL, "\none of the inputs\
			is not a vector");
		cross = rt_vector(0, 0, 0);
		return (cross);
	}
	cross_x = a.y * b.z - a.z * b.y;
	cross_y = a.z * b.x - a.x * b.z;
	cross_z = a.x * b.y - a.y * b.x;
	cross = rt_vector(cross_x, cross_y, cross_z);
	return (cross);
}

/// @brief Multiply two colors using the Hadamard product:
///
/// c.x = a.x * b.x 
///
/// c.y = a.y * b.y
///
/// c.z = a.z * b.z
/// @returns the Hadamard product tuple
t_tuple	rt_hadamard(t_tuple color1, t_tuple color2)
{
	t_tuple	output;

	output.x = color1.x * color2.x;
	output.y = color1.y * color2.y;
	output.z = color1.z * color2.z;
	return (output);
}
