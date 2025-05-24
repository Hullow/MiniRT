/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_assign_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:34:36 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_assign_sphere(t_object *sphere, char **needle)
{
	char	**coord;
	char	**color;

	coord = ft_split(*needle, ',');
	color = ft_split(*(needle +2), ',');
	if (!rt_valid_color(color) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_tab(coord);
		ft_free_tab(color);
		return ;
	}
	sphere->diameter = ft_strtof(*(needle +1));
	sphere->origin = rt_point( \
		ft_strtof(*coord), ft_strtof(*(coord +1)), ft_strtof(*(coord +2)));
	sphere->shape = SPHERE;
	sphere->transform = rt_set_transform(*sphere);
	*sphere = rt_sphere(rt_color( \
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2))));
	ft_free_tab(coord);
	ft_free_tab(color);
}

void	rt_assign_plane(t_object *plane, char **needle)
{
	char	**coord;
	char	**norm;
	char	**color;

	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle +1), ',');
	color = ft_split(*(needle +2), ',');
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord) \
		|| !rt_valid_color(color))
		return (ft_free_tab(coord), ft_free_tab(norm), ft_free_tab(color));
	plane->origin = rt_point(
			ft_strtof(*coord), ft_strtof(*(coord +1)), ft_strtof(*(coord +2)));
	plane->norm = rt_vector(
			ft_strtof(*norm), ft_strtof(*(norm +1)), ft_strtof(*(norm +2)));
	plane->shape = PLANE;
	plane->transform = rt_set_transform(*plane);
	*plane = rt_plane(rt_color(
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2))));
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}

void	rt_assign_cylinder(t_object *cylinder, char **needle)
{
	char	**coord;
	char	**norm;
	char	**color;

	cylinder->shape = CYLINDER;
	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle +1), ',');
	color = ft_split(*(needle + 4), ',');
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord) \
		|| !rt_valid_color(color))
		return (ft_free_tab(coord), ft_free_tab(norm), ft_free_tab(color));
	cylinder->diameter = ft_strtof(*(needle +2));
	cylinder->height = ft_strtof(*(needle + 3));
	cylinder->origin = rt_point(
			ft_strtof(*coord), ft_strtof(*(coord +1)), ft_strtof(*(coord +2)));
	cylinder->norm = rt_vector(
			ft_strtof(*norm), ft_strtof(*(norm +1)), ft_strtof(*(norm +2)));
	cylinder->transform = rt_set_transform(*cylinder);
	*cylinder = rt_cylinder(rt_color(
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2))));
	cylinder->shape = CYLINDER;
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}
