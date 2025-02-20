/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:14:45 by fallan            #+#    #+#             */
/*   Updated: 2025/02/20 18:52:39 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

/* Initializes a point: mallocs a tuple, fills it with the input coordinates,
sets it type to POINT (0) */
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
sets it type to VECTOR (0) */
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

/* adds two tuples by adding all elements and returning the resulting tuple:
	- if two tuples are points, prints an error message and returns NULL
	- else, add the tuple coordinates and determine the type by adding types:
		- if two are vectors, return a vector (0 + 0 == 0)
		- if one is point and the other a vector, return a point (1 + 0 == 1)*/
t_tuple	*add_tuple(t_tuple *a, t_tuple *b)
{
	t_tuple	*c;

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
t_tuple	*substract_tuple(t_tuple *minuend, t_tuple *subtrahend)
{
	t_tuple	*c;

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

/* main to test the functions */
int	main()
{
	t_tuple *a = point(0.1, -0.4, 15.0);
	t_tuple *b = vector(0.1000001, -0.4, 15.0);

	printf("a has coordinates x: %f, y:%f, z:%f and is a ", a->x, a->y, a->z);
	if (a->type == POINT)
		printf("point\n");
	else
		printf("vector\n");
	printf("b has coordinates x: %f, y:%f, z:%f and is a ", b->x, b->y, b->z);
	if (b->type == POINT)
		printf("point\n");
	else
		printf("vector\n");
	if (is_equal_float(a->x, b->x))
		printf("a->x and b->x are equal\n");
	else
		printf("a->x and b->x are not equal\n");
	if (add_tuple(a, b))
	return (0);
}

