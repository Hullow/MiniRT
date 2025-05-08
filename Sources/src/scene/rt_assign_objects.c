/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_assign_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:34:36 by pberset           #+#    #+#             */
/*   Updated: 2025/05/02 15:05:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* initializes a sphere based on a tuple for coordinates, a float for diameter, 
and a tuple for color. Both input tuples to be initialized on the stack, thus:
(t_tuple){.x = , .y = , .z = } */
t_object	rt_init_sphere(t_tuple coord, float diam, t_tuple color)
{
	t_object	sp;

	sp.coord = rt_point(coord.x, coord.y, coord.z);
	sp.color = rt_color(color.x, color.y, color.z);
	printf("rt_init_sphere\n- input (%f, %f, %f)\n", color.x, color.y, color.z);
	printf("- output (%f, %f, %f)\n", sp.color.x, sp.color.y, sp.color.z);
	sp.transform = identity_matrix(4, 4);
	sp.inverse = sp.transform;
	sp.diameter = diam;
	return (sp);
}

void	rt_assign_sphere(t_object *sphere, char **needle)
{
	char	**coord;
	char	**color;

	sphere->type = SPHERE;
	coord = ft_split(*needle, ',');
	color = ft_split(*(needle +2), ',');
	sphere->diameter = ft_strtof(*(needle +1));
	if (!rt_valid_color(color) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_tab(coord);
		ft_free_tab(color);
		return ;
	}
	sphere->coord = rt_point(
			ft_strtof(*coord), ft_strtof(*(coord +1)), ft_strtof(*(coord +2)));
	sphere->color = rt_color(
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2)));
	sphere->type = SPHERE;
	ft_free_tab(coord);
	ft_free_tab(color);
}

void	rt_assign_plane(t_object *plane, char **needle)
{
	char	**coord;
	char	**norm;
	char	**color;

	plane->type = PLANE;
	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle +1), ',');
	color = ft_split(*(needle +2), ',');
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord)
		|| !rt_valid_color(color))
		return (ft_free_tab(coord), ft_free_tab(norm), ft_free_tab(color));
	plane->coord = rt_point(
			ft_strtof(*coord), ft_strtof(*(coord +1)), ft_strtof(*(coord +2)));
	plane->norm = rt_vector(
			ft_strtof(*norm), ft_strtof(*(norm +1)), ft_strtof(*(norm +2)));
	plane->color = rt_color(
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2)));
	plane->type = PLANE;
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}

void	rt_assign_cylinder(t_object *cylinder, char **needle)
{
	char	**coord;
	char	**norm;
	char	**color;

	cylinder->type = CYLINDER;
	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle +1), ',');
	color = ft_split(*(needle + 4), ',');
	cylinder->diameter = ft_strtof(*(needle +2));
	cylinder->height = ft_strtof(*(needle + 3));
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord)
		|| !rt_valid_color(color))
		return (ft_free_tab(coord), ft_free_tab(norm), ft_free_tab(color));
	cylinder->coord = rt_point(
			ft_strtof(*coord), ft_strtof(*(coord +1)), ft_strtof(*(coord +2)));
	cylinder->norm = rt_vector(
			ft_strtof(*norm), ft_strtof(*(norm +1)), ft_strtof(*(norm +2)));
	cylinder->color = rt_color(
			ft_strtof(*color), ft_strtof(*(color +1)), ft_strtof(*(color +2)));
	cylinder->type = CYLINDER;
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}
