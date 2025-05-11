/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:07 by pberset           #+#    #+#             */
/*   Updated: 2025/04/19 18:55:13 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Init a translation matrix in the direction given by the vector t
t_matrix	rt_translation(t_tuple t)
{
	t_matrix	transform;

	transform = identity_matrix(4, 4);
	transform.m[0][3] = t.x;
	transform.m[1][3] = t.y;
	transform.m[2][3] = t.z;
	return (transform);
}

// Init a scaling matrix by the amount given by the vector t
t_matrix	rt_scaling(t_tuple t)
{
	t_matrix	scaling;

	scaling = identity_matrix(4, 4);
	scaling.m[0][0] = t.x;
	scaling.m[1][1] = t.y;
	scaling.m[2][2] = t.z;
	return (scaling);
}

// Init a rotation matrix around the 3 axis
// Takes in the object's normal vector
t_matrix	rt_rotation(t_tuple norm)
{
	t_matrix	rotate;
	float		alpha;
	float		beta;
	float		gamma;

	alpha = atan2f(norm.x, norm.z);
	beta = atan2f(-norm.z, sqrtf(norm.x * norm.x + norm.y * norm.y));
	gamma = atan2f(norm.y, norm.x);
	rotate = rt_rotation_z(alpha);
	rotate = matrix_multiplication(rotate, rt_rotation_y(beta));
	rotate = matrix_multiplication(rotate, rt_rotation_x(gamma));
	return (rotate);
}

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
