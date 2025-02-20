/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:05:24 by francis           #+#    #+#             */
/*   Updated: 2023/12/01 18:35:25 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

/* #include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	character;

	character = 'B';

	printf("The return value of tolower is %c\n", ft_tolower(character));
	printf("The return value of ft_tolower is %c\n", ft_tolower(character));
	printf("The variable character is now equal to: %c\n", character);
		return (0);
} */