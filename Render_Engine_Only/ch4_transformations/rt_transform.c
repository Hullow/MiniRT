/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_transform_ok.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:17:30 by pberset           #+#    #+#             */
/*   Updated: 2025/05/16 18:32:19 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

// Init a translation matrix in the direction given by the vector t
t_matrix	rt_translation(t_tuple t)
{
	t_matrix	translate;

	translate = rt_identity_matrix();
	translate.cell[0][3] = t.x;
	translate.cell[1][3] = t.y;
	translate.cell[2][3] = t.z;
	return (translate);
}

// Init a scaling matrix by the amount given by the vector t
t_matrix	rt_scaling(t_tuple t)
{
	t_matrix	scaling;

	scaling = rt_identity_matrix();
	scaling.cell[0][0] = t.x;
	scaling.cell[1][1] = t.y;
	scaling.cell[2][2] = t.z;
	return (scaling);
}

t_matrix	rt_set_transform(t_object object, t_matrix transform)
{
	t_matrix	modified;

	modified = rt_mul_matrix(object.transform, transform);
	return (modified);
}

/* Takes in an array of 6 floats shear_factors, which contains, in order:
	x_to_y, x_to_z, y_to_x,	y_to_z, z_to_x, z_to_y */
t_matrix	rt_shearing(float *shear_factors)
{
	t_matrix	shear;

	shear = rt_identity_matrix();
	shear.cell[0][1] = shear_factors[0];
	shear.cell[0][2] = shear_factors[1];
	shear.cell[1][0] = shear_factors[2];
	shear.cell[1][2] = shear_factors[3];
	shear.cell[2][0] = shear_factors[4];
	shear.cell[2][1] = shear_factors[5];
	return (shear);
}
