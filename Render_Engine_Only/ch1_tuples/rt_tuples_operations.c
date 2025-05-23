/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuples_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:56:27 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 10:06:03 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief adds two tuples by adding all elements and 
/// returning the resulting tuple
/// - if a and b are points, prints an error message and returns rt_point(0,0,0)
/// - if two are vectors, return a vector (0 + 0 == 0)
/// - if one is point and the other a vector, return a point (1 + 0 == 1)
/// @param a tuple
/// @param b tuple
/// @return the result of the addition (tuple)
t_tuple	rt_add_tuple(t_tuple a, t_tuple b)
{
	t_tuple	add;

	add.x = a.x + b.x;
	add.y = a.y + b.y;
	add.z = a.z + b.z;
	add.w = a.w + b.w;
	return (add);
}
		
/// @brief subtracts two tuples (a - b)
///
/// - if a and b are VECTOR, returns a VECTOR
///
/// - if a is a POINT and b a VECTOR, returns a POINT
///
/// - error cases:
/// 	(1) a is a VECTOR, b is a POINT;
/// 	(2) a and b are POINT;
///
/// @return the tuple resulting from the subtraction
t_tuple	rt_sub_tuple(t_tuple a, t_tuple b)
{
	t_tuple	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	sub.z = a.z - b.z;
	sub.w = a.w - b.w;
	return (sub);
}

/// @brief Gives us the opposite of a vector
/// @param a input vector
/// @return negated vector
t_tuple	rt_negate_vector(t_tuple a)
{
	t_tuple	negate;

	negate.x = -a.x;
	negate.y = -a.y;
	negate.z = -a.z;
	negate.w = a.w;
	return (negate);
}

/// @brief Checks if two tuples are equal using is_equal_float for each element
/// @param a tuple
/// @param b tuple
/// @return 1 (true) if all elements are equal, 0 (false) otherwise
int	rt_is_equal_tuple(t_tuple a, t_tuple b)
{
	if (!is_equal_float(a.w, b.w))
		return (0);
	if (!is_equal_float(a.x, b.x))
		return (0);
	if (!is_equal_float(a.y, b.y))
		return (0);
	if (!is_equal_float(a.z, b.z))
		return (0);
	return (1);
}
	
