/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:19:56 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
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
	sphere.transform = rt_identity_matrix();
	sphere.color = color;
	sphere.material = rt_material(0.1, 0.9, 0.9, 200.0);
	return (sphere);
}

void	rt_print_sphere(t_object sphere)
{
	ft_printf("Diameter: %f\n", sphere.diameter);
	ft_printf("Origin: ");
	rt_print_tuple(sphere.origin);
	ft_printf("Transform:\n");
	rt_print_matrix(sphere.transform);
	ft_printf("Color: ");
	rt_print_tuple(sphere.color);
	ft_printf("Material: ");
	rt_print_material(sphere.material);
}

t_object	rt_plane(t_tuple color)
{
	t_object	plane;

	plane.shape = PLANE;
	plane.origin = rt_point(0, 0, 0);
	plane.norm = rt_vector(0, 1, 0);
	plane.transform = rt_identity_matrix();
	plane.color = color;
	plane.material = rt_material(0.1, 0.9, 0.9, 200.0f);
	return (plane);
}

void	rt_print_plane(t_object plane)
{
	ft_printf("Origin: ");
	rt_print_tuple(plane.origin);
	ft_printf("Transform:\n");
	rt_print_matrix(plane.transform);
	ft_printf("Color: ");
	rt_print_tuple(plane.color);
	ft_printf("Material: ");
	rt_print_material(plane.material);
}
