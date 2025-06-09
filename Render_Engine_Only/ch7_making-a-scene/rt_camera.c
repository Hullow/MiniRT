/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:12:12 by pberset           #+#    #+#             */
/*   Updated: 2025/06/09 22:03:57 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_camera	rt_calc_camera_vals(t_camera camera, t_tuple coord, t_tuple orient)
{
	float	half_view;
	float	aspect;

	camera.transform = rt_view_transform(coord, \
		rt_add_tuple(coord, orient), rt_vector(0, 1, 0));
	half_view = tanf(camera.field_of_view / 2);
	camera.hsize = WINDOW_WIDTH;
	camera.vsize = WINDOW_HEIGHT;
	aspect = (float) camera.hsize / camera.vsize;
	if (aspect >= 1.0)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / (camera.hsize);
	return (camera);
}

t_ray	rt_ray_for_pixel(t_camera *camera, int pixel_x, int pixel_y)
{
	float	offset_xy[2];
	float	world_xy[2];
	t_tuple	origin;
	t_tuple	direction;
	t_tuple	pixel;

	offset_xy[0] = (pixel_x + 0.5) * camera->pixel_size;
	offset_xy[1] = (pixel_y + 0.5) * camera->pixel_size;
	world_xy[0] = camera->half_width - offset_xy[0];
	world_xy[1] = camera->half_height - offset_xy[1];
	pixel = rt_mul_tuple_matrix(rt_inversion(camera->transform), \
		rt_point(world_xy[0], world_xy[1], -1));
	origin = rt_mul_tuple_matrix(rt_inversion(camera->transform), \
		rt_point(0, 0, 0));
	direction = rt_normalize(rt_sub_tuple(pixel, origin));
	return (rt_ray(origin, direction));
}
