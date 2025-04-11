/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:35:04 by pberset           #+#    #+#             */
/*   Updated: 2025/04/11 16:47:29 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Pour calculs multiples: int main*()
// {
// 	char *str ;;;
	
// 	function(&str);
// }

/* 
static int	assign_obj_data(t_scene *scene, t_object object, void **obj_ptr)
{
	int	nr_objects;

	nr_objects = 0;
	if (object == SPHERE)
	{
		nr_objects = scene->n_sp;
		obj_ptr = &scene->sp;
	}
	else if (object == PLANE)
	{
		nr_objects = scene->n_pl;
		obj_ptr = &scene->pl;
	}
	else if (object == CYLINDER)
	{
		nr_objects = scene->n_cy;
		obj_ptr = &scene->cy;
	}
	return (nr_objects);
}
*/

/* // Helper to loop through all planes
static void	object_loop(t_scene *scene, int j, t_object object)
{
	int		i;
	int		nr_objects;
	int		max_type;
	void	**obj_ptr = NULL; // other possibility: initialize at &scene->sp

	max_type = 3;
	while (object < max_type)
	{
		nr_objects = assign_obj_data(obj_ptr, object, obj_ptr);
		i = 0;
		while (i < nr_objects)
		{
			if (!scene->intersects)
			{
				scene->intersects = ft_lstnew( \
				rt_ray_object_x(scene->rays[j], obj_ptr[i]));
			}
			else
			{
				ft_lstadd_back(&scene->intersects, ft_lstnew( \
				rt_ray_object_x(scene->rays[j], obj_ptr[i])));
			}
			i++;
		}
		object++;
	}
} */


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
			rt_ray_plane_x(scene->rays[j], &scene->pl[i]));
		}
		else
		{
			ft_lstadd_back(&scene->intersects, ft_lstnew( \
			rt_ray_object_x(scene->rays[j], &scene->pl[i])));
		}
		i++;
	}
}

// Helper to loop a ray through all cylinders
static void	cylinder_loop(t_scene *scene, int j)
{
	int	i;
	
	i = 0;
	while (i < scene->n_cy)
	{
		if (!scene->intersects)
		{
			scene->intersects = ft_lstnew( \
			rt_ray_object_x(scene->rays[j], &scene->cy[i]));
		}
		else
		{
			ft_lstadd_back(&scene->intersects, ft_lstnew( \
			rt_ray_object_x(scene->rays[j], &scene->cy[i])));
		}
		i++;
	}
}

// Helper to loop a ray through all spheres
static void	sphere_loop(t_scene *scene, int j)
{
	int	i;
	
	i = 0;
	while (i < scene->n_sp)
	{
		if (!scene->intersects)
		{
			scene->intersects = ft_lstnew( \
			rt_ray_object_x(scene->rays[j], &scene->sp[i]));
		}
		else
		{
			ft_lstadd_back(&scene->intersects, ft_lstnew( \
			rt_ray_object_x(scene->rays[j], &scene->sp[i])));
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
	t_list	*ray_intersects;
	while (j < n_rays)
	{
		// object_loop(scene, j, 0);
		sphere_loop(scene, j, ray_intersects);
		cylinder_loop(scene, j, ray_intersects);
		plane_loop(scene, j, ray_intersects);
		j++;
	}
	return (hit(ray_intersects));
}


// Creates an intersection given a t-value (float) 
// and a pointer (void *) to the object
// 
// Returns:
// a pointer to the intersection created
t_itsct	*rt_intersection(float t, void *object)
{
	t_itsct	*i;

	i = ft_calloc(1, sizeof(t_itsct));
	if (errno)
		return (handle_error(INTERSECTION, ENOMEM, NULL));
	i->t = t;
	i->object = object;
	return (i);
}

// Adds an intersection (t_itsct *) to a list of intersections (t_list *)
// 
t_list	*rt_add_intersect_list(t_list **first_item, t_itsct *intersection)
{
	t_list	*new_list_item;
	int	list_count;

	new_list_item = ft_lstnew(intersection);
	if (errno)
		return (handle_error(INTERSECT_LIST, ENOMEM, NULL));
	ft_lstadd_back(first_item, new_list_item);
}


