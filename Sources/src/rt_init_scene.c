/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:18:10 by pberset           #+#    #+#             */
/*   Updated: 2025/02/28 17:24:50 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

static void	rt_spacify(char *line)
{
	while (*line)
    {
        if (ft_isspace(*line))
            *line = ' ';
        line++;
    }
}

int	rt_init_scene(const char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**splitted;

	(void)scene;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rt_spacify(line);
		splitted = ft_split(line, ' ');

		ft_free_tab(splitted);
		free(line);
	}
	close(fd);
	return (0);
}

