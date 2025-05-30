/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:23:12 by pberset           #+#    #+#             */
/*   Updated: 2025/05/24 10:23:14 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_scene(t_scene scene)
{
	int	i;

	i = 0;
	while (i < scene.n_obj)
	{
		if (scene.objects[i].shape == SPHERE)
		{
			rt_print_sphere(scene.objects[i]);
		}
		else if (scene.objects[i].shape == PLANE)
		{
			rt_print_plane(scene.objects[i]);
		}
		else if (scene.objects[i].shape == CYLINDER)
		{
			rt_print_cylinder(scene.objects[i]);
		}
		ft_printf("\n");
		i++;
	}
}
