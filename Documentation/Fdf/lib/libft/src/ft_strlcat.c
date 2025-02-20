/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:07:37 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:33:39 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	if (srclen + dstlen < dstsize)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		while (i < dstsize - dstlen - 1)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
	}
	return (dstlen + srclen);
}

/* #include <string.h>
int main()
{
    // char src[] =  "abcd"; // srclen == 4
    // char src2[] = "abcd";

    // char dst[] =  "mnopqrstuvwxyz"; // dstlen == 14
    // char dst2[] = "mnopqrstuvwxyz";
    char dst3[10] = "a";
    char dst4[10] = "a";

    // size_t dstsize = 13;
    // printf("for src '%s' and dst '%s', \
	with dstsize = %lu,\n", src, dst, dstsize);
    // printf("strlcat yields '%s' with return value\
	 '%lu'\n", dst, strlcat(dst, src, dstsize));
    // printf("strlen(dst) is %lu\n\n", strlen(dst));

    // printf("for src '%s' and dst '%s', with \
	dstsize = %lu,\n", src2, dst2, dstsize);
    // printf("ft_strlcat yields '%s' with return\
	 value '%lu'\n", dst2, ft_strlcat(dst2, src2, dstsize));
    // printf("strlen(dst) is %lu\n", strlen(dst2));

    printf("strlcat yields '%s' with return value\
	 '%lu'\n", dst3, strlcat(dst3, "lorem ipsum dolor sit amet", 0));
	printf("ft_strlcat yields '%s' with return value\
	 '%lu'\n\n", dst4, ft_strlcat(dst4, "lorem ipsum dolor sit amet", 0));

    // printf("strlcat yields '%s' with return value\
	 '%lu'\n", dst3, strlcat(dst3, "lorem ipsum", 1));
	// printf("ft_strlcat yields '%s' with return value\
	 '%lu'\n\n", dst3, ft_strlcat(dst3, "lorem ipsum", 1));

    // printf("strlcat yields '%s' with return value\
	 '%lu'\n", dst3, strlcat(dst3, "lorem ipsum", 5));
	// printf("ft_strlcat yields '%s' with return value\
	 '%lu'\n", dst3, ft_strlcat(dst3, "lorem ipsum", 5));
	  return (0);
} */