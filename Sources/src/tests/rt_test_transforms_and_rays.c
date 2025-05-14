/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test_transforms_and_rays.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:36:33 by francis           #+#    #+#             */
/*   Updated: 2025/05/14 14:39:39 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	test_transforms_and_rays()
{
	// transformations:
	// test_translation();
	// test_scaling();
	// test_rotation();
	// test_shear();
	// test_transforms();
	// analog_clock();

	// rays, intersections, combinations
	// test_rays_positions();
	// test_ray_intersections_hits();
	test_transform_handling();
}

void	print_ray_intersections(t_ray *ray)
{
	if (!ray || !ray->intersects)
	{
		printf("print_ray_intersections: no intersections found for this ray\n");	
		return ;
	}
	t_intersect *iterator = NULL;
	t_list *anchor = ray->intersects;
	printf("ray %p intersects: \n", ray);
	while (ray->intersects)
	{
		iterator = ray->intersects->content;
		printf("  - object %p at t == %f\n", iterator->object, iterator->t);
		ray->intersects = ray->intersects->next;
	}
	ray->intersects = anchor;
}

void	test_ray_intersections_hits()
{
	printf("test_ray_intersections_hits():\n");

	// Test 1: A ray intersects a sphere at two points
	printf("Test 1: A ray intersects a sphere at two points\n");
	t_ray ray = rt_ray(rt_point(0, 0, -5), rt_vector(0, 0, 1));
	t_object s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0f, (t_tuple){0.5, 0.2, 0.1, COLOR});
	rt_ray_sphere_x(&ray, &s);
	print_ray_intersections(&ray);
	t_intersect *hit = rt_find_ray_hit(&ray);
	if (hit)
		printf("The hit is at t: %f (object: %p)\n", hit->t, hit->object);
	else
		printf("No hit found\n");
		
	// Test 2: A ray intersects a sphere at a tangent
	printf("\nTest 2: A ray intersects a sphere at a tangent\n");
	ray = rt_ray(rt_point(0, 1, -5), rt_vector(0, 0, 1));
	s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0, (t_tuple){0.5, 0.2, 0.1, COLOR});
	rt_ray_sphere_x(&ray, &s);
	print_ray_intersections(&ray);
	hit = rt_find_ray_hit(&ray);
	printf("The hit is at t: %f (object: %p)\n", hit->t, hit->object);
	
	// Test 3: A ray misses a sphere
	printf("\nTest 3: A ray misses a sphere\n");
	ray = rt_ray(rt_point(0, 2, -5), rt_vector(0, 0, 1));
	s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0, (t_tuple){0.5, 0.2, 0.1, COLOR});
	rt_ray_sphere_x(&ray, &s);
	print_ray_intersections(&ray);
	hit = rt_find_ray_hit(&ray);
	if (hit)
		printf("The hit is at t: %f (object: %p)\n", hit->t, hit->object);
	else
		printf("no hit found for this ray\n");
		
	// Test 4: A ray originates inside a sphere
	printf("\nTest 4: A ray originates inside a sphere\n");
	ray = rt_ray(rt_point(0, 0, 0), rt_vector(0, 0, 1));
	s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0, (t_tuple){0.5, 0.2, 0.1, COLOR});
	rt_ray_sphere_x(&ray, &s);
	print_ray_intersections(&ray);
	hit = rt_find_ray_hit(&ray);
	if (hit)
		printf("The hit is at t: %f (object: %p)\n", hit->t, hit->object);
	else
		printf("no hit found for this ray\n");
	
	// Test 5: A sphere is behind a ray
	printf("\nTest 5: A sphere is behind a ray\n");
	ray = rt_ray(rt_point(0, 0, 5), rt_vector(0, 0, 1));
	s = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2.0, (t_tuple){0.5, 0.2, 0.1, COLOR});
	rt_ray_sphere_x(&ray, &s);
	print_ray_intersections(&ray);
	hit = rt_find_ray_hit(&ray);
	if (hit)
		printf("The hit is at t: %f (object: %p)\n", hit->t, hit->object);
	else
		printf("no hit found for this ray\n");
}

void	test_transform_handling()
{
	printf("test_transform_handling\n\n");
	// printf("testing rt_transform_ray:\n");
	// t_tuple		pt = rt_point(1, 2, 3);
	// t_tuple		vec = rt_vector(0, 1, 0);

	// t_ray init_ray_3 = rt_ray(pt, vec);
	// t_ray	ray_3 = rt_transform_ray(&init_ray_3, rt_translation((t_tuple) {3, 4, 5, VECTOR}));
	// printf("\nthe translated ray:\n");
	// printf("- origin: (%f, %f, %f)\n- direction: (%f, %f, %f)\n", 
	// ray_3.origin.x, ray_3.origin.y, ray_3.origin.z,
	// ray_3.direction.x, ray_3.direction.y, ray_3.direction.z);
		
	// t_ray init_ray_2 = rt_ray(pt, vec);
	// t_ray	ray_2 = rt_transform_ray(&init_ray_2, rt_scaling((t_tuple) {2, 3, 4, VECTOR}));
	// printf("\nthe scaled ray:\n");
	// printf("- origin: (%f, %f, %f)\n- direction: (%f, %f, %f)\n\n", 
	// ray_2.origin.x, ray_2.origin.y, ray_2.origin.z,
	// ray_2.direction.x, ray_2.direction.y, ray_2.direction.z);

	t_object	sp = rt_init_sphere((t_tuple){0, 0, 0, POINT}, 2, (t_tuple) {0.5, 0.5, 0.5, COLOR});

	// Ray-sphere intersections
	t_ray	ray_4 = rt_ray(rt_point(0.0, 0.0, -5), rt_vector(0, 0, 1));
	
	// Intersection with a scaled sphere
	printf("\nIntersecting a scaled sphere with a ray:\n");
	sp.transform = rt_scaling((t_tuple) {2, 2, 2, VECTOR});
	sp.inverse = matrix_inversion(sp.transform);
	rt_ray_sphere_x(&ray_4, &sp);
	print_ray_intersections(&ray_4);
	t_intersect *hit = rt_find_ray_hit(&ray_4);
	if (hit)
		printf("The hit is at t: %f (object: %p)\n", hit->t, hit->object);
	else
		printf("No hit found\n");

	
	// Intersection with a translated sphere
	printf("\nIntersecting a translated sphere with a ray:\n");
	sp.transform = rt_translation((t_tuple) {5, 0, 0, VECTOR});
	sp.inverse = matrix_inversion(sp.transform);
	rt_ray_sphere_x(&ray_4, &sp);
	print_ray_intersections(&ray_4);
	hit = rt_find_ray_hit(&ray_4);
	if (hit)
		printf("The hit is at t: %f (object: %p)\n", hit->t, hit->object);
	else
		printf("No hit found\n");
}



// void	test_rays_positions()
// {
// 	t_tuple origin = rt_point(2, 3, 4);
// 	t_tuple direction = rt_vector(1, 0, 0);
// 	t_ray ray = rt_ray(origin, direction);
// 	printf("ray: origin is (%f, %f, %f)\n", ray.origin.x, ray.origin.y, ray.origin.z);
// 	printf("ray: direction is (%f, %f, %f)\n", ray.direction.x, ray.direction.y, ray.direction.z);
	
// 	t_tuple pos = rt_position(ray, 0);
// 	printf("position at t = 0 from the ray is (%f, %f, %f)\n", pos.x, pos.y, pos.z);
	
// 	pos = rt_position(ray, 1);
// 	printf("position at t = 1 from the ray is (%f, %f, %f)\n", pos.x, pos.y, pos.z);
	
// 	pos = rt_position(ray, -1);
// 	printf("position at t = -1 from the ray is (%f, %f, %f)\n", pos.x, pos.y, pos.z);
	
// 	pos = rt_position(ray, 2.5);
// 	printf("position at t = 2.5 from the ray is (%f, %f, %f)\n", pos.x, pos.y, pos.z);
// }

// void	test_transforms()
// {
// 	printf("\n*********************************\nTesting chained transformations:\n*********************************\n");
// 	/* test 1: Individual transformations are applied in sequence
// 	Given p ← point(1, 0, 1)
// 	And A ← rotation_x(π / 2)
// 	And B ← scaling(5, 5, 5)
// 	And C ← translation(10, 5, 7) */
// 	t_tuple		p = rt_point(1, 0, 1);
// 	t_matrix	A = rt_rotation_x(M_PI/2);
// 	t_matrix	B = rt_scaling((t_tuple){5, 5, 5, VECTOR});
// 	t_matrix	C = rt_translation((t_tuple) {10, 5, 7, VECTOR});
	
