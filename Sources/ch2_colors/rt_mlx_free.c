/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:01:39 by pberset           #+#    #+#             */
/*   Updated: 2025/06/03 14:01:41 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	mlx_free_all(t_env *env)
{
	if (env && env->mlx)
	{
		if (env->img)
		{
			mlx_destroy_image(env->mlx, env->img);
			env->img = NULL;
		}
		if (env->mlx_win)
		{
			mlx_destroy_window(env->mlx, env->mlx_win);
			env->mlx_win = NULL;
		}
		if (env->mlx)
		{
			mlx_destroy_display(env->mlx);
			free(env->mlx);
			env->mlx = NULL;
		}
	}
	exit(0);
}
