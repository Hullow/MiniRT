#include "miniRT.h"

void	test_tuples()
{	
	t_tuple	point;
	t_tuple	vector;

	printf("Point vector\n");
	point = rt_point(4.3, -4.2, 3.1);
	rt_print_tuple(point);
	vector = rt_vector(4.3, -4.2, 3.1);
	rt_print_tuple(vector);
	printf("\n");

	printf("add tuples\n");
	t_tuple	add_tuple;

	point = rt_point(3, -2, 5);
	vector = rt_vector(-2, 3, 1);
	add_tuple = rt_add_tuple(point, vector);
	rt_print_tuple(add_tuple);
	printf("\n");

	printf("sub points\n");
	t_tuple	point2;
	t_tuple	sub_points;

	point = rt_point(3, 2, 1);
	point2 = rt_point(5, 6, 7);
	sub_points = rt_sub_tuple(point, point2);
	rt_print_tuple(sub_points);
	printf("\n");

	printf("sub vector to point\n");
	t_tuple	sub_pt_vr;

	vector = rt_vector(5, 6, 7);
	sub_pt_vr = rt_sub_tuple(point, vector);
	rt_print_tuple(sub_pt_vr);
	printf("\n");

	printf("sub vectors\n");
	t_tuple	vector2;
	t_tuple	sub_vects;

	vector = rt_vector(3, 2, 1);
	vector2 = rt_vector(5, 6, 7);
	sub_vects = rt_sub_tuple(vector, vector2);
	rt_print_tuple(sub_vects);
	printf("\n");

	printf("Zero vector negation\n");
	vector = rt_vector(1, -2, 3);
	sub_vects = rt_sub_tuple(rt_vector(0, 0, 0), vector);
	rt_print_tuple(sub_vects);
	printf("Negate tuple\n");
	vector = rt_negate_vector(vector);
	rt_print_tuple(vector);
	printf("\n");
	
	printf("Scale tuple\n");
	t_tuple	scale;
	float	scalar;

	vector = rt_vector(1, -2, 3);
	scalar = 3.5f;
	scale = rt_scale_vector(vector, scalar);
	printf("Scale by %f = ", scalar);
	rt_print_tuple(scale);
	scalar = 1.0f / 2.0f;
	scale = rt_scale_vector(vector, scalar);
	printf("Scale by %f = ", scalar);
	rt_print_tuple(scale);
	printf("Divide tuple\n");
	scalar = 2.0f;
	scale = rt_divide_tuple(vector, scalar);
	printf("Divide by %f = ", scalar);
	rt_print_tuple(scale);
	printf("\n");

	printf("Magnitude\n");
	vector = rt_vector(1, 0, 0);
	printf("magnitude %f\n", rt_magnitude(vector));
	vector = rt_vector(0, 1, 0);
	printf("magnitude %f\n", rt_magnitude(vector));
	vector = rt_vector(0, 0, 1);
	printf("magnitude %f\n", rt_magnitude(vector));
	vector = rt_vector(1, 2, 3);
	printf("magnitude %f\n", rt_magnitude(vector));
	vector = rt_vector(-1, -2, -3);
	printf("magnitude %f\n", rt_magnitude(vector));
	printf("Reference for sqrtf(14) = %f\n\n", sqrtf(14));
	printf("\n");

	printf("Normal\n");
	t_tuple	norm;

	vector = rt_vector(4, 0, 0);
	norm = rt_normalize(vector);
	rt_print_tuple(norm);
	vector = rt_vector(1, 2, 3);
	norm = rt_normalize(vector);
	rt_print_tuple(norm);
	printf("magnitude of normal = %f\n\n", rt_magnitude(norm));

	printf("Dot product\n");
	vector = rt_vector(1, 2, 3);
	vector2 = rt_vector(2, 3, 4);
	printf("dot product = %f\n\n", rt_dot_product(vector, vector2));

	printf("Cross product\n");
	t_tuple	cross;

	cross = rt_cross_product(vector, vector2);
	printf("cross product vector(a) vector(b) = ");
	rt_print_tuple(cross);
	cross = rt_cross_product(vector2, vector);
	printf("cross product vector(b) vector(a) = ");
	rt_print_tuple(cross);
	printf("\n");

	printf("Add Colors\n");
	t_tuple	color;
	t_tuple	color2;
	t_tuple	add_color;

	color = rt_color(0.9f * 255.0f, 0.6f * 255.0f, 0.75f * 255.0f);
	color2 = rt_color(0.7f * 255.0f, 0.1f * 255.0f, 0.25f * 255.0f);
	add_color = rt_add_color(color, color2);
	rt_print_tuple(add_color);

	printf("Sub Colors\n");
	t_tuple	sub_color;

	sub_color = rt_sub_color(color, color2);
	rt_print_tuple(sub_color);

	printf("Scale Color\n");
	t_tuple	scal_color;

	color = rt_color(0.2f * 255.0f, 0.3f * 255.0f, 0.4f * 255.0f);
	scalar = 2.0f;
	scal_color = rt_scale_color(color, scalar);
	rt_print_tuple(scal_color);

	printf("Multiply Colors\n");
	t_tuple	mul_color;

	color = rt_color(1.0f * 255.0f, 0.2f * 255.0f, 0.4f * 255.0f);
	color2 = rt_color(0.9f * 255.0f, 1.0f * 255.0f, 0.1f * 255.0f);
	mul_color = rt_mul_color(color, color2);
	rt_print_tuple(mul_color);
}

