/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:44 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 16:08:35 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*string1;
	char	*string2;

	string1 = (char *) s1;
	string2 = (char *) s2;
	if (string1 == 0 && string2 == 0)
		return (0);
	while (n > 0)
	{
		if (*string1 == *string2)
		{
			string1++;
			string2++;
			n--;
		}
		else
			return ((unsigned char) *string1 - (unsigned char) *string2);
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char) *string1 - (unsigned char) *string2);
}

/* 
#include <string.h>
int	test(const void *s1, const void *s2, size_t n)
{
	int	result1 = ft_memcmp(s1, s2, n);
	int	result2 = memcmp(s1, s2, n);
	if (result1 == result2)
		printf("both functions return the same\
		 value: %d\n******************************\n", result1);
	else
		printf("the functions have different returns:\
		 ft_memcmp returns %d and memcmp returns %d\
		 .\n******************************\n", result1, result2);
	return (0);
}

int	main()
{
	// char s[] = {-128, 0, 127, 0};
	// char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, -42, 0};

	// test(s, sCpy, 4); 
	// test(s, s2, 0);
	// test(s, s2, 1);
	// test(s2, s, 1); 
	test(s2, s3, 4);
	return (0);
}
 */