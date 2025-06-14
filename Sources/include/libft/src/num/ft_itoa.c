/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:08:05 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 14:21:16 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static int	ft_digits_count(int nb)
{
	int	digits;

	digits = 1;
	while (nb > 9 || nb < -9)
	{
		nb /= 10;
		digits++;
	}
	return (digits);
}

static void	*err_msg(void)
{
	perror("ft_itoa");
	return (NULL);
}

char	*ft_itoa(int n)
{
	char		*output;
	int			digits_count;

	digits_count = ft_digits_count(n);
	if (n < 0)
		digits_count++;
	output = (char *)ft_calloc((digits_count + 1), sizeof(char));
	if (errno)
		return (err_msg());
	if (n < 0)
		output[0] = '-';
	output[digits_count] = '\0';
	if (n == 0)
		output[digits_count - 1] = 0 + '0';
	while (digits_count - 1 >= 0 && n)
	{
		if (n < 0)
			output[digits_count - 1] = -(n % 10) + '0';
		else
			output[digits_count - 1] = (n % 10) + '0';
		n /= 10;
		digits_count--;
	}
	return (output);
}
