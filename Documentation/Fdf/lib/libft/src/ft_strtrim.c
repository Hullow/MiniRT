/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:24:12 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:35:20 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_findstart(char const *s1, char const *set);
static unsigned int	ft_findstop(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ts1;
	unsigned int	start;
	unsigned int	stop;

	if (!s1)
		return (NULL);
	start = ft_findstart(s1, set);
	stop = ft_findstop(s1, set);
	if (start > stop)
		stop = start;
	ts1 = (char *)ft_calloc(stop - start + 1, sizeof(char));
	if (ts1 == NULL)
		return (NULL);
	ft_strlcpy(ts1, &s1[start], stop - start + 1);
	return (ts1);
}

static unsigned int	ft_findstart(char const *s1, char const *set)
{
	unsigned int	j;
	unsigned int	start;

	j = 0;
	start = 0;
	while (s1[start] && set[j])
	{
		if (s1[start] == set[j])
		{
			start++;
			j = 0;
		}
		else
			j++;
	}
	return (start);
}

static unsigned int	ft_findstop(char const *s1, char const *set)
{
	unsigned int	j;
	unsigned int	stop;

	j = 0;
	stop = ft_strlen(s1);
	while (stop > 0 && set[j])
	{
		if (s1[stop - 1] == set[j])
		{
			stop--;
			j = 0;
		}
		else
			j++;
	}
	return (stop);
}

/* int	test(int test_number,\
 char const *s1, char const *set)
{
	char	*trim;

	trim = ft_strtrim(s1, set);
	printf("Test #%d: ft_strtrim\
	(\"%s\", \"%s\") = \"%s\"\n", test_number, s1, set, trim);
	free(trim);
	return (0);
} */

/* #include <stdlib.h>
#include <string.h>
int	main()
{
	
    // char *s2 = NULL;
	// strlcpy(s2, "hello!", 8);
	
	// char *c2 = NULL;
	// strlcpy(c2, " ", 4);
	// test(2, s2, c2);
	
    char *s = ft_calloc(7, sizeof(char));
	char *c	= ft_calloc(2, sizeof(char));
	
	strlcpy(s, "hello!", 7);
	strlcpy(c, " ", 2);

	test(1, s, c);
	
	return (0);
} */
