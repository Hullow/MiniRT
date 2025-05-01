/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:56:56 by pberset           #+#    #+#             */
/*   Updated: 2025/05/01 15:14:50 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Computes the collision distance between the ray and the plane
// chapter 9
t_intersect	*rt_ray_plane_x(t_ray *ray, t_object *plane, t_intersect *x)
{
	(void)ray;
	(void)plane;
	return (x);
}

// Computes the two collision distances between the ray and the cylinder
// chapter 13
t_intersect	*rt_ray_cylinder_x(t_ray *ray, t_object *cylinder, t_intersect *x)
{
	(void)ray;
	(void)cylinder;
	return (x);
}

void	rt_compute_ray_sphere_params(float equation_params[3], t_object *sphere, t_ray transformed_ray, t_tuple sphere_to_ray)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;

	a = dot_product(transformed_ray.direction, transformed_ray.direction);
	b = 2.0f * dot_product(transformed_ray.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - \
		powf((sphere->diameter / 2.0f), 2);
	discriminant = (b * b) - (4.0f * a * c);
	equation_params[0] = a;
	equation_params[1] = b;
	equation_params[2] = discriminant;
}

t_intersect	*rt_add_to_ray_intersect_list(t_intersect *x, t_ray *ray, t_object *object);


/* Adds an intersection struct to the linked list of intersections of the ray
	1. Creates new list item with the intersection struct
	2. Specifies which object is being intersected (using pointer t_object *)
	3. Adds the list item to the end of the ray's list of intersections */
t_intersect	*rt_add_to_ray_intersect_list(t_intersect *x, t_ray *ray, t_object *object)
{
	t_list		*new_list_item;

	printf("rt_add_to_ray_intersect_list: x->t_count: %d\n", x->t_count);
	new_list_item = ft_lstnew(x);
	printf("rt_add_to_ray_intersect_list: new_list_item->content->t_count: %d\n", ((t_intersect *)(new_list_item->content))->t_count);
	
	if (errno)
	{
		rt_handle_error(RAY_INTERSECTS, ENOMEM, NULL);
		// free list
		return (NULL);
	}
	((t_intersect *)(new_list_item->content))->object = object;
	if (!ray->intersects)
		ray->intersects = new_list_item;
	else
		ft_lstadd_back(&ray->intersects, new_list_item);
	printf("rt_add_to_ray_intersect_list: t_count: %d\n", ((t_intersect *) ray->intersects->content)->t_count);
	return (x);
}


// Computes the (zero/one/two) collision distances between a ray and a sphere
//
// How it works:
// 1. Calloc a t_intersect, set its intersections t_count to 0, object to sphere
// 2. Transform the ray using the inverse of the sphere's transformation
// 3. Compute the sphere to ray vector
// 4. Compute the parameters eq_par[3] for the quadratic equation to be solved
// 5. Check the discriminant's value:
//		- if negative, return (with t_count previously set to 0)
//  	- if 0, set t_count to 1
//		- if > 0, set t_count to 2
// 6. Fills the two t-values of our intersections t[0] and t[1]
// 7. Return
//
// Returns: the t_intersect that was computed
// (n.b.: rt_add_to_ray_intersect_list adds it to the ray's intersections list)
t_intersect	*rt_ray_sphere_x(t_ray *ray, t_object *sphere)
{
	t_intersect *x;
	t_tuple		sphere_to_ray;
	float		eq_par[3]; // equation_parameters
	t_ray		transformed_ray;

	x = ft_calloc(1, sizeof(t_intersect));
	if (errno)
		return (rt_handle_error(RT_RAY_OBJ_X, ENOMEM, NULL));
	x->object = sphere;
	x->ray = ray; // necessary ? not sure, given that intersects are stored in rays ray->intersect
	x->t_count = 0;
	transformed_ray = rt_transform_ray(ray, sphere->inverse);
	sphere_to_ray = subtract_tuple(transformed_ray.origin, sphere->coord);
	rt_compute_ray_sphere_params(eq_par, sphere, transformed_ray, sphere_to_ray);
	if (DISCRIMINANT < 0)
	{
		printf("rt_ray_sphere_x: discriminant is < 0\n");
		printf("rt_ray_sphere_x: t_count: %d\n", x->t_count);
		return (rt_add_to_ray_intersect_list(x, ray, sphere));
	}
	else if (DISCRIMINANT == 0)
		x->t_count = 1;
	else
		x->t_count = 2;
	printf("rt_ray_sphere_x: t_count: %d\n", x->t_count);
	x->t[0] = (-B - sqrtf(DISCRIMINANT)) / (2.0f * A);
	x->t[1] = (-B + sqrtf(DISCRIMINANT)) / (2.0f * A);
	return (rt_add_to_ray_intersect_list(x, ray, sphere));
}

