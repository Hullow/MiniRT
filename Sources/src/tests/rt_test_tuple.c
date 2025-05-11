/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test_tuple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:35:34 by fallan            #+#    #+#             */
/*   Updated: 2025/04/18 18:30:42 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

/* void			free_projectile_and_environment(t_projectile proj, t_environment env);
t_environment	init_environment(t_tuple gravity, t_tuple wind);
t_projectile	*init_projectile(t_tuple position, t_tuple velocity);
t_projectile	*tick(t_environment env, t_projectile proj);
void			test_proj_sim(); */

/* initiates a environment t_environment, given:
- an initial position (a t_tuple POINT)
- an initial wind (a t_tuple VECTOR)
if either position and/or wind is NULL, sets default values */
 t_environment	init_environment(t_tuple gravity, t_tuple wind)
{
	t_environment	env;

	// if (!gravity)
	// {
	// 	gravity = malloc (sizeof(t_tuple));
	// 	if (!gravity)
	// 		return (NULL);
		// gravity = rt_vector(0, -0.1, 0);
	// 	printf("environment initial gravity set to default (0, -2, 0)\n");
	// }
	// if (!wind)
	// {
	// 	wind = malloc (sizeof(t_tuple));
	// 	if (!wind)
	// 		return (NULL);
		// wind = rt_vector(-0.01, 0, 0);
	// 	printf("environment initial wind set to default (0.2, 0.1, -0.05)\n");
	// }
	// env = malloc (sizeof(t_environment));
	// if (!env)
	// 	return (NULL);
	env.gravity = gravity;
	env.wind = wind;
	return (env);
}

/* initiates a projectile t_projectile, given:
- an initial position (a t_tuple POINT)
- an initial velocity (a t_tuple VECTOR)
if either position and/or velocity is NULL, sets default values */
t_projectile	init_projectile(t_tuple position, t_tuple velocity)
{
	t_projectile 	proj;

	// if (!position)
	// {
	// 	position = malloc (sizeof(t_tuple));
	// 	if (!position)
	// 		return (NULL);
		// position = rt_point(0, 1, 0);
	// 	printf("projectile initial position set to default (0, 1, 0)\n");
	// }
	// if (!velocity)
	// {
	// 	velocity = malloc (sizeof(t_tuple));
	// 	if (!velocity)
	// 		return (NULL);
		// velocity = rt_vector(3, 0.2, 0);
	// 	printf("projectile initial velocity set to default (2, 0, 0)\n");
	// }
	// proj = malloc (sizeof(t_projectile));
	// if (!proj)
	// 	return (NULL);
	proj.position = position;
	proj.velocity = velocity;
	return (proj);
}

/* updates and returns projectile position and velocity based on 
initial params + environment */
t_projectile	tick(t_environment env, t_projectile proj)
{
	proj.position = add_tuple(proj.position, proj.velocity);
	proj.velocity = add_tuple(proj.velocity, env.gravity);
	proj.velocity = add_tuple(proj.velocity, env.wind);
	printf("tick: position is now (%f, %f, %f)\n", proj.position.x, proj.position.y, proj.position.z);
	return (proj);
}

/* a function to simulate a projectile ballistic flight,
used as a test implementation of our tuple handling functions */
void	test_proj_sim()
{
	t_projectile proj = init_projectile(rt_point(0, 1, 0), rt_vector(3, 0.2, 0));
	t_environment	env = init_environment(rt_vector(0, -0.1, 0),rt_vector(-0.01, 0, 0));
	int	count = 0;

	while (proj.position.y >= 0)
	{
		proj = tick(env, proj);
		count++;
		sleep(1);
	}
	printf("proj has hit the ground at position (%f, %f, %f) with velocity (%f, %f, %f) after %d ticks\nstopping simulation\n",
	proj.position.x, proj.position.y, proj.position.z,
	proj.velocity.x, proj.velocity.y, proj.velocity.z, count);
	// free_projectile_and_environment(proj, env);
}

