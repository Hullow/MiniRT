/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:23:56 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:35:12 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*anchor;
	unsigned int	start;
	unsigned int	i;

	anchor = (char *) haystack;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	start = 0;
	i = 0;
	while (haystack[start + i] && needle[i] && len > 0)
	{
		if (needle[i] == haystack[start + i])
			i++;
		else
		{
			len += i;
			i = 0;
			start++;
		}
		len--;
	}
	if (needle[i] == '\0')
		return (anchor + start);
	else
		return (NULL);
}

// 	test(6, "abcabcd", "abcd", 7);

/* #include <string.h>
#include <stdio.h>
int	test(int test_number, \
 char *haystack, const char *needle, size_t len)
{
	char *result1 = ft_strnstr(haystack, needle, len);
	char *result2 = strnstr(haystack, needle, len);

	if (result1 == result2)
		printf("test %d: same return '%s'\n", test_number, result2);
	else
		printf("test %d: strnstr returns '%s', \
		returns '%s'\n", test_number, result2, result1);
	return (0);
}

int	main()
{
	// test(1, "eeeabc", "abc", 7);
	// test(2, "eeeabcffff", "abc", 7);
	// test(3, "eeeabc", "abc", 7);
	// test(4, "eeeabcfff", "abc", 7);
	// test(5, "eeeabcfff", "abc", 7);
	test(6, "abcabcd", "abcd", 7);
	
	return (0);
}
 */