// 	/* apply rotation first
// 	When p2 ← A * p
// 	Then p2 = point(1, -1, 0) */
// 	t_tuple p2 = matrix_tuple_multiplication(A, p);
// 	printf("p2: {%3.f, %3.f, %3.f, %3.f}\n", p2.x, p2.y, p2.z, p2.w);

// 	/* 	then apply scaling
// 	When p3 ← B * p2
// 	Then p3 = point(5, -5, 0) */
// 	t_tuple p3 = matrix_tuple_multiplication(B, p2);
// 	printf("p3: {%3.f, %3.f, %3.f, %3.f}\n", p3.x, p3.y, p3.z, p3.w);
	
// 	/* then apply translation
// 	When p4 ← C * p3
// 	Then p4 = point(15, 0, 7) */
// 	t_tuple p4 = matrix_tuple_multiplication(C, p3);
// 	printf("p4: {%3.f, %3.f, %3.f, %3.f}\n", p4.x, p4.y, p4.z, p4.w);
	
// 	printf("now, chain matrix multiplications and then apply them at once on the initial tuple:\n");
// 	t_matrix T = matrix_multiplication(C, matrix_multiplication(B, A));
// 	t_tuple	 p0 = matrix_tuple_multiplication(T, p);
// 	printf("p0: {%3.f, %3.f, %3.f, %3.f}\n", p0.x, p0.y, p0.z, p0.w);
// }

