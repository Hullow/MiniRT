/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:59:10 by pberset           #+#    #+#             */
/*   Updated: 2025/06/06 12:47:47 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
