/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_advanced_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:38:36 by fallan            #+#    #+#             */
/*   Updated: 2025/02/27 15:01:51 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/miniRT.h"



/* returns the magnitude (length) of a vector */
float	magnitude(t_tuple *tuple)
{
	float	intermed;

	if (!tuple)
		return (0.0);
	// if (tuple->w != VECTOR)
	// {
	// 	printf("magnitude: tuple is not a vector, cannot compute magnitude\n");
	// 	return (0.0);
	// }
	intermed = powf(tuple->x, 2.0) + powf(tuple->y, 2.0) + powf(tuple->z, 2.0)
	 + powf(tuple->w, 2.0);
	return (sqrtf(intermed));
}

/* normalizes a vector (reduces it to unit vector length
while preserving its direction), and returns it */
t_tuple	*normalize(t_tuple *tuple)
{
	if (!tuple)
		return (NULL);
	// if (tuple->w != VECTOR)
	// {
	// 	printf("normalize: not a vector, cannot normalize\n");	
	// 	return (NULL);
	// }
	if (is_equal_float(magnitude(tuple), 0))
	{
		printf("normalize: vector is null vector, cannot normalize\n");	
		return (NULL);
	}
	divide_tuple_by_scalar(tuple, magnitude(tuple));
	return (tuple);
}

/* returns the dot product for two (3d) vectors */
float	dot_product(t_tuple *a, t_tuple *b)
{
	if (!a || !b)
		return (0);
	// if (a->w != VECTOR || b->w != VECTOR)
	// {
	// 	printf("dot_product: one or both tuples are not vectors\n");	
	// 	return (0);
	// }
	// printf("dot product: a->x is %f, b->x is %f\n", a->x, b->x);
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w));
}

/* returns the cross product (3d) vector */
t_tuple	*cross_product(t_tuple *a, t_tuple *b)
{
	if (!a || !b)
		return (NULL);
	// if (a->w != VECTOR || b->w != VECTOR)
	// 	return (NULL);
	return (vector(
		(a->y * b->z) - (a->z * b->y),
		(a->z * b->x) - (a->x * b->z),
		(a->x * b->y) - (a->y * b->x)));
}
