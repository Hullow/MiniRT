/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_ok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:59:10 by pberset           #+#    #+#             */
/*   Updated: 2025/05/16 18:40:45 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

/// @brief Initializes a light object
/// @param color t_tuple type COLOR
/// @param coord t_tuple type POINT
/// @param intensity float
/// @return The initialized light structure
t_light	rt_light(t_tuple color, t_tuple coord, float intensity)
{
	t_light	light;

	light.color = color;
	light.coord = coord;
	light.intensity = intensity;
	return (light);
}

void	rt_print_light(t_light light)
{
	printf("Light\ncoord:\n");
	rt_print_tuple(light.coord);
	printf("color:\n");
	rt_print_tuple(light.color);
	printf("intensity: %f\n", light.intensity);
}

/// @brief Initializes a material struct without color because norminette
/// @param amb float
/// @param dif float
/// @param spec float
/// @param shine float
/// @return The initialized struct
t_material	rt_material(float amb, float dif, float spec, float shine)
{
	t_material	material;

	material.ambient = amb;
	material.diffuse = dif;
	material.specular = spec;
	material.shininess = shine;
	return (material);
}

void	rt_print_material(t_material mat)
{
	printf("ambient: %f, diffuse: %f, specular: %f, shininess: %f\n", \
		mat.ambient, mat.diffuse, mat.specular, mat.shininess);
}
