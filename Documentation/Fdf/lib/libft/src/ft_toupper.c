/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:37 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:35:28 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

/* 
#include <ctype.h>
int	test(int test_number, int c)
{
	if (ft_toupper(c) == toupper(c))
		printf("Test %d OK.\n", test_number);
	else
		printf("Test %d failed. ft_toupper: %c,\
		toupper: %c\n", test_number, ft_toupper(c), toupper(c));
	return (0);
} */

/* #include <stdio.h>
#include <ctype.h>
int	main(void)
{
	test(0, 'A');
	test(1, 'a');
	test(2, 'b');
	test(3, 'c');
	test(4, 'y');
	
	return (0);
} */
