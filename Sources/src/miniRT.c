/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:55:48 by pberset           #+#    #+#             */
/*   Updated: 2025/03/24 16:06:44 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	miniRT_input_tests(t_scene scene);

static void	rt_init_counters(t_scene *scene)
{
	scene->n_A = 0;
	scene->n_C = 0;
	scene->n_L = 0;
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
	if (rt_malloc_objects(scene))
		return (4);
	if (rt_init_scene(argv[1], scene))
		return (5);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (build_scene(argc, argv, &scene))
		return (2);
	miniRT_input_tests(scene);
	return (0);
}

void	miniRT_input_tests(t_scene scene)
{
	if (!errno)
	{
		printf("light coords x: %f y: %f z: %f\n", scene.lux.coord.x, scene.lux.coord.y, scene.lux.coord.z);
		printf("light ratio : %f\n", scene.lux.ratio);
		printf("light color R: %f G: %f B: %f\n", scene.lux.color.x, scene.lux.color.y, scene.lux.color.z);
		printf("ambient ratio : %f\n", scene.amb.ratio);
		printf("ambient color R: %f G: %f B: %f\n", scene.amb.color.x, scene.amb.color.y, scene.amb.color.z);
		printf("camera coords x: %f y: %f z: %f\n", scene.cam.coord.x, scene.cam.coord.y, scene.cam.coord.z);
		printf("camera orient x: %f y: %f z: %f\n", scene.cam.orient.x, scene.cam.orient.y, scene.cam.orient.z);
		printf("camera fov: %f\n", scene.cam.fov);
		printf("sphere coords x: %f y: %f z: %f\n", scene.objects->coord.x, scene.objects->coord.y, scene.objects->coord.z);
		printf("sphere diameter : %f\n", scene.objects->diameter);
		printf("sphere color R: %f G: %f B: %f\n", scene.objects->color.x, scene.objects->color.y, scene.objects->color.z);
		printf("plane coords x: %f y: %f z: %f\n", scene.objects->coord.x, scene.objects->coord.y, scene.objects->coord.z);
		printf("plane normal x: %f y: %f z: %f\n", scene.objects->norm.x, scene.objects->norm.y, scene.objects->norm.z);
		printf("plane color R: %f G: %f B: %f\n", scene.objects->color.x, scene.objects->color.y, scene.objects->color.z);
		printf("cylinder coords x: %f y: %f z: %f\n", scene.objects->coord.x, scene.objects->coord.y, scene.objects->coord.z);
		printf("cylinder normal x: %f y: %f z: %f\n", scene.objects->norm.x, scene.objects->norm.y, scene.objects->norm.z);
		printf("cylinder diameter : %f\n", scene.objects->diameter);
		printf("cylinder height : %f\n", scene.objects->height);
		printf("cylinder color R: %f G: %f B: %f\n", scene.objects->color.x, scene.objects->color.y, scene.objects->color.z);
	}
}