void	test_matrix()
{
// 	printf("Matrix equality\n");
	t_matrix	matrix;
	t_matrix	matrix2;
// 	int			equal;
	
// 	matrix.rows = 2;
// 	matrix.columns = 2;
// 	matrix.cell[0][0] = 1;
// 	matrix.cell[0][1] = 3;
// 	matrix.cell[1][0] = 5.5f;
// 	matrix.cell[1][1] = 6.5f;
// 	matrix2.rows = 2;
// 	matrix2.columns = 2;
// 	matrix2.cell[0][0] = 1;
// 	matrix2.cell[0][1] = 2;
// 	matrix2.cell[1][0] = 5.5f;
// 	matrix2.cell[1][1] = 6.5f;

// 	equal = rt_matrix_equality(matrix, matrix2);
// 	if (equal)
// 		printf("matrices are equal\n\n");
// 	else
// 		printf("matrices are not equal\n\n");

// 	printf("Matrix multiplication\n");
	t_matrix	m_mul;

// 	matrix.rows = 4;
// 	matrix.columns = 4;
// 	matrix.cell[0][0] = 1;
// 	matrix.cell[0][1] = 2;
// 	matrix.cell[0][2] = 3;
// 	matrix.cell[0][3] = 4;
// 	matrix.cell[1][0] = 5;
// 	matrix.cell[1][1] = 6;
// 	matrix.cell[1][2] = 7;
// 	matrix.cell[1][3] = 8;
// 	matrix.cell[2][0] = 9;
// 	matrix.cell[2][1] = 8;
// 	matrix.cell[2][2] = 7;
// 	matrix.cell[2][3] = 6;
// 	matrix.cell[3][0] = 5;
// 	matrix.cell[3][1] = 4;
// 	matrix.cell[3][2] = 3;
// 	matrix.cell[3][3] = 2;
// 	matrix2.rows = 4;
// 	matrix2.columns = 4;
// 	matrix2.cell[0][0] = -2;
// 	matrix2.cell[0][1] = 1;
// 	matrix2.cell[0][2] = 2;
// 	matrix2.cell[0][3] = 3;
// 	matrix2.cell[1][0] = 3;
// 	matrix2.cell[1][1] = 2;
// 	matrix2.cell[1][2] = 1;
// 	matrix2.cell[1][3] = -1;
// 	matrix2.cell[2][0] = 4;
// 	matrix2.cell[2][1] = 3;
// 	matrix2.cell[2][2] = 6;
// 	matrix2.cell[2][3] = 5;
// 	matrix2.cell[3][0] = 1;
// 	matrix2.cell[3][1] = 2;
// 	matrix2.cell[3][2] = 7;
// 	matrix2.cell[3][3] = 8;

// 	m_mul = rt_mul_matrix(matrix, matrix2);
// 	rt_print_matrix(m_mul);
// 	printf("\n");

// 	printf("Matrix tuple multiplication\n");
// 	t_tuple	tuple;
// 	t_tuple	m_tuple;

// 	tuple = rt_point(1, 2, 3);
// 	matrix.cell[0][0] = 1;
// 	matrix.cell[0][1] = 2;
// 	matrix.cell[0][2] = 3;
// 	matrix.cell[0][3] = 4;
// 	matrix.cell[1][0] = 2;
// 	matrix.cell[1][1] = 4;
// 	matrix.cell[1][2] = 4;
// 	matrix.cell[1][3] = 2;
// 	matrix.cell[2][0] = 8;
// 	matrix.cell[2][1] = 6;
// 	matrix.cell[2][2] = 4;
// 	matrix.cell[2][3] = 1;
// 	matrix.cell[3][0] = 0;
// 	matrix.cell[3][1] = 0;
// 	matrix.cell[3][2] = 0;
// 	matrix.cell[3][3] = 1;
// 	m_tuple = rt_mul_tuple_matrix(matrix, tuple);
// 	rt_print_tuple(m_tuple);
// 	printf("\n");

// 	printf("Identity matrix\n");
	
	matrix = rt_identity_matrix();
	matrix2 = rt_identity_matrix();
	// matrix2.cell[0][0] = 0;
	// matrix2.cell[0][1] = 1;
	// matrix2.cell[0][2] = 2;
	// matrix2.cell[0][3] = 4;
	// matrix2.cell[1][0] = 1;
	// matrix2.cell[1][1] = 2;
	// matrix2.cell[1][2] = 4;
	// matrix2.cell[1][3] = 8;
	// matrix2.cell[2][0] = 2;
	// matrix2.cell[2][1] = 4;
	// matrix2.cell[2][2] = 8;
	// matrix2.cell[2][3] = 16;
	// matrix2.cell[3][0] = 4;
	// matrix2.cell[3][1] = 8;
	// matrix2.cell[3][2] = 16;
	// matrix2.cell[3][3] = 32;
// 	m_mul = rt_mul_matrix(matrix, matrix2);
// 	rt_print_matrix(m_mul);
// 	m_tuple = rt_mul_tuple_matrix(matrix, tuple);
// 	rt_print_tuple(m_tuple);
// 	printf("\n");

// 	printf("Transpose\n");
// 	t_matrix transp;

// 	matrix.cell[0][0] = 0;
// 	matrix.cell[0][1] = 9;
// 	matrix.cell[0][2] = 3;
// 	matrix.cell[0][3] = 0;
// 	matrix.cell[1][0] = 9;
// 	matrix.cell[1][1] = 8;
// 	matrix.cell[1][2] = 0;
// 	matrix.cell[1][3] = 8;
// 	matrix.cell[2][0] = 1;
// 	matrix.cell[2][1] = 8;
// 	matrix.cell[2][2] = 5;
// 	matrix.cell[2][3] = 3;
// 	matrix.cell[3][0] = 0;
// 	matrix.cell[3][1] = 0;
// 	matrix.cell[3][2] = 5;
// 	matrix.cell[3][3] = 8;
// 	transp = rt_matrix_transpose(matrix);
// 	rt_print_matrix(transp);
// 	printf("Transpose identity\n");
// 	transp = rt_identity_matrix();
// 	rt_print_matrix(transp);
// 	printf("\n");

	printf("Matrix inversion\n");

	// matrix.rows = 2;
	// matrix.columns = 2;
	// matrix.cell[0][0] = 1;
	// matrix.cell[0][1] = 5;
	// matrix.cell[1][0] = -3;
	// matrix.cell[1][1] = 2;
	// printf("Determinant = %f\n\n", rt_determinant(matrix));

	// t_matrix	sub;

	// matrix.rows = 3;
	// matrix.columns = 3;
	// matrix.cell[0][0] = 1;
	// matrix.cell[0][1] = 5;
	// matrix.cell[0][2] = 0;
	// matrix.cell[1][0] = -3;
	// matrix.cell[1][1] = 2;
	// matrix.cell[1][2] = 7;
	// matrix.cell[2][0] = 0;
	// matrix.cell[2][1] = 6;
	// matrix.cell[2][2] = -3;
	// rt_sub_matrix(matrix, 0, 2, &sub);
	// printf("Sub matrix\n");
	// rt_print_matrix(sub);
	// printf("\n");
	// matrix.rows = 4;
	// matrix.columns = 4;
	// matrix.cell[0][0] = -6;
	// matrix.cell[0][1] = 1;
	// matrix.cell[0][2] = 1;
	// matrix.cell[0][3] = 6;
	// matrix.cell[1][0] = -8;
	// matrix.cell[1][1] = 5;
	// matrix.cell[1][2] = 8;
	// matrix.cell[1][3] = 6;
	// matrix.cell[2][0] = -1;
	// matrix.cell[2][1] = 0;
	// matrix.cell[2][2] = 8;
	// matrix.cell[2][3] = 2;
	// matrix.cell[3][0] = -7;
	// matrix.cell[3][1] = 1;
	// matrix.cell[3][2] = -1;
	// matrix.cell[3][3] = 1;
	// rt_sub_matrix(matrix, 2, 1, &sub);
	// printf("Sub matrix\n");
	// rt_print_matrix(sub);
	// printf("\n");

	// matrix.rows = 3;
	// matrix.columns = 3;
	// matrix.cell[0][0] = 3;
	// matrix.cell[0][1] = 5;
	// matrix.cell[0][2] = 0;
	// matrix.cell[1][0] = 2;
	// matrix.cell[1][1] = -1;
	// matrix.cell[1][2] = -7;
	// matrix.cell[2][0] = 6;
	// matrix.cell[2][1] = -1;
	// matrix.cell[2][2] = 5;
	// rt_sub_matrix(matrix, 1, 0, &sub);
	// printf("Determinant submatrix 1,0: %f\n", rt_determinant(sub));
	// printf("Minor 1,0: %f\n\n", rt_minor(matrix, 1, 0));

	// printf("minor 0,0: %f\ncofactor 0,0: %f\n", rt_minor(matrix, 0, 0), rt_cofactor(matrix, 0, 0));
	// printf("minor 1,0: %f\ncofactor 1,0: %f\n\n", rt_minor(matrix, 1, 0), rt_cofactor(matrix, 1, 0));

	// matrix.cell[0][0] = 1;
	// matrix.cell[0][1] = 2;
	// matrix.cell[0][2] = 6;
	// matrix.cell[1][0] = -5;
	// matrix.cell[1][1] = 8;
	// matrix.cell[1][2] = -4;
	// matrix.cell[2][0] = 2;
	// matrix.cell[2][1] = 6;
	// matrix.cell[2][2] = 4;
	// printf("Cofactor 0,0: %f\n", rt_cofactor(matrix, 0, 0));
	// printf("Cofactor 0,1: %f\n", rt_cofactor(matrix, 0, 1));
	// printf("Cofactor 0,2: %f\n", rt_cofactor(matrix, 0, 2));
	// printf("Determinant of A: %f\n\n", rt_determinant(matrix));

	// matrix.rows = 4;
	// matrix.columns = 4;
	// matrix.cell[0][0] = -2;
	// matrix.cell[0][1] = -8;
	// matrix.cell[0][2] = 3;
	// matrix.cell[0][3] = 5;
	// matrix.cell[1][0] = -3;
	// matrix.cell[1][1] = 1;
	// matrix.cell[1][2] = 7;
	// matrix.cell[1][3] = 3;
	// matrix.cell[2][0] = 1;
	// matrix.cell[2][1] = 2;
	// matrix.cell[2][2] = -9;
	// matrix.cell[2][3] = 6;
	// matrix.cell[3][0] = -6;
	// matrix.cell[3][1] = 7;
	// matrix.cell[3][2] = 7;
	// matrix.cell[3][3] = -9;
	// printf("Cofactor 0,0: %f\n", rt_cofactor(matrix, 0, 0));
	// printf("Cofactor 0,1: %f\n", rt_cofactor(matrix, 0, 1));
	// printf("Cofactor 0,2: %f\n", rt_cofactor(matrix, 0, 2));
	// printf("Cofactor 0,3: %f\n", rt_cofactor(matrix, 0, 3));
	// printf("Determinant of A: %f\n\n", rt_determinant(matrix));

	// matrix.cell[0][0] = 6;
	// matrix.cell[0][1] = 4;
	// matrix.cell[0][2] = 4;
	// matrix.cell[0][3] = 4;
	// matrix.cell[1][0] = 5;
	// matrix.cell[1][1] = 5;
	// matrix.cell[1][2] = 7;
	// matrix.cell[1][3] = 6;
	// matrix.cell[2][0] = 4;
	// matrix.cell[2][1] = -9;
	// matrix.cell[2][2] = 3;
	// matrix.cell[2][3] = -7;
	// matrix.cell[3][0] = 9;
	// matrix.cell[3][1] = 1;
	// matrix.cell[3][2] = 7;
	// matrix.cell[3][3] = -6;
	// printf("Determinant of A: %f\n", rt_determinant(matrix));
	// matrix.cell[0][0] = -4;
	// matrix.cell[0][1] = 2;
	// matrix.cell[0][2] = -2;
	// matrix.cell[0][3] = -3;
	// matrix.cell[1][0] = 9;
	// matrix.cell[1][1] = 6;
	// matrix.cell[1][2] = 2;
	// matrix.cell[1][3] = 6;
	// matrix.cell[2][0] = 0;
	// matrix.cell[2][1] = -5;
	// matrix.cell[2][2] = 1;
	// matrix.cell[2][3] = -5;
	// matrix.cell[3][0] = 0;
	// matrix.cell[3][1] = 0;
	// matrix.cell[3][2] = 0;
	// matrix.cell[3][3] = 0;
	// printf("Determinant of A: %f\n\n", rt_determinant(matrix));

	t_matrix	inverse;

	matrix.cell[0][0] = -5;
	matrix.cell[0][1] = 2;
	matrix.cell[0][2] = 6;
	matrix.cell[0][3] = -8;
	matrix.cell[1][0] = 1;
	matrix.cell[1][1] = -5;
	matrix.cell[1][2] = 1;
	matrix.cell[1][3] = 8;
	matrix.cell[2][0] = 7;
	matrix.cell[2][1] = 7;
	matrix.cell[2][2] = -6;
	matrix.cell[2][3] = -7;
	matrix.cell[3][0] = 1;
	matrix.cell[3][1] = -3;
	matrix.cell[3][2] = 7;
	matrix.cell[3][3] = 4;
	inverse = rt_inversion(matrix);
	printf("Determinant: %f\n", rt_determinant(matrix));
	printf("Cofactor 2,3: %f\n", rt_cofactor(matrix, 2, 3));
	printf("-160/532 = %f && inverse[3][2]: %f\n", -160.0f/532.0f, inverse.cell[3][2]);
	printf("Cofactor 3,2: %f\n", rt_cofactor(matrix, 3, 2));
	printf("105/532 = %f && inverse[2][3]: %f\n", 105.0f/532.0f, inverse.cell[2][3]);
	printf("Inverted matrix:\n");
	rt_print_matrix(inverse);
	printf("\n");

	matrix.cell[0][0] = 3;
	matrix.cell[0][1] = -9;
	matrix.cell[0][2] = 7;
	matrix.cell[0][3] = 3;
	matrix.cell[1][0] = 3;
	matrix.cell[1][1] = -8;
	matrix.cell[1][2] = 2;
	matrix.cell[1][3] = -9;
	matrix.cell[2][0] = -4;
	matrix.cell[2][1] = 4;
	matrix.cell[2][2] = 4;
	matrix.cell[2][3] = 1;
	matrix.cell[3][0] = -6;
	matrix.cell[3][1] = 5;
	matrix.cell[3][2] = -1;
	matrix.cell[3][3] = 1;

	matrix2.cell[0][0] = 8;
	matrix2.cell[0][1] = 2;
	matrix2.cell[0][2] = 2;
	matrix2.cell[0][3] = 2;
	matrix2.cell[1][0] = 3;
	matrix2.cell[1][1] = -1;
	matrix2.cell[1][2] = 7;
	matrix2.cell[1][3] = 0;
	matrix2.cell[2][0] = 7;
	matrix2.cell[2][1] = 0;
	matrix2.cell[2][2] = 5;
	matrix2.cell[2][3] = 4;
	matrix2.cell[3][0] = 6;
	matrix2.cell[3][1] = -2;
	matrix2.cell[3][2] = 0;
	matrix2.cell[3][3] = 5;
	printf("A:\n");
	rt_print_matrix(matrix);
	printf("B:\n");
	rt_print_matrix(matrix2);
	m_mul = rt_mul_matrix(matrix, matrix2);
	printf("C = A * B\n");
	rt_print_matrix(m_mul);
	printf("C * inv(B) (must == A)\n");
	inverse = rt_inversion(matrix2);
	m_mul = rt_mul_matrix(m_mul, inverse);
	rt_print_matrix(m_mul);
}

