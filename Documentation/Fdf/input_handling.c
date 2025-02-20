/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:45 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 12:38:52 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// dimensions[2] is the toggle to stop counting when set to 1
t_list	*ft_file_to_list(int fd, char *arg)
{
	char	***split;
	int		*dimensions;

	dimensions = malloc(sizeof(int) * 3);
	if (!dimensions)
	{
		ft_printf("ft_file_to_list: malloc fail\n");
		return (NULL);
	}
	dimensions[0] = 0;
	dimensions[1] = 0;
	dimensions[2] = 1;
	dimensions = ft_find_dimensions(fd, dimensions);
	close(fd);
	fd = open(arg, O_RDONLY);
	split = ft_read_to_array(fd, dimensions);
	return (ft_fill_list(split, dimensions, -1, -1));
}

char	***ft_read_to_array(int fd, int *dimensions)
{
	char	***split;
	char	*line_read;
	int		i;

	split = (char ***)malloc(sizeof(char **) * dimensions[0]);
	line_read = NULL;
	i = -1;
	while (++i < dimensions[0])
	{
		line_read = ft_whitespace_to_space(get_next_line(fd));
		split[i] = ft_split(line_read, ' ');
		ft_free((void **)&line_read);
	}
	return (split);
}

// parses the input file to produce an array of integers
// the while() goes through all lines (dimensions[0])
// and splits the elements with ft_split
// the nested while() then goes through each of these elements,
// i.e. through #columns (== dimensions[1]), and creates a
// linked list of points which are filled by ft_fill_pt
t_list	*ft_fill_list(char ***split, int *dimensions, int i, int j)
{
	t_list	*node;
	t_list	*head;

	node = NULL;
	head = NULL;
	while (++i < dimensions[0])
	{
		while (++j < dimensions[1])
		{
			if (node)
			{
				node->next = ft_lstnew(ft_fill_pt(split[i], i, j, dimensions));
				node = node->next;
			}
			else
			{
				node = ft_lstnew(ft_fill_pt(split[i], i, j, dimensions));
				head = node;
			}
		}
		j = -1;
	}
	ft_free_array(split, dimensions);
	ft_free((void **)&dimensions);
	return (head);
}

/* creates a coordinate point with data:
point[0]: column, i.e. x
point[1]: line, i.e. y
point[2]: altitude, i.e. z
point[3]: #lines
point[4]: #columns
point[5]: color (if ',' is found in our split,
otherwise color is set to white/16777215) */
double	*ft_fill_pt(char **split, int i, int j, int *dimensions)
{
	double	*point;
	char	**color_input;

	color_input = NULL;
	point = (double *)malloc (6 * sizeof(double));
	point[0] = j;
	point[1] = i;
	point[2] = ft_atoi(split[j]);
	if (ft_strchr(split[j], ','))
	{
		color_input = ft_split(split[j], ',');
		point[2] = ft_atoi(color_input[0]);
		point[5] = ft_hex_string_to_int(color_input[1]);
		ft_free((void **)&color_input[0]);
		ft_free((void **)&color_input[1]);
		ft_free((void **)&color_input);
	}
	else
	{
		point[2] = ft_atoi(split[j]);
		point[5] = 0xFFFFFF;
	}	
	point[3] = dimensions[0];
	point[4] = dimensions[1];
	return (point);
}
