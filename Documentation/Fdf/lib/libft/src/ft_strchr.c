/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:22:03 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:33:27 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char) c)
			return (ptr);
		else
			ptr++;
	}
	if (*ptr == (char) c)
		return (ptr);
	else
		return (NULL);
}

/* #include <string.h>
int	test(int test_number, const char *s, int c)
{
	void	*ptr1;
	void	*ptr2;

	ptr1 = ft_strchr(s, c);
	ptr2 = strchr(s, c);

	if (ptr1 == ptr2)
		printf("test %d - same return value: %p\n", test_number, ptr1);
	else
		printf("test %d - not the same return\
		value: ptr1: %p, ptr2: %p\n", test_number, ptr1, ptr2);
	return (0);
}

int	main()
{

	// test(1, "", 0);
	// test(2, "a", 0);
	// test(3, "", 65);
	// test(4, "a", 65);
	// test(5, "", 97);
	// test(6, "a0", 48);
	// test(7, "teste", 'e');
	// test(8, "teste", '\0');
	test(9, "teste", 357);
	test(10, "teste", 1024);
	
	return (0);
} */