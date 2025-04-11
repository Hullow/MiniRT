/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transforms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:36:33 by francis           #+#    #+#             */
/*   Updated: 2025/04/11 16:42:03 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// to run the tests, add .c to this file's name and run: 
// gcc -o test_transforms -Wall -Wextra -Werror *.c ../tuples/*tuple*.c ../matrices/*.c ../rays/*.c ../scene/*.c ../utils/*.c -lm -I../../include -I../../include/libft -L../../include/libft -lft
// remember to make the libft before

void	test_shear();
void	test_translation();
void	test_scaling();
void	test_rotation();
void	test_transforms();
void	test_transform_handling();
void	analog_clock();
void	test_rays_positions();
void	test_intersections();

int main()
{
	// test_shear();
	// test_translation();
	// test_scaling();
	// test_rotation();
	// test_transforms();
	// analog_clock();
	// test_rays_positions();
	test_intersections();
	// test_transform_handling();
	return (0);
}

void	analog_clock()
{
	
}

void	test_intersections()
{
	printf("test_intersections():\n");

	// Test 1: A ray intersects a sphere at two points
	printf("Test 1: A ray intersects a sphere at two points\n");
	t_ray *ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	t_sphere *s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0f, (t_tuple){0.5, 0.2, 0.1, COLOR});
	t_intersect *x = ft_calloc(1, sizeof(t_intersect));
	if (!x)
		printf("malloc fail in test_intersections()\n");
	x = rt_ray_sphere_x(ray, s, s->transform, x);
	printf("x->x_count: %d, x->x_distance[0]: %f, x->x_distance[1]: %f\n", x->x_count, x->x_distances[0], x->x_distances[1]);
	
	// Test 2: A ray intersects a sphere at a tangent
	printf("\nTest 2: A ray intersects a sphere at a tangent\n");
	ray = rt_ray(rt_point(0, 1, -5), rt_vector(0, 0, 1));
	s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0, (t_tuple){0.5, 0.2, 0.1, COLOR});
	t_intersect *y = ft_calloc(1, sizeof(t_intersect));
	if (!y)
		printf("malloc fail in test_intersections()\n");
	y = rt_ray_sphere_x(ray, s, s->transform, y);
	printf("y->x_count: %d, y->x_distance[0]: %f, y->x_distance[1]: %f\n", y->x_count, y->x_distances[0], y->x_distances[1]);

	// Test 3: A ray misses a sphere
	printf("\nTest 3: A ray misses a sphere\n");
	ray = rt_ray(rt_point(0, 2, -5), rt_vector(0, 0, 1));
	s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0, (t_tuple){0.5, 0.2, 0.1, COLOR});
	t_intersect *z = ft_calloc(1, sizeof(t_intersect));
	if (!z)
		printf("malloc fail in test_intersections()\n");
	z = rt_ray_sphere_x(ray, s, s->transform, z);
	printf("z->x_count: %d, z->x_distance[0]: %f, z->x_distance[1]: %f\n", z->x_count, z->x_distances[0], z->x_distances[1]);

	// Test 4: A ray originates inside a sphere
	printf("\nTest 4: A ray originates inside a sphere\n");
	ray = rt_ray(rt_point(0, 0, 0), rt_vector(0, 0, 1));
	s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0, (t_tuple){0.5, 0.2, 0.1, COLOR});
	t_intersect *w = ft_calloc(1, sizeof(t_intersect));
	if (!w)
		printf("malloc fail in test_intersections()\n");
	w = rt_ray_sphere_x(ray, s, s->transform, w);
	printf("w->x_count: %d, w->x_distance[0]: %f, w->x_distance[1]: %f\n", w->x_count, w->x_distances[0], w->x_distances[1]);

	// Test 5: A sphere is behind a ray
	printf("\nTest 5: A sphere is behind a ray\n");
	ray = rt_ray(rt_point(0, 0, 5), rt_vector(0, 0, 1));
	s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0, (t_tuple){0.5, 0.2, 0.1, COLOR});
	t_intersect *v = ft_calloc(1, sizeof(t_intersect));
	if (!v)
		printf("malloc fail in test_intersections()\n");
	v = rt_ray_sphere_x(ray, s, s->transform, v);
	printf("v->x_count: %d, v->x_distance[0]: %f, v->x_distance[1]: %f\n", v->x_count, v->x_distances[0], v->x_distances[1]);

	
}

void	test_rays_positions()
{
	t_tuple *origin = rt_point(2, 3, 4);
	t_tuple *direction = rt_vector(1, 0, 0);
	t_ray *ray = rt_ray(origin, direction);
	printf("ray: origin is (%f, %f, %f)\n", ray->origin->x, ray->origin->y, ray->origin->z);
	printf("ray: direction is (%f, %f, %f)\n", ray->direction->x, ray->direction->y, ray->direction->z);
	
	t_tuple *pos = rt_position(ray, 0);
	printf("position at t = 0 from the ray is (%f, %f, %f)\n", pos->x, pos->y, pos->z);
	
	pos = rt_position(ray, 1);
	printf("position at t = 1 from the ray is (%f, %f, %f)\n", pos->x, pos->y, pos->z);
	
	pos = rt_position(ray, -1);
	printf("position at t = -1 from the ray is (%f, %f, %f)\n", pos->x, pos->y, pos->z);
	
	pos = rt_position(ray, 2.5);
	printf("position at t = 2.5 from the ray is (%f, %f, %f)\n", pos->x, pos->y, pos->z);
}

void	test_transform_handling()
{
	printf("testing rt_transform_ray:\n");
	t_tuple		*pt = rt_point(1, 2, 3);
	t_tuple		*vec = rt_vector(0, 1, 0);
	
	t_ray	*ray_3 = rt_transform_ray(rt_ray(pt, vec), rt_translation(3, 4, 5));
	printf("the translated ray:\n");
	printf("- origin: (%f, %f, %f)\n- direction: (%f, %f, %f)\n", 
	ray_3->origin->x, ray_3->origin->y, ray_3->origin->z,
	ray_3->direction->x, ray_3->direction->y, ray_3->direction->z);

	t_ray	*ray_2 = rt_transform_ray(rt_ray(pt, vec), rt_scaling(2, 3, 4));
	printf("the scaled ray:\n");
	printf("- origin: (%f, %f, %f)\n- direction: (%f, %f, %f)\n", 
	ray_2->origin->x, ray_2->origin->y, ray_2->origin->z,
	ray_2->direction->x, ray_2->direction->y, ray_2->direction->z);
		
	t_sphere	*sp = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 1, (t_tuple) {0.5, 0.5, 0.5, COLOR});
	// rt_set_sphere_transform(sp, rt_translation(2, 3, 4));
	// print_matrix(sp->transform);
	// print_matrix(rt_translation(2, 3, 4));
		
	// First intersection with a transformed sphere
	t_ray	*ray_4 = rt_ray(rt_point(0.0, 0.0, -5), rt_vector(0, 0, 1));
	rt_set_sphere_transform(sp, rt_scaling(2, 2, 2));
	t_intersect	*x = ft_calloc(1, sizeof(t_intersect));
	if (!x)
	printf("error malloc\n");
	x = rt_ray_sphere_x(ray_4, sp, sp->transform, x);
	printf("\nIntersecting a scaled sphere with a ray:\n");
	printf("x->x_count: %d, x->x_distances[0]: %f, x->x_distances[1]: %f\n", x->x_count, x->x_distances[0], x->x_distances[1]);
	
	// Second intersection with a transformed sphere
	rt_set_sphere_transform(sp, rt_translation(5, 0, 0));
	t_intersect	*y = ft_calloc(1, sizeof(t_intersect));
	if (!y)
		printf("error malloc\n");
	y = rt_ray_sphere_x(ray_4, sp, sp->transform, y);
	printf("\nIntersecting a translated sphere with a ray:\n");
	printf("x->x_count: %d, x->x_distances[0]: %f, x->x_distances[1]: %f", y->x_count, y->x_distances[0], y->x_distances[1]);
	
	
}


void	test_transforms()
{
	printf("\n*********************************\nTesting chained transformations:\n*********************************\n");
	/* test 1: Individual transformations are applied in sequence
	Given p ← point(1, 0, 1)
	And A ← rotation_x(π / 2)
	And B ← scaling(5, 5, 5)
	And C ← translation(10, 5, 7) */
	t_tuple		*p = rt_point(1, 0, 1);
	t_matrix	*A = rt_rotation_x(90);
	t_matrix	*B = rt_scaling(5, 5, 5);
	t_matrix	*C = rt_translation(10, 5, 7);
	
	/* apply rotation first
	When p2 ← A * p
	Then p2 = point(1, -1, 0) */
	t_tuple *p2 = matrix_tuple_multiplication(A, p);
	printf("p2: {%3.f, %3.f, %3.f, %3.f}\n", p2->x, p2->y, p2->z, p2->w);

	/* 	then apply scaling
	When p3 ← B * p2
	Then p3 = point(5, -5, 0) */
	t_tuple *p3 = matrix_tuple_multiplication(B, p2);
	printf("p3: {%3.f, %3.f, %3.f, %3.f}\n", p3->x, p3->y, p3->z, p3->w);
	
	/* then apply translation
	When p4 ← C * p3
	Then p4 = point(15, 0, 7) */
	t_tuple *p4 = matrix_tuple_multiplication(C, p3);
	printf("p4: {%3.f, %3.f, %3.f, %3.f}\n", p4->x, p4->y, p4->z, p4->w);
	
	printf("now, chain matrix multiplications and then apply them at once on the initial tuple:\n");
	t_matrix *T = matrix_multiplication(C, matrix_multiplication(B, A));
	t_tuple	 *p0 = matrix_tuple_multiplication(T, p);
	printf("p0: {%3.f, %3.f, %3.f, %3.f}\n", p0->x, p0->y, p0->z, p0->w);
}


