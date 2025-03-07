/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:31:54 by pberset           #+#    #+#             */
/*   Updated: 2025/03/07 11:47:29 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"
#include <stdio.h>

static int	valid_floatstr(const char *str)
{
	int	b_decimal;
	int	b_digit;

	b_decimal = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			b_digit = 1;
		else if (*str == '.')
		{
			if (b_decimal)
				return (0);
			b_decimal = 1;
		}
		else
			return (0);
		str++;
	}
	return (b_digit);
}

float	ft_strtof(const char *str)
{
	double	output;

	errno = 0;
	if (!valid_floatstr(str))
	{
		errno = EINVAL;
		perror(str);
	}
	output = ft_atof(str);
	if (isinf(output) || output > FLT_MAX || output < -FLT_MAX)
		errno = ERANGE;
	return (output);
}

