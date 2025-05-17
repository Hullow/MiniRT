/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_assign_view_elements_check_with_pberset.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:06:53 by fallan            #+#    #+#             */
/*   Updated: 2025/05/17 18:14:24 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "miniRT.h"

void	rt_assign_light(t_scene *scene, char **needle)
{
	char	**coord;
	char	**color;

	errno = 0;
	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
	scene->lux.ratio = ft_strtof(*(needle + 1));
	if (scene->lux.ratio > 1.0 || scene->lux.ratio < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong ratio value");
	}
	if (errno != 0 || !rt_valid_color(color) || !rt_valid_coord(coord))
	{
		ft_free_tab(coord);
		ft_free_tab(color);
		return ;
	}
	scene->lux.coord = rt_point(
			ft_strtof(*coord), ft_strtof(*(coord +1)), ft_strtof(*(coord +2)));
	scene->lux.color = rt_color(
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2)));
	ft_free_tab(coord);
	ft_free_tab(color);
}

void	rt_assign_ambient(t_scene *scene, char **needle)
{
	char	**color;

	errno = 0;
	color = ft_split(*(needle + 1), ',');
	scene->amb.ratio = ft_strtof(*(needle));
	if (scene->amb.ratio > 1.0 || scene->amb.ratio < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong ratio value");
	}
	if (!rt_valid_color(color) || errno != 0)
	{
		ft_free_tab(color);
		return ;
	}
	scene->amb.color = rt_color(
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2)));
	ft_free_tab(color);
}

void	rt_assign_camera(t_scene *scene, char **needle)
{
	char	**coord;
	char	**orient;

	errno = 0;
	coord = ft_split(*needle, ',');
	orient = ft_split(*(needle + 1), ',');
	scene->cam.fov = ft_strtof(*(needle + 2));
	if (scene->cam.fov > 180.0 || scene->cam.fov < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong fov value");
	}
	if (!rt_valid_orient(orient) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_tab(coord);
		ft_free_tab(orient);
		return ;
	}
	scene->cam.orient = rt_vector(ft_strtof(*orient), ft_strtof(*(orient + 1)),
			ft_strtof(*(orient +2)));
	scene->cam.coord = rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)),
			ft_strtof(*(coord +2)));
	ft_free_tab(coord);
	ft_free_tab(orient);
}
*/