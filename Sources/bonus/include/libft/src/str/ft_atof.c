/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:51:28 by pberset           #+#    #+#             */
/*   Updated: 2025/02/21 11:23:01 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static float	ft_decimal(const char *str)
{
	float	decimal;
	int		divisor;

	decimal = 0;
	divisor = 1;
	while (*str >= '0' && *str <= '9')
	{
		decimal = decimal * 10 + (*str - '0');
		divisor *= 10;
		str++;
	}
	return (decimal / divisor);
}

float	ft_atof(const char *str)
{
	float	output;
	int		sign;

	output = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign *= ft_sign(*str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		output += ft_decimal(str + 1);
	return (output * sign);
}
