/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:19:56 by pberset           #+#    #+#             */
/*   Updated: 2025/06/03 17:34:59 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Initializes a unit sphere
/// @param color t_tuple type COLOR not in material because norminette
/// @param material t_material
/// @return The initialized struct.
t_object	rt_sphere(t_tuple origin, float diameter, t_tuple color)
{
	t_object	sphere;

	sphere.shape = SPHERE;
	sphere.origin = origin;
	sphere.radius = diameter / 2;
	sphere.color = color;
	sphere.material = rt_material(0.1, 0.9, 0.9, 200.0);
	return (sphere);
}

t_object	rt_plane(t_tuple origin, t_tuple norm, t_tuple color)
{
	t_object	plane;

	plane.shape = PLANE;
	plane.origin = origin;
	plane.norm = rt_normalize(norm);
	plane.color = color;
	plane.material = rt_material(0.1, 0.9, 0.9, 200.0f);
	return (plane);
}

t_object	rt_cylinder(t_tuple origin, t_tuple norm, t_tuple color)
{
	t_object	cylinder;

	cylinder.shape = CYLINDER;
	cylinder.closed = 1;
	cylinder.color = color;
	cylinder.material = rt_material(0.1, 0.9, 0.9, 200.0);
	cylinder.norm = rt_normalize(norm);
	cylinder.origin = origin;
	return (cylinder);
}