/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:13:54 by fallan            #+#    #+#             */
/*   Updated: 2025/03/24 15:36:12 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* handles the error print by printing to STDERR:
- "Error" followed by
- an optional function name, followed by
- a call to perrno if errno was set, or
- if errno was not set, print an error message

Arguments:
- function (int, a #define): function where the error was found
- errno_value (int): the value we want to set errno to
- message (char *): the error message to print (can be a #define in some cases)

Return value: NULL in all cases */
void	*handle_error(char *function, int errno_value, char *message)
{
	errno = errno_value;

	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(function, STDERR_FILENO); // Print {Function name}

	if (errno) // perror call
		perror(message);
	else
	{
		if (message)
			ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}

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
