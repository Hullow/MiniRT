/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:04:56 by fallan            #+#    #+#             */
/*   Updated: 2025/02/28 14:13:36 by fallan           ###   ########.fr       */
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

/* initializes and returns an identity matrix of size (rows, columns)*/
t_matrix	*identity_matrix(int rows, int columns)
{
	t_matrix	*mat;
	int			i;
	int			j;

	mat = init_matrix(rows, columns);
	if (!mat)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (i == j)
				mat->m[i][j] = 1;
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
			if (!is_equal_float(a->m[i][j], b->m[i][j]))
				return (0);
		}
	}
	printf("equal\n");
	return (1);
}

/* converts a tuple to a 1x4 matrix (4 rows, 1 column) */
t_matrix	*convert_tuple_to_matrix(t_tuple *tuple)
{
	t_matrix	*mat;

	if (!tuple)
		return (handle_error(NULL_INPUT));
	mat = init_matrix(4, 1);
	if (!mat)
		return (NULL);
	mat->m[0][0] = tuple->x;
	mat->m[1][0] = tuple->y;
	mat->m[2][0] = tuple->z;
	mat->m[3][0] = tuple->w;
	return (mat);
}

/* prints out all the values of a matrix */
int	print_matrix(t_matrix *mat)
{
	int	i;
	int	j;

	i = 0;
	if (!mat)
		return (-1);
	printf("Printing out matrix at address {%p}\n", mat);
	printf("---------------------------------------------\n");
	while (i < mat->rows)
	{
		j = -1;
		printf("|");
		while (++j < mat->columns)
		{
			if (mat->m[i][j] >= 0.0)
				printf(" ");
			printf(" %.2f |", mat->m[i][j]);
		}
		printf("\n");
		i++;
	}
	printf("---------------------------------------------\n");
	return (0);
}
