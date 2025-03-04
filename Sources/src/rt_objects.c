/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:34:36 by pberset           #+#    #+#             */
/*   Updated: 2025/03/04 17:57:34 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

static int rt_valid_color(char **color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3 && color[i])
	{
		if (ft_atoi(color[i]) > 255 || ft_atoi(color[i]) < 0)
		{
			errno = ERANGE;
			perror("invalid color values");
			return (0);
		}
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]))
			{
				errno = EINVAL;
				perror("invalid color values");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i != 3 || color[i] != 0)
	{
		errno = EINVAL;
		perror("wrong number of color arguments");
		return (0);
	}
	return (1);
}

static int	rt_valid_coord(char **coord)
{
	int	i;

	i = 3;
	errno = 0;
	while (i > 0 && *coord)
	{
		ft_strtof(*coord);
		if (errno != 0)
		{
			perror(*coord);
			return (0);
		}
		i--;
		coord++;
	}
	if (i != 0 || *coord != 0)
	{
		errno = EINVAL;
		perror("wrong number of coordinate arguments");
		return (0);
	}
	return (1);
}

void	rt_assign_light(t_scene *scene, char **needle)
{
	char	**coord;
	char	**color;

	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
	if (!rt_valid_color(color) || !rt_valid_coord(coord))
	{
		ft_free_tab(coord);
		ft_free_tab(color);
		return ;
	}
	scene->lux->coord = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->lux->color = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->lux->coord->x = ft_strtof(*coord);
	scene->lux->coord->y = ft_strtof(*(coord + 1));
	scene->lux->coord->z = ft_strtof(*(coord + 2));
	scene->lux->ratio = ft_strtof(*(needle + 1));
	scene->lux->color->x = ft_atoi(*color) / 255.0;
	scene->lux->color->y = ft_atoi(*(color + 1)) / 255.0;
	scene->lux->color->z = ft_atoi(*(color + 2)) / 255.0;
	ft_free_tab(coord);
	ft_free_tab(color);
}

void	rt_assign_ambient(t_scene *scene, char **needle)
{
	(void)scene;
	(void)needle;
}

void	rt_assign_camera(t_scene *scene, char **needle)
{
	(void)scene;
	(void)needle;
}

void	rt_assign_sphere(t_scene *scene, char **needle)
{
	(void)scene;
	(void)needle;
}

void	rt_assign_plane(t_scene *scene, char **needle)
{
	(void)scene;
	(void)needle;
}

void	rt_assign_cylinder(t_scene *scene, char **needle)
{
	(void)scene;
	(void)needle;
}

