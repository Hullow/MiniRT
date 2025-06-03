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
t_object	rt_sphere(t_tuple color)
{
	t_object	sphere;

	sphere.shape = SPHERE;
	sphere.origin = rt_point(0, 0, 0);
	sphere.diameter = 2.0f;
	sphere.color = color;
	sphere.material = rt_material(0.1, 0.9, 0.9, 200.0);
	sphere.transform = rt_identity_matrix();
	return (sphere);
}

t_object	rt_plane(t_tuple color)
{
	t_object	plane;

	plane.shape = PLANE;
	plane.origin = rt_point(0, 0, 0);
	plane.norm = rt_vector(0, 1, 0);
	plane.color = color;
	plane.material = rt_material(0.1, 0.9, 0.9, 200.0f);
	return (plane);
}

t_object	rt_cylinder(t_tuple color)
{
	t_object	cylinder;

	cylinder.shape = CYLINDER;
	cylinder.diameter = 2.0;
	cylinder.height = INFINITY;
	cylinder.min = -INFINITY;
	cylinder.max = INFINITY;
	cylinder.closed = 0;
	cylinder.color = color;
	cylinder.material = rt_material(0.1, 0.9, 0.9, 200.0);
	cylinder.norm = rt_vector(0, 1, 0);
	cylinder.origin = rt_point(0, 0, 0);
	return (cylinder);
}
