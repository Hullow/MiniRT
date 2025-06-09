/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:28:27 by francis           #+#    #+#             */
/*   Updated: 2025/06/07 11:29:37 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	test_decentered_sphere()
{
	t_scene		scene;
	t_camera	camera;
	t_object	sphere_1;

	// light (L  -0.0,0.0,-20.0     1.0               255,255,255)
	scene.lux.coord = rt_point(-0.0,0.0,-20.00);
	scene.lux.intensity = 1.0;
	scene.lux.color = rt_color(255, 255, 255);

	// ambient (A  0.2   255,255,255)
	scene.lux.ambient.intensity = 0.2;
	scene.lux.ambient.color = rt_color(255, 255, 255);

	// camera (C  0,0,-15      0,0,1        70)
	camera.coord = rt_point(0, 0, -15);
	camera.orient = rt_vector(0, 0, 1);
	camera.field_of_view = 70 * (M_PI / 180);
	camera.hsize = WINDOW_WIDTH;
	camera.vsize = WINDOW_HEIGHT;
	rt_calculate_camera_values(&camera);

	// sphere (sp  -2,0,0    2    0,255,0)
	sphere_1 = rt_sphere(rt_color(0, 255, 0));
	sphere_1.transform = rt_translation(rt_vector(-2, 0, 0));

	// scene objects
	scene.n_obj = 1;
	t_object	scene_objects[1];
	scene_objects[0] = sphere_1;
	scene.objects = scene_objects;

	// mlx + render
	t_env	env;
	env = mlx_set_env();
	rt_render(&camera, &scene, &env);
	mlx_run_window(&env);
}


void	test_self_shadow()
{
	t_scene		scene;
	t_camera	camera;
	// t_object	sphere_1;
	t_object	plane_1;


	// light (L  -10.0,10.0,-16.0     0.6                  255,255,255)
	scene.lux.coord = rt_point(-10.0,10.0,-16.0);
	scene.lux.intensity = 0.6;
	scene.lux.color = rt_color(255, 255, 255);

	// ambient (A  0.2   255,255,255)
	scene.lux.ambient.intensity = 0.2;
	scene.lux.ambient.color = rt_color(255, 255, 255);

	// camera (C  0,4.5,-12     0,-0.35,1      60)
	camera.coord = rt_point(0,4.5,-12);
	camera.orient = rt_vector(0,-0.35,1);
	camera.field_of_view = 60 * (M_PI / 180);
	camera.hsize = WINDOW_WIDTH;
	camera.vsize = WINDOW_HEIGHT;
	rt_calculate_camera_values(&camera);

	// sphere (sp  -0.5,1,0.5      2       25,255,127)
	// sphere_1 = rt_sphere(rt_color(25,255,127));
	// sphere_1.transform = rt_translation(rt_vector(-0.5,1,0.5));

	// plane (pl  0,0,0       0.0,1.0,0.0       255,230,230)
	plane_1 = rt_plane(rt_color(255,230,230));

	// scene objects
	scene.n_obj = 1;
	t_object	scene_objects[1];
	scene_objects[0] = plane_1;
	// scene_objects[0] = sphere_1;
	scene.objects = scene_objects;

	// mlx + render
	t_env	env;
	env = mlx_set_env();
	rt_render(&camera, &scene, &env);
	mlx_run_window(&env);
}