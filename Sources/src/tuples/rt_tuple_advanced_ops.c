/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuple_advanced_ops.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:38:36 by fallan            #+#    #+#             */
/*   Updated: 2025/04/19 15:30:54 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* returns the magnitude (length) of a vector
n.b.: should only be used with vector */
float	magnitude(t_tuple tuple)
{
	float	intermed;

	intermed = powf(tuple.x, 2.0) + powf(tuple.y, 2.0) + powf(tuple.z, 2.0)
		+ powf(tuple.w, 2.0);
	return (sqrtf(intermed));
}

/* normalizes a vector (reduces it to unit vector length
while preserving its direction), and returns it */
t_tuple	normalize(t_tuple tuple)
{
	t_tuple	norm;

	if (is_equal_float(magnitude(tuple), 0))
	{
		printf("Error\nnormalize: vector is null vector, cannot normalize\n");
		return (tuple);
	}
	norm = divide_tuple_by_scalar(tuple, magnitude(tuple));
	return (norm);
}

/* returns the dot product for two (3d) vectors
n.b.: should only be used with vectors */
float	dot_product(t_tuple a, t_tuple b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w));
}

/* returns the cross product (3d) vector
n.b.: should only be used with vectors */
t_tuple	cross_product(t_tuple a, t_tuple b)
{
	return (rt_vector(
			(a.y * b.z) - (a.z * b.y),
			(a.z * b.x) - (a.x * b.z),
			(a.x * b.y) - (a.y * b.x)));
}

// Multiply two colors using the Hadamard product (c.x = a.x * b.x, ...)
// Returns a tuple
t_tuple	rt_hadamard(t_tuple color1, t_tuple color2)
{
	t_tuple	output;

	output.x = color1.x * color2.x;
	output.y = color1.y * color2.y;
	output.z = color1.z * color2.z;
	return (output);
}
