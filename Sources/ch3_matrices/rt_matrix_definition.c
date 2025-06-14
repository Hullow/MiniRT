/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_definition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:46:36 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 10:04:03 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief initializes and returns an identity matrix (on the stack, no malloc)
t_matrix	rt_identity_matrix(int size)
{
	t_matrix	matrix;
	int			i;
	int			j;

	matrix.rows = size;
	matrix.columns = size;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				matrix.cell[i][j] = 1.0f;
			else
				matrix.cell[i][j] = 0.0f;
			j++;
		}
		i++;
	}
	return (matrix);
}

/// @brief Checks equality of matrices a and b
/// @param a t_matrix
/// @param b t_matrix
/// @return 1 if matrices are equal, 0 otherwise.
int	rt_matrix_equality(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	if (a.rows != b.rows || a.columns != b.columns)
		return (0);
	i = 0;
	while (i < a.rows)
	{
		j = 0;
		while (j < a.columns)
		{
			if (a.cell[i][j] != b.cell[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
