/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:26:27 by pberset           #+#    #+#             */
/*   Updated: 2025/06/05 17:36:59 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
/// @brief Init a rotation matrix that rotates an object to have norm "norm"
/// @details the norm is our desired Y-axis, so it keeps it unchanged.
/// it checks if the norm is parallel to the X-axis using the magnitude of the
/// their cross product:
/// - If it is not, it uses the X-basis vector (1, 0, 0)
/// as the second basis vector, "new_x".
/// - If it is, it uses the Z-basis vector (0,0,1).
/// The third new basis vector "new_z "is calculated using 
/// the cross product of the first two "new_y" and "new_x".
/// The vector components are used to init the corresponding rotation matrix.
t_matrix	rt_rotation(t_tuple norm)
{
	t_matrix	rotate;
	t_tuple		new_x;
	t_tuple		new_y;
	t_tuple		new_z;
	
	new_y = norm;
	if (is_equal_float(
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
	
	/*
	typedef struct s_rota_values
	{
		float cos_angle;
		float angle;
		float cos_a;
		float sin_a;
		float one_minus_cos;
	}	t_rota_values;
	
	// Init a rotation matrix of angle around x
	//angle is in radians
	t_matrix	rt_rotation_x(float angle)
	{
		t_matrix	rotation;
	
		rotation = rt_identity_matrix(4);
		rotation.cell[1][1] = cosf(angle);
		rotation.cell[1][2] = -sinf(angle);
		rotation.cell[2][1] = sinf(angle);
		rotation.cell[2][2] = cosf(angle);
		return (rotation);
	}
	
	static void	clean_matrix(t_matrix *m)
	{
		int	i;
		int	j;
	
		i = 0;
		while (i < m->rows)
		{
			j = 0;
			while (j < m->columns)
			{
				if (fabs(m->cell[i][j]) < EPSILON)
					m->cell[i][j] = 0.0f;
				j++;
			}
			i++;
		}
	}
	
	static void	rodrigues_rotation(t_rota_values vals, t_tuple axis, t_matrix *rotation)
	{
		rotation->cell[0][0] = vals.cos_a + axis.x * axis.x * vals.one_minus_cos;
		rotation->cell[0][1] = axis.x * axis.y * vals.one_minus_cos - axis.z * vals.sin_a;
		rotation->cell[0][2] = axis.x * axis.z * vals.one_minus_cos + axis.y * vals.sin_a;
		rotation->cell[1][0] = axis.y * axis.x * vals.one_minus_cos + axis.z * vals.sin_a;
		rotation->cell[1][1] = vals.cos_a + axis.y * axis.y * vals.one_minus_cos;
		rotation->cell[1][2] = axis.y * axis.z * vals.one_minus_cos - axis.x * vals.sin_a;
		rotation->cell[2][0] = axis.z * axis.x * vals.one_minus_cos - axis.y * vals.sin_a;
		rotation->cell[2][1] = axis.z * axis.y * vals.one_minus_cos + axis.x * vals.sin_a;
		rotation->cell[2][2] = vals.cos_a + axis.z * axis.z * vals.one_minus_cos;
	}
	
	t_matrix rt_rotation(t_tuple norm)
	{
		t_tuple axis;
		t_rota_values	vals;
		t_matrix rotation = rt_identity_matrix(4);
		
		if (rt_is_equal_tuple(norm, rt_vector(0.0, 1.0, 0.0)))
		return (rt_identity_matrix(4));
		if (rt_is_equal_tuple(norm, rt_vector(0.0, -1.0, 0.0)))
		return (rt_rotation_x(M_PI));
		norm = rt_normalize(norm);
		vals.cos_angle = rt_dot_product(rt_vector(0.0, 1.0, 0.0), norm);
		vals.angle = acosf(vals.cos_angle);
		vals.cos_a = cosf(vals.angle);
		vals.sin_a = sinf(vals.angle);
		vals.one_minus_cos = 1.0f - vals.cos_a;
		axis = rt_cross_product(rt_vector(0.0, 1.0, 0.0), norm);
		rodrigues_rotation(vals, axis, &rotation);
		clean_matrix(&rotation);
		return (rotation);
	}
	*/
