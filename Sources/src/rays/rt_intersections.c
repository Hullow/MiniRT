/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_pair_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:56:56 by pberset           #+#    #+#             */
/*   Updated: 2025/05/01 17:08:06 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_intersect	*rt_init_intersect(float t_value, t_object *object);
t_intersect	*rt_add_intersect_to_ray_list(t_intersect *x1, t_intersect *x2, t_ray *ray);

// Computes the collision distance between the ray and the plane
// chapter 9
t_intersect	*rt_ray_plane_x(t_ray *ray, t_object *plane)
{
	t_intersect	*x = NULL;

	(void)ray;
	(void)plane;
	return (x);
}

// Computes the two collision distances between the ray and the cylinder
// chapter 13
t_intersect	*rt_ray_cylinder_x(t_ray *ray, t_object *cylinder)
{
	t_intersect	*x = NULL;

	(void)ray;
	(void)cylinder;
	return (x);
}

/* Helper function for rt_ray_sphere_x: does the actual computations to find
the quadratic equations' parameters, including determinant

	Returns: an array of three floats: a, b, the discriminant (c is forgotten)*/
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
	// printf("%f^2 (== %f) - 4 * %f * %f (== %f) == %f\n", b, (b * b), a, c, 4.0f * a * c, discriminant);
	equation_params[0] = a;
	equation_params[1] = b;
	equation_params[2] = discriminant;
}

/* Mallocs and returns a new t_intersect struct, with a t-value and an
intersected object given as parameters */
t_intersect	*rt_init_intersect(float t_value, t_object *object)
{
	t_intersect	*x;

	x = ft_calloc(1, sizeof(t_pair_intersect));
	if (errno)
		return (rt_handle_error(RT_RAY_OBJ_X, ENOMEM, NULL));
	x->t = t_value;
	x->object = object;
	return (x);
}

/* Adds an intersection struct to the linked list of intersections of the ray
	1. Creates new list item with the intersection struct
	2. Specifies which object is being intersected (using pointer t_object *)
	3. Adds the list item to the end of the ray's list of intersections
	
	Returns: the first intersection (x1 )*/
t_intersect	*rt_add_intersect_to_ray_list(t_intersect *x1, t_intersect *x2, t_ray *ray)
{
	t_list		*list_item_1;
	t_list		*list_item_2;

	list_item_1 = ft_lstnew(x1);
	if (errno)
	{
		// free list
		return(rt_handle_error(RAY_INTERSECTS, ENOMEM, NULL));
	}
	list_item_2 = ft_lstnew(x2);
	if (errno)
	{
		// free list
		return(rt_handle_error(RAY_INTERSECTS, ENOMEM, NULL));
	}
	if (!ray->intersects)
		ray->intersects = list_item_1;
	else
		ft_lstadd_back(&ray->intersects, list_item_1);
	ft_lstadd_back(&ray->intersects, list_item_2);
	return (x1);
}


// Computes the (zero/one/two) collision distances between a ray and a sphere
//
// How it works:
// 1. Calloc a t_pair_intersect, set its intersections t_count to 0, object to sphere
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
// Returns: the t_pair_intersect that was computed
// (n.b.: rt_add_intersect_to_ray_list adds it to the ray's intersections list)
t_intersect	*rt_ray_sphere_x(t_ray *ray, t_object *sphere)
{
	t_intersect	*x1;
	t_intersect	*x2;
	t_ray		transformed_ray;
	t_tuple		sphere_to_ray;
	float		eq_par[3]; // equation_parameters

	transformed_ray = rt_transform_ray(ray, sphere->inverse);
	sphere_to_ray = subtract_tuple(transformed_ray.origin, sphere->coord);
	rt_compute_ray_sphere_params(eq_par, sphere, transformed_ray, sphere_to_ray);
	if (DISCRIMINANT < 0)
	{
		// printf("rt_ray_sphere_x: discriminant is < 0\n");
		return (NULL);
	}
	x1 = rt_init_intersect((-B - sqrtf(DISCRIMINANT)) / (2.0f * A), sphere);
	if (!x1)
		return (NULL);
	if (DISCRIMINANT == 0)
		x2 = x1;
	else
	{
		x2 = rt_init_intersect((-B + sqrtf(DISCRIMINANT)) / (2.0f * A), sphere);
		if (!x2)
			return (NULL);
	}
	return (rt_add_intersect_to_ray_list(x1, x2, ray));
}

// - Evaluates a ray's intersections with objects and returns the ray's hit
// (the intersection with the lowest nonnegative "t-value")
// - no malloc
// 
// Returns:
// where the ray hits (t_intersect), with values:
// - t: the t-value of the intersection
// - object: a pointer to the object hit
// or NULL if no hit found
t_intersect *rt_find_ray_hit(t_ray *ray)
{
	float		t_min = INT_MAX; // What does t==0 mean ? Invisible ?
	t_intersect	*hit_intersect = NULL;
	t_intersect	*iterator = NULL;

	if (!ray->intersects || !ray->intersects->content)
	{
		// printf("rt_find_ray_hit: no t_intersect list or -> content found for the ray, returning NULL\n");
		return (NULL);
	}
	// else
	// printf("rt_find_ray_hit: one intersect found for the ray, continuing\n");
	while (ray->intersects)
	{
		iterator = (t_intersect *) (ray->intersects->content);
		if (iterator->t > 0 && t_min > iterator->t)
		{
			t_min = iterator->t;
			hit_intersect = iterator;
		}
		ray->intersects = ray->intersects->next;
	}
	// if (hit_intersect)
	// 	    printf("rt_find_ray_hit: => hit_intersect set to (t: %f, obj: %p)\n", hit_intersect->t, hit_intersect->object); // => never comes up in my tests
	// else
	// 	printf("rt_find_ray_hit: returning hit_intersect == NULL\n");
	return (hit_intersect);
}

// Computes the intersections of a ray on an object (sphere, cylinder, plane)
// Returns a float[2] with the two (or one if plane) distances values from the 
// origin of the ray to the surfaces of the object
t_intersect	*rt_ray_object_x(t_ray *ray, t_object *object)
{
	if (object->type == SPHERE)
		return (rt_ray_sphere_x(ray, object));
	if (object->type == CYLINDER)
		return (rt_ray_cylinder_x(ray, object));
	if (object->type == PLANE)
		return (rt_ray_plane_x(ray, object));
	return (NULL);
}
