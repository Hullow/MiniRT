/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:16:18 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 15:29:16 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// These functions are used to examine the input,
// including finding its dimensions and checking
// its regularity, as well as converting types
// (hexadecimal string to int for the color)

// while dimensions[2]: if set to 0, we've read an empty line => stop
// dimensions[1] != columns: irregular map handling
int	*ft_find_dimensions(int fd, int *dimensions)
{
	char	*line_read;
	int		columns;

	line_read = NULL;
	dimensions = ft_examine_line(fd, line_read, dimensions);
	if (!dimensions[2])
	{
		ft_printf("no line found\n");
		ft_free((void **)&dimensions);
		exit(1);
	}
	columns = dimensions[1];
	while (dimensions[2])
	{
		dimensions = ft_examine_line(fd, line_read, dimensions);
		if (dimensions[1] != columns)
		{
			ft_printf("irregular map, aborting\n");
			ft_free((void **)&dimensions);
			exit(1);
		}
	}
	return (dimensions);
}

/* counts the number of lines (dimensions[0]) from our 
file descriptor (array of characters) and calls ft_count_columns 
to count the number of columns (dimensions[1]) */
int	*ft_examine_line(int fd, char *line_read, int *dimensions)
{
	line_read = get_next_line(fd);
	if (line_read)
	{
		dimensions[0]++;
		line_read = ft_whitespace_to_space(line_read);
		dimensions[1] = ft_count_columns(line_read);
	}
	else
		dimensions[2] = 0;
	ft_free((void **)&line_read);
	return (dimensions);
}

int	ft_count_columns(char *line)
{
	int	i;
	int	columns;

	columns = 0;
	if (!line)
		return (-1);
	i = 0;
	columns = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
		{
			columns++;
			while (line[i] != ' ' && line[i])
				i++;
		}
	}
	return (columns);
}

int	ft_count_array_elements(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
