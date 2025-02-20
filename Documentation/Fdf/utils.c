/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:34:13 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 15:30:13 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_array(char ***split, int *line_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (split)
	{
		while (i < line_data[0])
		{
			while (split[i][j])
			{
				ft_free((void **)&split[i][j]);
				j++;
			}
			ft_free((void **)&split[i]);
			i++;
			j = 0;
		}
		ft_free((void **)&split);
	}
}

void	ft_free_list(t_list *point_list)
{
	void	*node;
	void	*content;

	node = NULL;
	content = NULL;
	while (point_list)
	{
		node = point_list;
		content = point_list->content;
		point_list = point_list->next;
		ft_free((void **)&node);
		ft_free((void **)&content);
	}
}

// converts all whitespaces in the line
// read from the file to simple spaces
// enabling an easier split
char	*ft_whitespace_to_space(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		str[i] = ' ';
		i++;
	}
	return (str);
}

/* converts a hexadecimal string to an integer
with the corresponding decimal value */
int	ft_hex_string_to_int(char *hex_string)
{
	int	i;
	int	decimal_value;
	int	hex_factor;

	i = 0;
	decimal_value = 0;
	hex_factor = 1;
	while (hex_string[i + 1])
		i++;
	while (hex_string[i] != 'x' && hex_string[i] != 'X')
	{
		if (hex_string[i] >= 'A' && hex_string[i] <= 'F')
			decimal_value += (hex_string[i] - 55) * hex_factor;
		else if (hex_string[i] >= 'a' && hex_string[i] <= 'f')
			decimal_value += (hex_string[i] - 87) * hex_factor;
		else
			decimal_value += (hex_string[i] - 48) * hex_factor;
		hex_factor *= 16;
		i--;
	}
	return (decimal_value);
}
