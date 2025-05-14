/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test_projectile_sim.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:35:34 by fallan            #+#    #+#             */
/*   Updated: 2025/05/14 13:38:18 by francis          ###   ########.fr       */
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
