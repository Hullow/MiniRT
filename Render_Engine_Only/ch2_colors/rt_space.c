/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:47:06 by pberset           #+#    #+#             */
/*   Updated: 2025/05/11 18:12:49 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_ray	rt_define_ray_to_wall(t_ray ray, float x_mlx, float y_mlx, float wall_z)
{
	float		x_mrt;
	float		y_mrt;
	t_tuple		wall_coords;

	x_mrt = (x_mlx / 100) - ((WINDOW_WIDTH / 200));
	y_mrt = (-y_mlx / 100) + (WINDOW_HEIGHT / 200);
	wall_coords = (t_tuple) {x_mrt, -y_mrt, wall_z, POINT};	

	ray.direction = rt_normalize(rt_sub_tuple(wall_coords, ray.origin));
	return (ray);
}
