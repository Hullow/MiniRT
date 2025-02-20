/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:55:51 by francis           #+#    #+#             */
/*   Updated: 2023/12/01 18:33:07 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *) b;
	while (len > 0)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}

/* #include <string.h>
#include <stdio.h>
int	main()
{
	char	str[50];
	int c = 100;

	strcpy(str, "This is a string to be copied.");
	puts(str);

	ft_memset(str, c, 4);
	puts(str);

	strcpy(str, "This is a string to be copied.");
	puts(str);

	memset(str, c, 4);
	puts(str);

	return (0);
} */