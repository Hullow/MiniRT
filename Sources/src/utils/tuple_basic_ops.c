/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils_edit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:11:00 by fallan            #+#    #+#             */
/*   Updated: 2025/02/21 15:37:53 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

/* adds two tuples by adding all elements and returning the resulting tuple:
	- if two tuples are points, prints an error message and returns NULL
	- else, add the tuple coordinates and determine the type by adding types:
		- if two are vectors, return a vector (0 + 0 == 0)
		- if one is point and the other a vector, return a point (1 + 0 == 1)*/
t_tuple	*add_tuple(t_tuple *a, t_tuple *b)
{
	t_tuple	*c;

	if (!a || !b)
		return (NULL);
	if (a->type == POINT && b->type == POINT)
	{
		printf("add_tuple: can't add point to point\n");
		return (NULL);
	}
	c = malloc (sizeof(t_tuple));
	if (!c)
		return (NULL);
	c->type = a->type + b->type;
	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;
	return (c);
}

/* substracts two tuples by substracting all elements of subtrahend
from the minuend (minuend - subtrahend), and returning the resulting tuple:
	- error cases:
		- minuend and subtrahend are points
		- minuend is vector and subtrahend is point (0 - 1 == -1)
			=> print error message and returns NULL
	- else, subtract the tuple coordinates
	and determine the type by subtracting types:
		- if two are vectors, return a vector (0 - 0 == 0)
		- if minuend is point; subtrahend a vector, ret. a point (1 - 0 == 1) */
t_tuple	*subtract_tuple(t_tuple *minuend, t_tuple *subtrahend)
{
	t_tuple	*c;

	if (!minuend || !subtrahend)
		return (NULL);
	if (minuend->type == POINT && subtrahend->type == POINT)
	{
		printf("add_tuple: can't subtract point from point\n");
		return (NULL);
	}
	else if (minuend->type == VECTOR && subtrahend->type == POINT)
	{
		printf("add_tuple: can't subtract point from vector\n");
		return (NULL);
	}
	c = malloc (sizeof(t_tuple));
	if (!c)
		return (NULL);
	c->type = minuend->type - subtrahend->type;
	c->x = minuend->x - subtrahend->x;
	c->y = minuend->y - subtrahend->y;
	c->z = minuend->z - subtrahend->z;
	return (c);
}

/* Gives us the opposite of a vector,
by subtracting it from the zero vector (0,0,0) */
t_tuple	*negate_tuple(t_tuple *a)
{
	if (!a)
		return (NULL);
	if (a->type != VECTOR)
	{
		printf("negate_tuple: can't negate a point\n");
		return (NULL);
	}
	a = subtract_tuple(vector(0, 0, 0), a);
	return (a);
}

/* modifies the coordinates of the tuple by multiplying them with a scalar;
returns the tuple after these modifications */
t_tuple	*multiply_tuple_by_scalar(t_tuple *a, float scalar)
{
	if (!a)
		return (NULL);
	printf("tuple->x before: %.3f\n", a->x);
	a->x = a->x * scalar;
	printf("tuple->x after: %.3f\n", a->x);
	printf("tuple->y before: %2.f\n", a->y);
	a->y = a->y * scalar;
	a->z = a->z * scalar;
	return (a);
}

/* modifies the coordinates of the tuple by dividing them with a scalar;
returns the tuple after these modifications */
t_tuple	*divide_tuple_by_scalar(t_tuple *a, float scalar)
{
	if (!a)
		return (NULL);
	if (is_equal_float(scalar, 0.0))
	{
		printf("divide_by_scalar: cannot divide by 0\n");
		return (NULL);
	}
	a->x = a->x / scalar;
	a->y = a->y / scalar;
	a->z = a->z / scalar;
	return (a);
}
