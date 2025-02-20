/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:22:38 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:33:30 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>
#include <string.h>
int	test_dup(char *string1, int test_number)
{
	char	*s1 = NULL;
	char	*s2 = NULL;

	s1 = ft_strdup(string1);
	s2 = strdup(string1);
	
	if (strcmp(s1,s2) == 0)
	{
		printf("test %d: s1 is '%s', s2 is '%s'\n", test_number, s1, s2);
		printf("result: same\n******************\n");	
	}
	else
	{		
		printf("test %d: s1 is '%s', s2 is '%s'\n", test_number, s1, s2);
		printf("result: not the same\n******************\n");
	}
	free(s1);
	free(s2);
	return (0);
}

int	main()
{
	test_dup("", 1);
	test_dup("blablabla", 2);
	test_dup("   ", 3);
	
	return (0);
} */