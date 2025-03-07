/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:13:54 by fallan            #+#    #+#             */
/*   Updated: 2025/03/07 15:17:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

/* prints the message corresponding to the error type (see enum in header), 
and returns -1 */
void	*handle_error(t_error error_type)
{
	if (error_type == NULL_INPUT)
	{
		printf("input is NULL - couldn't perform operation\n");
		return (NULL);
	}
	else if (error_type == MALLOC_FAIL)
	{
		printf("malloc fail\n");
		return (NULL);
	}
	else if (error_type == INVALID_MATRIX_SIZE)
	{
		printf("invalid matrix size\n");
		return (NULL);
	}
	else if (error_type == MATRIX_NOT_INVERTIBLE)
	{
		printf("matrix is not invertible\n");
		return (NULL);
	}
	return (0);
}

/* Checks if two floats a and b are equal:
	- returns 1 (true) if the absolute value of the difference between a and b
	(a - b) is smaller than a very small value, EPSILON (defined in the header)
	- return 0 (false) otherwise */
int	is_equal_float(float a, float b)
{
	if (fabsf(a - b) < EPSILON)
		return (1);
	else
		return (0);
}
