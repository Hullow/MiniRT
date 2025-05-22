/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:39:51 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 10:00:19 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

/*
void	rt_draw(t_env *env, t_object obj, t_ray ray)
{
	float		wall_z;
	float		h;
	float		w;
	t_xs		xs;
	t_inter		inter[2];
	int			noneed = 0;

	wall_z = 5;
	h = 0;
	xs.inter = inter;
	while (h < WINDOW_HEIGHT)
	{
		w = 0;
		while (w < WINDOW_WIDTH)
		{
			ray = rt_define_ray_to_wall(ray, w, h, wall_z);
			if (rt_intersects(obj, ray, xs.inter, &noneed).count != 0)
			{
				my_mlx_pixel_put(env, (int) w, WINDOW_HEIGHT - (int) h, \
				rgb_to_int(obj.color));
			}
			else
			{
				my_mlx_pixel_put(env, (int) w, WINDOW_HEIGHT - (int) h, \
				rgb_to_int((t_tuple){1, 1, 1, COLOR}));
			}
			w++;
		}
		h++;
	}
}
*/

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
	printf("Window closed, program stopping\n");
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->mlx_win);
	// exit(1);
	return (0);
}