/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:00:24 by fallan            #+#    #+#             */
/*   Updated: 2024/04/02 14:20:02 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
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

	printf("last element: %p\n", elem3);
	printf("ft_lstlast: %p\n", result);

	printf("last element value: %s\n", ((char *)(elem3->content)));
	printf("ft_lstlast value: %s\n", ((char *)(result->content)));

	t_list	*add = (t_list *)malloc(sizeof(t_list));
	
	char arradd[] = "four";
	add->content = arradd;
	add->next = NULL;

	ft_lstadd_back(&elem3, add);
	t_list *result2 = ft_lstlast(elem0);
	printf("\nafter ft_lstadd_back: \
	ft_lstlast value: %s\n", ((char *)(result2->content)));

	ft_lstdelone(result2, &del);
	printf("last element after lstdelone: %p\n", result2);
	
}
long long add(int a, int b)
{
	return a+b;
}

long long mul(int a, int b)
{
	return a*b;
}

void exec(long long	(*fun)(int, int))
{
	printf("%lld\n", fun(5, 7));
	
}

*/