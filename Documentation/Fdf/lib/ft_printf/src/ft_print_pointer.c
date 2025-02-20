/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:28:25 by fallan            #+#    #+#             */
/*   Updated: 2024/04/04 14:41:13 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_ptr_write(unsigned long long decimal, char format_specifier)
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

static int	ft_ptr_base(unsigned long long number, char format_specifier)
{
	int	res;

	res = 0;
	if (number < 16)
		res += ft_ptr_write(number, format_specifier);
	else
	{
		res += ft_ptr_base(number / 16, format_specifier);
		res += ft_ptr_base(number % 16, format_specifier);
	}
	return (res);
}

int	ft_print_pointer(unsigned long long ptr)
{
	char	character;
	int		res;

	res = 0;
	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
	{
		res += write(1, "0x", 2);
		character = 'x';
		res += ft_ptr_base(ptr, character);
	}
	return (res);
}
