/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test_ray_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:26:58 by fallan            #+#    #+#             */
/*   Updated: 2025/05/02 16:43:47 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_open_window_and_draw(t_object sp);
void	rt_run_window(t_env *env);
void	rt_set_mlx_env(t_env *env);
void	rt_draw(t_env *env, t_object *sp);
void	test_ray_sphere(void);
void	rt_initialize_test_sphere(t_object *sp);
int		rt_check_if_ray_hits_sphere(t_ray *ray, t_object *sp);
t_ray	*rt_define_ray_to_wall(t_ray *ray, float x_mlx, float y_mlx, float wall_z);

void	test_ray_sphere(void)
{
	t_env		env;
	t_object	sp;

	rt_initialize_test_sphere(&sp);
	dprintf(2, "sphere address: %p\n", &sp);
	rt_set_mlx_env(&env);
	rt_draw(&env, &sp);
	rt_run_window(&env);
}

void	rt_initialize_test_sphere(t_object *sp)
{
	sp->type = SPHERE;
	sp->coord = (t_tuple) {0, 0, 0, POINT};
	sp->diameter = 2;
	sp->color = (t_tuple) {1, 0, 0, COLOR};
	sp->transform = identity_matrix(4, 4);
	sp->inverse = matrix_inversion(sp->transform);
}

void	rt_draw(t_env *env, t_object *sp)
{
	t_tuple		ray_origin;
	t_tuple		ray_direction;
	t_ray		ray;
	float		wall_z; // the wall's position on z-axis 
	float		h;
	float		w;

	// General coordinates (n.b. sphere coordinates are already given as argument)
	ray_origin = rt_point(0, 0, -5);
	ray_direction = rt_vector(0, 0, 1);
	ray = rt_ray(ray_origin, ray_direction);
	wall_z = 5;
	
	// Looping through each possible ray/pixel to check hits with the sphere, 
	h = 0;
	while (h < WINDOW_HEIGHT)
	{
		w = 0;
		while (w < WINDOW_WIDTH)
		{
			rt_define_ray_to_wall(&ray, w, h, wall_z);
			if (rt_check_if_ray_hits_sphere(&ray, sp)) // if ray hits sphere, then put red pixel (otherwise nothing)
			{
				// printf("(%d, %d): red\n", (int) h, (int) w);
				my_mlx_pixel_put(env, (int) w, WINDOW_HEIGHT - (int) h, rgb_to_int(sp->color));
			}
			else
			{
				// printf("(%d, %d): black\n", (int) h, (int) w);
				my_mlx_pixel_put(env, (int) w, WINDOW_HEIGHT - (int) h, rgb_to_int((t_tuple){1, 1, 1, COLOR}));
			}
			w++;
		}
		h++;
	}
}

int	rt_check_if_ray_hits_sphere(t_ray *ray, t_object *sp)
{
	int		ret = 0;

	t_intersect *hit_intersect;
	rt_ray_object_x(ray, sp);
	hit_intersect = rt_find_ray_hit(ray);
	if (!hit_intersect)
	{
		// printf("rt_check_if_ray_hits_sphere: hit_intersect: NULL\n");
		ret = 0;
	}
	else if (!hit_intersect->object || hit_intersect->object != sp)
	{
		// printf("hit_intersect: no object found/not a sphere\n");
		ret = 0;
	}
	else
		ret = 1;

	free(ray->intersects);
	ray->intersects = NULL;
	return ret;
}

// coordinate conversion:
// x_mlx: 0-100
// y_mlx: 0-100
//
// x_mrt: -5 to 5
// y_mrt: -5 to 5
//
// x_mrt = x_mlx/100 

/* defines the ray from the camera to a given pixel of the wall
	first converts the coordinates to miniRT coordinates (x_mrt, y_mrt, 1) */
t_ray	*rt_define_ray_to_wall(t_ray *ray, float x_mlx, float y_mlx, float wall_z)
{
	float		x_mrt;
	float		y_mrt;
	t_tuple		wall_coords;

	x_mrt = (x_mlx / 100) - ((WINDOW_WIDTH / 200));
	y_mrt = (-y_mlx / 100) + (WINDOW_HEIGHT / 200);
	wall_coords = (t_tuple) {x_mrt, y_mrt, wall_z, POINT};	

	ray->direction = subtract_tuple(wall_coords, ray->origin);
	// printf("rt_define_ray_to_wall: input (%.2f, %.2f), wall_coords: (%.2f, %.2f, %.2f), defined ray->direction as {%.2f, %.2f, %.2f}\n", x_mlx, y_mlx, wall_coords.x, wall_coords.y, wall_coords.z, ray->direction.x, ray->direction.y, ray->direction.z);
	return (ray);
}

void	rt_set_mlx_env(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	env->img = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bits_per_pixel, \
		&env->line_length, &env->endian);
}

void	rt_run_window(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_hook(env->win, 2, 1L << 0, key_handler, env);
	mlx_hook(env->win, 17, 0, window_closed, env);
	mlx_loop(env->mlx);
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