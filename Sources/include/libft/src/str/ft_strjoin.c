/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:32:00 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 14:26:01 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static void	*err_msg()
{
	perror("ft_strjoin");
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	size;
	char	*start;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)ft_calloc((size + 1), sizeof(char));
	if (errno)
		return (err_msg());
	start = join;
	while (s1 && *s1)
	{
		*join = (unsigned char)*s1;
		join++;
		s1++;
	}
	while (s2 && *s2)
	{
		*join = (unsigned char)*s2;
		join++;
		s2++;
	}
	*join = '\0';
	return (start);
}
