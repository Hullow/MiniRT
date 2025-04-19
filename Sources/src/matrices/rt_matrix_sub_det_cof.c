/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_sub_det_cof.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:49 by fallan            #+#    #+#             */
/*   Updated: 2025/04/19 15:45:29 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* handle error cases for submatrix, returning 1 if:
	- NULL matrix as input
	- row or column count too small (< 2)

	returns 0 otherwise */
int	submatrix_errors(t_matrix mat)
{
	if (mat.rows < 2 || mat.columns < 2)
		return (1);
	return (0);
}

/* removes one specified row and one specified column from a matrix, and
returns the resulting matrix (input matrix isn't modified nor freed).

n.b.:
	- indexation of rows and columns starts at 0
	- function must be called with the submatrix initialized at right size
	i.e. init_matrix(mat->rows - 1, mat->columns - 1)
	- l++: advance by one column in the new matrix after writing
	- k++: advance by one row in the new matrix after writing a whole row */
void	submatrix(t_matrix mat, int row, int column, t_matrix *sub)
{
	int			i;
	int			j;
	int			k;
	int			l;

	if (submatrix_errors(mat))
		handle_error(SUBMATRIX, EINVAL, SUB_ERROR);
	i = -1;
	k = 0;
	while (++i < mat.rows)
	{
		j = -1;
		l = 0;
		while (++j < mat.columns)
		{
			if (i != row && j != column)
			{
				sub->m[k][l] = mat.m[i][j];
				l++;
			}
		}
		if (i != row)
			k++;
	}
}

/* computes and returns the minor (float) at i, j of an arbitrarily matrix,
using the submatrix at i,j (row, column), and computing its determinant */
float	matrix_minor(t_matrix mat, int row, int column)
{
	t_matrix	empty_submatrix;
	float		output;

	empty_submatrix = init_matrix(mat.rows - 1, mat.columns - 1);
	submatrix(mat, row, column, &empty_submatrix); //What if failure ?
	output = determinant(empty_submatrix);
	ft_free_float_tab(&(empty_submatrix).m, empty_submatrix.rows);
	return (output);
}

/* computes and returns the cofactor of a matrix, using matrix_minor */
float	matrix_cofactor(t_matrix mat, int row, int column)
{
	float	sign;

	if ((row + column) % 2)
		sign = -1;
	else
		sign = 1;
	return (matrix_minor(mat, row, column) * sign);
}

float	determinant(t_matrix mat)
{
	int		j;
	float	det;

	j = 0;
	det = 0.0;
	if (mat.rows == 2 && mat.columns == 2)
		return ((mat.m[0][0] * mat.m[1][1]) - (mat.m[0][1] * mat.m[1][0]));
	else
	{
		while (j < mat.columns)
		{
			det += mat.m[0][j] * matrix_cofactor(mat, 0, j);
			j++;
		}
	}
	return (det);
}
