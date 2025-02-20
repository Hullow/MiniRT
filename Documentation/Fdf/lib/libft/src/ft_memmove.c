/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:21:55 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:33:03 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_memmove(void *dst, const void *src, size_t len);
#include <string.h>
int main()
{
	char test1[] = "abcdefgh";
	printf("before memmove: src is '%s', dst is '%s'\n", test1 + 2, test1);
	memmove(test1, test1 + 2, 4);
	printf("after memmove: src is '%s' and dst is '%s'\n\n", test1 + 2, test1);

	char test2[] = "abcdefgh";
	printf("before ft_memmove: '%s', dst is '%s'\n", test2 + 2, test2);
	ft_memmove(test2, test2 + 2, 4);
	printf("after ft_memmove: src is '%s' and dst is '%s'\n", test2 + 2, test2);

	return (0);
} */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *) src;
	s2 = (char *) dst;
	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (s1 < s2)
		while (len-- > 0)
			s2[len] = s1[len];
	else
		while (i++ < len)
			s2[i - 1] = s1[i - 1];
	return (dst);
}
