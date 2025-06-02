/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:43:50 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 18:56:46 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rt_print_material(t_material mat)
{
	printf("ambient: %f, diffuse: %f, specular: %f, shininess: %f\n", \
		mat.ambient, mat.diffuse, mat.specular, mat.shininess);
}

void	rt_print_tuple(t_tuple t)
{
	ft_printf("x = %f y = %f z = %f ", t.x, t.y, t.z);
	if (t.w == VECTOR)
		ft_printf("of type VECTOR\n");
	if (t.w == POINT)
		ft_printf("of type POINT\n");
	if (t.w == COLOR)
		ft_printf("of type COLOR\n");
}

void	rt_print_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.rows)
	{
		ft_printf("row[%d]: | ", i);
		j = 0;
		while (j < m.columns)
		{
			ft_printf("%f | ", m.cell[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	rt_print_sphere(t_object sphere)
{
	ft_printf("Sphere %p\n", &sphere);
	ft_printf("Diameter: %f\n", sphere.diameter);
	ft_printf("Origin: ");
	rt_print_tuple(sphere.origin);
	ft_printf("Color: ");
	rt_print_tuple(sphere.color);
	ft_printf("Material: ");
	rt_print_material(sphere.material);
	ft_printf("Transform:\n");
	if (sphere.transform.columns != 4 || sphere.transform.rows != 4)
		ft_printf("Matrix size error: col: %d row: %d\n", sphere.transform.columns, sphere.transform.rows);
	else
		rt_print_matrix(sphere.transform);
}

t_inter	rt_intersect(float t, t_object obj)
{
	t_inter	i;

	i.object = obj;
	i.t = t;
	return (i);
}

void	rt_intersects(t_object object, t_xs *xs, int *i)
{
	if (object.shape == SPHERE)
		rt_discriminant(object.saved_ray, object, xs, i);
	else if (object.shape == PLANE)
		rt_ray_plane_x(object, object.saved_ray, xs, i);
	else if (object.shape == CYLINDER)
		rt_ray_cylinder_x(object, object.saved_ray, xs, i);
	else
		xs->count = 0;
}

t_tuple	rt_position(t_ray ray, float t)
{
	t_tuple	position;

	position = rt_add_tuple(ray.origin, rt_scale_vector(ray.direction, t));
	return (position);
}

t_tuple	rt_sphere_to_ray(t_tuple ray_origin, t_tuple sphere_origin)
{
	t_tuple	distance;

	distance = rt_sub_tuple(ray_origin, sphere_origin);
	return (distance);
}

void	rt_discriminant(t_ray ray, t_object sphere, t_xs *xs, int *i)
{
	float	discr;
	float	a;
	float	b;
	float	c;
	t_tuple	sp_ray;

	errno = 0;
	sp_ray = rt_sphere_to_ray(ray.origin, sphere.origin);
	a = rt_dot_product(ray.direction, ray.direction);
	b = 2 * rt_dot_product(ray.direction, sp_ray);
	c = rt_dot_product(sp_ray, sp_ray) - 1;
	discr = b * b - 4 * a * c;
	if (discr < 0)
		errno = EDISCRIMINANT;
	else
	{
		xs->count += 2;
		xs->inter[*i] = rt_intersect((-b - sqrtf(discr)) / (2 * a), sphere);
		(*i)++;
		xs->inter[*i] = rt_intersect((-b + sqrtf(discr)) / (2 * a), sphere);
		(*i)++;
	}
}
