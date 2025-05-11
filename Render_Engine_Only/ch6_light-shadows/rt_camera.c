/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:12:12 by pberset           #+#    #+#             */
/*   Updated: 2025/05/09 14:12:13 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_camera	rt_camera(t_tuple coord, t_tuple orient, float fov)
{
	t_camera	camera;

	camera.coord = coord;
	camera.orient = orient;
	camera.fov = fov;
	return	(camera);
}
