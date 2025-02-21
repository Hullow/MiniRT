/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:35:34 by fallan            #+#    #+#             */
/*   Updated: 2025/02/21 16:43:08 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../miniRT.h"


/* main to test the functions */
int	main()
{

	// t_tuple *neg_b = vector(-0.1000001, 0.4, -15.0);
	// t_tuple *c = point(0.2000001, -0.8, 30.00001);

	// printf("a has coordinates x: %f, y:%f, z:%f and is a ", a->x, a->y, a->z);
	// if (a->type == POINT)
	// 	printf("point\n");
	// else
	// 	printf("vector\n");
	// printf("b has coordinates x: %f, y:%f, z:%f and is a ", b->x, b->y, b->z);
	// if (b->type == POINT)
	// 	printf("point\n");
	// else
	// 	printf("vector\n");
	// if (is_equal_float(a->x, b->x))
	// 	printf("a->x and b->x are equal\n");
	// else
	// 	printf("a->x and b->x are not equal\n");
	// if (is_equal_tuple(add_tuple(a, b), c))
	// 	printf("adding tuples: a+b == c\n");
	// else
	// 	printf("adding tuples: a+b != c\n");
	// if (is_equal_tuple(subtract_tuple(c, b), a))
	// 	printf("subtracting tuples: c-b == a\n");
	// else
	// 	printf("subtracting tuples: c-b != a\n");
	// if (is_equal_tuple(negate_tuple(b), neg_b))
	// 	printf("negate b == neg_b\n");
	// else
	// 	printf("negate b != neg_b\n");


	// if (is_equal_tuple(multiply_tuple_by_scalar(b, 1), b))
	// 	printf("multiply b by 1 == b\n");
	// else
	// 	printf("multiply b by 1 != b\n");
	// if (is_equal_tuple(divide_tuple_by_scalar(b, 1), b))
	// 	printf("divide b by 1 == b\n");
	// else
	// 	printf("divide b by 1 != b\n");
	// if (is_equal_tuple(divide_tuple_by_scalar(b, 0), vector(0,0,0)))
	// 	printf("divide b by 0 == 0\n");
	// else
	// 	printf("divide b by 0 != 0\n");

	// t_tuple *a = point(0.1, -0.4, 15.0);
	// if (is_equal_tuple(divide_tuple_by_scalar(double_b, 2), b))
	// 	printf("divide double_b by 2 == b\n");
	// else
	// 	printf("divide double_b by 2 != b\n");


	t_tuple *b = vector(0.10, -0.4, 15.0);
	t_tuple *double_b = vector(0.20, -0.8, 30.0);
	if (is_equal_tuple(multiply_tuple_by_scalar(b, 2), double_b))
		printf("multiply b by 2 == double_b\n");
	else
		printf("multiply b by 2 != double_b\n");

	// if (is_equal_tuple(multiply_tuple_by_scalar(b, 0), vector(0,0,0)))
	// 	printf("multiply b by 0 == 0\n");
	// else
	// 	printf("multiply b by 0 != 0\n");
	
	t_tuple	*unit_vector = vector(1, 1, 1.0);
	printf("\n", magnitude(unit_vector));
	return (0);
}
