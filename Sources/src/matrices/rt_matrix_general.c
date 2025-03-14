/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_general.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:04:56 by fallan            #+#    #+#             */
/*   Updated: 2025/03/14 14:30:09 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	*malloc_matrix_contents(t_matrix *mat, int rows, int columns)
{
	int	i;
	int	j;

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

/* initializes and returns an empty matrix (filled with 0s)
as a 2d array of floats, given number of rows and columns (mat [rows][cols])*/
t_matrix	*init_matrix(int rows, int columns)
{
	t_matrix	*mat;

	mat = malloc (sizeof(t_matrix));
	if (!mat)
		return (handle_error(MALLOC_FAIL));
	mat->rows = rows;
	mat->columns = columns;
	mat->m = malloc (rows * sizeof(float *));
	if (!mat->m)
		return (handle_error(MALLOC_FAIL));
	if (!malloc_matrix_contents(mat, rows, columns))
		return (NULL);
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
			printf(" %.6f |", mat->m[i][j]);
		}
		printf("\n");
		i++;
	}
	printf("---------------------------------------------\n");
	return (0);
}
