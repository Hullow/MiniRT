/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:47:06 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 10:04:25 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief 
/// @param ray 
/// @param x_mlx 
/// @param y_mlx 
/// @param wall_z 
/// @return 
t_ray	rt_define_ray_to_wall(t_ray ray, float x_mlx, float y_mlx, float wall_z)
{
	float		x_mrt;
	float		y_mrt;
	t_tuple		wall_coords;

	x_mrt = (x_mlx / 100) - ((WINDOW_WIDTH / 200));
	y_mrt = (-y_mlx / 100) + (WINDOW_HEIGHT / 200);
	wall_coords = (t_tuple){x_mrt, -y_mrt, wall_z, POINT};
	ray.dir = rt_normalize(rt_sub_tuple(wall_coords, ray.origin));
	return (ray);
}
