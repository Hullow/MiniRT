/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:31:00 by pberset           #+#    #+#             */
/*   Updated: 2025/03/21 18:26:34 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Returns 1 if the file extension is wrong. Otherwise 0
int	rt_check_ext(const char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (ft_strncmp(&file[i - 3], ".rt", 3))
	{
		ft_puterr_fd("error: not a .rt file\n");
		return (1);
	}
	return (0);
}

// Extracts the values contained in .rt file for counting objects
// Returns 1 if file open failed. Otherwise 0
int	rt_read_id(const char *file, t_scene *scene)
{
	int		fd;
	int		n_err;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return (1);
	}
	n_err = 0;
	line = get_next_line(fd);
	while(line != NULL && *line != 0 && n_err == 0)
	{
		if (rt_count_object(line, scene))
			n_err = 1;
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	close(fd);
	return (n_err);
}

