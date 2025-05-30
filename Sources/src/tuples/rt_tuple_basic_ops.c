/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuple_basic_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:11:00 by fallan            #+#    #+#             */
/*   Updated: 2025/04/21 16:25:14 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* adds two tuples by adding all elements and returning the resulting tuple:
	- if two tuples are points, prints an error message and returns NULL
	- else, add the tuple coordinates and determine the type by adding types:
		- if two are vectors, return a vector (0 + 0 == 0)
		- if one is point and the other a vector, return a point (1 + 0 == 1)*/
t_tuple	add_tuple(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = 0;
	if (a.w == POINT && b.w == POINT)
	{
		printf("add_tuple: can't add point to point\n");
		return (c);
	}
	c.w = a.w + b.w;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

/* substracts two tuples (minuend - subtrahend), 
by substracting all elements of subtrahend from the minuend, 
and returning the resulting tuple:
	- error cases:
		- minuend and subtrahend are points
		- minuend is vector and subtrahend is point (0 - 1 == -1)
			=> print error message and returns NULL
	- else, subtract the tuple coordinates
	and determine the type by subtracting types:
		- if two are vectors, return a vector (0 - 0 == 0)
		- if minuend is point; subtrahend a vector, ret. a point (1 - 0 == 1) */
t_tuple	subtract_tuple(t_tuple minuend, t_tuple subtrahend)
{
	t_tuple	c;

	c.x = 0;
	if (minuend.w == VECTOR && subtrahend.w == POINT)
	{
		printf("Error\nsubtract_tuple: can't subtract point from vector\n");
		return (c);
	}
	c.w = minuend.w - subtrahend.w;
	c.x = minuend.x - subtrahend.x;
	c.y = minuend.y - subtrahend.y;
	c.z = minuend.z - subtrahend.z;
	return (c);
}

/* Gives us the opposite of a vector,
by subtracting it from the zero vector (0,0,0) */
t_tuple	negate_tuple(t_tuple a)
{
	if (a.w != VECTOR)
	{
		printf("Error\nnegate_tuple: can't negate a point or a color\n");
		return (a);
	}
	return (subtract_tuple(rt_vector(0, 0, 0), a));
}

/* modifies the coordinates of the tuple by multiplying them with a scalar;
returns the tuple after these modifications */
t_tuple	multiply_tuple_by_scalar(t_tuple a, float scalar)
{
	t_tuple	c;

	c.x = 0;
	c.x = a.x * scalar;
	c.y = a.y * scalar;
	c.z = a.z * scalar;
	c.w = a.w * scalar;
	return (c);
}

/* modifies the coordinates of the tuple by dividing them with a scalar;
returns the tuple after these modifications */
t_tuple	divide_tuple_by_scalar(t_tuple a, float scalar)
{
	t_tuple	c;

	c.x = 0;
	if (is_equal_float(scalar, 0.0))
	{
		printf("Error\ndivide_by_scalar: cannot divide by 0\n");
		return (c);
	}
	c.x = a.x / scalar;
	c.y = a.y / scalar;
	c.z = a.z / scalar;
	c.w = a.w / scalar;
	return (c);
}
