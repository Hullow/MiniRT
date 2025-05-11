/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:26:27 by pberset           #+#    #+#             */
/*   Updated: 2025/05/02 20:26:30 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

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
