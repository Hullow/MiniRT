/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:18:36 by fallan            #+#    #+#             */
/*   Updated: 2025/04/20 21:47:29 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// add .c to the end of the file and compile with 
// `gcc -Wall -Wextra -Werror *.c ../utils/rt_utils.c ../tuples/*tuple*.c -lm` to run the tests

void	test_matrices(void)
{
	// test_identity();
	// test_mat_multiplication();
	// test_mat_tuple_multiplication();
	// test_matrix_inversion();
	// test_determinant_2x2();
	// test_determinant_4x4();
	// test_determinant_3x3();
	// test_cofactor();
	// test_minor();
	// test_submatrix();
	// test_tuple_to_mat_conv_and_diff_size_mat_mul();
	 test_transposition();
}

void	test_mat_tuple_multiplication()
{
	t_matrix m = init_matrix(4, 4);
	mat_val_init(m, (t_matrix) {0, 0, NULL}, (t_matrix) {0, 0, NULL});
	print_matrix(convert_tuple_to_matrix(matrix_tuple_multiplication(m, rt_point(1, 2, 3))));
	/*printf("\nNow compare:\n**********\n");
	print_matrix(matrix_multiplication(m, convert_tuple_to_matrix(rt_point(5, 5, 5))));*/
}

/* test values for three matrices */
void	mat_val_init(t_matrix mat, t_matrix mat2, t_matrix mat3)
{
	if (mat.m)
	{
		mat.m[0][0] = 1;
		mat.m[0][1] = 2;
		mat.m[0][2] = 3;
		mat.m[0][3] = 4;
		
		mat.m[1][0] = 2;
		mat.m[1][1] = 4;
		mat.m[1][2] = 4;
		mat.m[1][3] = 2;
		
		mat.m[2][0] = 8;
		mat.m[2][1] = 6;
		mat.m[2][2] = 4;
		mat.m[2][3] = 1;
		
		mat.m[3][0] = 0;
		mat.m[3][1] = 0;
		mat.m[3][2] = 0;
		mat.m[3][3] = 1;
	}
	print_matrix(mat);

	if (mat2.m)
	{
		mat2.m[0][0] = -2;
		mat2.m[0][1] = 1;
		mat2.m[0][2] = 2;
		mat2.m[0][3] = 3;
		
		mat2.m[1][0] = 3;
		mat2.m[1][1] = 2;
		mat2.m[1][2] = 1;
		mat2.m[1][3] = -1;
		
		mat2.m[2][0] = 4;
		mat2.m[2][1] = 3;
		mat2.m[2][2] = 6;
		mat2.m[2][3] = 5;
		
		mat2.m[3][0] = 1;
		mat2.m[3][1] = 2;
		mat2.m[3][2] = 7;
		mat2.m[3][3] = 8;
	}
	if (mat3.m)
	{	
		mat3.m[0][0] = -2;
		mat3.m[0][1] = 1;
		mat3.m[0][2] = 2;
		mat3.m[0][3] = 3;
		
		mat3.m[1][0] = 3;
		mat3.m[1][1] = 2;
		mat3.m[1][2] = 1;
		mat3.m[1][3] = -1;
		
		mat3.m[2][0] = 4;
		mat3.m[2][1] = 3;
		mat3.m[2][2] = 6;
		mat3.m[2][3] = 5;
		
		mat3.m[3][0] = 1;
		mat3.m[3][1] = 2;
		mat3.m[3][2] = 7;
		mat3.m[3][3] = 8;
	}
}

void	test_identity()
{
	print_matrix(matrix_multiplication(identity_matrix(4, 4), convert_tuple_to_matrix(rt_point(4, 5, 6))));
	t_matrix id = identity_matrix(4, 4);
	//id.m[1][1] = 4;
	print_matrix(matrix_multiplication(id, convert_tuple_to_matrix(rt_point(4, 5, 6))));
	print_matrix(id);
}

