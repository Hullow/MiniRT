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
	return (0);
}
