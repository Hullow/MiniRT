/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:13:25 by pberset           #+#    #+#             */
/*   Updated: 2025/06/09 23:16:00 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	rt_init_counters(t_scene *scene)
{
	scene->n_a = 0;
	scene->n_cam = 0;
	scene->n_l = 0;
	scene->n_obj = 0;
}

static int	build_scene(int argc, char *argv[], t_scene *scene)
{
	errno = 0;
	if (argc != 2)
	{
		errno = EBADF;
		perror("Error\nmissing \".rt\" file");
		return (1);
	}
	if (rt_check_ext(argv[1]))
		return (2);
	rt_init_counters(scene);
	if (rt_read_id(argv[1], scene))
		return (3);
	if (rt_check_uniques(scene))
		return (4);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_scene		scene;
	t_object	objects[MAX_OBJECTS];
	t_env		env;

	scene.objects = objects;
	if (build_scene(argc, argv, &scene))
		return (1);
	env = mlx_set_env();
	if (scene.n_obj > 0)
		rt_render(&(scene.cam), &scene, &env);
	mlx_run_window(&env);
	return (0);
}

/*int	main(int argc, char *argv[])
{
	t_scene		scene;
	t_object	objects[MAX_OBJECTS];

	scene.objects = objects;
	if (build_scene(argc, argv, &scene))
		return (1);
	printf("nobj %d\nsphere1.color rgb %f %f %f\n", scene.n_obj, scene.objects[0].color.x, scene.objects[0].color.y, scene.objects[0].color.z);
	printf("sphere2.color rgb %f %f %f\n", scene.objects[1].color.x, scene.objects[1].color.y, scene.objects[1].color.z);
	printf("sphere1.origin xyz %f %f %f\n", scene.objects[0].origin.x, scene.objects[0].origin.y, scene.objects[0].origin.z);
	printf("sphere2.origin xyz %f %f %f\n", scene.objects[1].origin.x, scene.objects[1].origin.y, scene.objects[1].origin.z);
	printf("sphere1.radius %f\n", scene.objects[0].radius);
	printf("sphere2.radius %f\n", scene.objects[1].radius);
	return (0);
}*/
