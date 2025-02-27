/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:04:56 by fallan            #+#    #+#             */
/*   Updated: 2025/02/27 16:51:44 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/miniRT.h"

/* initializes and returns an empty matrix (filled with 0s)
as a 2d array of floats, given number of rows and columns (matrix[rows][cols])*/
t_matrix	*init_matrix(int rows, int columns)
{
	int			i;
	int			j;
	t_matrix	*mat;

	mat = malloc (sizeof(t_matrix));
	if (!mat)
		return (handle_error(MALLOC_FAIL));
	mat->rows = rows;
	mat->columns = columns;
	mat->m = malloc (rows * sizeof(float *));
	if (!mat->m)
		return (handle_error(MALLOC_FAIL));
	i = 0;
	while (i < rows)
	{
		mat->m[i] = malloc (columns * sizeof(float));
		if (!mat->m[i])
			return (handle_error(MALLOC_FAIL));
		j = 0;
		while (j < columns)
		{
			mat->m[i][j] = 0;
			j++;
		}
		i++;
	}
	return (mat);
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
			if (a->m[i][j] != b->m[i][j])
				return (0);
		}
	}
	return (1);
}

/* initializes and returns tuple (no malloc) with given parameters x,y,z,w */
t_tuple	*init_tuple(float x, float y, float z, float w)
{
	t_tuple	*tuple;
	
	tuple = malloc(sizeof(t_tuple));
	if (!tuple)
		return (NULL);
	tuple->w = w;
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	return (tuple);
}

/* multiplies matrices (a * b) and returns the result
	returns -NULL for the following error cases:
		- a or b is NULL
		- matrices are not multipliable (a->columns != b->rows) */
t_matrix	*matrix_multiplication(t_matrix *a, t_matrix *b)
{
	int			i;
	int			k;
	t_matrix	*res;

	if (!a || !b)
		return (handle_error(MALLOC_FAIL));
	if (a->columns != b->rows) /* matrices not multipliable */
		return (0);
	
	res = init_matrix(4, 4);
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
	printf("-----------------------------\nmatrix multiplication result:\n-----------------------------\n");
	print_matrix(res);
	return (res);
}
