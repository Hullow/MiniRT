/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:22:54 by fallan            #+#    #+#             */
/*   Updated: 2024/05/15 17:55:06 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900
#define WINDOW_NAME "Fil de Fer"

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

// key hook handler for key pressing events:
// 1. ESC closes the window and stops the program
// 2. any other key launches the graph drawing functions
// and displays the output in a mlx-handled window
int	key_handler(int keycode, t_env *env)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == 53)
	{
		ft_printf("ESC key pressed, program stopping\n");
		ft_free_list(env->point_list);
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		// exit(1);
	}
	return (0);
}

// program closer, is called if the window is closed with the mouse
int	window_closed(t_env *env)
{
	ft_printf("Window closed, program stopping\n");
	ft_free_list(env->point_list);
	mlx_destroy_window(env->mlx, env->win);
	// exit(1);
	return (0);
}

// the main function opens the file,
// sends it to the input handling functions,
// then calls the window/event handling functions,
// which call the graph handling and drawing functions
int	main(int argc, char *argv[])
{
	int		fd;
	t_list	*point_list;
	t_list	*anchor;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror(argv[1]);
		else
		{
			ft_printf("%s opened\n", argv[1]);
			point_list = ft_file_to_list(fd, argv[1]);
			anchor = point_list;
			launch_window_and_draw(point_list);
			ft_free_list(anchor);
		}
	}
	else
		ft_printf("missing arguments\n");
	// exit(1);
	return (0);
}
