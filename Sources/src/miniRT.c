/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:55:48 by pberset           #+#    #+#             */
/*   Updated: 2025/03/14 14:32:54 by fallan           ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_scene	*scene;

	errno = 0;
	if (argc != 2)
	{
		ft_puterr_fd("error: one <file>.rt expected\n");
		return (1);
	}
	if (rt_check_ext(argv[1]))
		return (2);
	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (scene == NULL)
	{
		ft_puterr_fd("error: failed to malloc scene\n");
		return (3);
	}
	rt_init_counters(scene);
	if (rt_read_id(argv[1], scene))
		return (4);
	if (rt_malloc_objects(scene))
		return (5);
	if (rt_init_scene(argv[1], scene))
		return (6);
	if (!errno)
	{
		printf("light coords x: %f y: %f z: %f\n", scene->lux->coord->x, scene->lux->coord->y, scene->lux->coord->z);
		printf("light ratio : %f\n", scene->lux->ratio);
		printf("light color R: %f G: %f B: %f\n", scene->lux->color->x, scene->lux->color->y, scene->lux->color->z);
		printf("ambient ratio : %f\n", scene->amb->ratio);
		printf("ambient color R: %f G: %f B: %f\n", scene->amb->color->x, scene->amb->color->y, scene->amb->color->z);
		printf("camera coords x: %f y: %f z: %f\n", scene->cam->coord->x, scene->cam->coord->y, scene->cam->coord->z);
		printf("camera orient x: %f y: %f z: %f\n", scene->cam->orient->x, scene->cam->orient->y, scene->cam->orient->z);
		printf("camera fov: %f\n", scene->cam->fov);
		printf("sphere coords x: %f y: %f z: %f\n", scene->sp->coord->x, scene->sp->coord->y, scene->sp->coord->z);
		printf("sphere diameter : %f\n", scene->sp->diameter);
		printf("sphere color R: %f G: %f B: %f\n", scene->sp->color->x, scene->sp->color->y, scene->sp->color->z);
		printf("plane coords x: %f y: %f z: %f\n", scene->pl->coord->x, scene->pl->coord->y, scene->pl->coord->z);
		printf("plane normal x: %f y: %f z: %f\n", scene->pl->norm->x, scene->pl->norm->y, scene->pl->norm->z);
		printf("plane color R: %f G: %f B: %f\n", scene->pl->color->x, scene->pl->color->y, scene->pl->color->z);
		printf("cylinder coords x: %f y: %f z: %f\n", scene->cy->coord->x, scene->cy->coord->y, scene->cy->coord->z);
		printf("cylinder normal x: %f y: %f z: %f\n", scene->cy->norm->x, scene->cy->norm->y, scene->cy->norm->z);
		printf("cylinder diameter : %f\n", scene->cy->diameter);
		printf("cylinder height : %f\n", scene->cy->height);
		printf("cylinder color R: %f G: %f B: %f\n", scene->cy->color->x, scene->cy->color->y, scene->cy->color->z);
	}
	return (0);
}
