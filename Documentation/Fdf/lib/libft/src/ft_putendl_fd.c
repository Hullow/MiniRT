/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:58:12 by francis           #+#    #+#             */
/*   Updated: 2023/12/01 18:33:13 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/* int	main()
{
	ft_putendl_fd("Hey Johnny", 0);
	ft_putendl_fd("Hey Johnny", 1);
	ft_putendl_fd("Hey Johnny", 2);
	ft_putendl_fd("Hey Johnny\n", 2);

	ft_putendl_fd("Hey Johnny", 3);
	return (0);
} */