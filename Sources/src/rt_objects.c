/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:34:36 by pberset           #+#    #+#             */
/*   Updated: 2025/02/28 20:40:47 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

void	rt_assign_light(t_scene *scene, char **needle)
{
	char	**coord;
	float	ratio;
	char	**color;

	coord = ft_split(*needle, ',');
	ratio = ft_atof(*(needle + 1));
	color = ft_split(*(needle + 2), ',');
	scene->coord.x = ft_atof(*coord);
	scene->coord.y = ft_atof(*(coord + 1));
	scene->coord.z = ft_atof(*(coord + 2));
	scene->ratio = ratio;
	scene->color.x = ft_atof(*color);
	scene->color.y = ft_atof(*(color + 1));
	scene->color.z = ft_atof(*(color + 2));
}

void	rt_assign_ambient(t_scene *scene, char **needle)
{}

void	rt_assign_camera(t_scene *scene, char **needle)
{}

void	rt_assign_plane(t_scene *scene, char **needle)
{}

void	rt_assign_cylinder(t_scene *scene, char **needle)
{}

