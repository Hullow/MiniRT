/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_general.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:04:56 by fallan            #+#    #+#             */
/*   Updated: 2025/03/24 15:18:57 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* initializes and returns an empty matrix (filled with 0s)
as a 2d array of floats, given number of rows and columns (mat [rows][cols])

How it works:
- Mallocs the matrix struct (t_matrix)
- Sets the number of rows and columns (from the arguments rows, columns)
- Mallocs the matrix rows as an array of arrays of floats ((float *) mat->m)
- Calls malloc_matrix_columns to malloc the columns as arrays of floats,
and initialize the value of each matrix element to 0

Returns: a pointer to the initialized matrix (t_matrix *)
*/
t_matrix	*init_matrix(int rows, int columns)
{
	t_matrix	*mat;

	mat = malloc (sizeof(t_matrix));
	if (!mat)
		return (handle_error(INIT_MATRIX, ENOMEM, "malloc fail")); // remove "malloc fail" ?
	mat->rows = rows;
	mat->columns = columns;
	mat->m = malloc (rows * sizeof(float *));
	if (!mat->m)
		return (handle_error(INIT_MATRIX, ENOMEM, "malloc fail")); // remove "malloc fail" ?
	if (!malloc_matrix_columns(mat, rows, columns))
		return (handle_error(INIT_MATRIX, ENOMEM, NULL));
	return (mat);
}

/* mallocs matrix columns (called from init_matrix),
and initialize all values to 0 */
t_matrix	*malloc_matrix_columns(t_matrix *mat, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		mat->m[i] = malloc (columns * sizeof(float));
		if (!mat->m[i])
			return (handle_error(MAT_MALLOC, ENOMEM, "malloc fail")); // remove "malloc fail" ?
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
		return (handle_error(ID_MATRIX, ENOMEM, NULL));
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

/* converts a tuple to a 1x4 matrix (4 rows, 1 column) */
t_matrix	*convert_tuple_to_matrix(t_tuple *tuple)
{
	t_matrix	*mat;

	if (!tuple)
		return (handle_error(CONV_TUP_MAT, EINVAL, "null input"));
	mat = init_matrix(4, 1);
	if (!mat)
		return (handle_error(CONV_TUP_MAT, ENOMEM, NULL));
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
			printf(" %.6f |", mat->m[i][j]);
		}
		printf("\n");
		i++;
	}
	printf("---------------------------------------------\n");
	return (0);
}
