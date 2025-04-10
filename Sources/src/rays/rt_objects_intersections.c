/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:56:56 by pberset           #+#    #+#             */
/*   Updated: 2025/04/10 17:03:01 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Computes the collision distance between the ray and the plane
// chapter 9
t_intersect	*rt_ray_plane_x(t_ray *ray, t_plane *plane, t_intersect *x)
{
	(void)ray;
	(void)plane;
	return (x);
}

// Computes the two collision distances between the ray and the cylinder
// chapter 13
t_intersect	*rt_ray_cylinder_x(t_ray *ray, t_cylinder *cylinder, t_intersect *x)
{
	(void)ray;
	(void)cylinder;
	return (x);
}

// Computes the two collision distances between the ray and the sphere
// Uses a quadratic equation discriminant = b²-4ac
t_intersect	*rt_ray_sphere_x(t_ray *ray, t_ray *new_ray,
t_sphere *sphere, t_intersect *x)
{
	t_tuple	*sphere_to_ray;
	float	a;
	float	b;
	float	c;
	float	discriminant;

	new_ray = rt_transform_ray(ray, sphere->transform);
	sphere_to_ray = subtract_tuple(ray->origin, sphere->coord);
	a = dot_product(ray->direction, ray->direction);
	b = 2.0f * dot_product(ray->direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - \
					powf((sphere->diameter / 2.0f), 2);
	discriminant = powf(b, 2) - 4.0f * a * c;
	free(sphere_to_ray);
	free(new_ray);
	if (discriminant < 0)
		return (x);
	x->x_distances[0] = (-b - sqrtf(discriminant)) / (2.0f * a);
	x->x_distances[1] = (-b + sqrtf(discriminant)) / (2.0f * a);
	x->x_count = 2;
	if (discriminant == 0)
		x->x_count = 1;
	return (x);
}

// Computes the intersections of a ray on a sphere.
// Returns a float[2] with the two distances values from the origin of the ray
// to the surfaces of the sphere 
t_intersect	*rt_ray_object_x(t_ray ray, void *object)
{
	t_intersect	*x;
	t_object	type;

	x = (t_intersect *)ft_calloc(1, sizeof(t_intersect));
	if (errno)
		handle_error(RT_RAY_OBJ_X, ENOMEM, "ft_calloc failed");
	x->object = object;
	x->ray = &ray;
	x->x_count = 0;
	type = *((t_object *)object);
	if (type == SPHERE)
		return (rt_ray_sphere_x(&ray, (t_sphere *)object, x));
	if (type == CYLINDER)
		return (rt_ray_cylinder_x(&ray, (t_cylinder *)object, x));
	if (type == PLANE)
		return (rt_ray_sphere_x(&ray, (t_plane *)object, x));
	return (x);
}