void	test_rotation()
{
	printf("\n*********************************\nTesting rotation transformations:\n*********************************\n");
	/* test 1: Rotating a point around the x axis
	Given p ← point(0, 1, 0)
	And half_quarter ← rotation_x(π / 4)
	And full_quarter ← rotation_x(π / 2)
	Then half_quarter * p = point(0, √2/2, √2/2)
	And full_quarter * p = point(0, 0, 1) */
	print_matrix(
				matrix_multiplication(
					rt_rotation_x((M_PI / 4) / (M_PI / 180)), 
					convert_tuple_to_matrix(rt_point(0, 1, 0)))
	);
	print_matrix(
				matrix_multiplication(
					rt_rotation_x((M_PI / 2) / (M_PI / 180)), 
					convert_tuple_to_matrix(rt_point(0, 1, 0)))
	);

	/* test 2: The inverse of an x-rotation rotates in the opposite direction
	Given p ← point(0, 1, 0)
	And half_quarter ← rotation_x(π / 4)
	And inv ← inverse(half_quarter)
	Then inv * p = point(0, √2/2, -√2/2)  */
	print_matrix(
			matrix_multiplication(
				matrix_inversion(rt_rotation_x((M_PI / 4) / (M_PI / 180))), 
				convert_tuple_to_matrix(rt_point(0, 1, 0)))
	);

	/* test 3: Rotating a point around the y axis
	Given p ← point(0, 0, 1)
	And half_quarter ← rotation_y(π / 4)
	And full_quarter ← rotation_y(π / 2)
	Then half_quarter * p = point(√2/2, 0, √2/2)
	And full_quarter * p = point(1, 0, 0) */
	print_matrix(
				matrix_multiplication(
					rt_rotation_y((M_PI / 4) / (M_PI / 180)), 
					convert_tuple_to_matrix(rt_point(0, 0, 1)))
	);
	print_matrix(
				matrix_multiplication(
					rt_rotation_y((M_PI / 2) / (M_PI / 180)), 
					convert_tuple_to_matrix(rt_point(0, 0, 1)))
	);
	/* test 4: Rotating a point around the z axis
	Given p ← point(0, 1, 0)
	And half_quarter ← rotation_z(π / 4)
	And full_quarter ← rotation_z(π / 2)
	Then half_quarter * p = point(-√2/2, √2/2, 0)
	And full_quarter * p = point(-1, 0, 0) */
	print_matrix(
				matrix_multiplication(
					rt_rotation_z((M_PI / 4) / (M_PI / 180)), 
					convert_tuple_to_matrix(rt_point(-1, 0, 0)))
	);
	print_matrix(
				matrix_multiplication(
					rt_rotation_z((M_PI / 2) / (M_PI / 180)), 
					convert_tuple_to_matrix(rt_point(0, 1, 0)))
	);	
}

