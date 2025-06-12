/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_plane_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:32:05 by fallan            #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* 
// Computes the collision distance between the ray and the plane
// chapter 9
t_intersect	*rt_ray_plane_x(t_ray *ray, t_object *plane)
void	rt_ray_plane_x(t_ray ray, t_object plane, t_intersect *x)
{
	t_tuple	local_intersect;
	float	t;

	if (abs(ray.dir.y) < EPSILON) // edge case: ray paralel to plane normal
	{
		x->x_count = 0;
		x->ray = ray;
		x->object = plane;
		return ;
	}
	t = -ray.origin.y / ray.dir.y;
	local_intersect = rt_point(ray.origin.x + t * ray.dir.x, \
								ray.origin.y + t * ray.dir.y, \
								ray.origin.y + t * ray.dir.z);
	x->object = plane;
	x->ray = ray;
	x->x_count = 1;
	x->x_distances[0] = t;
	//store the point value in the intersect too ??? would make sense
	t_intersect	*x = NULL;

	(void)ray;
	(void)plane;
	return (x);
}

// Computes the two collision distances between the ray and the cylinder
// chapter 13
t_intersect	*rt_ray_cylinder_x(t_ray *ray, t_object *cylinder)
void	rt_ray_cylinder_x(t_ray ray, t_object cylinder, t_intersect *x)
{
	t_intersect	*x = NULL;

	(void)ray;
	(void)cylinder;
}
*/
