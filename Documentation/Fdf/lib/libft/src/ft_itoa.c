/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:18:52 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:34:36 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	digits;

	digits = 0;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}	

static char	*ft_int_min(char	*str)
{
	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*ft_edge_cases(int n)
{
	char	*str;

	str = NULL;
	if (n == 0)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	if (n == -2147483648)
		str = ft_int_min(str);
	return (str);
}

static int	ft_negative(int n)
{
	int	negative;

	if (n < 0)
		negative = 1;
	else
		negative = 0;
	return (negative);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		negative;

	if (n == 0 || n == -2147483648)
		return (ft_edge_cases(n));
	negative = ft_negative(n);
	if (n < 0)
		n *= -1;
	digits = ft_count_digits(n);
	str = (char *)ft_calloc(digits + negative + 1, sizeof(char));
	if (!str)
		return (NULL);
	digits--;
	while (digits >= 0)
	{
		str[digits + negative] = (n % 10) + 48;
		n /= 10;
		digits--;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}

/* int test(int test_number, int n)
{
	
	printf("test %d: \n: ft_putnbr_fd", test_number);
	ft_putnbr_fd(n, 1);
	printf("\n%s: ft_itoa\n\n", ft_itoa(n));
	
	return (0);
}

int main()
{
	// test(1, 0);
	// test(2, 1);
	// test(3, 5);
	// test(4, 10);
	// test(5, 100);
	// test(6, 2147483647);
	// test(7, -1);
	// test(8, -10);
	// test(9, -2147483647);
	test(10, -2147483648);
	test(11, -2147483647 -1);
	return (0);
} */