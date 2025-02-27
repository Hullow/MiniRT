/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:18:36 by fallan            #+#    #+#             */
/*   Updated: 2025/02/27 16:52:13 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/miniRT.h"

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

int	main()
{
	t_matrix	*mat;
	t_matrix	*mat2;
	t_matrix	*mat3;
	int			rows = 4;
	int			columns = 4;
	// int			i = 0;
	// int			j = -1;

	mat = init_matrix(rows, columns);
	mat2 = init_matrix(rows, columns);
	mat3 = init_matrix(rows, columns);
	if (!mat || !mat2 || !mat3)
		return (printf("init_matrix failed\n"));
	// while (i < rows)
	// {
	// 	j = -1;
	// 	while (++j < columns)
	// 		printf("mat[%d][%d]: %f\n", i, j, mat->m[i][j]);
	// 	i++;
	// }
	
// Example mat mul (from book p. 28)
	mat->m[0][0] = 1;
	mat->m[0][1] = 2;
	mat->m[0][2] = 3;
	mat->m[0][3] = 4;
	
	mat->m[1][0] = 5;
	mat->m[1][1] = 6;
	mat->m[1][2] = 7;
	mat->m[1][3] = 8;
	
	mat->m[2][0] = 9;
	mat->m[2][1] = 8;
	mat->m[2][2] = 7;
	mat->m[2][3] = 6;
	
	mat->m[3][0] = 5;
	mat->m[3][1] = 4;
	mat->m[3][2] = 3;
	mat->m[3][3] = 2;

	mat2->m[0][0] = -2;
	mat2->m[0][1] = 1;
	mat2->m[0][2] = 2;
	mat2->m[0][3] = 3;
	
	mat2->m[1][0] = 3;
	mat2->m[1][1] = 2;
	mat2->m[1][2] = 1;
	mat2->m[1][3] = -1;
	
	mat2->m[2][0] = 4;
	mat2->m[2][1] = 3;
	mat2->m[2][2] = 6;
	mat2->m[2][3] = 5;
	
	mat2->m[3][0] = 1;
	mat2->m[3][1] = 2;
	mat2->m[3][2] = 7;
	mat2->m[3][3] = 8;

	mat3->m[0][0] = -2;
	mat3->m[0][1] = 1;
	mat3->m[0][2] = 2;
	mat3->m[0][3] = 3;
	
	mat3->m[1][0] = 3;
	mat3->m[1][1] = 2;
	mat3->m[1][2] = 1;
	mat3->m[1][3] = -1;
	
	mat3->m[2][0] = 4;
	mat3->m[2][1] = 3;
	mat3->m[2][2] = 6;
	mat3->m[2][3] = 5;
	
	mat3->m[3][0] = 1;
	mat3->m[3][1] = 2;
	mat3->m[3][2] = 7;
	mat3->m[3][3] = 8;

	// print_matrix(mat);
	// print_matrix(mat2);
	// if (matrix_equality(mat, mat2))
	t_matrix	*mul_res = matrix_multiplication(mat2, identity_matrix(4, 4));
	if (matrix_equality(mul_res, mat3))
		printf("matrices are equal\n");
	else
		printf("matrices not equal\n");
	t_matrix	*mul_res2 = matrix_multiplication(identity_matrix(4, 4), mat2);
	if (matrix_equality(mul_res2, mat2))
		printf("matrices are equal\n");
	else
		printf("matrices not equal\n");
	return (0);
}


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

