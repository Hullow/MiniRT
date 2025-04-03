/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:35:04 by pberset           #+#    #+#             */
/*   Updated: 2025/04/03 10:35:09 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Computes the intersections of a ray on a sphere.
// Returns a float[2] with the two distances values from the origin of the ray
// to the surfaces of the sphere 
t_intersect	*rt_ray_object_intersect(t_ray ray, void *object)
{

}

// Create the intersection struct and assigns values foreach object in the scene
void	rt_compute_intersect(t_scene *scene)
{
	int	i;
	int j;
	int	n_rays = 42; // how many rays. how to decide ???

	i = 0;
	j = 0;
	while (j < n_rays)
	{
		while (i < scene->n_sp)
		{
			scene->intersects = ft_lstnew(rt_ray_object_intersect(scene->rays[j], &scene->sp[i]));
			i++;
		}
		j++;
	}
}
