/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:22:27 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:37:56 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/* 
int main()
{
	t_list	*elem0 = (t_list *)malloc(sizeof(t_list));
	t_list	*elem1 = (t_list *)malloc(sizeof(t_list));
	t_list	*elem2 = (t_list *)malloc(sizeof(t_list));

	int	int1 = 1;
	int	int2 = 2;

	elem0->content = 0;
	elem0->next = elem1;

	elem1->content = &int1;
	elem1->next = elem2;

	elem2->content = &int2;
	elem2->next = NULL;
	
	t_list *result = ft_lstlast(elem2);

	printf("last element: %p\n", elem2);
	printf("ft_lstlast: %p\n", result);

	printf("last element value: %d\n", *((int *)(elem2->content)));
	printf("ft_lstlast value: %d\n", *((int *)(result->content)));
}
 */