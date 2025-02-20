/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:06:06 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:32:37 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*elem;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst)
	{
		content = f(lst->content);
		elem = ft_lstnew(content);
		if (!elem)
		{
			del(content);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, elem);
		lst = lst->next;
	}
	return (map);
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

	// t_list *result = ft_lstlast(elem0);

	// printf("elem3 element address: %p\n", elem3);
	// printf("elem3 content: %s\n", ((char *)(elem3->content)));
	// printf("last element address: %p\n", result);
	// printf("last element content: %s\n", ((char *)(result->content)));

	t_list *map = ft_lstmap(elem0, &ft_modifyfirstchar);
	printf("map 1st element address: %p\n", map);
	printf("map 1st element content: %s\n", map->content);

	t_list *resultmap = ft_lstlast(map);
	printf("map last element address: %p\n", resultmap);
	printf("map last element content: %s\n", resultmap->content);

	// t_list	*add = (t_list *)malloc(sizeof(t_list));
	
	// char arradd[] = "four";
	// add->content = arradd;
	// add->next = NULL;

	// ft_lstadd_back(&elem2, add);
	// t_list *result2 = ft_lstlast(elem2);
	// printf("\nafter ft_lstadd_back: \
	ft_lstlast value: %s\n", ((char *)(result2->content)));
}
 */