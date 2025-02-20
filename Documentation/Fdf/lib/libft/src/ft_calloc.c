/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:20:12 by fallan            #+#    #+#             */
/*   Updated: 2024/04/02 14:25:59 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	total_size;
	unsigned char	*filler;

	total_size = (unsigned int)count * (unsigned int)size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	filler = (unsigned char *) ptr;
	while (total_size > 0)
	{
		*filler = '\0';
		filler++;
		total_size--;
	}
	return (ptr);
}

/* #include <string.h>
int	test(int number, int count, int size)
{
	void	*ptr1 = ft_calloc(count, size);
	void	*ptr2 = calloc(count, size);
	
	ft_memset(ptr1, 65, count);
	ft_memset(ptr2, 65, count);
	
	if (memcmp(ptr1, ptr1, (size_t)count) == 0)
		printf("test %d OK: \nft_calloc: %s at address\
		 %p\ncalloc: %s at address %p\n", number, ptr1, ptr1, ptr2, ptr2);
	else
		printf("test %d KO: ft_calloc: %p, calloc %p\n", number, ptr1, ptr2);
	return (0);
}

int	main()
{
	test(0, 3, 4);
	test(1, 0, 4);
	test(2, 4, 0);
	test(3, 0, 0);
	return (0);
} */