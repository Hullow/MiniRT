/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_inversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:45:04 by pberset           #+#    #+#             */
/*   Updated: 2025/06/03 18:34:32 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	rt_determinant(t_matrix m)
{
	float	det;
	int		i;

	if (m.rows == 2)
		det = m.cell[0][0] * m.cell[1][1] - m.cell[0][1] * m.cell[1][0];
	else
	{
		i = 0;
		det = 0;
		while (i < m.columns)
		{
			det = det + m.cell[0][i] * rt_cofactor(m, 0, i);
			i++;
		}
	}
	return (det);
}

/// @brief removes one specified row and one specified column from a matrix, and
/// returns the resulting matrix (input matrix isn't modified nor freed)
/// @param m 
/// @param row 
/// @param col 
/// @param sub 
void	rt_sub_matrix(t_matrix m, int row, int col, t_matrix *sub)
{
	int			i;
	int			j;
	int			k;
	int			l;

	sub->rows = m.rows - 1;
	sub->columns = m.columns - 1;
	i = -1;
	k = 0;
	while (++i < m.rows)
	{
		if (i == row)
			continue ;
		j = -1;
		l = 0;
		while (++j < m.columns)
		{
			if (j == col)
				continue ;
			sub->cell[k][l] = m.cell[i][j];
			l++;
		}
		k++;
	}
}

/// @brief computes and returns the minor (float) at i, j of a matrix,
/// using the submatrix at i,j (row, column), and computing its determinant
float	rt_minor(t_matrix m, int row, int col)
{
	float		minor;
	t_matrix	sub;

	sub = rt_identity_matrix();
	sub = rt_identity_matrix();
	rt_sub_matrix(m, row, col, &sub);
	minor = rt_determinant(sub);
	return (minor);
}

/// @brief computes and returns the cofactor of a matrix, using matrix_minor
float	rt_cofactor(t_matrix m, int row, int col)
{
	float	cofactor;

	cofactor = rt_minor(m, row, col);
	if ((row + col) % 2)
		cofactor = -cofactor;
	return (cofactor);
}

/// @brief inverts a matrix of any size (row, columns <= 4)
/// @returns the inverted matrix
t_matrix	rt_inversion(t_matrix m)
{
	float		det;
	float		cofactor;
	t_matrix	invert;
	int			i;
	int			j;

	errno = 0;
	det = rt_determinant(m);
	if (fabs(det) < EPSILON)
		return (errno = ENOTINVERTIBLE, (t_matrix) {.columns = 0, .rows = 0});
	invert = rt_identity_matrix();
	invert.rows = m.rows;
	invert.columns = m.columns;
	i = -1;
	while (++i < m.rows)
	{
		j = -1;
		while (++j < m.columns)
		{
			cofactor = rt_cofactor(m, i, j);
			invert.cell[j][i] = cofactor / det;
		}
	}
	return (invert);
}