void	test_matrix_inversion()
{
	t_matrix mat = init_matrix(4, 4);
	mat.m[0][0] = -5;
	mat.m[0][1] = 2;
	mat.m[0][2] = 6;
	mat.m[0][3] = -8;
	mat.m[1][0] = 1;
	mat.m[1][1] = -5;
	mat.m[1][2] = 1;
	mat.m[1][3] = 8;
	mat.m[2][0] = 7;
	mat.m[2][1] = 7;
	mat.m[2][2] = -6;
	mat.m[2][3] = -7;
	mat.m[3][0] = 1;
	mat.m[3][1] = -3;
	mat.m[3][2] = 7;
	mat.m[3][3] = 4;
	t_matrix mat2 = init_matrix(4, 4);
	mat2.m[0][0] = -4;
	mat2.m[0][1] = 2;
	mat2.m[0][2] = -2;
	mat2.m[0][3] = -3;
	mat2.m[1][0] = 9;
	mat2.m[1][1] = 6;
	mat2.m[1][2] = 2;
	mat2.m[1][3] = 6;
	mat2.m[2][0] = 0;
	mat2.m[2][1] = -5;
	mat2.m[2][2] = 1;
	mat2.m[2][3] = -5;
	mat2.m[3][0] = 0;
	mat2.m[3][1] = 0;
	mat2.m[3][2] = 0;
	mat2.m[3][3] = 0;
	/*t_matrix mat3 = init_matrix(4, 4);
	mat3.m[0][0] = 9;
	mat3.m[0][1] = 3;
	mat3.m[0][2] = 0;
	mat3.m[0][3] = 9;
	mat3.m[1][0] = -5;
	mat3.m[1][1] = -2;
	mat3.m[1][2] = -6;
	mat3.m[1][3] = -3;
	mat3.m[2][0] = -4;
	mat3.m[2][1] = 9;
	mat3.m[2][2] = 6;
	mat3.m[2][3] = 4;
	mat3.m[3][0] = -7;
	mat3.m[3][1] = 6;
	mat3.m[3][2] = 6;
	mat3.m[3][3] = 2;*/
	 t_matrix inv = matrix_inversion(mat);
	 t_matrix inv2 = matrix_inversion(mat2);
	 print_matrix(inv);
	 print_matrix(inv2);
	// print_matrix(inv3);
	// print_matrix(mat2);
	t_matrix transpose_inverse = matrix_transposition(matrix_inversion(mat));
	t_matrix inverse_transpose = matrix_inversion(matrix_transposition(mat));
	print_matrix(transpose_inverse);
	print_matrix(inverse_transpose);
}

void	test_determinant_4x4()
{
	t_matrix mat = init_matrix(4, 4);
	mat.m[0][0] = -2;
	mat.m[0][1] = -8;
	mat.m[0][2] = 3;
	mat.m[0][3] = 5;
	mat.m[1][0] = -3;
	mat.m[1][1] = 1;
	mat.m[1][2] = 7;
	mat.m[1][3] = 3;
	mat.m[2][0] = 1;
	mat.m[2][1] = 2;
	mat.m[2][2] = -9;
	mat.m[2][3] = 6;
	mat.m[3][0] = -6;
	mat.m[3][1] = 7;
	mat.m[3][2] = 7;
	mat.m[3][3] = -9;
	printf("is this the det of the 4x4 matrix ? %f\n", determinant(mat));
}

void	test_determinant_3x3()
{
	t_matrix mat = init_matrix(3, 3);
	mat.m[0][0] = 1;
	mat.m[0][1] = 2;
	mat.m[0][2] = 6;
	mat.m[1][0] = -5;
	mat.m[1][1] = 8;
	mat.m[1][2] = -4;
	mat.m[2][0] = 2;
	mat.m[2][1] = 6;
	mat.m[2][2] = 4;
	printf("is this the det of the 3x3 matrix ? %f\n", determinant(mat));
}

void	test_cofactor()
{
	t_matrix mat = init_matrix(3, 3);
	mat.m[0][0] = 3;
	mat.m[0][1] = 5;
	mat.m[0][2] = 0;
	mat.m[1][0] = 2;
	mat.m[1][1] = -1;
	mat.m[1][2] = -7;
	mat.m[2][0] = 6;
	mat.m[2][1] = -1;
	mat.m[2][2] = 5;
	printf("cofactor(1, 0) of matrix is %f\n", matrix_cofactor(mat, 1, 0));
}

void	test_minor()
{
	t_matrix mat = init_matrix(3, 3);
	mat.m[0][0] = 3;
	mat.m[0][1] = 5;
	mat.m[0][2] = 0;
	mat.m[1][0] = 2;
	mat.m[1][1] = -1;
	mat.m[1][2] = -7;
	mat.m[2][0] = 6;
	mat.m[2][1] = -1;
	mat.m[2][2] = 5;
	printf("minor (1, 0) of matrix is %f\n", matrix_minor(mat, 1, 0));

}

void	test_determinant_2x2()
{
	t_matrix	mat = init_matrix(2, 2);
	mat.m[0][0] = 1;
	mat.m[0][1] = 5;
	mat.m[1][0] = -3;
	mat.m[1][1] = 2;
	printf("is this the determinant of the 2x2 matrix ? %f\n", determinant(mat));
}

