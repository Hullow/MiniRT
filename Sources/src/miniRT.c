/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:55:48 by pberset           #+#    #+#             */
/*   Updated: 2025/03/04 17:58:26 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

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
	printf("assign light %f\n", scene->lux->color->x);
	printf("assign light %f\n", scene->lux->color->y);
	printf("assign light %f\n", scene->lux->color->z);
	return (0);
}
