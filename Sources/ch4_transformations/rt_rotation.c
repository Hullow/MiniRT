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

t_matrix	rt_rotation(t_tuple norm)
{
	t_matrix	rotate;
	t_tuple		new_x;
	t_tuple		new_y;
	t_tuple		new_z;
	
	new_y = norm;
	if (is_equal_float(\
		0, rt_magnitude(rt_cross_product(new_y, rt_vector(1, 0, 0)))))
		new_x = rt_normalize(rt_cross_product(new_y, rt_vector(0, 0, 1)));
		else
		new_x = rt_normalize(rt_cross_product(new_y, rt_vector(1, 0, 0)));
		new_z = rt_cross_product(new_x, new_y);
		rotate = rt_identity_matrix(4);
		rotate.cell[0][0] = new_x.x;
		rotate.cell[0][1] = new_y.x;
		rotate.cell[0][2] = new_z.x;
		rotate.cell[1][0] = new_x.y;
		rotate.cell[1][1] = new_y.y;
		rotate.cell[1][2] = new_z.y;
		rotate.cell[2][0] = new_x.z;
		rotate.cell[2][1] = new_y.z;
		rotate.cell[2][2] = new_z.z;
		return (rotate);
}
