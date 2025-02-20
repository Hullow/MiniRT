/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:23:50 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:33:53 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	else if (*s1 > 0 && *s2 == 0)
		return ((unsigned char) *s1 - (unsigned char) *s2);
	else if (*s1 == 0 && *s2 > 0)
		return ((unsigned char) *s1 - (unsigned char) *s2);
	else
	{
		while (n > 0 && *s1 && *s2)
		{
			if (*s1 == *s2)
				n--;
			else if (*s1 > *s2)
				return ((unsigned char) *s1 - (unsigned char) *s2);
			else if (*s1 < *s2)
				return ((unsigned char) *s1 - (unsigned char) *s2);
			if (n != 0)
			{
				s1++;
				s2++;
			}
		}
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

/* #include <string.h>
int	test(const char *s1, const char *s2, size_t n)
{
	char	*string1;
	char	*string2;
	int result;
	int benchmark;

	string1 = (char *) s1;
	string2 = (char *) s2;

	result = ft_strncmp(string1, string2, n);
	benchmark = strncmp(string1, string2, n);

	if (result == benchmark)
		printf("return value is the same as strncmp\n");
	else
		printf("ft_strncmp's return value %d\
		is not the same as strncmp: %d\n", result, benchmark);
	return (0);
}

int main(void)
{
	test("1234", "1235", 3);
	test("abcdefgh", "abcdwxyz", 4);
	return(0);
} */