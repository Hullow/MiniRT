/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:17:45 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:33:43 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t	strlcpy(char * dst, const char * src, size_t dstsize);
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char src[50] = "djdjdjd glou glou glou";
	char dst1[50];
	char dst2[50];

	size_t	result;
	size_t	dstsize = 0;

	result = strlcpy(dst1, src, dstsize);
	printf("strlcpy: dst is now %s\n,\
return value is %lu\n", dst1, result);

	result = ft_strlcpy(dst2, src, dstsize);
	printf("ft_strlcpy: dst is now %s,\
return value is %lu\n", dst2, result);

	return (0);
}

*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (ft_strlen(src));
}
