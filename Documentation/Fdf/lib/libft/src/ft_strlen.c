/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:23:46 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:33:46 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

/* #include <stdlib.h>
#include <string.h>
int main()
{
	char *str = "abbcddk";

	printf("str[strlen(str)] is '%c'\n", str[strlen(str) - 1]);
	printf("str[ft_strlen(str)] is '%c'\n", str[ft_strlen(str) - 1]);
	return (0);
} */