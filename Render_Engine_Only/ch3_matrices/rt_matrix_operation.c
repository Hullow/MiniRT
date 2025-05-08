/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:21:37 by pberset           #+#    #+#             */
/*   Updated: 2025/05/05 16:18:11 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

/// @brief Multiplies matrices a and b. For this project, only matrices 4x4
/// @param a t_matrix
/// @param b t_matrix
/// @return the multiplication matrix. sets errno if size of a or b is not 4x4
t_matrix	rt_mul_matrix(t_matrix a, t_matrix b)
{
	t_matrix	mul;
	int			i;
	int			j;

	mul.rows = 4;
	mul.columns = 4;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mul.cell[i][j] = a.cell[i][0] * b.cell[0][j] \
						+ a.cell[i][1] * b.cell[1][j] \
						+ a.cell[i][2] * b.cell[2][j] \
						+ a.cell[i][3] * b.cell[3][j];
			j++;
		}
		i++;
	}
	return (mul);
}

static float mat_dot_product(float *a, t_tuple b)
{
	float	dot;

	dot = a[0] * b.x + a[1] * b.y + a[2] * b.z + a[3] * (float)b.w;
	return (dot);
}

t_tuple	rt_mul_tuple_matrix(t_matrix m, t_tuple t)
{
	float	buffer[4];
	int		i;
	t_tuple	mul;

	mul.w = t.w;
	i = 0;
	while (i < 4)
	{
		buffer[0] = m.cell[i][0];
		buffer[1] = m.cell[i][1];
		buffer[2] = m.cell[i][2];
		buffer[3] = m.cell[i][3];
		if (i == 0)
			mul.x = mat_dot_product(buffer, t);
		if (i == 1)
			mul.y = mat_dot_product(buffer, t);
		if (i == 2)
			mul.z = mat_dot_product(buffer, t);
		i++;
	}
	return (mul);
}

t_matrix	rt_matrix_transpose(t_matrix m)
{
	t_matrix	transpose;
	int			i;
	int			j;

	transpose.rows = 4;
	transpose.columns = 4;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			transpose.cell[j][i] = m.cell[i][j];
			j++;
		}
		i++;
	}
	return (transpose);
}
