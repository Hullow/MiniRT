/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:35:04 by pberset           #+#    #+#             */
/*   Updated: 2025/04/17 17:08:53 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* 
// Computes all the intersects between a ray and the objects in the scene
// Stores intersections in a linked list in the ray struct
static void	rt_compute_ray_intersects(
	t_scene *scene, t_ray *ray, t_object *object)
{
	int			i;
	t_list		*new_list_item;
	t_intersect	*x;

	scene->n_obj = scene->n_sp + scene->n_pl + scene->n_cy; // need to compute this before in the code => input handling?
	while (i < scene->n_obj)
	{
		x = rt_ray_object_x(*ray, object);
		new_list_item = ft_lstnew(x);
		if (errno)
		{
			handle_error(RAY_INTERSECTS, ENOMEM, NULL);
			// free list
			return ;	
		}
		if (!ray->intersects)
			ray->intersects = new_list_item;
		else
			ft_lstadd_back(&ray->intersects, new_list_item);
		i++;
		object++;
	}
}
*/


// - Evaluates a ray's intersections with objects and returns the ray's hit
// (the intersection with the lowest "t-value")
// - no malloc
// - must be called with a NULL value for "void *hit_object"
// 
// Returns:
// where the ray hits (t_intersect), with values:
// - object: a pointer to the object hit (or NULL if none)
// - ray: set to NULL (because we know which ray it is)
// - x_distances[2]: t_min in [0], 0 in [1]
// - x_count: 1
t_intersect	rt_compute_ray_hit(t_ray *ray, void	*hit_object)
{
	float	t_min;
	float	t_iter_0;
	float	t_iter_1;

	if (ray->intersects)
		t_min = ((t_intersect *) ray->intersects->content)->x_distances[0];
	else
		return ((t_intersect){NULL, NULL, {0.0, 0.0}, 0});
	while (ray->intersects)
	{
		t_iter_0 = ((t_intersect *) ray->intersects->content)->x_distances[0];
		t_iter_1 = ((t_intersect *) ray->intersects->content)->x_distances[1];
		if (t_iter_0 > 0 && t_iter_0 < t_min)
		{
			t_min = t_iter_0;
			hit_object = ((t_intersect *) ray->intersects->content)->object;
		}
		if (t_iter_1 > 0 && t_iter_1 < t_min)
		{
			t_min = t_iter_1;
			hit_object = ((t_intersect *) ray->intersects->content)->object;
		}
		ray->intersects = ray->intersects->next;
	}
	return ((t_intersect){hit_object, NULL, {t_min, 0.0}, 1});
}

/* // Computes the hits for all rays (to be precised)
//
// How it works:
// - Loops over all rays (one ray per pixel, # based on the size of the window)
// 
// - First calls rt_compute_ray_intersects to compute all intersects of a ray
// and the objects in the scene
// - Then calls rt_compute_ray_hit to compute the hit from these intersects
void	rt_compute_hits(t_scene *scene)
{
	int 		j;
	int			n_rays;
	t_intersect	hit;
	t_ray		ray;
	int			t_value;
	void		*hit_object;

	n_rays = WINDOW_WIDTH * WINDOW_HEIGHT;
	j = 0;
	while (j < n_rays)
	{
		rt_compute_ray_intersects(scene, &ray, scene->objects);
		hit = rt_compute_ray_hit(&ray, NULL);
		if (hit.object) // if an object was hit, here are the relevant values:
		{
			t_value = hit.x_distances[0];
			hit_object = hit.object;	
		}
		j++;
	}
}
 */