/*
void	test_transform()
{
	printf("Translation\n");
	t_matrix	transform;
	t_tuple		point;
	t_matrix	inverse;
	t_tuple		vector;

	transform = rt_translation(rt_vector(5, -3, 2));
	point = rt_mul_tuple_matrix(transform, rt_point(-3, 4, 5));
	rt_print_tuple(point);
	= rt_inversion(transform);
	point = rt_mul_tuple_matrix(inverse, rt_point(-3, 4, 5));
	rt_print_tuple(point);
	vector = rt_vector(-3, 4, 5);
	rt_print_tuple(rt_mul_tuple_matrix(transform, vector));
	printf("\n");

	printf("Scaling\n");

	transform = rt_scaling(rt_vector(2, 3, 4));
	point = rt_point(-4, 6, 8);
	rt_print_tuple(rt_mul_tuple_matrix(transform, point));
	vector = rt_vector(-4, 6, 8);
	rt_print_tuple(rt_mul_tuple_matrix(transform, vector));
	= rt_inversion(transform);
	rt_print_tuple(rt_mul_tuple_matrix(inverse, vector));
	transform = rt_scaling(rt_vector(-1, 1, 1));
	point = rt_point(2, 3, 4);
	rt_print_tuple(rt_mul_tuple_matrix(transform, point));
	printf("\n");

	printf("Rotation x\n");

	point = rt_point(0, 1, 0);
	transform = rt_rotation_x(M_PI / 4);
	rt_print_tuple(rt_mul_tuple_matrix(transform, point));
	transform = rt_rotation_x(M_PI / 2);
	rt_print_tuple(rt_mul_tuple_matrix(transform, point));
	transform = rt_rotation_x(M_PI / 4);
	= rt_inversion(transform);
	rt_print_tuple(rt_mul_tuple_matrix(inverse, point));
	printf("\n");

	printf("Rotation y\n");

	point = rt_point(0, 0, 1);
	transform = rt_rotation_y(M_PI / 4);
	rt_print_tuple(rt_mul_tuple_matrix(transform, point));
	transform = rt_rotation_y(M_PI / 2);
	rt_print_tuple(rt_mul_tuple_matrix(transform, point));
	transform = rt_rotation_y(M_PI / 4);
	= rt_inversion(transform);
	rt_print_tuple(rt_mul_tuple_matrix(inverse, point));
	printf("\n");

	printf("Rotation z\n");

	point = rt_point(0, 1, 0);
	transform = rt_rotation_z(M_PI / 4);
	rt_print_tuple(rt_mul_tuple_matrix(transform, point));
	transform = rt_rotation_z(M_PI / 2);
	rt_print_tuple(rt_mul_tuple_matrix(transform, point));
	transform = rt_rotation_z(M_PI / 4);
	= rt_inversion(transform);
	rt_print_tuple(rt_mul_tuple_matrix(inverse, point));
	printf("\n");

	printf("Sequence of transforms\n");

	point = rt_point(1, 0, 1);
	rt_print_tuple(point);
	transform = rt_rotation_x(M_PI / 2);
	point = rt_mul_tuple_matrix(transform, point);
	rt_print_tuple(point);
	transform = rt_scaling(rt_vector(5, 5, 5));
	point = rt_mul_tuple_matrix(transform, point);
	rt_print_tuple(point);
	transform = rt_translation(rt_vector(10, 5, 7));
	point = rt_mul_tuple_matrix(transform, point);
	rt_print_tuple(point);
	printf("\n");

	printf("Chained transforms\n");
	t_matrix	rotate_x;
	t_matrix	scale;
	t_matrix	translate;

	point = rt_point(1, 0, 1);
	rt_print_tuple(point);
	rotate_x = rt_rotation_x(M_PI / 2);
	scale = rt_scaling(rt_vector(5, 5, 5));
	translate = rt_translation(rt_vector(10, 5, 7));
	transform = rt_mul_matrix(rt_mul_matrix(translate, scale), rotate_x);
	point = rt_mul_tuple_matrix(transform, point);
	rt_print_tuple(point);
	printf("\n");
}

*/


