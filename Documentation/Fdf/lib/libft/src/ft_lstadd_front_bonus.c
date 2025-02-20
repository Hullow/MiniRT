/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:58:36 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 16:09:39 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list; */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* int	main()
{
	t_list	root;
	root->x = 15;
	root->next = NULL;
	
	ft_lstadd_front(&root, &10);
	root = 
	printf("%d\n", (int) )
} */