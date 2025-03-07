/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:34:36 by pberset           #+#    #+#             */
/*   Updated: 2025/03/07 11:45:05 by pberset          ###   Lausanne.ch       */
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

static int	rt_valid_orient(char **orient)
{
	int		i;
	float	ver;

	i = 3;
	errno = 0;
	while (i > 0 && *orient)
	{
		ver = ft_strtof(*orient);
		if (ver < -1.0 || ver > 1.0)
			errno = ERANGE;
		if (errno != 0)
		{
			perror(*orient);
			return (0);
		}
		i--;
		orient++;
	}
	if (i != 0 || *orient != 0)
	{
		errno = EINVAL;
		perror("wrong number of orientation arguments");
		return (0);
	}
	return (1);
}

void	rt_assign_light(t_scene *scene, char **needle)
{
	char	**coord;
	char	**color;

	errno = 0;
	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
	scene->lux->ratio = ft_strtof(*(needle + 1));
	if (scene->lux->ratio > 1.0 || scene->lux->ratio < 0.0)
	{
		errno = ERANGE;
		perror("wrong ratio value");
	}
	if (errno != 0 || !rt_valid_color(color) || !rt_valid_coord(coord))
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
	scene->lux->color->x = ft_atoi(*color) / 255.0;
	scene->lux->color->y = ft_atoi(*(color + 1)) / 255.0;
	scene->lux->color->z = ft_atoi(*(color + 2)) / 255.0;
	ft_free_tab(coord);
	ft_free_tab(color);
}

void	rt_assign_ambient(t_scene *scene, char **needle)
{
	char	**color;

	errno = 0;
	color = ft_split(*(needle + 1), ',');
	scene->amb->ratio = ft_strtof(*(needle));
	if (scene->amb->ratio > 1.0 || scene->amb->ratio < 0.0)
	{
		errno = ERANGE;
		perror("wrong ratio value");
	}
	if (!rt_valid_color(color) || errno != 0)
	{
		ft_free_tab(color);
		return ;
	}
	scene->amb->color = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->amb->color->x = ft_atoi(*color) / 255.0;
	scene->amb->color->y = ft_atoi(*(color + 1)) / 255.0;
	scene->amb->color->z = ft_atoi(*(color + 2)) / 255.0;
	ft_free_tab(color);
}

void	rt_assign_camera(t_scene *scene, char **needle)
{
	char	**coord;
	char	**orient;

	errno = 0;
	coord = ft_split(*needle, ',');
	orient = ft_split(*(needle + 1), ',');
	scene->cam->fov = ft_strtof(*(needle + 2));
	if (scene->cam->fov > 180.0 || scene->cam->fov < 0.0)
	{
		errno = ERANGE;
		perror("wrong fov value");
	}
	if (!rt_valid_orient(orient) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_tab(coord);
		ft_free_tab(orient);
		return ;
	}
	scene->cam->coord = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->cam->orient = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->cam->orient->x = ft_strtof(*orient);
	scene->cam->orient->y = ft_strtof(*(orient + 1));
	scene->cam->orient->z = ft_strtof(*(orient + 2));
	scene->cam->coord->x = ft_strtof(*coord);
	scene->cam->coord->y = ft_strtof(*(coord + 1));
	scene->cam->coord->z = ft_strtof(*(coord + 2));
	ft_free_tab(coord);
	ft_free_tab(orient);
}

void	rt_assign_sphere(t_scene *scene, char **needle)
{
	char	**coord;
	char	**color;

	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
	scene->sp->diameter = ft_strtof(*(needle + 1));
	if (!rt_valid_color(color) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_tab(coord);
		ft_free_tab(color);
		return ;
	}
	scene->sp->coord = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->sp->color = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->sp->coord->x = ft_strtof(*coord);
	scene->sp->coord->y = ft_strtof(*(coord + 1));
	scene->sp->coord->z = ft_strtof(*(coord + 2));
	scene->sp->color->x = ft_atoi(*color) / 255.0;
	scene->sp->color->y = ft_atoi(*(color + 1)) / 255.0;
	scene->sp->color->z = ft_atoi(*(color + 2)) / 255.0;
	ft_free_tab(coord);
	ft_free_tab(color);
}

void	rt_assign_plane(t_scene *scene, char **needle)
{
	char	**coord;
	char	**norm;
	char	**color;

	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle + 1), ',');
	color = ft_split(*(needle + 2), ',');
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord) || !rt_valid_color(color))
	{
		ft_free_tab(coord);
		ft_free_tab(norm);
		ft_free_tab(color);
		return ;
	}
	scene->pl->coord = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->pl->norm = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->pl->color = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->pl->norm->x = ft_strtof(*norm);
	scene->pl->norm->y = ft_strtof(*(norm + 1));
	scene->pl->norm->z = ft_strtof(*(norm + 2));
	scene->pl->coord->x = ft_strtof(*coord);
	scene->pl->coord->y = ft_strtof(*(coord + 1));
	scene->pl->coord->z = ft_strtof(*(coord + 2));
	scene->pl->color->x = ft_atoi(*color) / 255.0;
	scene->pl->color->y = ft_atoi(*(color + 1)) / 255.0;
	scene->pl->color->z = ft_atoi(*(color + 2)) / 255.0;
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}

void	rt_assign_cylinder(t_scene *scene, char **needle)
{
	char	**coord;
	char	**norm;
	char	**color;

	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle + 1), ',');
	color = ft_split(*(needle + 4), ',');
	scene->cy->diameter = ft_strtof(*(needle + 2));
	scene->cy->height = ft_strtof(*(needle + 3));
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord) || !rt_valid_color(color))
	{
		ft_free_tab(coord);
		ft_free_tab(norm);
		ft_free_tab(color);
		return ;
	}
	scene->cy->coord = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->cy->norm = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->cy->color = (t_tuple *)ft_calloc(1, sizeof(t_tuple));
	scene->cy->norm->x = ft_strtof(*norm);
	scene->cy->norm->y = ft_strtof(*(norm + 1));
	scene->cy->norm->z = ft_strtof(*(norm + 2));
	scene->cy->coord->x = ft_strtof(*coord);
	scene->cy->coord->y = ft_strtof(*(coord + 1));
	scene->cy->coord->z = ft_strtof(*(coord + 2));
	scene->cy->color->x = ft_atoi(*color) / 255.0;
	scene->cy->color->y = ft_atoi(*(color + 1)) / 255.0;
	scene->cy->color->z = ft_atoi(*(color + 2)) / 255.0;
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}

