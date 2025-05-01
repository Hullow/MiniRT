/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test_ray_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:26:58 by fallan            #+#    #+#             */
/*   Updated: 2025/05/01 15:04:01 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_open_window_and_draw(t_object sp);
void	rt_run_window(t_env *env);
void	rt_set_mlx_env(t_env *env);
void	rt_draw(t_env *env, t_object *sp);
void	test_ray_sphere(void);
int		rt_check_if_ray_hits_sphere(t_ray *ray, t_object *sp, int h, int w);
t_ray	*rt_define_ray_to_wall(t_ray *ray, int x_mlx, int y_mlx);

void	test_ray_sphere(void)
{
	t_env		env;
	t_object	sp;

	sp.type = SPHERE;
	sp.coord = (t_tuple) {0, 0, 0, POINT};
	sp.diameter = 1.0;
	sp.color = (t_tuple) {1, 0, 0, COLOR};
	sp.transform = identity_matrix(4, 4);
	sp.inverse = matrix_inversion(sp.transform);
	
	dprintf(2, "sphere address: %p\n", &sp);
	
	rt_set_mlx_env(&env);
	
	rt_draw(&env, &sp);

	rt_run_window(&env);
}

void	rt_draw(t_env *env, t_object *sp)
{
	t_ray	ray;
	int		h;
	int		w;
	
	printf("rt_draw: sphere address: %p\n", sp);
	printf("rt_draw: hit->obj->color.x: %f\n", sp->color.x);
	h = 0;
	ray = rt_ray(rt_point(0, 0, -2), rt_vector(0, 0, 0));
	while (h < WINDOW_HEIGHT) // 60)
	{
		w = 0;
		while (w < WINDOW_WIDTH) // 80)
		{
			rt_define_ray_to_wall(&ray, w, h);
			if (rt_check_if_ray_hits_sphere(&ray, sp, h, w)) // if ray hits sphere, then put red pixel (otherwise nothing)
			{
				// printf("(%d, %d): red\n", h, w);
				my_mlx_pixel_put(env, w, WINDOW_HEIGHT - h, rgb_to_int(sp->color));
			}
			else
			{
				// printf("(%d, %d): black\n", h, w);
				my_mlx_pixel_put(env, w, WINDOW_HEIGHT - h, 0);
			}
			w++;
		}
		h++;
	}
}

int	rt_check_if_ray_hits_sphere(t_ray *ray, t_object *sp, int h, int w)
{
	int		ret = 0;

	t_intersect *hit_intersect = rt_ray_object_x(ray, sp);
	printf("rt_check_if_ray_hits_sphere: t_count: %d\n", ((t_intersect *) ray->intersects->content)->t_count);
	hit_intersect = rt_find_ray_hit(ray);
	if (!hit_intersect->object || hit_intersect->object != sp)
	{
		printf("hit_intersect: no object found/not a sphere\n");
		ret = 0;
	}
	else
		ret = 1;

	if (h == 100 && w == 100 && hit_intersect)
	{
		printf("rt_check_if_ray_hits_sphere: address of hit object: %p\n", hit_intersect->object);
		printf("hit->obj->color.x: %f\n", hit_intersect->object->color.x);
	}

	free(ray->intersects);
	ray->intersects = NULL;
	return ret;
}

/* defines the ray from the camera to a given pixel of the wall
	first converts the coordinates to miniRT coordinates (x_mrt, y_mrt, 1) */
t_ray	*rt_define_ray_to_wall(t_ray *ray, int x_mlx, int y_mlx)
{
	int		x_mrt;
	int		y_mrt;

	x_mrt = (x_mlx / 100) - ((WINDOW_WIDTH / 200));
	y_mrt = (-y_mlx / 100) + (WINDOW_HEIGHT / 200);
	ray->direction = subtract_tuple(rt_point(x_mrt, y_mrt, 2), ray->origin);
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