void	test_intersect()
{
	printf("Ray\n");
	t_ray	ray;

	ray = rt_ray(rt_point(1, 2, 3), rt_vector(4, 5, 6));
	rt_print_ray(ray);
	printf("\n");

	printf("Distance\n");

	ray = rt_ray(rt_point(2, 3, 4), rt_vector(1, 0, 0));
	rt_print_tuple(rt_position(ray, 0));
	rt_print_tuple(rt_position(ray, 1));
	rt_print_tuple(rt_position(ray, -1));
	rt_print_tuple(rt_position(ray, 2.5));
	printf("\n");

	printf("Intersection\n");
	t_object	plane;
	t_xs		xs;
	int			i = 0;
	
	xs.inter = (t_inter *)calloc(2, sizeof(t_inter));
	sphere = rt_sphere(rt_color(255, 0, 0), rt_material(0.1, 0.9, 0.9, 200.0f));
	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	rt_intersects(sphere, ray, &xs, &noneed);
	printf("XS Count = %d, [noneed - 2] = %f, [noneed - 1] = %f\n", xs.count, xs.inter[noneed - 2].t, xs.inter[noneed - 1].t);
	printf("\n");

	printf("Intersection at tangent\n");
	
	ray = rt_ray(rt_point(0, 1, -5), rt_vector(0, 0, 1));
	rt_intersects(sphere, ray, &xs, &noneed);
	printf("XS Count = %d, [noneed - 2] = %f, [noneed - 1] = %f\n", xs.count, xs.inter[noneed - 2].t, xs.inter[noneed - 1].t);
	printf("\n");

	printf("Miss the sphere\n");
	
	ray = rt_ray(rt_point(0, 2, -5), rt_vector(0, 0, 1));
	rt_intersects(sphere, ray, &xs, &noneed);
	printf("XS Count = %d, [noneed - 2] = %f, [noneed - 1] = %f\n", xs.count, xs.inter[noneed - 2].t, xs.inter[noneed - 1].t);
	printf("\n");

	printf("Ray origin in sphere\n");
	
	ray = rt_ray(rt_point(0, 0, 0), rt_vector(0, 0, 1));
	rt_intersects(sphere, ray, &xs, &noneed);
	printf("XS Count = %d, [noneed - 2] = %f, [noneed - 1] = %f\n", xs.count, xs.inter[noneed - 2].t, xs.inter[noneed - 1].t);
	printf("\n");

	printf("Sphere behind ray\n");
	
	ray = rt_ray(rt_point(0, 0, 5), rt_vector(0, 0, 1));
	rt_intersects(sphere, ray, &xs, &noneed);
	printf("XS Count = %d, [noneed - 2] = %f, [noneed - 1] = %f\n", xs.count, xs.inter[noneed - 2].t, xs.inter[noneed - 1].t);
	printf("\n");

	printf("The hit\n");
	t_inter	hit;

	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1)); //2 hits
	rt_intersects(sphere, ray, &xs, &noneed);
	hit = rt_hit(xs);
	printf("The hit is: %f\n", hit.t);
	ray = rt_ray(rt_point(0, 1, -5), rt_vector(0, 0, 1)); //1 hit tangent
	rt_intersects(sphere, ray, &xs, &noneed);
	hit = rt_hit(xs);
	printf("The hit is: %f\n", hit.t);
	ray = rt_ray(rt_point(0, 2, -5), rt_vector(0, 0, 1)); //no hit
	rt_intersects(sphere, ray, &xs, &noneed);
	hit = rt_hit(xs);
	printf("The hit is: %f\n", hit.t);
	ray = rt_ray(rt_point(0, 0, 0), rt_vector(0, 0, 1)); //1 hit inside sphere
	rt_intersects(sphere, ray, &xs, &noneed);
	hit = rt_hit(xs);
	printf("The hit is: %f\n", hit.t);
	ray = rt_ray(rt_point(0, 0, 5), rt_vector(0, 0, 1)); //2 hits negative
	rt_intersects(sphere, ray, &xs, &noneed);
	hit = rt_hit(xs);
	printf("The hit is: %f\n", hit.t);
	printf("\n");

	printf("Looping to find the hit\n");
	free(xs.inter);
	xs.inter = (t_inter *)calloc(4, sizeof(t_inter));
	
	xs.inter[noneed - 2].object = sphere;
	xs.inter[noneed - 1].object = sphere;
	xs.inter[2].object = sphere;
	xs.inter[3].object = sphere;
	xs.inter[4].object = sphere;
	xs.inter[5].object = sphere;
	xs.inter[6].object = sphere;
	xs.inter[7].object = sphere;
	xs.count = 8;
	xs.inter[noneed - 2].t = 5.0f;
	xs.inter[noneed - 1].t = 6.0f;
	xs.inter[2].t = 7.0f;
	xs.inter[3].t = 12.0f;
	xs.inter[4].t = -3.0f;
	xs.inter[5].t = -6.0f;
	xs.inter[6].t = 2.0f;
	xs.inter[7].t = 6.0f;
	hit.t = -1.0f;
	errno = 0;
	for (int i = 0; i < 4; i++)
	{
		hit = rt_hit(xs);
	}
	printf("The hit is: %f\n\n", hit.t);

	printf("Translating a ray\n");
	t_matrix	translate;
	t_matrix	scale;

	ray = rt_ray(rt_point(1, 2, 3), rt_vector(0, 1, 0));
	translate = rt_translation(rt_vector(3, 4, 5));
	ray = rt_ray_transform(translate, ray);
	rt_print_ray(ray);
	printf("\n");

	printf("Scaling a ray\n");

	ray = rt_ray(rt_point(1, 2, 3), rt_vector(0, 1, 0));
	scale = rt_scaling(rt_vector(2, 3, 4));
	ray = rt_ray_transform(scale, ray);
	rt_print_ray(ray);
	printf("\n");

	printf("Transform a sphere\n");

	sphere.transform = rt_identity_matrix();
	printf("Identity\n");
	rt_print_matrix(sphere.transform);
	printf("Transformed\n");
	translate = rt_translation(rt_vector(2, 3, 4));
	sphere.transform = rt_set_transform(sphere, translate);
	rt_print_matrix(sphere.transform);
	printf("\n");

	printf("Intersecting a scaled sphere with a ray\n");

	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	sphere.transform = rt_set_transform(sphere, rt_scaling(rt_vector(2, 2, 2)));
	rt_intersects(sphere, ray, &xs, &noneed);
	printf("count = %d, [noneed - 2] = %f, [noneed - 1] = %f\n", xs.count, xs.inter[noneed - 2].t, xs.inter[noneed - 1].t);
	printf("\n");

	printf("Intersecting a translated sphere with a ray\n");

	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	sphere.transform = rt_set_transform(sphere, rt_translation(rt_vector(5, 0, 0)));
	rt_intersects(sphere, ray, &xs, &noneed);
	printf("count = %d, [noneed - 2] = %f, [noneed - 1] = %f\n", xs.count, xs.inter[noneed - 2].t, xs.inter[noneed - 1].t);

	free(xs.inter);
}