// // void	test_rotation()
// // {
// // 	printf("\n*********************************\nTesting rotation transformations:\n*********************************\n");
// // 	/* test 1: Rotating a point around the x axis
// // 	Given p ← point(0, 1, 0)
// // 	And half_quarter ← rotation_x(π / 4)
// // 	And full_quarter ← rotation_x(π / 2)
// // 	Then half_quarter * p = point(0, √2/2, √2/2)
// // 	And full_quarter * p = point(0, 0, 1) */
// // 	print_matrix(
// // 				matrix_multiplication(
// // 					rt_rotation_x((M_PI / 4) / (M_PI / 180)), 
// // 					convert_tuple_to_matrix(rt_point(0, 1, 0)))
// // 	);
// // 	print_matrix(
// // 				matrix_multiplication(
// // 					rt_rotation_x((M_PI / 2) / (M_PI / 180)), 
// // 					convert_tuple_to_matrix(rt_point(0, 1, 0)))
// // 	);

// // 	/* test 2: The inverse of an x-rotation rotates in the opposite direction
// // 	Given p ← point(0, 1, 0)
// // 	And half_quarter ← rotation_x(π / 4)
// // 	And inv ← inverse(half_quarter)
// // 	Then inv * p = point(0, √2/2, -√2/2)  */
// // 	print_matrix(
// // 			matrix_multiplication(
// // 				matrix_inversion(rt_rotation_x((M_PI / 4) / (M_PI / 180))), 
// // 				convert_tuple_to_matrix(rt_point(0, 1, 0)))
// // 	);

