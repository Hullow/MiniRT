/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.c                                            :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:39:51 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 10:08:06 by fallan         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// draws a pixel
// the if checks if a pixel is outside the window,
// and ignores it (to avoid a segfault)
void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	if (y > WINDOW_HEIGHT || x > WINDOW_WIDTH)
		return ;
	dst = env->addr + (y * env->line_length + x * (env->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// key hook handler for key pressing events:
// 1. ESC closes the window and stops the program
// 2. any other key launches the graph drawing functions
// and displays the output in a mlx-handled window
int	key_handler(int keycode, t_env *env)
{
	(void)env;
	printf("keycode: %d\n", keycode);
	if (keycode)
		printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("ESC key pressed, program stopping\n");
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->mlx_win);
		exit(1);
	}
	return (0);
}

// program closer, is called if the window is closed with the mouse
int	window_closed(t_env *env)
{
	(void)env;
	printf("Window closed, program stopping\n");
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->mlx_win);
	// exit(1);
	return (0);
}

t_env	mlx_set_env(void)
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
