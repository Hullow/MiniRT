/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:31:00 by pberset           #+#    #+#             */
/*   Updated: 2025/02/27 11:46:25 by pberset          ###   Lausanne.ch       */
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

static int	rt_check_line(char *line)
{
	int		found_id;
	char	*err_line;

	err_line = line;
	while (*line)
	{
		while (ft_isspace(*line) || *line == ' ')
			line++;
		if (!ft_isalnum(*line) && !ft_isspace(*line) && *line != ',' && *line != '-' && *line != '.')
		{
			ft_puterr_fd("error: invalid char found\n");
			ft_printf("%s -> %c\n", err_line, *line);
			return (1);
		}
		line++;
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
		if (rt_check_line(line))
			break ;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	return (0);
}

int	rt_check_scene(char *file)
{
	(void)file;
	return (0);
}