// // 	/* test 3: Rotating a point around the y axis
// // 	Given p ← point(0, 0, 1)
// // 	And half_quarter ← rotation_y(π / 4)
// // 	And full_quarter ← rotation_y(π / 2)
// // 	Then half_quarter * p = point(√2/2, 0, √2/2)
// // 	And full_quarter * p = point(1, 0, 0) */
// // 	print_matrix(
// // 				matrix_multiplication(
// // 					rt_rotation_y((M_PI / 4) / (M_PI / 180)), 
// // 					convert_tuple_to_matrix(rt_point(0, 0, 1)))
// // 	);
// // 	print_matrix(
// // 				matrix_multiplication(
// // 					rt_rotation_y((M_PI / 2) / (M_PI / 180)), 
// // 					convert_tuple_to_matrix(rt_point(0, 0, 1)))
// // 	);
// // 	/* test 4: Rotating a point around the z axis
// // 	Given p ← point(0, 1, 0)
// // 	And half_quarter ← rotation_z(π / 4)
// // 	And full_quarter ← rotation_z(π / 2)
// // 	Then half_quarter * p = point(-√2/2, √2/2, 0)
// // 	And full_quarter * p = point(-1, 0, 0) */
// // 	print_matrix(
// // 				matrix_multiplication(
// // 					rt_rotation_z((M_PI / 4) / (M_PI / 180)), 
// // 					convert_tuple_to_matrix(rt_point(-1, 0, 0)))
// // 	);
// // 	print_matrix(
// // 				matrix_multiplication(
// // 					rt_rotation_z((M_PI / 2) / (M_PI / 180)), 
// // 					convert_tuple_to_matrix(rt_point(0, 1, 0)))
// // 	);	
// // }


// // void	test_scaling()
// // {
// // 	printf("\n*********************************\nTesting scaling transformations:\n*********************************\n");
// // 	/* test 1: A scaling matrix applied to a point
// // 	Given transform ← scaling(2, 3, 4)
// // 	And p ← point(-4, 6, 8)
// // 	Then transform * p = point(-8, 18, 32) */
// // 	print_matrix(
// // 		matrix_multiplication(
// // 			rt_scaling(2, 3, 4), 
// // 			convert_tuple_to_matrix(rt_point(-4, 6, 8))));
			
// // 	/* test 2: A scaling matrix applied to a vector
// // 	Given transform ← scaling(2, 3, 4)
// // 	And v ← vector(-4, 6, 8)
// // 	Then transform * v = vector(-8, 18, 32) */
// // 	print_matrix(
// // 		matrix_multiplication(
// // 			rt_scaling(2, 3, 4), 
// // 			convert_tuple_to_matrix(rt_vector(-4, 6, 8))));

// // 	/* test 3: Multiplying by the inverse of a scaling matrix
// // 	Given transform ← scaling(2, 3, 4)
// // 	And inv ← inverse(transform)
// // 	And v ← vector(-4, 6, 8)
// // 	Then inv * v = vector(-2, 2, 2) */
// // 	print_matrix(
// // 		matrix_multiplication(
// // 			matrix_inversion(rt_scaling(2, 3, 4)), 
// // 			convert_tuple_to_matrix(rt_point(-4, 6, 8))));

// // 	/* test 4: Reflection is scaling by a negative value
// // 	Given transform ← scaling(-1, 1, 1)
// // 	And p ← point(2, 3, 4)
// // 	Then transform * p = point(-2, 3, 4) */
// // 	print_matrix(
// // 		matrix_multiplication(
// // 			rt_scaling(-1, 1, 1), 
// // 			convert_tuple_to_matrix(rt_point(2, 3, 4))));
// // }

// // void	test_translation()
// // {
// // 	printf("\n*********************************\nTesting translation transformations:\n*********************************\n");
	
// // 	/* test 1: Multiplying by a translation matrix
// // 	Given transform ← translation(5, -3, 2)
// // 	And p ← point(-3, 4, 5)
// // 	Then transform * p = point(2, 1, 7) */
// // 	print_matrix(
// // 		matrix_multiplication(
// // 			rt_translation(5, -3, 2), 
// // 			convert_tuple_to_matrix(rt_point(-3, 4, 5))));

