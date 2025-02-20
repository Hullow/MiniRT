/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:58:36 by fallan            #+#    #+#             */
/*   Updated: 2024/02/08 16:09:38 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list; */

/* t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode->content = *content;
	newnode->next = NULL;
	return (*content);
} */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(temp);
	temp->next = new;
}

/* void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;
	
	temp = *lst;
	if (!new)
		return ;
	if (!temp){
		temp = new;
		*lst = temp;
		return ;
	}
	temp = ft_lstlast(temp);
	(temp)->next = new;
	*lst = temp;
} */

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

	ft_lstadd_back(&elem2, add);
	t_list *result2 = ft_lstlast(elem2);
	printf("\nafter ft_lstadd_back: \
	ft_lstlast value: %s\n", ((char *)(result2->content)));
} */
