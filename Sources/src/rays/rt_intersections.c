/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:56:56 by pberset           #+#    #+#             */
/*   Updated: 2025/04/19 19:31:33 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Computes the collision distance between the ray and the plane
// chapter 9
t_intersect	rt_ray_plane_x(t_ray ray, t_object plane, t_intersect x)
{
	(void)ray;
	(void)plane;
	return (x);
}

// Computes the two collision distances between the ray and the cylinder
// chapter 13
t_intersect	rt_ray_cylinder_x(t_ray ray, t_object cylinder, t_intersect x)
{
	(void)ray;
	(void)cylinder;
	return (x);
}

void	rt_compute_ray_sphere_params(float **equation_params, t_object sphere, t_ray ray, t_tuple sphere_to_ray);
void	rt_compute_ray_sphere_params(float **equation_params, t_object sphere, t_ray ray, t_tuple sphere_to_ray)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;

	a = dot_product(ray.direction, ray.direction);
	b = 2.0f * dot_product(ray.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - \
					powf((sphere.diameter / 2.0f), 2);
	discriminant = powf(b, 2) - 4.0f * a * c;
	(*equation_params)[0] = a;
	(*equation_params)[1] = b;
	(*equation_params)[2] = discriminant;
}

// Computes the two collision distances between the ray and the sphere
// Uses a quadratic equation discriminant = b²-4ac
// to transform the sphere beform the collision calculus, 
// the invert of the transformation is applied to the ray
t_intersect	*rt_ray_sphere_x(t_ray ray, t_object sphere, t_intersect *x)
{
	t_tuple		sphere_to_ray;
	float		eq_par[4]; // equation_parameters
	t_matrix	temp;
	t_list		*new_list_item;

	temp = matrix_inversion(sphere.transform);
	ray = rt_transform_ray(ray, temp);
	sphere_to_ray = subtract_tuple(ray.origin, sphere.coord);
	rt_compute_ray_sphere_params(&eq_par, sphere, ray, sphere_to_ray);
	if (eq_par[2] < 0)
		return (x);
	x->x_distances[0] = (-eq_par[1] - sqrtf(eq_par[2])) / (2.0f * eq_par[0]);
	x->x_distances[1] = (-eq_par[1] + sqrtf(eq_par[2])) / (2.0f * eq_par[0]);
	x->x_count = 2;
	if (eq_par[2] == 0)
		x->x_count = 1;
	new_list_item = ft_lstnew(x);
	if (errno)
	{
		rt_handle_error(RAY_INTERSECTS, ENOMEM, NULL);
		// free list
		return ;	
	}
	if (!ray.intersects)
		ray.intersects = new_list_item;
	else
		ft_lstadd_back(&ray.intersects, new_list_item);
	return (x);
}

// TO DO: WRITE CODE TO ADD ITEMS TO INTERSECT LIST (see below old code)

// Computes all the intersects between a ray and the objects in the scene
// Stores intersections in a linked list in the ray struct
static void	rt_compute_ray_intersects(t_scene *scene, t_ray *ray, t_object *object)
	
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
			rt_handle_error(RAY_INTERSECTS, ENOMEM, NULL);
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
// - x_distances[2]: t_min in [0], 0 in [1]
// - x_count: 1
t_intersect	rt_compute_ray_hit(t_ray ray, float t_min)
{
	float		t_iter_0;
	float		t_iter_1;
	t_object	hit_object;

	if (ray.intersects)
		t_min = ((t_intersect *) ray.intersects->content)->x_distances[0];
	else
		return ((t_intersect){NULL, NULL, {0.0, 0.0}, 0});
	while (ray.intersects)
	{
		t_iter_0 = ((t_intersect *) ray.intersects->content)->x_distances[0];
		t_iter_1 = ((t_intersect *) ray.intersects->content)->x_distances[1];
		if (t_iter_0 > 0 && t_iter_0 < t_min)
		{
			t_min = t_iter_0;
			hit_object = ((t_intersect *) ray.intersects->content)->object;
		}
		if (t_iter_1 > 0 && t_iter_1 < t_min)
		{
			t_min = t_iter_1;
			hit_object = ((t_intersect *) ray.intersects->content)->object;
		}
		ray.intersects = ray.intersects->next;
	}
	return ((t_intersect){hit_object, 0.0, {t_min, 0.0}, 1});
}

// Computes the intersections of a ray on a sphere.
// Returns a float[2] with the two distances values from the origin of the ray
// to the surfaces of the sphere 
t_intersect	rt_ray_object_x(t_ray ray, t_object object)
{
	t_intersect	x;
	t_object	type;

	x.object = object;
	x.ray = ray;
	x.x_count = 0;
	if (object.type == SPHERE)
		return (rt_ray_sphere_x(ray, object, x));
	if (object.type == CYLINDER)
		return (rt_ray_cylinder_x(ray, object, x));
	if (object.type == PLANE)
		return (rt_ray_sphere_x(ray, object, x));
	return (x);
}
