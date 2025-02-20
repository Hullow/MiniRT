/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:58:09 by francis           #+#    #+#             */
/*   Updated: 2023/12/01 18:33:17 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_putnbr_fd(int n, int fd);

/* int	test(int n, int fd)
{
	write(fd, "test : ", 8);
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);
	return (0);
}

int	main()
{
	// test(56, 1);
	// test(2147483646, 1);
	// test(2147483647, 1);
	// // test(2147483648, 1);
	// test(564584, 1);
	// test(0, 1);
	// test(-56, 1);
	// test(-2147483647, 1);
	// test(-2147483648, 1);
	return (0);
} */

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= (-1);
			write(fd, "-", 1);
		}
		if (n >= 0 && n <= 9)
		{
		n += 48;
			write(fd, &n, 1);
		n -= 48;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
