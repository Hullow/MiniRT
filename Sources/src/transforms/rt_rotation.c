/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:31:13 by pberset           #+#    #+#             */
/*   Updated: 2025/05/14 13:33:36 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Init a rotation matrix of angle around x
//angle is in radians
t_matrix	rt_rotation_x(float angle)
{
	t_matrix	rotation;

	rotation = identity_matrix(4, 4);
	rotation.m[1][1] = cosf(angle);
	rotation.m[1][2] = -sinf(angle);
	rotation.m[2][1] = sinf(angle);
	rotation.m[2][2] = cosf(angle);
	return (rotation);
}

// Init a rotation matrix of angle around y
//angle is in radians
t_matrix	rt_rotation_y(float angle)
{
	t_matrix	rotation;

	rotation = identity_matrix(4, 4);
	rotation.m[0][0] = cosf(angle);
	rotation.m[2][0] = -sinf(angle);
	rotation.m[0][2] = sinf(angle);
	rotation.m[2][2] = cosf(angle);
	return (rotation);
}

// Init a rotation matrix of angle around z
//angle is in radians
t_matrix	rt_rotation_z(float angle)
{
	t_matrix	rotation;

	rotation = identity_matrix(4, 4);
	rotation.m[0][0] = cosf(angle);
	rotation.m[0][1] = -sinf(angle);
	rotation.m[1][0] = sinf(angle);
	rotation.m[1][1] = cosf(angle);
	return (rotation);
}
