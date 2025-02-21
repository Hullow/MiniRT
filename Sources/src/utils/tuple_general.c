/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:14:45 by fallan            #+#    #+#             */
/*   Updated: 2025/02/21 15:37:38 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

/* Initializes a point: mallocs a tuple, fills it with the input coordinates,
sets its type to POINT (0) */
t_tuple	*point(float x, float y, float z)
{
	t_tuple	*point;

	point = malloc(sizeof(t_tuple));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->type = POINT;
	return (point);
}

/* Initializes a vector: mallocs a tuple, fills it with the input coordinates,
sets its type to VECTOR (0) */
t_tuple	*vector(float x, float y, float z)
{
	t_tuple	*vector;

	vector = malloc(sizeof(t_tuple));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->type = VECTOR;
	return (vector);
}

/* Checks if two tuples are equal:
	- if type not equal, return 0 (false)
	- if any of the coordinates are not equal, return 0 (false)
	- return 1 (true) otherwise */
int	is_equal_tuple(t_tuple *a, t_tuple *b)
{
	if (!a || !b)
		return (0);
	if (a->type != b->type)
		return (0);
	if (!is_equal_float(a->x, b->x))
		return (0);
	if (!is_equal_float(a->y, b->y))
		return (0);
	if (!is_equal_float(a->z, b->z))
		return (0);
	return (1);
}
