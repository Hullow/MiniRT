/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:31:00 by pberset           #+#    #+#             */
/*   Updated: 2025/02/20 19:17:10 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	rt_check_ext(char *file)
{
	int		fd;
	size_t	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return (1);
	}
	else
	{
		if (close(fd) == -1)
		{
			perror(file);
			return (2);
		}
	}
	i = ft_strlen(file);
	if (ft_strncmp(&file[i - 3], ".rt", 3))
	{
		ft_puterr_fd("error: not a .rt file\n");
		return (3);
	}
	return (0);
}

int	rt_check_scene(char *file)
{
	(void)file;
	return (0);
}
