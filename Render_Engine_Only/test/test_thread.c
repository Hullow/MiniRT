/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:30:54 by fallan            #+#    #+#             */
/*   Updated: 2025/05/23 11:00:40 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

#include <pthread.h>
#include <unistd.h>
typedef struct s_arg_struct {
	// general, same for all threads => put into single *general* struct, and point to it ?
	t_ray			ray;
	t_object		sphere;
	// pthread_mutex_t *w_mut;
	float			wall_z;
	t_light			light;
	t_env			*env;
	// specific to each thread
	int				h;
	int				w;
} t_arg_struct;


void *rt_thread_render_sphere_pixel(void *vargp)
{
	t_arg_struct	*args;
	t_intersect		intersect;
	t_tuple			point;
	t_tuple			eyev;
	t_tuple			normalv;
	t_tuple			color;

	if (!vargp)
		return NULL;
	args = (t_arg_struct *) vargp;
	while (args->h < WINDOW_HEIGHT)
	{
		args->w = 0;
		while (args->w < WINDOW_WIDTH)
		{
			args->ray = rt_define_ray_to_wall(args->ray, args->w, args->h, args->wall_z);
			intersect = rt_intersect(args->sphere, args->ray);
			if (intersect.count != 0)
			{
				point = rt_position(args->ray, rt_hit(intersect.first, intersect.last));
				normalv = rt_normal_at(intersect.object, point);
				eyev = rt_negate_tuple(args->ray.direction);
				color = rt_lighting(intersect.object, args->light, point, eyev, normalv);
				color = rt_reinhard_tonemap(color);
				// pthread_mutex_lock(); // lock env mutex
				my_mlx_pixel_put(args->env, args->w, WINDOW_HEIGHT - args->h, rgb_to_int(color));
				// pthread_mutex_unlock(); // unlock env mutex
			}
			else
			{
				// pthread_mutex_lock(); // lock env mutex
				my_mlx_pixel_put(args->env, args->w, WINDOW_HEIGHT - args->h, rgb_to_int((t_tuple){0, 0, 1, COLOR}));
				// pthread_mutex_unlock(); // unlock env mutex
			}
			args->w++;
		}
		args->h += NUM_THREADS;
	}
	return NULL;
}

void	test_light_render()
{
	printf("CH6 - Putting it together\n");
	t_camera		camera;
	t_env			env;
	t_ray			ray;
	t_light			light;
	t_object		sphere;
	pthread_t		threads[NUM_THREADS];
	t_arg_struct	thread_arg_struct[NUM_THREADS];

	float			wall_z;
	int 			i;

	env = mlx_set_env();
	camera = rt_camera_parsing(rt_point(0, 0, -100), rt_vector(0, 0, 1), 200.0f);
	ray = rt_ray(camera.coord, camera.orient);
	sphere = rt_sphere(rt_color(255, 0.2 * 255, 12), rt_material(0.1, 0.9, 0.9, 200.0f));
	sphere.transform = rt_mul_matrix(rt_rotation_z(60), rt_scaling(rt_vector(2, 0.6, 2)));
	rt_print_matrix(sphere.transform);
	// float shear_factors[6] = {-1, 0, 0, 0, 0, 0};
	// sphere.transform = rt_shearing(shear_factors);
	light = rt_light(rt_color(255, 255, 255), rt_point(-10, 10, -10), 1.0f);
	wall_z = 5;

	i = 0;
	while (i < NUM_THREADS)
	{
		thread_arg_struct[i] = (t_arg_struct) {
			.ray = ray,
			.sphere = sphere,
			.wall_z = wall_z,
			.light = light,
			.env = &env,
			thread_arg_struct[i].h = i,
			thread_arg_struct[i].w = 0
		};
		pthread_create(&threads[i], NULL, rt_thread_render_sphere_pixel, &thread_arg_struct[i]);
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
	printf("seg check\n");
	mlx_run_window(&env);
}

*/