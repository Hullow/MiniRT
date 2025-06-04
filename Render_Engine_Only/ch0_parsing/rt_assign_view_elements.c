/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_assign_view_elements.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:06:53 by fallan            #+#    #+#             */
/*   Updated: 2025/06/02 18:18:55 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_assign_light(t_scene *scene, char **needle)
{
	char	**coord;
	char	**color;

	errno = 0;
	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
	scene->lux.intensity = ft_strtof(*(needle + 1));
	if (scene->lux.intensity > 1.0 || scene->lux.intensity < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong intensity value");
	}
	if (errno != 0 || !rt_valid_color(color) || !rt_valid_coord(coord))
	{
		ft_free_double_tab(coord, color);
		return ;
	}
	scene->lux.coord = rt_point(
			ft_strtof(*coord), ft_strtof(*(coord +1)), ft_strtof(*(coord +2)));
	scene->lux.color = rt_color(
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2)));
	ft_free_double_tab(coord, color);
}

void	rt_assign_ambient(t_scene *scene, char **needle)
{
	char	**color;

	errno = 0;
	color = ft_split(*(needle + 1), ',');
	scene->lux.ambient.intensity = ft_strtof(*(needle));
	if (scene->lux.ambient.intensity > 1.0 || scene->lux.ambient.intensity < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong intensity value");
	}
	if (!rt_valid_color(color) || errno != 0)
	{
		ft_free_tab(color);
		return ;
	}
	scene->lux.ambient.color = rt_color(
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2)));
	ft_free_tab(color);
}

t_matrix	rt_camera_transform(t_camera camera)
{
	t_tuple		vtrans;
	t_matrix	transf;

	vtrans = rt_vector(camera.coord.x, camera.coord.y, camera.coord.z);
	transf = rt_mul_matrix(rt_rotation(camera.orient), rt_translation(vtrans));
	return (transf);
}

void	rt_assign_camera(t_scene *scene, char **needle)
{
	char	**coord;
	char	**orient;

	errno = 0;
	coord = ft_split(*needle, ',');
	orient = ft_split(*(needle + 1), ',');
	scene->cam.field_of_view = ft_strtof(*(needle + 2)) * (M_PI / 180);
	if (ft_strtof(*(needle + 2)) > 180.0 || ft_strtof(*(needle + 2)) < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong field_of_view value");
	}
	if (!rt_valid_orient(orient) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_double_tab(coord, orient);
		return ;
	}
	scene->cam.orient = rt_vector(ft_strtof(*orient), ft_strtof(*(orient + 1)),
			ft_strtof(*(orient +2)));
	scene->cam.coord = rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)),
			ft_strtof(*(coord +2)));
	scene->cam.hsize = WINDOW_WIDTH;
	scene->cam.vsize = WINDOW_HEIGHT;
	ft_free_double_tab(coord, orient);
}
