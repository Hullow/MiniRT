/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_view_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:32:54 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 10:03:11 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	rt_orientation_matrix(t_tuple left, t_tuple true_up, \
	t_tuple forward)
{
	t_matrix	orientation;

	orientation = rt_identity_matrix();
	orientation.cell[0][0] = left.x;
	orientation.cell[0][1] = left.y;
	orientation.cell[0][2] = left.z;
	orientation.cell[1][0] = true_up.x;
	orientation.cell[1][1] = true_up.y;
	orientation.cell[1][2] = true_up.z;
	orientation.cell[2][0] = -forward.x;
	orientation.cell[2][1] = -forward.y;
	orientation.cell[2][2] = -forward.z;
	return (orientation);
}

/// @brief Returns the transformation matrix to apply to the view point
/// @param from point of origin of the view
/// @param to point we are looking at
/// @param up vector pointing to the up direction
/// @return transformation matrix
t_matrix	rt_view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix	transform;
	t_matrix	orientation;
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;

	forward = rt_normalize(rt_sub_tuple(to, from));
	left = rt_cross_product(forward, rt_normalize(up));
	true_up = rt_cross_product(left, forward);
	orientation = rt_orientation_matrix(left, true_up, forward);
	transform = rt_mul_matrix(orientation, \
		rt_translation(rt_vector(-from.x, -from.y, -from.z)));
	return (transform);
}
