/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:35:04 by pberset           #+#    #+#             */
/*   Updated: 2025/04/03 15:27:42 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Helper to loop through all planes
static void	plane_loop(t_scene *scene, int j)
{
	int	i;

	i = 0;
	while (i < scene->n_pl)
	{
		if (!scene->intersects)
		{
			scene->intersects = ft_lstnew( \
				rt_ray_object_intersect(scene->rays[j], &scene->pl[i]));
		}
		else
		{
			ft_lstadd_back(&scene->intersects, ft_lstnew( \
				rt_ray_object_intersect(scene->rays[j], &scene->pl[i])));
		}
		i++;
	}
}

// Helper to loop through all cylinders
static void	cylinder_loop(t_scene *scene, int j)
{
	int	i;

	i = 0;
	while (i < scene->n_cy)
	{
		if (!scene->intersects)
		{
			scene->intersects = ft_lstnew( \
				rt_ray_object_intersect(scene->rays[j], &scene->cy[i]));
		}
		else
		{
			ft_lstadd_back(&scene->intersects, ft_lstnew( \
				rt_ray_object_intersect(scene->rays[j], &scene->cy[i])));
		}
		i++;
	}
}

// Helper to loop through all spheres
static void	sphere_loop(t_scene *scene, int j)
{
	int	i;

	i = 0;
	while (i < scene->n_sp)
	{
		if (!scene->intersects)
		{
			scene->intersects = ft_lstnew( \
				rt_ray_object_intersect(scene->rays[j], &scene->sp[i]));
		}
		else
		{
			ft_lstadd_back(&scene->intersects, ft_lstnew( \
				rt_ray_object_intersect(scene->rays[j], &scene->sp[i])));
		}
		i++;
	}
}

// Create the intersection struct and assigns values foreach object in the scene
// The number of rays is decided by the size of the window
// One ray per pixel
void	rt_compute_intersect(t_scene *scene)
{
	int j;
	int	n_rays;

	n_rays = WINDOW_WIDTH * WINDOW_HEIGHT;
	j = 0;
	while (j < n_rays)
	{
		sphere_loop(scene, j);
		cylinder_loop(scene, j);
		plane_loop(scene, j);
		j++;
	}
}
