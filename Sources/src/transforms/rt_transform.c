/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student->42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:07 by pberset           #+#    #+#             */
/*   Updated: 2025/03/21 15:29:52 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	*rt_translation(t_tuple *t)
{
	t_matrix	*transform;

	transform = identity_matrix(4, 4);
	if (!transform)
		return (NULL);
	transform->m[0][3] = t->x;
	transform->m[1][3] = t->y;
	transform->m[2][3] = t->z;
	return (transform);
}

t_matrix	*rt_scaling(t_tuple *t)
{
	t_matrix	*scaling;

	scaling = identity_matrix(4, 4);
	if (!scaling)
		return (NULL);
	scaling->m[0][0] = t->x;
	scaling->m[1][1] = t->y;
	scaling->m[2][2] = t->z;
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
	rotation->m[1][1] = cosf(r);
	rotation->m[1][2] = -sinf(r);
	rotation->m[2][1] = sinf(r);
	rotation->m[2][2] = cosf(r);
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
	rotation->m[0][0] = cosf(r);
	rotation->m[2][0] = -sinf(r);
	rotation->m[0][2] = sinf(r);
	rotation->m[2][2] = cosf(r);
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
	rotation->m[0][0] = cosf(r);
	rotation->m[0][1] = -sinf(r);
	rotation->m[1][0] = sinf(r);
	rotation->m[1][1] = cosf(r);
	return (rotation);
}

