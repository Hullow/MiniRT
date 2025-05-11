/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:41:51 by pberset           #+#    #+#             */
/*   Updated: 2025/05/08 10:41:53 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_env	mlx_set_env()
{
	t_env		env;

	env.mlx = mlx_init();
	env.mlx_win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "env");
	env.img = mlx_new_image(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env.addr = mlx_get_data_addr \
		(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);
	return (env);
}

void	mlx_run_window(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img, 0, 0);
	mlx_hook(env->mlx_win, 2, 1L << 0, key_handler, &env);
	mlx_hook(env->mlx_win, 17, 1L << 17, window_closed, &env);
	mlx_loop(env->mlx);
}
