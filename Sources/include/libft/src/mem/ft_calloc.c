/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:49:03 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 14:35:01 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	errno = 0;
	ptr = malloc(count * size);
	if (!ptr)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ptr = ft_memset(ptr, 0, count * size);
	return (ptr);
}
