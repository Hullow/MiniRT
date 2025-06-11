/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_assign_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:34:36 by pberset           #+#    #+#             */
/*   Updated: 2025/06/09 23:05:51 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_assign_sphere(t_object *sphere, char **needle)
{
	char		**coord;
	char		**color;
	t_matrix	transform;

	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
	color = ft_split(*(needle + 2), ',');
	if (!rt_valid_color(color) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_double_tab(coord, color);
		return ;
	}
	*sphere = rt_sphere(rt_point(ft_strtof(*coord),	ft_strtof(*(coord + 1)), \
		ft_strtof(*(coord + 2))), ft_strtof(*(needle + 1)), \
			rt_color(ft_strtof(*color), ft_strtof(*(color + 1)), \
			ft_strtof(*(color + 2))));
	transform = rt_set_transform(*sphere);
	sphere->transform = transform;
	ft_free_double_tab(coord, color);
}

void	rt_assign_plane(t_object *plane, char **needle)
{
	char		**coord;
	char		**norm;
	char		**color;
	t_matrix	transform;

	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle + 1), ',');
	color = ft_split(*(needle + 2), ',');
	norm = ft_split(*(needle + 1), ',');
	color = ft_split(*(needle + 2), ',');
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord) \
		|| !rt_valid_color(color))
		return (ft_free_tab(coord), ft_free_tab(norm), ft_free_tab(color));
	*plane = rt_plane(rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)), \
		ft_strtof(*(coord + 2))), rt_vector(ft_strtof(*norm), \
			ft_strtof(*(norm + 1)), ft_strtof(*(norm + 2))), rt_color(\
				ft_strtof(*color), ft_strtof(*(color + 1)), \
					ft_strtof(*(color + 2))));
	*plane = rt_plane(rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)), \
		ft_strtof(*(coord + 2))), rt_vector(ft_strtof(*norm), \
			ft_strtof(*(norm + 1)), ft_strtof(*(norm + 2))), rt_color(\
				ft_strtof(*color), ft_strtof(*(color + 1)), \
					ft_strtof(*(color + 2))));
	transform = rt_set_transform(*plane);
	plane->transform = transform;
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}

void	rt_assign_cylinder(t_object *cylinder, char **needle)
{
	char		**coord;
	char		**norm;
	char		**color;
	t_matrix	transform;

	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle + 1), ',');
	norm = ft_split(*(needle + 1), ',');
	color = ft_split(*(needle + 4), ',');
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord) \
	|| !rt_valid_color(color))
		return (ft_free_tab(coord), ft_free_tab(norm), ft_free_tab(color));
	*cylinder = rt_cylinder(rt_point(ft_strtof(*coord), \
		ft_strtof(*(coord + 1)), ft_strtof(*(coord + 2))), rt_vector(\
			ft_strtof(*norm), ft_strtof(*(norm + 1)), ft_strtof(*(norm + 2))), \
				rt_color(ft_strtof(*color), ft_strtof(*(color + 1)), \
					ft_strtof(*(color + 2))));
	cylinder->radius = ft_strtof(*(needle + 2)) / 2;
	cylinder->max = ft_strtof(*(needle + 3));
	*cylinder = rt_cylinder(rt_point(ft_strtof(*coord), \
		ft_strtof(*(coord + 1)), ft_strtof(*(coord + 2))), rt_vector(\
			ft_strtof(*norm), ft_strtof(*(norm + 1)), ft_strtof(*(norm + 2))), \
				rt_color(ft_strtof(*color), ft_strtof(*(color + 1)), \
					ft_strtof(*(color + 2))));
	cylinder->radius = ft_strtof(*(needle + 2)) / 2;
	cylinder->max = ft_strtof(*(needle + 3));
	transform = rt_set_transform(*cylinder);
	cylinder->transform = transform;
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}