/*
void	test_mlx()
{
	t_env		env;
	t_object	sp;
	t_ray		ray;

	sp = rt_sphere(rt_color(255, 0, 0), rt_material(0.1, 0.9, 0.9, 200.0f));
	rt_print_matrix(sp.transform);
	//sp.transform = rt_set_transform(sp, rt_scaling(rt_vector(1, 2, 1)));
	//sp.transform = rt_set_transform(sp, rt_translation(rt_vector(1, 0, 0)));
	//rt_print_matrix(sp.transform);
	env = mlx_set_env();
	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	rt_draw(&env, sp, ray);
	mlx_run_window(&env);
}
*/
void	test_light()
{
	printf("Normal basic tests\n");
	t_object	sphere;
	t_tuple		normal;
	
	sphere = rt_sphere(rt_color(1, 0, 0));
	normal = rt_normal_at(sphere, rt_point(1, 0, 0));
	rt_print_tuple(normal);
	normal = rt_normal_at(sphere, rt_point(0, 1, 0));
	rt_print_tuple(normal);
	normal = rt_normal_at(sphere, rt_point(0, 0, 1));
	rt_print_tuple(normal);
	normal = rt_normal_at(sphere, rt_point(sqrtf(3)/3, sqrtf(3)/3, sqrtf(3)/3));
	rt_print_tuple(normal);
	normal = rt_normalize(normal);
	rt_print_tuple(normal);
	printf("sqrt3 /3: %f\n\n", sqrtf(3)/3);

	printf("Normal of translated sphere\n");

	sphere.transform = rt_set_transform(sphere, rt_translation(rt_vector(0, 1, 0)));
	normal = rt_normal_at(sphere, rt_point(0, 1.70711, -0.70711));
	rt_print_tuple(normal);
	printf("\n");

	printf("Normal of scaled sphere\n");
	t_matrix	rotate;
	t_matrix	scale;
	t_matrix	transform;

	scale = rt_scaling(rt_vector(1, 0.5, 1));
	rotate = rt_rotation_z(M_PI / 5);
	transform = rt_mul_matrix(scale, rotate);
	sphere.transform = transform;
	normal = rt_normal_at(sphere, rt_point(0, sqrtf(2)/2, -sqrtf(2)/2));
	rt_print_tuple(normal);

	printf("Reflecting a vector\n");
	t_tuple	vector;
	t_tuple	reflect;

	printf("45 deg\n");
	vector = rt_vector(1, -1, 0);
	normal = rt_vector(0, 1, 0);
	reflect = rt_reflect(vector, normal);
	rt_print_tuple(reflect);

	printf("Slanted\n");
	vector = rt_vector(0, -1, 0);
	normal = rt_vector(sqrtf(2)/2, sqrtf(2)/2, 0);
	reflect = rt_reflect(vector, normal);
	rt_print_tuple(reflect);
	printf("\n");

	printf("Phong light reflection\n");
	t_light	light;

	light = rt_light(rt_color(255, 255, 255), rt_point(0, 0, 0), 1.0f);
	rt_print_light(light);
	printf("\n");

	printf("Material\n");
	t_material	material;

	material = rt_material(0.1, 0.9, 0.9, 200.0f);
	rt_print_material(material);
	printf("\n");

	printf("Sphere with material\n");

	sphere = rt_sphere(rt_color(255, 255, 255));
	rt_print_sphere(sphere);
	printf("\n");

	printf("Light - eye - surface\n");
	t_tuple	result;
	t_tuple	point;
	t_tuple	eyev;

	normal = rt_vector(0, 0, -1);
	point = rt_point(0, 0, 0);
	eyev = rt_vector(0, 0, -1);
	light.coord = rt_point(0, 0, -10);
	result = rt_lighting(sphere, light, point, eyev, normal);
	rt_print_tuple(result);
	printf("\n");

	printf("Light - eye 45 - surface\n");

	light.coord = rt_point(0, 0, -10);
	eyev = rt_vector(0, sqrtf(2)/2, -sqrtf(2)/2);

	result = rt_lighting(sphere, light, point, eyev, normal);
	rt_print_tuple(result);
	printf("\n");

	printf("Eye - light 45 - surface\n");

	light.coord = rt_point(0, 10, -10);
	eyev = rt_vector(0, 0, -1);
	result = rt_lighting(sphere, light, point, eyev, normal);
	rt_print_tuple(result);
	printf("\n");

	printf("Eye = light reflect - surface\n");

	light.coord = rt_point(0, 10, -10);
	eyev = rt_vector(0, -sqrtf(2)/2, -sqrtf(2)/2);
	result = rt_lighting(sphere, light, point, eyev, normal);
	rt_print_tuple(result);
	printf("\n");

	printf("Eye - surface - light\n");

	light.coord = rt_point(0, 0, 10);
	eyev = rt_vector(0, 0, -1);
	result = rt_lighting(sphere, light, point, eyev, normal);
	rt_print_tuple(result);
	printf("\n");
}

