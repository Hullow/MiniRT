/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:52:19 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:32:12 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}

/* 
int main()
{
	t_list	*elem0 = (t_list *)malloc(sizeof(t_list));
	t_list	*elem1 = (t_list *)malloc(sizeof(t_list));
	t_list	*elem2 = (t_list *)malloc(sizeof(t_list));
	t_list	*elem3 = (t_list *)malloc(sizeof(t_list));

	char arr0[] = "zero";
	char arr1[] = "one";
	char arr2[] = "two";
	char arr3[] = "three";

	elem0->content = arr0;
	elem0->next = elem1;

	elem1->content = arr1;
	elem1->next = elem2;

	elem2->content = arr2;
	elem2->next = elem3;

	elem3->content = arr3;
	elem3->next = NULL;
	
	t_list *result = ft_lstlast(elem0);

	printf("last element address: %p\n", result);
	printf("last element->content address' address: %p\n", &(result->content));
	printf("last element->content address: %p\n", result->content);
	printf("last element value: %s\n", ((char *)(result->content)));
		
	t_list	*elem4 = (t_list *)malloc(sizeof(t_list));
	char arrelem4[] = "four";
	elem4->content = arrelem4;
	elem4->next = NULL;
	ft_lstadd_back(&elem3, elem4);

	t_list *result2 = ft_lstlast(elem0);
	printf("*******\nafter lstadd_ back:\nlast element: %p\n", result2);
	printf("last element value: %s\n", ((char *)(result2->content)));

	ft_lstclear(&elem3, del);
	
	// t_list *result3 = ft_lstlast(elem0);
	
	printf("*******\nafter lstclear:\nlast element: %p\n", ft_lstlast(elem0));
	printf("last element value: %s\n", ((char *)(ft_lstlast(elem0)->content)));
	// printf("last element value: %s\n", ((char *)(result3->content)));

	// printf("elem2: %p\n", elem2);
	// printf("elem2 value: %s\n", ((char *)(elem2->content)));

	// printf("elem4: %p\n", elem4);
	// printf("elem4 value: %s\n", ((char *)(elem4->content)));
}
 */