/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:39 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:32:53 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*string;
	unsigned char	character;

	string = (const char *) s;
	character = (unsigned char) c;
	while (n > 0)
	{
		if ((unsigned char) *string == character)
			return ((void *)string);
		else
		{
			string++;
			n--;
		}
	}
	return (NULL);
}

/*
#include <string.h>
 int	test(const void *s, int c, size_t n, int test_number)
{
	void	*p1;
	void	*p2;

	p1 = ft_memchr(s, c, n);
	p2 = memchr(s, c, n);

	if (p1 == p2)
		printf("test %d - same result: %p\
		 \n******************\n", test_number, p1);
	else
		printf("test %d - different result:\
		 ft_memchr returns '%p', memchr returns '%p'\
		  \n******************\n", test_number, p1, p2);
	return (0);
} */

/* int	main()
{
	// test("", 48, 0, 1);
	// test("", 48, 1, 2);
	// test("", 48, 2, 3);
	
	// test("0", 48, 0, 1);
	// test("0", 48, 1, 2);
	// test("0", 48, 2, 3);

	// test(" 0", 48, 0, 1);
	// test(" 0", 48, 1, 2);
	// test(" 0", 48, 2, 3);

	// test(" 00000", 48, 0, 1);
	// test(" 00000", 48, 1, 2);
	// test(" 00000", 48, 2, 3);
	
	// test("0    A", 41, 0, 1);
	// test("A0", 41, 1, 2);
	// test("AAAAAA", 41, 2, 3);

    int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
    printf("ft_memchr: %s\n", (char *)ft_memchr(tab, -49, 7));
    printf("memchr: %s\n", (char *)memchr(tab, -49, 7));

	int c = -49;
	unsigned char character = (unsigned char) c;
	printf("character is %d\n", character);
	return (0);
} */