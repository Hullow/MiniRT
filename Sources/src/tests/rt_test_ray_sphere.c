/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test_sphere_draw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:26:58 by fallan            #+#    #+#             */
/*   Updated: 2025/04/19 17:28:38 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_open_window_and_draw(t_object sp);
void	rt_draw(t_env *env, t_object sp);
void	test_ray_sphere(void);

void	test_ray_sphere(void)
{
	t_object	sp;

	sp.coord = (t_tuple) {0, 0, 0, POINT};
	sp.diameter = 2.0;
	sp.color = (t_tuple) {255, 0, 0, COLOR};

	rt_open_window_and_draw(sp);	
}

void	rt_draw(t_env *env, t_object sp)
{
	int	h;
	int	v;
	
	h = 0;
	while (h < WINDOW_HEIGHT)
	{
		v = 0;
		while (v < WINDOW_WIDTH)
		{
			// if ray hits sphere, then put red pixel (otherwise nothing)
			
			my_mlx_pixel_put(env, v, WINDOW_HEIGHT - h, rgb_to_int(sp.color));
			v++;
		}
		h++;
	}
}

void	rt_open_window_and_draw(t_object sp)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	env.img = mlx_new_image(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, \
		&env.line_length, &env.endian);

	rt_draw(&env, sp);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	mlx_hook(env.win, 17, 0, window_closed, &env);
	mlx_loop(env.mlx);
}

/* 
// creates a new mlx window with
// hooks for key presses, launching
// key_handler, and for mouse clicks that
// close the window on event: ON_DESTROY = 17
void	launch_window_and_draw(t_list *point_list)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	env.img = mlx_new_image(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, \
	&env.line_length, &env.endian);
	env.point_list = point_list;
	ft_draw(&env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	mlx_hook(env.win, 17, 0, window_closed, &env);
	mlx_loop(env.mlx);
}
*/