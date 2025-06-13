/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:57:32 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 14:27:38 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static int	ft_setcmp(char c, char const *c_set)
{
	int	i;

	i = 0;
	while (c_set[i])
	{
		if (c_set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	*err_msg(void)
{
	perror("ft_strjoin");
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	size_t	start;
	size_t	end;
	int		i;

	start = 0;
	while (s1[start] && ft_setcmp(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_setcmp(s1[end - 1], set))
		end--;
	i = 0;
	output = (char *)ft_calloc((end - start + 1), sizeof(char));
	if (errno)
		return (err_msg());
	while (start < end)
	{
		output[i] = s1[start];
		i++;
		start++;
	}
	output[i] = '\0';
	return (output);
}
