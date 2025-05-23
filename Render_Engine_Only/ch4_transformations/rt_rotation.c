/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:26:27 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	rotate = rt_mul_matrix(rotate, rt_rotation_y(beta));
	rotate = rt_mul_matrix(rotate, rt_rotation_x(gamma));
	return (rotate);
}

// Init a rotation matrix of angle around x
//angle is in radians
t_matrix	rt_rotation_x(float angle)
{
	t_matrix	rotation;

	rotation = rt_identity_matrix();
	rotation.cell[1][1] = cosf(angle);
	rotation.cell[1][2] = -sinf(angle);
	rotation.cell[2][1] = sinf(angle);
	rotation.cell[2][2] = cosf(angle);
	return (rotation);
}

// Init a rotation matrix of angle around y
//angle is in radians
t_matrix	rt_rotation_y(float angle)
{
	t_matrix	rotation;

	rotation = rt_identity_matrix();
	rotation.cell[0][0] = cosf(angle);
	rotation.cell[2][0] = -sinf(angle);
	rotation.cell[0][2] = sinf(angle);
	rotation.cell[2][2] = cosf(angle);
	return (rotation);
}

// Init a rotation matrix of angle around z
//angle is in radians
t_matrix	rt_rotation_z(float angle)
{
	t_matrix	rotation;

	rotation = rt_identity_matrix();
	rotation.cell[0][0] = cosf(angle);
	rotation.cell[0][1] = -sinf(angle);
	rotation.cell[1][0] = sinf(angle);
	rotation.cell[1][1] = cosf(angle);
	return (rotation);
}
