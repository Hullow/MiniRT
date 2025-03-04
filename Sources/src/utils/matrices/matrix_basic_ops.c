/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_basic_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:55:56 by fallan            #+#    #+#             */
/*   Updated: 2025/03/04 19:58:57 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/miniRT.h"

/* multiplies 4x4 matrices (a * b) and returns the result
	returns -NULL for the following error cases:
		- a or b is NULL
		- matrices are not multipliable (a->columns != b->rows) */
t_matrix	*matrix_multiplication(t_matrix *a, t_matrix *b)
{
	int			i;
	int			k;
	t_matrix	*res;

	if (!a || !b)
		return (handle_error(NULL_INPUT));
	if (a->columns != b->rows) /* matrices not multipliable */
		return (NULL);
	res = init_matrix(a->rows, b->columns);
	if (!res)
		return (handle_error(MALLOC_FAIL));
	/* column k of the result matrix is the result of 
	a dot product of each row of the left matrix with column k of the right matrix */
	k = 0;
	while (k < b->columns)
	{
		i = -1;
		while (++i < a->rows)
			res->m[i][k] =
			(a->m[i][0] * b->m[0][k]) +
			(a->m[i][1] * b->m[1][k]) +
			(a->m[i][2] * b->m[2][k]) +
			(a->m[i][3] * b->m[3][k]);
		k++;
	}
	// printf("input matrix a:\n");
	// print_matrix(a);
	// printf("input matrix b:\n");
	// print_matrix(b);
	// printf("-----------------------------\nmatrix multiplication result:\n-----------------------------\n");
	// print_matrix(res);
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
	// printf("*******************************original matrix:\n*******************************");
	// print_matrix(mat);
	// printf("*******************************transposed matrix:\n*******************************");
	// print_matrix(transpose);
	return (transpose);
}

/* computes and returns (as an int) the determinant of a 2x2 matrix */
int	determinant(t_matrix *mat)
{
	if (!mat)
	{
		handle_error(NULL_INPUT);
		return (-1);
	}
	if (mat->columns != 2 || mat->rows != 2)
	{
		handle_error(INVALID_MATRIX_SIZE);
		return (-1);
	}
	return ((mat->m[0][0] * mat->m[1][1]) - (mat->m[0][1] * mat->m[1][0]));
}

/* handle error cases for submatrix, returning 1 if:
	- NULL matrix as input
	- row or column count too small (< 2)

	returns 0 otherwise */
int	submatrix_errors(t_matrix *mat, t_matrix *sub)
{
	if (!mat || !sub)
		return (1);
	if (mat->rows < 2 || mat->columns < 2)
		return (1);
	return (0);
}

/* removes one specified row and one specified column from a matrix, and
returns the resulting matrix (input matrix isn't modified nor freed).

n.b.:
	- indexation of rows and columns starts at 0
	- function must be called with the submatrix initialized at right size
	i.e. init_matrix(mat->rows - 1, mat->columns - 1) */
t_matrix	*submatrix(t_matrix *mat, int row, int column, t_matrix *sub)
{
	int			i;
	int			j;
	int			k;
	int			l;

	if (submatrix_errors(mat, sub))
		return (NULL);
	i = -1;
	k = 0;
	while (++i < mat->rows)
	{
		j = -1;
		l = 0;
		while (++j < mat->columns)
		{
			if (i != row && j != column)
			{
				sub->m[k][l] = mat->m[i][j];
				l++; /* advance by one column in the new matrix after writing */
			}
		}
		if (i != row)
			k++; /* advance by one row in the new matrix after writing a whole row */
	}
	// printf("submatrix: removing row %d and column %d from:\n*********************\n", row, column);
	// print_matrix(mat);
	// printf("result:\n*********************\n");
	// print_matrix(sub);
	return (sub);
}

/* computes and returns the minor (float) at i, j of a 3x3 matrix,
using the submatrix at i,j (row, column), and computing its determinant */
float	matrix_minor(t_matrix *mat, int row, int column)
{
	return (determinant(submatrix(mat, row, column, init_matrix(2, 2))));
}

/* computes and returns the cofactor of a 3x3 matrix, using matrix_minor */
float	matrix_cofactor(t_matrix *mat, int row, int column)
{
	float	sign;
	
	if ((row + column) % 2)
		sign = -1;
	else  // [0, 0], [2, 0], [1, 1], [2, 0], [2, 2] => % 2 == 0 => false
		sign = 1;
	return (matrix_minor(mat, row, column) * sign);
}

float	determinant_general(t_matrix *mat)
{
	float	det;
	int		i;
	int		j;

	det = 0;
	if (mat->rows >= mat->columns)
	{
		i = 0;
		printf("going via rows\n");
		while (i < mat->rows)
		{
			det += mat->m[i][0] * matrix_cofactor(mat, i, 0);
			i++;
		}
	}
	else
	{
		j = 0;
		printf("going via columns\n");
		while (j < mat->columns)
		{
			det += mat->m[0][j] * matrix_cofactor(mat, 0, j);
			j++;
		}
	}
	printf("matrix_det_3: %f\n", det);
	return (det);
}





























/* 
t_matrix	*matrix_inversion(t_matrix *mat)
{
	t_matrix	*inverse;

	inverse = init_matrix()
	return (inverse);
} */