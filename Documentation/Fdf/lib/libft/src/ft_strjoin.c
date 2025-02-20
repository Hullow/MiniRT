/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:22:41 by fallan            #+#    #+#             */
/*   Updated: 2024/02/12 14:52:46 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (str)
	{
		i = 0;
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[i - len1])
		{
			str[i] = s2[i - len1];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

/* #include <stdio.h>
int	main()
{
	char	s1[] = "Hello";
	char	s2[] = " moto";

	printf("ft_strjoin of '%s' and '%s' \
	yields '%s'\n", s1, s2, ft_strjoin(s1, s2));
	return (0);
} */