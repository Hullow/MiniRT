/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:28:11 by fallan            #+#    #+#             */
/*   Updated: 2024/04/04 14:41:07 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_print_hex(unsigned int decimal, char format_specifier)
{
	if (decimal < 16)
	{
		if (decimal <= 9)
		{
			decimal += 48;
			write(1, &decimal, 1);
		}
		else
		{
			if (format_specifier == 'X')
			{
				decimal += 55;
				write(1, &decimal, 1);
			}
			if (format_specifier == 'x')
			{
				decimal += 87;
				write(1, &decimal, 1);
			}
		}
		return (1);
	}
	else
		return (-1);
}

int	ft_hex(unsigned int number, char format_specifier)
{
	int	res;

	res = 0;
	if (number < 16)
		res += ft_print_hex(number, format_specifier);
	else
	{
		res += ft_hex(number / 16, format_specifier);
		res += ft_hex(number % 16, format_specifier);
	}
	return (res);
}
