/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:14:38 by fallan            #+#    #+#             */
/*   Updated: 2025/04/14 16:16:44 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* void	rt_open_window_and_draw();
void	rt_draw(t_env *env, t_tuple col_tuple);
int		rgb_to_int(t_tuple col_tuple); */

void	my_mlx_pixel_put(t_env *env, int x, int y, int color);

int main()
{
	t_sphere	*sp;

	sp = rt_init_sphere(
		(t_tuple) {0, 0, 0, POINT},
		1.0,
		(t_tuple) {1.0, 0, 0, COLOR});
	(void)sp;
	rt_open_window_and_draw((t_tuple) {1.0, 0, 0, COLOR});
	return 0;
}

int	rgb_to_int(t_tuple col_tuple)
{
	int	color;
	int	hex_r;
	int	hex_g;
	int	hex_b;

	color = 0;
	hex_r = (int) (col_tuple.x * 255);
	hex_g = (int) (col_tuple.y * 255);
	hex_b = (int) (col_tuple.z * 255);
	color += (hex_r / 16) * pow(16, 5) + (hex_r % 16) * pow(16, 4);
	color += (hex_g / 16) * pow(16, 3) + (hex_g % 16) * pow(16, 2);
	color += (hex_b / 16) * 16 + (hex_b % 16);
	return (color);
}

void	rt_draw(t_env *env, t_tuple col_tuple)
{
	int	h;
	int	v;
	
	h = 0;
	(void)col_tuple;
	printf("rt_draw: rgb_to_int((%.2f, %.2f, %.2f)) == %d\n", col_tuple.x, col_tuple.y, col_tuple.z, rgb_to_int(col_tuple));
	while (h < WINDOW_HEIGHT)
	{
		v = 0;
		while (v < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(env, v, WINDOW_HEIGHT - h, rgb_to_int(col_tuple));
			v++;
		}
		h++;
	}
}

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
	ft_printf("keycode: %d\n", keycode);
	if (keycode)
		printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		ft_printf("ESC key pressed, program stopping\n");
		// ft_free_list(env->point_list);
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		exit(1);
	}
	return (0);
}

// program closer, is called if the window is closed with the mouse
int	window_closed(t_env *env)
{
	ft_printf("Window closed, program stopping\n");
	// ft_free_list(env->point_list);
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	// exit(1);
	return (0);
}

void	rt_open_window_and_draw(t_tuple col_tuple)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	env.img = mlx_new_image(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, \
		&env.line_length, &env.endian);
	rt_draw(&env, col_tuple);
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
			(point_list);
			ft_free_list(anchor);
		}
	}
	else
		ft_printf("missing arguments\n");
	// exit(1);
	return (0);
}
 */