void	test_light_render()
{
	ft_printf("CH6 - Putting it together\n");
	t_camera	camera;
	t_env		env;
	t_ray		ray;
	t_xs		xs;
	t_light		light;
	t_object	sphere;
	t_tuple		point;
	t_tuple 	eyev;
	t_tuple		normalv;
	t_tuple		color;
	t_matrix	transform;

	int			h;
	int			w;
	float		wall_z;
	int			i;

	xs.inter = (t_inter *)calloc(2, sizeof(t_inter));
	camera = rt_camera_parsing(rt_point(0, 0, -5), rt_vector(0, 0, 1), 90.0f);
	sphere = rt_sphere(rt_color(255, 0.2 * 255, 255), rt_material(0.1, 0.9, 0.9, 200.0f));
	light = rt_light(rt_color(255, 255, 255), rt_point(-10, 10, -10), 1.0f);
	ray = rt_ray(camera.coord, camera.orient);
	env = mlx_set_env();
	transform = rt_scaling(rt_vector(2, 0.5, 1));
	sphere.transform = rt_set_transform(sphere, transform);

	wall_z = 5;
	h = 0;
	while (h < WINDOW_HEIGHT)
	{
		if ((h + 1) % 100 == 0)
		ft_printf("Progressing: %f\n", (float)((float)(h + 1) / (float)WINDOW_HEIGHT * 100.0f));
		w = 0;
		while (w < WINDOW_WIDTH)
		{
			i = 0;
			xs.count = 0;
			ray = rt_define_ray_to_wall(ray, w, h, wall_z);
			rt_intersects(&sphere, ray, &xs, &i);
			if(xs.count != 0)
			{
				point = rt_position(ray, rt_hit(xs).t);
				normalv = rt_normal_at(xs.inter[noneed - 2].object, point);
				eyev = rt_negate_vector(ray.direction);
				color = rt_lighting(xs.inter[noneed - 2].object, light, point, eyev, normalv);
				color = rt_reinhard_tonemap(color);
				my_mlx_pixel_put(&env, w, WINDOW_HEIGHT - h, rgb_to_int(color));
			}
			else
			{
				my_mlx_pixel_put(&env, w, WINDOW_HEIGHT - h, rgb_to_int((t_tuple){0, 0, 0, COLOR}));
			}
			w++;
		}
		h++;
	}
	mlx_run_window(&env);
}

void	test_scene()
{
	printf("Setup a world\n");
	t_scene		scene;
	t_light		light;
	t_object	sphere;
	
	scene.n_obj = 2;
	scene.n_sp = 2;
	light = rt_light(rt_color(255, 255, 255), rt_point(-10, -10, -10), 1.0);
	scene.lux = light;
	scene.objects = (t_object *)calloc(scene.n_obj, sizeof(t_object));
	sphere = rt_sphere(rt_color(0.8 * 255, 255, 0.6 * 255));
	sphere.material = rt_material(0.1, 0.7, 0.2, 200.0);
	scene.objects[0] = sphere;
	sphere.diameter = 1.0;
	sphere.transform = rt_scaling(rt_vector(0.5, 0.5, 0.5));
	scene.objects[1] = sphere;
	rt_print_sphere(scene.objects[0]);
	rt_print_sphere(scene.objects[1]);
	printf("\n");
	
	printf("Intersect a world with a ray\n");
	t_ray	ray;
	t_xs	xs;
	int		j;


	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	xs.inter = (t_inter *)calloc(scene.n_obj * 2, sizeof(t_inter));
	xs.count = 0;
	rt_intersect_scene(scene, ray, &xs);
	j = 0;
	printf("xs.count = %d\n", xs.count);
	while (j < scene.n_obj * 2)
	{
		printf("xs.t[%d] = %f\n", j, xs.inter[j].t);
		j++;
	}
	printf("\n");

	printf("The hit");
	t_inter	hit;

	hit = rt_hit(xs);
	printf(" is %f\n", hit.t);
	printf("\n");

	printf("Computed values\n");
	t_comps	comps;
	t_inter	inter;

	printf("from the outside\n");
	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	sphere = scene.objects[0];
	inter = rt_intersect(4, sphere);
	comps = rt_prepare_computations(inter, ray);
	rt_print_sphere(comps.object);
	rt_print_sphere(inter.object);
	rt_print_tuple(comps.point);
	rt_print_tuple(comps.eyev);
	rt_print_tuple(comps.normalv);
	printf("comp.inside = %d\n", comps.inside);

	printf("from the inside\n");
	ray = rt_ray(rt_point(0, 0, 0), rt_vector(0, 0, 1));
	inter = rt_intersect(1, sphere);
	comps = rt_prepare_computations(inter, ray);
	rt_print_sphere(comps.object);
	rt_print_sphere(inter.object);
	rt_print_tuple(comps.point);
	rt_print_tuple(comps.eyev);
	rt_print_tuple(comps.normalv);
	printf("comp.inside = %d\n", comps.inside);
	printf("\n");

	printf("Shade hit\n");
	t_tuple	color;

	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	scene.lux = rt_light(rt_color(255, 255, 255), rt_point(-10, 10, -10), 1.0);
	sphere = scene.objects[0];
	inter = rt_intersect(4, sphere);
	comps = rt_prepare_computations(inter, ray);
	color = rt_shade_hit(scene, comps);
	rt_print_tuple(color);
	printf("\n");

	printf("Shade hit from inside\n");

	ray = rt_ray(rt_point(0, 0, 0), rt_vector(0, 0, 1));
	scene.lux = rt_light(rt_color(255, 255, 255), rt_point(0, 0.25, 0), 1.0);
	sphere = scene.objects[1];
	sphere.material = rt_material(0.1, 0.7, 0.2, 1);
	sphere.color = rt_color(1.0 * 255, 1.0 * 255, 1.0 * 255);
	inter = rt_intersect(0.5, sphere);
	comps = rt_prepare_computations(inter, ray);
	color = rt_shade_hit(scene, comps);
	rt_print_tuple(color);
	printf("\n");

	printf("Shade hit ray missed\n");

	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 1, 0));
	color = rt_color_at(scene, ray);
	rt_print_tuple(color);
	printf("\n");
	
	printf("Shade hit ray hits\n");
	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	
	rt_default_scene(&scene);
	color = rt_color_at(scene, ray);
	rt_print_tuple(color);
	printf("\n");

	printf("Shade hit behind ray\n");
	ray = rt_ray(rt_point(0, 0, 0.75), rt_vector(0, 0, -1));
	
	scene.objects[0].material.ambient = 1;
	scene.objects[1].material.ambient = 1;
	
	color = rt_color_at(scene, ray);
	rt_print_tuple(color);
	rt_print_tuple(scene.objects[1].color);
	printf("\n");

	free(scene.objects);
}

