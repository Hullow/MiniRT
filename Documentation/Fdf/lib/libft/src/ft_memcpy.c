/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:47 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:32:59 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) src;
	s2 = (unsigned char *) dst;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (dst);
}

/* #include <string.h>
#include <stdio.h>

int	main()
{
	char src[] = "Hello my name is Francis";
	char dst[50];

	strcpy(dst, "Goodbye");
	puts("dst before memcpy:");
	puts(dst);
 
 	memcpy(dst, src, sizeof(src)+1); // "returns the original value of dst"
	puts("\ndst after memcpy:");
	puts(dst);

	strcpy(dst, "Goodbye");
	puts("\ndst re-initialized before ft_memcpy:");
	puts(dst);

 	ft_memcpy(dst, src, sizeof(src)+1); // "returns the original value of dst"
	puts("\ndst after ft_memcpy:");
	puts(dst);

	return (0);
} */