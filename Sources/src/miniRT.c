/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:55:48 by pberset           #+#    #+#             */
/*   Updated: 2025/02/27 11:19:46 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

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
	if (rt_extract_scene(argv[1], scene))
		return (4);
	if (rt_check_scene(argv[1]))
		return (5);
	return (0);
}