void	test_scaling()
{
	printf("\n*********************************\nTesting scaling transformations:\n*********************************\n");
	/* test 1: A scaling matrix applied to a point
	Given transform ← scaling(2, 3, 4)
	And p ← point(-4, 6, 8)
	Then transform * p = point(-8, 18, 32) */
	print_matrix(
		matrix_multiplication(
			rt_scaling(2, 3, 4), 
			convert_tuple_to_matrix(rt_point(-4, 6, 8))));
			
	/* test 2: A scaling matrix applied to a vector
	Given transform ← scaling(2, 3, 4)
	And v ← vector(-4, 6, 8)
	Then transform * v = vector(-8, 18, 32) */
	print_matrix(
		matrix_multiplication(
			rt_scaling(2, 3, 4), 
			convert_tuple_to_matrix(rt_vector(-4, 6, 8))));

	/* test 3: Multiplying by the inverse of a scaling matrix
	Given transform ← scaling(2, 3, 4)
	And inv ← inverse(transform)
	And v ← vector(-4, 6, 8)
	Then inv * v = vector(-2, 2, 2) */
	print_matrix(
		matrix_multiplication(
			matrix_inversion(rt_scaling(2, 3, 4)), 
			convert_tuple_to_matrix(rt_point(-4, 6, 8))));

	/* test 4: Reflection is scaling by a negative value
	Given transform ← scaling(-1, 1, 1)
	And p ← point(2, 3, 4)
	Then transform * p = point(-2, 3, 4) */
	print_matrix(
		matrix_multiplication(
			rt_scaling(-1, 1, 1), 
			convert_tuple_to_matrix(rt_point(2, 3, 4))));
}

