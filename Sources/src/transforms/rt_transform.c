/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:07 by pberset           #+#    #+#             */
/*   Updated: 2025/03/20 17:37:19 by pberset          ###   Lausanne.ch       */
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

	sclaing
	scaling.rows = 4;
	scaling.columns = 4;
	scaling.m = (float [4][4]){ \
		{t.x, 0, 0, 0}, \
		{0, t.y, 0, 0}, \
		{0, 0, t.z, 0}, \
		{0, 0, 0, 1} \
		};
	return (scaling);
}

t_matrix	*rt_rotation_x(float angle)
{
	t_matrix	*rotation;
	float		r;

	r = (angle * M_PI) / 180;
	rotation.rows = 4;
	rotation.columns = 4;
	rotation.m = {
		{1, 0, 0, 0},
		{0, cosf(r), -sinf(r), 0},
		{0, sinf(r), cosf(r), 0},
		{0, 0, 0, 1}
	};
	return (rotation);
}

t_matrix	*rt_rotation_y(float angle)
{
	t_matrix	*rotation;
	float		r;

	r = (angle * M_PI) / 180;
	rotation.rows = 4;
	rotation.columns = 4;
	rotation.m = {
		{cosf(r), 0, sinf(r), 0},
		{0, 1, 0, 0},
		{-sinf(r), 0, cosf(r), 0},
		{0, 0, 0, 1}
	};
	return (rotation);
}

t_matrix	*rt_rotation_z(float angle)
{
	t_matrix	*rotation;
	float		r;

	r = (angle * M_PI) / 180;
	rotation.rows = 4;
	rotation.columns = 4;
	rotation.m = {
		{cosf(r), -sinf(r), 0, 0},
		{sinf(r), cosf(r), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	return (rotation);
}