void	test_rgb_to_int()
{
	// generate color
	int col;
	col = rgb_to_int(rt_color(0.90498 * 255, 0.90498 * 255, 0.90498 * 255));
	printf("rgb_to_int %d \n", col);
	
	// draw window with color
	float		h;
	float		w;
	t_env env = mlx_set_env();
	h = 0;
	while (h < WINDOW_HEIGHT)
	{
		w = 0;
		while (w < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&env, (int) w, WINDOW_HEIGHT - (int) h, col);
			w++;
		}
		h++;
	}
	mlx_run_window(&env);
}

void	test_view_transform()
{
	printf ("View Transformation tests:\n\n");
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix	view_transform;

	printf("- transformation matrix for the default orientation:\n");
	from = rt_point(0, 0, 0);
	to = rt_point(0, 0, -1);
	up = rt_vector(0, 1, 0);
	view_transform = rt_view_transform(from, to, up);
	if (rt_matrix_equality(view_transform, rt_identity_matrix()))
		printf("the view transformation matrix == identity matrix\n");
	else
		printf("the view transformation matrix NOT == identity matrix\n");
	
	printf("\n- a view transformation matrix looking in the positive z direction:\n");
	from = rt_point(0, 0, 0);
	to = rt_point(0, 0, 1);
	up = rt_vector(0, 1, 0);
	view_transform = rt_view_transform(from, to, up);
	if (rt_matrix_equality(view_transform, rt_scaling(rt_vector(-1, 1, -1))))
		printf("the view transformation matrix == scaling(-1, 1, -1)\n");
	else
		printf("the view transformation matrix NOT == scaling(-1, 1, -1)\n");
		
		
	printf("\n- the view transformation matrix moves the world:\n");
	from = rt_point(0, 0, 8);
	to = rt_point(0, 0, 0);
	up = rt_vector(0, 1, 0);
	view_transform = rt_view_transform(from, to, up);
	if (rt_matrix_equality(view_transform, rt_translation(rt_vector(0, 0, -8))))
		printf("the view transformation matrix == translation(0, 0, -8)\n");
	else
		printf("the view transformation matrix NOT == translation(0, 0, -8)\n");
		
		
	printf("\n- an arbitrary view transformation:\n");
	from = rt_point(1, 3, 2);
	to = rt_point(4, -2, 8);
	up = rt_vector(1, 1, 0);
	view_transform = rt_view_transform(from, to, up);
	rt_print_matrix(view_transform);
}

void	test_camera()
{
	printf("Test camera\n***********\n");
	t_camera	camera;
	// t_ray		ray;
	t_scene		scene;
	t_object	objects[2];

	scene.objects = objects;

	// printf("Constructing a camera:\n");
	// camera = rt_camera_book(160, 120, M_PI / 2);
	// rt_print_camera(camera);

	// printf("\nthe pixel size for a horizontal canvas:\n");
	// camera = rt_camera_book(200, 125, M_PI / 2);
	// printf("=> camera.pixel_size: %f\n", camera.pixel_size);
	
	// printf("\nthe pixel size for a vertical canvas:\n");
	// camera = rt_camera_book(125, 200, M_PI / 2);
	// printf("=> camera.pixel_size: %f\n", camera.pixel_size);
	
	// printf("\nconstructing a ray through the center of the canvas\n");
	// camera = rt_camera_book(201, 101, M_PI / 2);
	// ray = rt_ray_for_pixel(camera, 100, 50);
	// printf("ray.origin: ");	rt_print_tuple(ray.origin);
	// printf("ray.direction: ");	rt_print_tuple(ray.direction);

	// printf("\nconstructing a ray through a corner of the canvas\n");
	// camera = rt_camera_book(201, 101, M_PI / 2);
	// ray = rt_ray_for_pixel(camera, 0, 0);
	// printf("ray.origin: ");	rt_print_tuple(ray.origin);
	// printf("ray.direction: ");	rt_print_tuple(ray.direction);

	// printf("\nconstructing a ray when the camera is transformed\n");
	// camera = rt_camera_book(201, 101, M_PI / 2);
	// camera.transform = rt_mul_matrix(
	// 	rt_rotation_y(M_PI / 4), rt_translation(rt_vector(0, -2, 5)));
	// ray = rt_ray_for_pixel(camera, 100, 50);
	// printf("ray.origin: ");	rt_print_tuple(ray.origin);
	// printf("ray.direction: ");	rt_print_tuple(ray.direction);

	printf("\nrendering a world with a camera\n");
	rt_default_scene(&scene);
	camera = rt_camera_book(WINDOW_WIDTH, WINDOW_HEIGHT, M_PI / 2);

	// camera settings
	t_tuple from;
	t_tuple to;
	t_tuple up;
	from = rt_point(0, 0, -5);
	to = rt_point(0, 0, 0);
	up = rt_vector(0, 1, 0);
	camera.transform = rt_view_transform(from, to, up);

	// mlx settings
	t_env	env;
	env = mlx_set_env();
	rt_render(camera, scene, &env);
	mlx_run_window(&env);
}

void	test_pixel_at(t_tuple color)
{
	if (rt_is_equal_tuple(color, rt_color(0.38066, 0.47583, 0.2855)))
		printf("at (5, 5), color is equal to (0.38066, 0.47583, 0.2855) (correct)\n");
	else
	{
		printf("at (5, 5), color is NOT equal to (0.38066, 0.47583, 0.2855) \
			(incorrect)\ntuple value is:");
		rt_print_tuple(color);
	}
}

