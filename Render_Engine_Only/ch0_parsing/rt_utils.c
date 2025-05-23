/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:13:54 by fallan            #+#    #+#             */
/*   Updated: 2025/05/23 10:07:38 by fallan         ########   odam.nl        */
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
void	*rt_handle_error(char *function, int errno_value, char *message)
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

/* Converts a tuple with RGB values ranging from 0 to 1
(e.g. (0.34, 0.12, 0.56)) to the corresponding int value, which it returns */
int	rgb_to_int(t_tuple col_tuple)
{
	int	color;
	int	hex_r;
	int	hex_g;
	int	hex_b;

	color = 0;
	hex_r = (int) (col_tuple.x * 255);
	hex_g = (int) (col_tuple.y * 255);
	hex_b = (int) (col_tuple.z * 255);
	color += (hex_r / 16) * pow(16, 5) + (hex_r % 16) * pow(16, 4);
	color += (hex_g / 16) * pow(16, 3) + (hex_g % 16) * pow(16, 2);
	color += (hex_b / 16) * 16 + (hex_b % 16);
	return (color);
}
