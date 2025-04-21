/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:56:56 by pberset           #+#    #+#             */
/*   Updated: 2025/04/21 19:06:49 by fallan           ###   ########.fr       */
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


// Computes the two collision distances between the ray and the sphere
// Uses a quadratic equation discriminant = b²-4ac
// to transform the sphere beform the collision calculus, 
// the invert of the transformation is applied to the ray
t_intersect	*rt_ray_sphere_x(t_ray *ray, t_object *sphere, t_intersect *x)
{
	t_tuple		sphere_to_ray;
	float		eq_par[3]; // equation_parameters
	t_list		*new_list_item;
	t_ray		transformed_ray;


	
	transformed_ray = rt_transform_ray(ray, sphere->inverse);
	sphere_to_ray = subtract_tuple(transformed_ray.origin, sphere->coord);


	rt_compute_ray_sphere_params(eq_par, sphere, transformed_ray, sphere_to_ray);
	if (DISCRIMINANT < 0) // if discriminant < 0, return ... what ?
		return (x);
	x->t[0] = (-B - sqrtf(DISCRIMINANT)) / (2.0f * A);
	x->t[1] = (-B + sqrtf(DISCRIMINANT)) / (2.0f * A);
	x->t_count = 2;
	if (DISCRIMINANT == 0)
		x->t_count = 1;

	t_object	*obj_addr = x->object;
	
	new_list_item = ft_lstnew(x);
	((t_intersect *)(new_list_item->content))->object = obj_addr;
	if (errno)
	{
		rt_handle_error(RAY_INTERSECTS, ENOMEM, NULL);
		// free list
		return (NULL);
	}
	if (!ray->intersects)
		ray->intersects = new_list_item;
	else
		ft_lstadd_back(&ray->intersects, new_list_item);

	// printf("SPHERE_X --- x->object: %p\n", x->object);
	// printf("SPHERE_X --- ((t_intersect *)(new_list_item->content))->object: %p\n", ((t_intersect *)(new_list_item->content))->object);
	
	return (x);
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
t_hit	*rt_find_ray_hit(t_ray *ray, float t_min, t_hit *hit)
{
	float		t_iter_0;
	float		t_iter_1;
	t_object	*hit_object;


	if (ray->intersects)
		t_min = ((t_intersect *) ray->intersects->content)->t[0];
	else
	{
		hit->obj = NULL;
		hit->t = 0;
		return (hit);
	}
	while (ray->intersects)
	{
		t_iter_0 = ((t_intersect *) ray->intersects->content)->t[0];
		t_iter_1 = ((t_intersect *) ray->intersects->content)->t[1];
		if (t_iter_0 > 0 && t_iter_0 < t_min)
		{
			t_min = t_iter_0;
			hit_object = (t_object *)((t_intersect *)ray->intersects->content)->object;
		}
		if (t_iter_1 > 0 && t_iter_1 < t_min)
		{
			t_min = t_iter_1;
			hit_object = (t_object *)((t_intersect *)ray->intersects->content)->object;
		}
		ray->intersects = ray->intersects->next;
	}
	hit->t = t_min;
	hit->obj = hit_object;
	return (hit);
}

// Computes the intersections of a ray on a sphere.
// Returns a float[2] with the two distances values from the origin of the ray
// to the surfaces of the sphere 
t_intersect	*rt_ray_object_x(t_ray *ray, t_object *object)
{
	t_intersect	*x;

	x = ft_calloc(1, sizeof(t_intersect));
	if (errno)
		return (rt_handle_error(RT_RAY_OBJ_X, ENOMEM, NULL));
	x->object = object;
	// printf("OBJECT_X --- x->object: %p\n", x->object);
	x->ray = ray;
	x->t_count = 0;
	if (object->type == SPHERE)
		return (rt_ray_sphere_x(ray, object, x));
	if (object->type == CYLINDER)
		return (rt_ray_cylinder_x(ray, object, x));
	if (object->type == PLANE)
		return (rt_ray_plane_x(ray, object, x));
	return (x);
}
