/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:35:04 by pberset           #+#    #+#             */
/*   Updated: 2025/04/04 18:52:13 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Pour calculs multiples: int main*()
// {
// 	char *str ;;;
	
// 	function(&str);
// }

static int	assign_obj_data(t_scene *scene, t_object object, t_object obj_ptr)
{
	int	nr_objects;

	nr_objects = 0;
	if (object.type == SPHERE)
	{
		nr_objects = scene->n_sp;
		obj_ptr = &scene->objects;
	}
	else if (object.type == PLANE)
	{
		nr_objects = scene->n_pl;
		obj_ptr = &scene->objects;
	}
	else if (object.type == CYLINDER)
	{
		nr_objects = scene->n_cy;
		obj_ptr = &scene->objects;
	}
	return (nr_objects);
}

// Helper to loop through all objects
static void	object_loop(t_scene *scene, int j, t_object *object)
{
	int			i;
	t_intersect	x;

	while (i < scene->n_obj)
	{
		x = rt_ray_object_x(scene->rays[j], *object);
		if (!scene->intersects)
			scene->intersects = ft_lstnew(&x);
		else
			ft_lstadd_back(&scene->intersects, ft_lstnew(&x));
		i++;
		object++;
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
		object_loop(scene, j, scene->objects);
		j++;
	}
}

// // Helper to loop through all planes
// static void	plane_loop(t_scene *scene, int j)
// {
// 	int	i;

// 	i = 0;
// 	while (i < scene->n_pl)
// 	{
// 		if (!scene->intersects)
// 		{
// 			scene->intersects = ft_lstnew( \
// 				rt_ray_object_intersect(scene->rays[j], &scene->objects[i]));
// 		}
// 		else
// 		{
// 			ft_lstadd_back(&scene->intersects, ft_lstnew( \
// 				rt_ray_object_intersect(scene->rays[j], &scene->objects[i])));
// 		}
// 		i++;
// 	}
// }

// // Helper to loop through all cylinders
// static void	cylinder_loop(t_scene *scene, int j)
// {
// 	int	i;

// 	i = 0;
// 	while (i < scene->n_cy)
// 	{
// 		if (!scene->intersects)
// 		{
// 			scene->intersects = ft_lstnew( \
// 				rt_ray_object_intersect(scene->rays[j], &scene->objects[i]));
// 		}
// 		else
// 		{
// 			ft_lstadd_back(&scene->intersects, ft_lstnew( \
// 				rt_ray_object_intersect(scene->rays[j], &scene->objects[i])));
// 		}
// 		i++;
// 	}
// }

// // Helper to loop through all spheres
// static void	sphere_loop(t_scene *scene, int j)
// {
// 	int	i;

// 	i = 0;
// 	while (i < scene->n_sp)
// 	{
// 		if (!scene->intersects)
// 		{
// 			scene->intersects = ft_lstnew( \
// 				rt_ray_object_intersect(scene->rays[j], &scene->objects[i]));
// 		}
// 		else
// 		{
// 			ft_lstadd_back(&scene->intersects, ft_lstnew( \
// 				rt_ray_object_intersect(scene->rays[j], &scene->objects[i])));
// 		}
// 		i++;
// 	}
// }
