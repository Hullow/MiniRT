/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_shearing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:17:23 by francis           #+#    #+#             */
/*   Updated: 2025/04/19 15:33:08 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Takes in an array of 6 floats shear_factors, which contains, in order:
	x_to_y, x_to_z, y_to_x,	y_to_z, z_to_x, z_to_y
*/
t_matrix	rt_shearing(float *shear_factors)
{
	t_matrix	shear;

	shear = identity_matrix(4, 4);
	shear.m[0][1] = shear_factors[0];
	shear.m[0][2] = shear_factors[1];
	shear.m[1][0] = shear_factors[2];
	shear.m[1][2] = shear_factors[3];
	shear.m[2][0] = shear_factors[4];
	shear.m[2][1] = shear_factors[5];
	return (shear);
}
