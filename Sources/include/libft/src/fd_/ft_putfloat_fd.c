/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:20:18 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 15:20:19 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static int	fraction_to_int(double f)
{
	f = round(f * 1000000);
	if (f < 0)
		f = -f;
	return ((int)f);
}

static int	print_leading_zeros(int leading_zeros, int check, int fd)
{
	int	i;

	i = 0;
	while (i < leading_zeros)
	{
		check += write(fd, "0", 1);
		i++;
	}
	return (check);
}

int ft_putfloat_fd(double f, int fd)
{
	int		check;
	int		integer_part;
	double	fractional_part;
	int		fractional_int;
	int		leading_zeros;

	check = 0;
	if (f < 0)
	{
		check += write(fd, "-", 1);
		f = -f;
	}
	integer_part = (int)f;
	fractional_part = f - integer_part;
	check += ft_putnbr_fd(integer_part, fd);
	check += write(fd, ".", 1);
	fractional_int = fraction_to_int(fractional_part);
	leading_zeros = 6 - (int)(log10(fractional_int) + 1);
	check += print_leading_zeros(leading_zeros, check, fd);
	check += ft_putnbr_fd(fractional_int, fd);
	return (check);
}
