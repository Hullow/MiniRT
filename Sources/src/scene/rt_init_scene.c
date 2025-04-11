/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:18:10 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 15:32:11 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	rt_spacify(char *line)
{
	while (*line)
    {
        if (ft_isspace(*line))
            *line = ' ';
        line++;
    }
}

static void	rt_assign_values(t_scene *scene, char **values)
{
	char	**needle;
	int		i;

	i = 0;
	while (values[i])
	{
		needle = values + 1;
		if (**values == 'L')
			rt_assign_light(scene, needle);
		else if (**values == 'A')
			rt_assign_ambient(scene, needle);
		else if (**values == 'C')
			rt_assign_camera(scene, needle);
		else
			rt_assign_object(&(scene->objects[i]), needle, **values);
		i++;
	}
}

// Reads file to assign values in scene
int	rt_init_scene(const char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**splitted;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		handle_error("rt_init_scene", errno, (char *)file);
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rt_spacify(line);
		splitted = ft_split(line, ' ');
		rt_assign_values(scene, splitted);
		ft_free_tab(splitted);
		free(line);
		if (errno)
		{
			close(fd);
			return (2);
		}
	}
	close(fd);
	return (0);
}

