/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:52:16 by fallan            #+#    #+#             */
/*   Updated: 2025/02/20 18:52:34 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

/* Return the absolute value of a float number, as a float */
float	abs_float(float a)
{
	if (a < 0)
		a = a * -1;
	return (a);
}

/* Checks if two floats a and b are equal:
	- returns 1 (true) if the absolute value of the difference between a and b
	(a - b) is smaller than a very small value, EPSILON (defined in the header)
	- return 0 (false) otherwise */
int	is_equal_float(float a, float b)
{
	if (abs_float(a - b) < EPSILON)
		return (1);
	else
		return (0);
}
