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
	scene->lux.intensity = ft_strtof(*(needle + 1));
	if (scene->lux.intensity > 1.0 || scene->lux.intensity < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong intensity value");
		return ;
	}
	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
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
	scene->n_l++;
}

void	rt_assign_ambient(t_scene *scene, char **needle)
{
	char	**color;

	errno = 0;
	scene->lux.ambient.ratio = ft_strtof(*(needle));
	if (scene->lux.ambient.ratio > 1.0 || scene->lux.ambient.ratio < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong intensity value");
		return ;
	}
	color = ft_split(*(needle + 1), ',');
	if (!color)
	{
		rt_handle_error("RT_ASSIGN_AMBIENT", ENOMEM, "ft_split failed");
		return ;
	}
	if (!rt_valid_color(color) || errno != 0)
	{
		ft_free_tab(color);
		return ;
	}
	scene->lux.ambient.color = rt_color(\
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2)));
	ft_free_tab(color);
	scene->n_a++;
}

void	rt_assign_camera(t_scene *scene, char **needle)
{
	char	**coord;
	char	**orient;

	errno = 0;
	scene->cam.field_of_view = ft_strtof(*(needle + 2)) * (M_PI / 180);
	if (scene->cam.field_of_view > 180.0 || scene->cam.field_of_view < 0.0)
	{
		rt_handle_error("Assign_Camera", ERANGE, "Field of view out of range");
		return ;
	}
	coord = ft_split(*needle, ',');
	orient = ft_split(*(needle + 1), ',');
	if (!rt_valid_orient(orient) || !rt_valid_coord(coord))
	{
		errno = ERANGE;
		perror("Error\nwrong tuple value");
		ft_free_double_tab(coord, orient);
		return ;
	}
	scene->cam = rt_calc_camera_vals(scene->cam, \
		rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)), \
			ft_strtof(*(coord +2))), rt_vector(ft_strtof(*orient), \
				ft_strtof(*(orient + 1)), ft_strtof(*(orient +2))));
	ft_free_double_tab(coord, orient);
	scene->n_cam++;
}
