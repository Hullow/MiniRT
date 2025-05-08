/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:19:56 by pberset           #+#    #+#             */
/*   Updated: 2025/05/07 11:18:20 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

/// @brief Initializes a unit sphere
/// @param color t_tuple type COLOR not in material because norminette
/// @param material t_material
/// @return The initialized struct.
t_object	rt_sphere(t_tuple color, t_material material)
{
	t_object	sphere;

	sphere.shape = SPHERE;
	sphere.origin = rt_point(0, 0, 0);
	sphere.diameter = 2.0f;
	sphere.transform = rt_identity_matrix();
	sphere.color = color;
	sphere.material = material;
	return (sphere);
}

void	rt_print_sphere(t_object sphere)
{
	printf("Sphere diameter: %f\n", sphere.diameter);
	printf("Origin: ");
	rt_print_tuple(sphere.origin);
	printf("Transform:\n");
	rt_print_matrix(sphere.transform);
	printf("Color: ");
	rt_print_tuple(sphere.color);
	printf("Material: ");
	rt_print_material(sphere.material);
}
