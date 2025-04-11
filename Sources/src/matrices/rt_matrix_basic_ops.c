/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_basic_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:55:56 by fallan            #+#    #+#             */
/*   Updated: 2025/04/11 12:13:38 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
		return (handle_error(MAT_MUL, EINVAL, "NULL matrix"));
	if (a->columns != b->rows)
		return (handle_error(MAT_MUL, EINVAL, "matrices not multipliable"));
	res = init_matrix(a->rows, b->columns);
	if (!res)
		return (handle_error(MAT_MUL, ENOMEM, NULL));
		
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

t_tuple		*matrix_tuple_multiplication(t_matrix *m, t_tuple *t)
{
	t_tuple *res;

	if (!m || !t)
		return (handle_error(MAT_TUP_MUL, EINVAL, "null input"));
	if (m->columns != 4 || m->rows != 4)
		return (handle_error(MAT_TUP_MUL, EINVAL, "matrix is not 4x4"));
	// if (t->w == POINT)
	// 	res->w = POINT;
	// else if (t->w == VECTOR)
	// 	res->w = VECTOR;
	res = rt_point(0, 0, 0);
	res->x = (m->m[0][0] * t->x) + (m->m[0][1] * t->y) 
	+ (m->m[0][2] * t->z) + (m->m[0][3] * t->w);
	res->y = (m->m[1][0] * t->x) + (m->m[1][1] * t->y) 
	+ (m->m[1][2] * t->z) + (m->m[1][3] * t->w);
	res->z = (m->m[2][0] * t->x) + (m->m[2][1] * t->y) 
	+ (m->m[2][2] * t->z) + (m->m[2][3] * t->w);
	res->w = (m->m[3][0] * t->x) + (m->m[3][1] * t->y) 
	+ (m->m[3][2] * t->z) + (m->m[3][3] * t->w);
// 	printf("matrix_tuple_multiplication:\n");
// 	print_matrix(m);
// 	printf("multiplying:\ninput tuple {x: %3.f, y: %3.f, z: %3.f, w: %3.f}\n", t->x, t->y, t->z, t->w);
// 	printf("gives us output tuple {x: %3.f, y: %3.f, z: %3.f, w: %3.f}\n", res->x, res->y, res->z, res->w);
	return (res);
}

/* initalizes and returns the transpose of a matrix of any size */
t_matrix	*matrix_transposition(t_matrix *mat)
{
	t_matrix	*transpose;
	int			i;
	int			j;

	if (!mat)
		return (handle_error(MAT_TRANSP, EINVAL, "null input"));
	transpose = init_matrix(mat->columns, mat->rows);
	if (!transpose)
		return (handle_error(MAT_TRANSP, ENOMEM, NULL));
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

	// printf("matrix inversion: mat address before: %p --- ", mat);
	det = determinant(mat);
	if (is_equal_float(det, 0))
		return (handle_error(MAT_INV, EINVAL, "matrix not invertible\
			(determinant == 0)"));
	inv = init_matrix(mat->rows, mat->columns);
	if (!inv)
		return (handle_error(MAT_INV, ENOMEM, NULL));
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
	// printf("mat address after: %p --- and inv address: %p\n", mat, inv);
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