void	rt_render(t_camera camera, t_scene scene, t_env *env)
{
	t_ray	ray;
	int		x;
	int		y;
	t_tuple	color;

	y = 0;
	printf("camera.vsize: %d, camera.hsize: %d\n", camera.vsize, camera.hsize);
	while (y < camera.vsize - 1)
	{
		x = 0;
		while (x < camera.hsize - 1)
		{
			ray = rt_ray_for_pixel(camera, x, y);
			color = rt_color_at(scene, ray);
			// if (x == 5 && y == 5)
				// test_pixel_at(color);
			my_mlx_pixel_put(env, x, y, rgb_to_int(color));
			// printf("(%d, %d): ", x, y); rt_print_tuple(color);
			x++;
		}
		y++;
	}
	printf("finished rendering\n");
}
void	test_planes()
{
	ft_printf("Plane initialisation\n");
	t_object	plane;

	plane = rt_plane(rt_color(255, 0.2 * 255, 255));
	plane.transform = rt_translation(rt_vector(2, 3, 4));
	if (rt_matrix_equality(plane.transform, rt_identity_matrix()))
		ft_printf("Plane transform is identity\n");
	else
		ft_printf("Plane transform is not identity\n");
	rt_print_matrix(plane.transform);
	ft_printf("\n");

	ft_printf("Default material\n");
	plane.material.ambient = 1;
	rt_print_material(plane.material);
	ft_printf("\n");

	ft_printf("Ray scaled plane intersect\n");
	t_ray		ray;
	t_xs		xs;
	int			i = 0;
	t_inter		inter[1];

	xs.inter = inter;
	plane = rt_plane(rt_color(255, 0.2 * 255, 255));
	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	plane.transform = rt_set_transform(plane, rt_scaling(rt_vector(2, 2, 2)));
	rt_intersects(&plane, ray, &xs, &i);
	rt_print_ray(plane.saved_ray);
	ft_printf("\n");

	ft_printf("Ray translated plane intersect\n");
	ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	plane = rt_plane(rt_color(255, 0.2 * 255, 255));
	plane.transform = rt_set_transform(plane, rt_translation(rt_vector(5, 0, 0)));
	rt_intersects(&plane, ray, &xs, &i);
	rt_print_ray(plane.saved_ray);
	ft_printf("\n");

	ft_printf("Normal translated sphere intersect\n");
	t_tuple		normal_at;
	t_object	sphere;

	sphere = rt_sphere(rt_color(255, 0.2 * 255, 255));
	sphere.transform = rt_set_transform(sphere, rt_translation(rt_vector(0, 1, 0)));
	normal_at = rt_normal_at(sphere, rt_point(0, 1.70711, -0.70711));
	rt_print_tuple(normal_at);
	ft_printf("\n");

	ft_printf("Normal scaled rotated sphere intersect\n");
	t_matrix	transform;

	sphere = rt_sphere(rt_color(255, 0.2 * 255, 255));
	transform = rt_mul_matrix(rt_scaling(rt_vector(1.0, 0.5, 1.0)), \
							rt_rotation_z(M_PI / 5));
	sphere.transform = rt_set_transform(sphere, transform);
	normal_at = rt_normal_at(sphere, rt_point(0, sqrtf(2)/2, -sqrtf(2)/2));
	rt_print_tuple(normal_at);
	ft_printf("\n");

	ft_printf("Normal on a plane is the same everywhere!\n");

	plane = rt_plane(rt_color(255, 0.2 * 255, 255));
	normal_at = rt_local_normal_at(plane, rt_point(0, 0, 0));
	rt_print_tuple(normal_at);
	normal_at = rt_local_normal_at(plane, rt_point(10, 0, -10));
	rt_print_tuple(normal_at);
	normal_at = rt_local_normal_at(plane, rt_point(-5, 0, 150));
	rt_print_tuple(normal_at);
	ft_printf("\n");

	ft_printf("Intersect ray parallel to plane\n");

	xs.inter = inter;
	plane = rt_plane(rt_color(255, 0.2 * 255, 255));
	ray = rt_ray(rt_point(0, 10, 0), rt_vector(0, 0, 1));
	rt_intersects(&plane, ray, &xs, &i);
	ft_printf("intersects %d\n", xs.count);
	ft_printf("\n");

	ft_printf("Intersect ray coplanar to plane\n");

	i = 0;
	plane = rt_plane(rt_color(255, 0.2 * 255, 255));
	ray = rt_ray(rt_point(0, 0, 0), rt_vector(0, 0, 1));
	rt_intersects(&plane, ray, &xs, &i);
	ft_printf("intersects %d\n", xs.count);
	ft_printf("\n");

	ft_printf("Intersect a plane from above\n");

	i = 0;
	plane = rt_plane(rt_color(255, 0.2 * 255, 255));
	ray = rt_ray(rt_point(0, 1, 0), rt_vector(0, -1, 0));
	rt_intersects(&plane, ray, &xs, &i);
	ft_printf("intersects count %d, t : %f, object %d\n", xs.count, xs.inter[0].t, xs.inter[0].object.shape);
	ft_printf("\n");

	ft_printf("Intersect a plane from below\n");

	xs.count = 0;
	i = 0;
	plane = rt_plane(rt_color(255, 0.2 * 255, 255));
	ray = rt_ray(rt_point(0, -1, 0), rt_vector(0, 1, 0));
	rt_intersects(&plane, ray, &xs, &i);
	ft_printf("intersects count %d, t : %f, object %d\n", xs.count, xs.inter[0].t, xs.inter[0].object.shape);
	ft_printf("\n");
}

void	test_render_plane()
{
	ft_printf("CH9 - Putting it together\n");
	t_camera	camera;
	t_env		env;
	t_ray		ray;
	t_xs		xs;
	t_light		light;
	t_object	plane;
	t_tuple		point;
	t_tuple 	eyev;
	t_tuple		normalv;
	t_tuple		color;
	t_inter		inter[1];

	int			h;
	int			w;
	float		wall_z;
	int			i;

	xs.inter = inter;
	camera = rt_camera(rt_point(0, 2, -5), rt_vector(0, -0.5, 1), 90.0f);
	plane = rt_plane(rt_color(255, 0.2 * 255, 255));
	light = rt_light(rt_color(255, 255, 255), rt_point(-10, 10, -10), 1.0f);
	ray = rt_ray(camera.coord, camera.orient);
	env = mlx_set_env();

	wall_z = 5;
	h = 0;
	while (h < WINDOW_HEIGHT)
	{
		if ((h + 1) % 100 == 0)
		ft_printf("Progressing: %f\n", (float)((float)(h + 1) / (float)WINDOW_HEIGHT * 100.0f));
		w = 0;
		while (w < WINDOW_WIDTH)
		{
			i = 0;
			xs.count = 0;
			ray = rt_define_ray_to_wall(ray, w, h, wall_z);
			rt_intersects(&plane, ray, &xs, &i);
			if(xs.count != 0)
			{
				point = rt_position(ray, rt_hit(xs).t);
				normalv = rt_normal_at(xs.inter[0].object, point);
				eyev = rt_negate_vector(ray.direction);
				color = rt_lighting(xs.inter[0].object, light, point, eyev, normalv);
				color = rt_reinhard_tonemap(color);
				my_mlx_pixel_put(&env, w, WINDOW_HEIGHT - h, rgb_to_int(color));
			}
			else
			{
				my_mlx_pixel_put(&env, w, WINDOW_HEIGHT - h, rgb_to_int((t_tuple){0, 0, 0, COLOR}));
			}
			w++;
		}
		h++;
	}
	mlx_run_window(&env);
}
