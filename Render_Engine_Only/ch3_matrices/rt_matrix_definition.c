/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_definition.cell                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:46:36 by pberset           #+#    #+#             */
/*   Updated: 2025/05/01 16:46:37 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_matrix	rt_identity_matrix()
{
	t_matrix	matrix;
	int			i;
	int			j;

	matrix.rows = 4;
	matrix.columns = 4;
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
	int i;
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

void	rt_print_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.rows)
	{
		printf("row[%d]: | ", i);
		j = 0;
		while (j < m.columns)
		{
			printf("%f | ", m.cell[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
