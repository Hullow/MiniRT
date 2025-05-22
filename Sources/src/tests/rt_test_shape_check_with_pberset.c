/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:54:58 by pberset           #+#    #+#             */
/*   Updated: 2025/04/21 14:55:00 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
/*Sample objects
SPHERE:
ID COORD          DIAMETER    COLOR
sp 0.0,0.0,20.6   12.6        10,0,255

CYLINDER:
ID COORD            NORM           DIAMeTER      HEIGHT    COLOR
cy 50.0,0.0,20.6    0.0,0.0,1.0    14.2          21.42     10,0,255

PLANE:
ID COORD            NORM           COLOR
pl 0.0,0.0,-10.0    0.0,1.0,0.0    0,0,255
*/

static void	rt_assign_object(t_object *object, char **needle, char type);
static t_matrix	transform(t_object object);

// Book mentions ambient on material. We do not use this yet
void	test_shape(void)
{
	t_object	shape;
	t_ray		ray;
	t_scene		scene; // is not here in the final version, of course.
	t_tuple		point;
	t_tuple		world_normal;

	rt_assign_object(&shape, (char **){"50.0,0.0,20.6", "0.0,0.0,1.0", "14.2", "21.42", "10,0,255"}, 'c'); // example cylinder
	// rt_assign_object(&shape, (char **){"0.0,0.0,20.6", "12.6", "10,0,255"}, 's'); // example sphere
	// rt_assign_object(&shape, (char **){"0.0,0.0,-10.0", "0.0,1.0,0.0", "0,0,255"}, 'p'); // example plane

	ray.direction = rt_vector(1, 2, 3);
	ray.origin = rt_point(3, 2, 1);

	/*
	passing scene here. for the list of objects
	could pass the list directly
	initially list of intersections was stored in the scene. now can only be in ray
	no need to keep after pixel put

	unfinished function for now. Need sphere intersection to work first
	*/
	//ray.intersects = rt_compute_ray_intersects(&scene, ray, shape);

	// This transforms the ray according to the inverse of the transform matrix of the t_object shape
	// The transformation matrix and the inverse contain information for all the transforms applied to the t_object shape
	// Meaning: Rotation, transaltion, scale, (shear, if wanted for bonus)
	ray = rt_transform_ray(ray, shape.inverse);

	point = rt_point(1, 2, 3);
	world_normal = rt_normal_at(shape, point);

	/*test normal_at(shape, point), when shape is a plane always egal shape.norm*/
}

// Needle contains the values except the id in a splitted string
// type is the first letter of the id
static void	rt_assign_object(t_object *object, char **needle, char type)
{
	if (type == 's')
		rt_assign_sphere(object, needle);
	if (type == 'c')
		rt_assign_cylinder(object, needle);
	if (type == 'p')
		rt_assign_plane(object, needle);
	object->transform = transform(*object);
	object->inverse = matrix_inversion(object->transform);
}

static t_matrix	transform(t_object object)
{
	t_matrix	transform;

	transform = rt_translation( \
		rt_vector(object.coord.x, object.coord.y, object.coord.z));
	if (object.type == SPHERE)
	{
		transform = matrix_multiplication(transform, rt_scaling( \
			rt_vector(object.diameter, object.diameter, object.diameter)));
	}
	if (object.type == CYLINDER)
	{
		transform = matrix_multiplication(transform, rt_scaling( \
			rt_vector(object.diameter, object.height, object.diameter)));
	}
	if (object.type == PLANE || object.type == CYLINDER)
		transform = matrix_multiplication(transform, rt_rotation(object.norm));
	return (transform);
}
