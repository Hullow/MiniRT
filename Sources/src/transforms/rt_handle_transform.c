/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_handle_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:49:52 by fallan            #+#    #+#             */
/*   Updated: 2025/05/02 14:20:57 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Applies a transformation to a ray, returning a new (non malloc-ed) ray
// Input:
// 	- a pointer to the ray to transform (t_ray *)
//	- a pointer to the transformation matrix to apply
//
// Returns:
//	- a pointer to the transformed ray (t_ray *)
t_ray	rt_transform_ray(t_ray *initial_ray, t_matrix trans)
{
	t_tuple		new_origin;
	t_tuple		new_direction;

	new_origin = matrix_tuple_multiplication(trans, initial_ray->origin);
	new_direction = matrix_tuple_multiplication(trans, initial_ray->direction);
	return (rt_ray(new_origin, new_direction));
}

// LIKELY USELESS
// Resets a sphere's transformation to the one given as argument (t_matrix *).
// frees the previously assigned transformation (default: identity)
// Returns: NULL in all cases
t_object	rt_set_sphere_transform(t_object sp, t_matrix trans)
{
	sp.transform = trans;
	return (sp);
}
