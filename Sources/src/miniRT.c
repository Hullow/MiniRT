/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                            :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:55:48 by pberset           #+#    #+#             */
/*   Updated: 2025/02/21 17:38:05 by pberset        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (argc != 2)
	{
		ft_puterr_fd("error: one <file>.rt expected\n");
		return (1);
	}
	if (rt_check_ext(argv[1]))
		return (2);
	scene = rt_extract_scene(argv[1]);
	if (!scene)
		return (3);
	if (rt_check_scene(argv[1]))
		return (4);
	return (0);
}
