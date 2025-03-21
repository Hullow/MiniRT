/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuple_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:14:45 by fallan            #+#    #+#             */
/*   Updated: 2025/03/21 18:26:34 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Initializes a point: mallocs a tuple, fills it with the input coordinates,
sets its type to POINT (0) */
t_tuple	*rt_point(float x, float y, float z)
{
	t_tuple	*point;

	point = malloc(sizeof(t_tuple));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->w = POINT;
	return (point);
}

/* Initializes a color tuple: mallocs a tuple, 
fills it with the input colors RGB / 255, sets its type to COLOR (2.0) */
t_tuple	*rt_color(float r, float g, float b)
{
	t_tuple	*color;

	color = malloc(sizeof(t_tuple));
	if (!color)
		return (NULL);
	color->x = r / 255.0;
	color->y = g / 255.0;
	color->z = b / 255.0;
	color->w = COLOR;
	return (color);
}

/* Initializes a vector: mallocs a tuple, fills it with the input coordinates,
sets its type to VECTOR (0) */
t_tuple	*rt_vector(float x, float y, float z)
{
	t_tuple	*vector;

	vector = malloc(sizeof(t_tuple));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->w = VECTOR;
	return (vector);
}

/* Checks if two tuples are equal:
	- if type (w) not equal, return 0 (false)
	- if any of the coordinates are not equal, return 0 (false)
	- return 1 (true) otherwise */
int	is_equal_tuple(t_tuple *a, t_tuple *b)
{
	if (!a || !b)
		return (0);
	if (!is_equal_float(a->w, b->w))
		return (0);
	if (!is_equal_float(a->x, b->x))
		return (0);
	if (!is_equal_float(a->y, b->y))
		return (0);
	if (!is_equal_float(a->z, b->z))
		return (0);
	return (1);
}
