/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:19 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:35:22 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// "tripouille", 100, 1) => ""

/*
#include <string.h>
int test(int test_number, char const *s,\
unsigned int start, size_t len)
{
	char *result = ft_substr(s, start, len);
	printf("Test %d: \"%s\"\n", test_number, result);
	if (!strcmp(s, ""))
		printf("OK\n");
	else
		printf("KO\n");
	if (result != NULL)
		free(result);
	return (0);
}

#include <stdio.h>
int	main()
{
	// char s[] = "Lorem ipsum dolor sit amet,\
	consectetur adipiscing elit."; // Lorem ipsum dolor \
	sit amet, consectetur adipiscing elit. Sed non risus.
	// unsigned int start = 0;
	// unsigned int start2 = 3;

	char s[] = "Tripouille";
	test(0, s, 100, 1);
	char *s2 = NULL;
	test(0, s2, 1, 1);
	// printf("start = 0:\n");
	// test(1, s, start, 0);
	// test(2, s, start, 1);
	// test(3, s, start, 3);
	// test(4, s, start, 4);
	// test(5, s, start, 5);
	// test(55, s, start, 55);
	// test(6, s, start, 56);
	// test(7, s, start, 57);
	// test(8, s, start, 57);
	// test(9, s, start, 1844674407370955161);

	// printf("\nstart = 3:\n");
	// test(1, s, start2, 0);
	// test(2, s, start2, 1);
	// test(3, s, start2, 3);
	// test(4, s, start2, 4);
	// test(5, s, start2, 5);
	// test(6, s, start2, 1844674407370955161);
	
	// printf("\nstart = 56:\n");
	// test(1, s, 56, 0);
	// test(2, s, 56, 1);
	// test(3, s, 56, 2);
	// test(3, s, 56, 3);
	// test(4, s, 56, 57);
	
	// printf("\nstart: >57\n");
	// test(2, s, 57, 1);
	// test(3, s, 58, 3);
	// test(4, s, 2576980377, 4);
	// test(5, s, -15, 5);
	// test(6, s, 2576980377, 1844674407370955161);
	return (0);
}
 */