/* main to test the functions */
void	test_tuple()
{
	// test_proj_sim();

	// t_tuple neg_b = rt_vector(-0.1000001, 0.4, -15.0);
	// t_tuple p = (t_tuple){4, -4, 3, 0};
	// t_tuple c = rt_vector(-2, -4, -6);
	// t_tuple a = rt_vector(1, -2, 3);
	// t_tuple b = rt_vector(5, 6, 7);
	// t_tuple double_b = rt_vector(10, 12, 14);


	// printf("a has coordinates x: %f, y:%f, z:%f and is a ", a.x, a.y, a.z);
	// if (a.w == POINT)
	// 	printf("point\n");
	// else
	// 	printf("vector\n");
	// printf("b has coordinates x: %f, y:%f, z:%f and is a ", b.x, b.y, b.z);
	// if (b.w == POINT)
	// 	printf("point\n");
	// else
	// 	printf("vector\n");

	// if (p.w == POINT)
	// 	printf("p is a point\n");
	// else if (p.w == VECTOR)
	// 	printf("p is a vector\n");
		

	// if (is_equal_float(a.x, b.x))
	// 	printf("a.x and b.x are equal\n");
	// else
	// 	printf("a.x and b.x are not equal\n");
	// if (is_equal_tuple(add_tuple(a, b), c))
	// 	printf("adding tuples: a+b == c\n");
	// else
	// 	printf("adding tuples: a+b != c\n");
	
	// if (is_equal_tuple(subtract_tuple(a, b), c))
	// 	printf("subtracting tuples: a-b == c\n");
	// else
	// 	printf("subtracting tuples: a-b != c\n");

	// if (is_equal_tuple(negate_tuple(a), c))
	// 	printf("negate a == c\n");
	// else
	// 	printf("negate a != c\n");

	
	// MULTIPLICATIONS
	// if (is_equal_tuple(multiply_tuple_by_scalar(b, 1), b))
	// 	printf("multiply b by 1 == b\n");
	// else
	// 	printf("multiply b by 1 != b\n");
	// if (is_equal_tuple(divide_tuple_by_scalar(b, 1), b))
	// 	printf("divide b by 1 == b\n");
	// else
	// 	printf("divide b by 1 != b\n");
	// if (is_equal_tuple(divide_tuple_by_scalar(b, 0), rt_vector(0,0,0)))
	// 	printf("divide b by 0 == 0\n");
	// else
	// 	printf("divide b by 0 != 0\n");
	// if (is_equal_tuple(divide_tuple_by_scalar(double_b, 2), b))
	// 	printf("divide double_b by 2 == b\n");
	// else
	// 	printf("divide double_b by 2 != b\n");
	// if (is_equal_tuple(multiply_tuple_by_scalar(b, 2), double_b))
	// 	printf("multiply b by 2 == double_b\n");
	// else
	// 	printf("multiply b by 2 != double_b\n");

	// if (is_equal_tuple(multiply_tuple_by_scalar(b, 0), rt_vector(0,0,0)))
	// 	printf("multiply b by 0 == 0\n");
	// else
	// 	printf("multiply b by 0 != 0\n");


	/* magnitude, dot product, cross product */
	/*****************************************/
	// t_tuple	sample_vector = rt_vector(1, 2, 3);
	// printf("sample vector has magnitude: %f; squared: %f\n", magnitude(sample_vector), powf(magnitude(sample_vector), 2));
	// t_tuple	normd = normalize(sample_vector);
	// printf("sample vector normalised is (%f, %f, %f) and has magnitude %f\n", normd.x, normd.y, normd.z, magnitude(normd));
	
	// printf("dot product of sample vector and another vector is %f\n", dot_product(sample_vector, rt_vector(2, 3, 4)));

	// t_tuple	cross = cross_product(rt_vector(1, 2, 3), rt_vector(2, 3, 4));
	// t_tuple	cross2 = cross_product(rt_vector(2, 3, 4), rt_vector(1, 2, 3));
	// printf("the cross product (0, -1, 0) x (0, 0, -1) is (%f, %f, %f)\n", cross.x, cross.y, cross.z);
	// printf("the cross product (0, 0, -1) x (0, -1, 0) is (%f, %f, %f)\n", cross2.x, cross2.y, cross2.z);
	

}
