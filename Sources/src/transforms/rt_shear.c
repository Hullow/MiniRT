/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_shear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:17:23 by francis           #+#    #+#             */
/*   Updated: 2025/03/21 18:19:17 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	*rt_shear(float x_to_y, float x_to_z, float y_to_x, float y_to_z, float z_to_x, float z_to_y)
{
	t_matrix	*shear;
	
	shear = identity_matrix(4, 4);
	if (!shear)
		return (NULL);
	shear->m[0][1] = x_to_y;
	shear->m[0][2] = x_to_z;
	shear->m[1][0] = y_to_x;
	shear->m[1][2] = y_to_z;
	shear->m[2][0] = z_to_x;
	shear->m[2][1] = z_to_y;
	return (shear);
}
