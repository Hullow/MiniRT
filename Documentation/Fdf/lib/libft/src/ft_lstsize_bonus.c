/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:13:16 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:32:48 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstsize;

	if (lst)
		lstsize = 1;
	else
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		lstsize++;
	}	
	return (lstsize);
}
