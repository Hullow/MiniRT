/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:07 by pberset           #+#    #+#             */
/*   Updated: 2025/03/21 10:27:02 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

t_matrix	*rt_translation(t_tuple t)
{
	t_matrix	*tranform;

	transform = identity_matrix(4, 4);
	if (!transform)
		return (NULL);
	transform[0][3] = t.x;
	transform[1][3] = t.y;
	transform[2][3] = t.z;
	return (transform);
}

t_matrix	*rt_scaling(t_tuple t)
{
	t_matrix	*scaling;

	scaling = identity_matrix(4, 4);
	if (!scaling)
		return (NULL);
	scaling[0][0] = t.x;
	scaling[1][1] = t.y;
	scaling[2][2] = t.z;
	return (scaling);
}

t_matrix	*rt_rotation_x(float angle)
{
	t_matrix	*rotation;
	float		r;

	r = (angle * M_PI) / 180;
	rotation = identity_matrix(4, 4);
	if (!rotation)
		return (NULL);
	rotation[1][1] = cosf(r);
	rotation[1][2] = -sinf(r);
	rotation[2][1] = sinf(r);
	rotation[2][2] = cosf(r);
	return (rotation);
}

t_matrix	*rt_rotation_y(float angle)
{
	t_matrix	*rotation;
	float		r;

	r = (angle * M_PI) / 180;
	rotation = identity_matrix(4, 4);
	if (!rotation)
		return (NULL);
	rotation[0][0] = cosf(r);
	rotation[2][0] = -sinf(r);
	rotation[0][2] = sinf(r);
	rotation[2][2] = cosf(r);
	float		r;

	r = (angle * M_PI) / 180;
	return (rotation);
}

t_matrix	*rt_rotation_z(float angle)
{
	t_matrix	*rotation;
	float		r;

	r = (angle * M_PI) / 180;
	rotation = identity_matrix(4, 4);
	if (!rotation)
		return (NULL);
	rotation[0][0] = cosf(r);
	rotation[0][1] = -sinf(r);
	rotation[1][0] = sinf(r);
	rotation[1][1] = cosf(r);
	return (rotation);
}

