/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_basic_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:55:56 by fallan            #+#    #+#             */
/*   Updated: 2025/03/13 11:51:02 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

/* multiplies 4x4 matrices (a * b) and returns the result
	returns
		-NULL for the following error cases:
			- a or b is NULL
			- matrices are not multipliable (a->columns != b->rows)
		
	How it works:
		- column k of the result matrix is the result of a dot product of each
		row of the left matrix with column k of the right matrix */
t_matrix	*matrix_multiplication(t_matrix *a, t_matrix *b)
{
	int			i;
	int			k;
	t_matrix	*res;

	if (!a || !b)
		return (handle_error(NULL_INPUT));
	if (a->columns != b->rows)
		return (NULL);
	res = init_matrix(a->rows, b->columns);
	if (!res)
		return (handle_error(MALLOC_FAIL));
	k = 0;
	while (k < b->columns)
	{
		i = -1;
		while (++i < a->rows)
			res->m[i][k]
				= (a->m[i][0] * b->m[0][k])
				+ (a->m[i][1] * b->m[1][k])
				+ (a->m[i][2] * b->m[2][k])
				+ (a->m[i][3] * b->m[3][k]);
		k++;
	}
	return (res);
}

/* initalizes and returns the transpose of a matrix of any size */
t_matrix	*matrix_transposition(t_matrix *mat)
{
	t_matrix	*transpose;
	int			i;
	int			j;

	if (!mat)
		return (handle_error(NULL_INPUT));
	transpose = init_matrix(mat->columns, mat->rows);
	if (!transpose)
		return (NULL);
	i = 0;
	while (i < mat->rows)
	{
		j = 0;
		while (j < mat->columns)
		{
			transpose->m[j][i] = mat->m[i][j];
			j++;
		}
		i++;
	}
	return (transpose);
}

t_matrix	*matrix_inversion(t_matrix *mat)
{
	t_matrix	*inv;
	int			i;
	int			j;
	float		det;

	det = determinant(mat);
	if (is_equal_float(det, 0))
		return (handle_error(MATRIX_NOT_INVERTIBLE));
	inv = init_matrix(mat->rows, mat->columns);
	if (!inv)
		return (NULL);
	i = 0;
	while (i < mat->rows)
	{
		j = 0;
		while (j < mat->columns)
		{
			inv->m[i][j] = matrix_cofactor(mat, j, i) / det;
			j++;
		}
		i++;
	}
	return (inv);
}

/* checks if two matrices are equal:
	- returns 0 (false) if:
		- one of the matrix is NULL, 
		- the matrices don't have same number of rows and matrices
		- any element of the matrices has a different value (a[i][j] != b[i][j])
	- return 1 (true) otherwise (the two matrices are found to be equal) */
int	matrix_equality(t_matrix *a, t_matrix *b)
{
	int	i;
	int	j;
	int	rows;
	int	columns;

	if (!a || !b)
		return (0);
	if (a->rows != b->rows || a->columns != b->columns)
		return (0);
	i = -1;
	rows = a->rows;
	columns = a->columns;
	while (++i < rows)
	{
		j = -1;
		while (++j < columns)
		{
			if (!is_equal_float(a->m[i][j], b->m[i][j]))
				return (0);
		}
	}
	return (1);
}
