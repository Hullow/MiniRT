/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:27:24 by pberset           #+#    #+#             */
/*   Updated: 2025/05/01 15:58:27 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"


t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/* 
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
	printf("ft_lstnew: sizeof(content): %ld\n", sizeof(content));
	output->next = NULL;
	return (output);
}


 */