/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:52:38 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 14:24:50 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_max;

	s_max = ft_strlen(s);
	if (start + len > s_max && start < s_max)
		len = s_max - start;
	if (start >= s_max)
		len = 0;
	sub = (char *)ft_calloc((len + 1), sizeof(char));
	if (errno)
	{
		perror("substr");
		return (NULL);
	}
	i = 0;
	while (i < len && s[start + i] && start + i < s_max)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
