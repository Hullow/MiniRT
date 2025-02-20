/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:28:40 by fallan            #+#    #+#             */
/*   Updated: 2024/04/04 14:41:23 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n, int res)
{
	if (n == 2147483648)
		return (write(1, "2147483648", 10));
	else
	{
		if (n < 0)
		{
			n *= (-1);
			res += write(1, "-", 1);
		}
		if (n >= 0 && n <= 9)
		{
			n += 48;
			write(1, &n, 1);
			n -= 48;
			res++;
		}
		if (n > 9)
		{
			res = ft_putnbr_unsigned(n / 10, res);
			res = ft_putnbr_unsigned(n % 10, res);
		}
	}
	return (res);
}