void	test_translation()
{
	printf("\n*********************************\nTesting translation transformations:\n*********************************\n");
	
	/* test 1: Multiplying by a translation matrix
	Given transform ← translation(5, -3, 2)
	And p ← point(-3, 4, 5)
	Then transform * p = point(2, 1, 7) */
	print_matrix(
		matrix_multiplication(
			rt_translation(5, -3, 2), 
			convert_tuple_to_matrix(rt_point(-3, 4, 5))));

	/*  test 2: Multiplying by the inverse of a translation matrix
	Given transform ← translation(5, -3, 2)
	And inv ← inverse(transform)
	And p ← point(-3, 4, 5)
	Then inv * p = point(-8, 7, 3 */
	print_matrix(
	matrix_multiplication(
		matrix_inversion(rt_translation(5, -3, 2)), 
		convert_tuple_to_matrix(rt_point(-3, 4, 5))));

	/* test 3: Translation does not affect vectors
	Given transform ← translation(5, -3, 2)
	And v ← vector(-3, 4, 5)
	Then transform * v = v */
	print_matrix(
	matrix_multiplication(
		rt_translation(5, -3, 2), 
		convert_tuple_to_matrix(rt_vector(-3, 4, 5))));

}

void	test_shear()
{
	printf("\n*********************************\nTesting shearing transformations:\n*********************************\n");

	/* test 0 :
	shearing(1, 0, 0, 0, 0, 0)
	And p ← point(2, 3, 4)
	Then transform * p = point(5, 3, 4)
 	*/
	print_matrix(
		matrix_multiplication(
			rt_shearing((float[6]) {1.0, 0.0, 0.0, 0.0, 0.0, 0.0}), 
			convert_tuple_to_matrix(rt_point(2, 3, 4))));

	/* test 1 :
	shearing(0, 1, 0, 0, 0, 0)
	And p ← point(2, 3, 4)
	Then transform * p = point(6, 3, 4)
 	*/
	print_matrix(
		matrix_multiplication(
			rt_shearing((float[6]) {0.0, 1.0, 0.0, 0.0, 0.0, 0.0}), 
			convert_tuple_to_matrix(rt_point(2, 3, 4))));

	/* test 2: 
	A shearing transformation moves y in proportion to x
	Given transform ← shearing(0, 0, 1, 0, 0, 0)
	And p ← point(2, 3, 4)
	Then transform * p = point(2, 5, 4) */
	print_matrix(
		matrix_multiplication(
			rt_shearing((float[6]) {0.0, 0.0, 1.0, 0.0, 0.0, 0.0}), 
			convert_tuple_to_matrix(rt_point(2, 3, 4))));

	/* test 3:
	A shearing transformation moves y in proportion to z
	Given transform ← shearing(0, 0, 0, 1, 0, 0)
	And p ← point(2, 3, 4)
	Then transform * p = point(2, 7, 4) */
	print_matrix(
		matrix_multiplication(
			rt_shearing((float[6]) {0.0, 0.0, 0.0, 1.0, 0.0, 0.0}), 
			convert_tuple_to_matrix(rt_point(2, 3, 4))));

	/* test 4:
	A shearing transformation moves z in proportion to x
	Given transform ← shearing(0, 0, 0, 0, 1, 0)
	And p ← point(2, 3, 4)
	Then transform * p = point(2, 3, 6) */
	print_matrix(
		matrix_multiplication(
			rt_shearing((float[6]) {0.0, 0.0, 0.0, 0.0, 1.0, 0.0}), 
			convert_tuple_to_matrix(rt_point(2, 3, 4))));

	/* test 5:
	A shearing transformation moves z in proportion to y
	Given transform ← shearing(0, 0, 0, 0, 0, 1)
	And p ← point(2, 3, 4)
	Then transform * p = point(2, 3, 7) */
		print_matrix(
		matrix_multiplication(
			rt_shearing((float[6]) {0.0, 0.0, 0.0, 0.0, 0.0, 1.0}), 
			convert_tuple_to_matrix(rt_point(2, 3, 4))));

}
