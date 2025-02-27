/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:31:00 by pberset           #+#    #+#             */
/*   Updated: 2025/02/27 15:30:03 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	rt_check_ext(char *file)
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

int	rt_extract_scene(char *file, t_scene *scene)
{
	int		fd;
	char	*line;

	(void)scene;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return (1);
	}
	line = get_next_line(fd);
	while(line != NULL && *line != 0)
	{
		rt_unique_object(line, scene);
		rt_multiple_objects(line, scene);
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}

