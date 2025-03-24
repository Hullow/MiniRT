/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:27:24 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 14:18:59 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*output;

	output = (t_list *)ft_calloc(1, sizeof(t_list));
	if (errno)
	{
		perror("ft_lstnew output");
		return (NULL);
	}
	output->content = (void *)ft_calloc(1, sizeof(content));
	if (!output->content)
	{
		free(output);
		perror("ft_lstnew output->content");
		return (NULL);
	}
	ft_memcpy(output->content, content, sizeof(content));
	output->next = NULL;
	return (output);
}
