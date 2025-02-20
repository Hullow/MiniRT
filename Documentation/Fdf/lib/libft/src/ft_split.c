/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:25:56 by tkashi            #+#    #+#             */
/*   Updated: 2024/05/06 17:22:49 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calc_size(char const *s, char c)
{
	int	prev;
	int	i;
	int	count;

	prev = -1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (i - prev - 1 > 0)
				count++;
			prev = i;
		}
		i++;
	}
	if (i - prev - 1 > 0)
		count++;
	return (count);
}

int	ft_add_splitted(char const *s, int start, int end, char **ret)
{
	*ret = ft_substr(s, start + 1, end - start - 1);
	if (*ret == NULL)
		return (0);
	return (1);
}

int	ft_apply_split(char const *s, char c, char **ret)
{
	int	prev;
	int	i;

	prev = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (i - prev - 1 > 0)
			{
				if (!ft_add_splitted(s, prev, i, ret))
					return (0);
				ret++;
			}
			prev = i;
		}
		i++;
	}
	if (i - prev - 1 > 0)
	{
		if (!ft_add_splitted(s, prev, i, ret))
			return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	size;
	int		i;

	size = ft_calc_size(s, c);
	ret = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	if (!ft_apply_split(s, c, ret))
	{
		i = 0;
		while (ret[i] != NULL)
		{
			free(ret[i]);
			i++;
		}
		free(ret);
		return (NULL);
	}
	return (ret);
}