// // 	/*  test 2: Multiplying by the inverse of a translation matrix
// // 	Given transform ← translation(5, -3, 2)
// // 	And inv ← inverse(transform)
// // 	And p ← point(-3, 4, 5)
// // 	Then inv * p = point(-8, 7, 3 */
// // 	print_matrix(
// // 	matrix_multiplication(
// // 		matrix_inversion(rt_translation(5, -3, 2)), 
// // 		convert_tuple_to_matrix(rt_point(-3, 4, 5))));

// // 	/* test 3: Translation does not affect vectors
// // 	Given transform ← translation(5, -3, 2)
// // 	And v ← vector(-3, 4, 5)
// // 	Then transform * v = v */
// // 	print_matrix(
// // 	matrix_multiplication(
// // 		rt_translation(5, -3, 2), 
// // 		convert_tuple_to_matrix(rt_vector(-3, 4, 5))));

// // }

// void	test_shear()
// {
// 	printf("\n*********************************\nTesting shearing transformations:\n*********************************\n");

// 	/* test 0 :
// 	shearing(1, 0, 0, 0, 0, 0)
// 	And p ← point(2, 3, 4)
// 	Then transform * p = point(5, 3, 4)
//  	*/
// 	print_matrix(
// 		matrix_multiplication(
// 			rt_shearing((float[6]) {1.0, 0.0, 0.0, 0.0, 0.0, 0.0}), 
// 			convert_tuple_to_matrix(rt_point(2, 3, 4))));

// 	/* test 1 :
// 	shearing(0, 1, 0, 0, 0, 0)
// 	And p ← point(2, 3, 4)
// 	Then transform * p = point(6, 3, 4)
//  	*/
// 	print_matrix(
// 		matrix_multiplication(
// 			rt_shearing((float[6]) {0.0, 1.0, 0.0, 0.0, 0.0, 0.0}), 
// 			convert_tuple_to_matrix(rt_point(2, 3, 4))));

// 	/* test 2: 
// 	A shearing transformation moves y in proportion to x
// 	Given transform ← shearing(0, 0, 1, 0, 0, 0)
// 	And p ← point(2, 3, 4)
// 	Then transform * p = point(2, 5, 4) */
// 	print_matrix(
// 		matrix_multiplication(
// 			rt_shearing((float[6]) {0.0, 0.0, 1.0, 0.0, 0.0, 0.0}), 
// 			convert_tuple_to_matrix(rt_point(2, 3, 4))));

// 	/* test 3:
// 	A shearing transformation moves y in proportion to z
// 	Given transform ← shearing(0, 0, 0, 1, 0, 0)
// 	And p ← point(2, 3, 4)
// 	Then transform * p = point(2, 7, 4) */
// 	print_matrix(
// 		matrix_multiplication(
// 			rt_shearing((float[6]) {0.0, 0.0, 0.0, 1.0, 0.0, 0.0}), 
// 			convert_tuple_to_matrix(rt_point(2, 3, 4))));

// 	/* test 4:
// 	A shearing transformation moves z in proportion to x
// 	Given transform ← shearing(0, 0, 0, 0, 1, 0)
// 	And p ← point(2, 3, 4)
// 	Then transform * p = point(2, 3, 6) */
// 	print_matrix(
// 		matrix_multiplication(
// 			rt_shearing((float[6]) {0.0, 0.0, 0.0, 0.0, 1.0, 0.0}), 
// 			convert_tuple_to_matrix(rt_point(2, 3, 4))));

// 	/* test 5:
// 	A shearing transformation moves z in proportion to y
// 	Given transform ← shearing(0, 0, 0, 0, 0, 1)
// 	And p ← point(2, 3, 4)
// 	Then transform * p = point(2, 3, 7) */
// 		print_matrix(
// 		matrix_multiplication(
// 			rt_shearing((float[6]) {0.0, 0.0, 0.0, 0.0, 0.0, 1.0}), 
// 			convert_tuple_to_matrix(rt_point(2, 3, 4))));

// }