void	test_submatrix()
{
	t_matrix	mat = init_matrix(4, 4);
	//mat_val_init(mat, (t_matrix) {0, 0, NULL}, (t_matrix) {0, 0, NULL});
	mat.m[0][0] = -6;
	mat.m[0][1] = 1;
	mat.m[0][2] = 1;
	mat.m[0][3] = 6;
	
	mat.m[1][0] = -8;
	mat.m[1][1] = 5;
	mat.m[1][2] = 8;
	mat.m[1][3] = 6;
	
	mat.m[2][0] = -1;
	mat.m[2][1] = 0;
	mat.m[2][2] = 8;
	mat.m[2][3] = 2;
	
	mat.m[3][0] = -7;
	mat.m[3][1] = 1;
	mat.m[3][2] = -1;
	mat.m[3][3] = 1;

	t_matrix sub3 = submatrix(mat, 2, 1, init_matrix(mat.rows - 1, mat.columns - 1));
	print_matrix(sub3);
	//t_matrix sub2 = submatrix(sub3, 1, 2, init_matrix(sub3.rows - 1, sub3.columns - 1));
	//t_matrix sub1 = submatrix(sub2, 0, 1, init_matrix(sub2.rows - 1, sub2.columns - 1));
	//submatrix(sub1, 0, 0, init_matrix(sub2.rows - 1, sub3.columns - 1));
}

void	test_tuple_to_mat_conv_and_diff_size_mat_mul()
{
	t_matrix mat = convert_tuple_to_matrix(rt_point(1, 2, 3));
	print_matrix(mat);
	print_matrix(matrix_multiplication(identity_matrix(4, 4), mat));
}

void	test_mat_multiplication()
{
	int	rows = 4;
	int	columns = 4;
	
	//t_matrix	mat;
	// t_matrix	mat2;
	//t_matrix	mat3;
	//mat = init_matrix(rows, columns);
	t_matrix mat = init_matrix(rows, columns);
	mat.m[0][0] = 1;
	mat.m[0][1] = 2;
	mat.m[0][2] = 3;
	mat.m[0][3] = 4;
	mat.m[1][0] = 5;
	mat.m[1][1] = 6;
	mat.m[1][2] = 7;
	mat.m[1][3] = 8;
	mat.m[2][0] = 9;
	mat.m[2][1] = 8;
	mat.m[2][2] = 7;
	mat.m[2][3] = 6;
	mat.m[3][0] = 5;
	mat.m[3][1] = 4;
	mat.m[3][2] = 3;
	mat.m[3][3] = 2;
	
	t_matrix mat2 = init_matrix(rows, columns);
	mat2.m[0][0] = -2;
	mat2.m[0][1] = 1;
	mat2.m[0][2] = 2;
	mat2.m[0][3] = 3;
	mat2.m[1][0] = 3;
	mat2.m[1][1] = 2;
	mat2.m[1][2] = 1;
	mat2.m[1][3] = -1;
	mat2.m[2][0] = 4;
	mat2.m[2][1] = 3;
	mat2.m[2][2] = 6;
	mat2.m[2][3] = 5;
	mat2.m[3][0] = 1;
	mat2.m[3][1] = 2;
	mat2.m[3][2] = 7;
	mat2.m[3][3] = 8;
	//mat2 = init_matrix(rows, columns);
	//mat2 = identity_matrix(rows, columns);
	if (!mat.m || !mat2.m /*|| !mat3.m*/)
	{
		printf("init_matrix failed\n");
		return;
	}
	print_matrix(mat);
	print_matrix(mat2);
	t_matrix	mul_res = matrix_multiplication(mat, mat2);
	print_matrix(mul_res);
	/*if (matrix_equality(mul_res, mat3))
		printf("matrices are equal\n");
	else
		printf("matrices not equal\n");
	t_matrix	mul_res2 = matrix_multiplication(identity_matrix(4, 4), mat2);
	if (matrix_equality(mul_res2, mat2))
		printf("matrices are equal\n");
	else
		printf("matrices not equal\n");*/
}

void	test_transposition()
{
	t_matrix mat = init_matrix(4, 4);
	//mat_val_init(mat, (t_matrix) {0, 0, NULL}, (t_matrix) {0, 0, NULL});
	mat.m[0][0] = 0;
	mat.m[0][1] = 9;
	mat.m[0][2] = 3;
	mat.m[0][3] = 0;
	mat.m[1][0] = 9;
	mat.m[1][1] = 8;
	mat.m[1][2] = 0;
	mat.m[1][3] = 8;
	mat.m[2][0] = 1;
	mat.m[2][1] = 8;
	mat.m[2][2] = 5;
	mat.m[2][3] = 3;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 5;
	mat.m[3][3] = 8;
	
	print_matrix(matrix_transposition(mat));
}
