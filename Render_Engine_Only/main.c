/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:13:25 by pberset           #+#    #+#             */
/*   Updated: 2025/06/02 18:26:10 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	rt_init_counters(t_scene *scene)
{
	scene->n_a = 0;
	scene->n_cam = 0;
	scene->n_l = 0;
	scene->n_sp = 0;
	scene->n_pl = 0;
	scene->n_cy = 0;
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
	if (rt_init_scene(argv[1], scene))
		return (5);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_scene		scene;
	t_object	objects[MAX_OBJECTS];
	//t_env		env;

	scene.objects = objects;
	if (build_scene(argc, argv, &scene))
		return (1);
	/*env = mlx_set_env();
	rt_render(scene.cam, scene, &env);
	mlx_run_window(&env);*/
	test_example_scene();
	return (0);
}
