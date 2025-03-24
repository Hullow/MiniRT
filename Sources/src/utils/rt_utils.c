/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:13:54 by fallan            #+#    #+#             */
/*   Updated: 2025/03/24 12:00:44 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* handles the error print by calling print_ret_null with
the appropriate error message

Arguments:
- FUNCTION (enum): the function where the error was found
- error_type (t_error, a typedef'd enum)

Return value: NULL in all cases */
void	*handle_error(enum FUNCTION, t_error error_type)
{
	if (error_type == WRONG_INPUT)
		return (print_ret_null(FUNCTION, "wrong input"));
	else if (error_type == NULL_INPUT)
		return (print_ret_null(FUNCTION, "wrong input (NULL)"));
	else if (error_type == MALLOC_FAIL)
		return (print_ret_null(FUNCTION, "malloc fail"));
	else if (error_type == INVALID_MATRIX_SIZE)
		return (print_ret_null(FUNCTION, "invalid matrix size"));
	else if (error_type == MATRIX_NOT_INVERTIBLE)
		return (print_ret_null(FUNCTION, "matrix is not invertible"));
	return (NULL);
}

/* Prints an error message and returns NULL

Arguments:
	- FUNCTION (enum): the function where the error was found
	- message (char *): the error message to print */
void	*print_ret_null(enum FUNCTION, char *message)
{
	printf("Error ");
	if (FUNCTION)
	{
		if (FUNCTION == RT_RAY)
			printf(" – rt_ray: ");
			// ....
	}
	else
		printf(": ");
	printf("%s\n", message);
	return (NULL);
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