// - Evaluates a ray's intersections with objects and returns the ray's hit
// (the intersection with the lowest "t-value")
// - no malloc
// - must be called with a 0 value for "float t_min"
// 
// Returns:
// where the ray hits (t_intersect), with values:
// - object: a pointer to the object hit (or NULL if none)
// - ray: set to NULL (because we know which ray it is)
// - t[2]: t_min in [0], 0 in [1]
// - t_count: 1
t_intersect *rt_find_ray_hit(t_ray *ray)
{
	float		t_min;
	float		t_iter_0;
	float		t_iter_1;
	t_intersect	*hit_intersect;

	if (!ray->intersects)
	{
		printf("rt_find_ray_hit: no t_intersect list found for the ray, returning NULL\n");
		return (NULL);
	}
	if (!ray->intersects->content)
	{
		printf("rt_find_ray_hit: ray->intersects->content NULL, returning NULL\n");
		return (NULL);
	}
	printf("rt_find_ray_hit: one intersect found for the ray, continuing\n");
	printf("rt_find_ray_hit: t_count: %d\n", ((t_intersect *) ray->intersects->content)->t_count);
	t_min = ((t_intersect *) ray->intersects->content)->t[0]; // SOUCI HERE
	while (ray->intersects)
	{
		if (((t_intersect *) (ray->intersects->content))->t_count == 0\
		|| ((t_intersect *) (ray->intersects->content))->object->type != SPHERE)
		{
			ray->intersects = ray->intersects->next;
			continue ;
		}
		t_iter_0 = ((t_intersect *) ray->intersects->content)->t[0];
		t_iter_1 = ((t_intersect *) ray->intersects->content)->t[1];
		if (t_iter_0 > 0 && t_iter_0 < t_min)
		{
			t_min = t_iter_0;
			((t_intersect *) ray->intersects->content)->t[1] = 0;
			((t_intersect *) ray->intersects->content)->t_count = 1;
			hit_intersect = (t_intersect *)ray->intersects;
		}
		if (t_iter_1 > 0 && t_iter_1 < t_min)
		{
			t_min = t_iter_1;
			((t_intersect *) ray->intersects->content)->t[0] = 0;
			((t_intersect *) ray->intersects->content)->t_count = 1;
			hit_intersect = (t_intersect *)ray->intersects;
		}
		ray->intersects = ray->intersects->next;
	}
	return (hit_intersect);
}

// Computes the intersections of a ray on an object (sphere, cylinder, plane)
// Returns a float[2] with the two (or one if plane) distances values from the 
// origin of the ray to the surfaces of the object
t_intersect	*rt_ray_object_x(t_ray *ray, t_object *object)
{
	t_intersect	*x;

	x = NULL;
	if (object->type == SPHERE)
		return (rt_ray_sphere_x(ray, object));
	if (object->type == CYLINDER)
		return (rt_ray_cylinder_x(ray, object, x));
	if (object->type == PLANE)
		return (rt_ray_plane_x(ray, object, x));
	return (x);
}
