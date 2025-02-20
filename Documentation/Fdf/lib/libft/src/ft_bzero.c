/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:20:31 by fallan            #+#    #+#             */
/*   Updated: 2023/12/01 18:34:19 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

/* #include <strings.h>
#include <stdio.h>
int main ()
{
	char str[6] = "Blabla";

	// bzero(str, 3);
	// puts(str);
	// puts(str+3);

	ft_bzero(str, 3);
	puts(str);
	puts(str+3);

	return (0);
} */