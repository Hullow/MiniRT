/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:55:48 by pberset           #+#    #+#             */
/*   Updated: 2025/04/13 21:40:27 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
		int i = 0;
		while (i < scene.n_obj)
		{
			switch(scene.objects[i].type)
			{
				case SPHERE:
					printf("Type: SPHERE\n");
					break ;
				case PLANE:
					printf("Type: PLANE\n");
					break ;
				case CYLINDER:
					printf("Type: CYLINDER\n");
					break ;
				default:
					printf("not an object\n");
			}
			printf("coord: %f\n", scene.objects[i].coord.x);
			printf("coord: %f\n", scene.objects[i].coord.y);
			printf("coord: %f\n", scene.objects[i].coord.z);
			i++;
		}
	}
}

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
		return (1);
	miniRT_input_tests(scene);
	return (0);
}
