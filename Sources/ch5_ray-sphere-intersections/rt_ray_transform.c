/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:41:00 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief Applies a transformation to a ray
/// @param m transformation matrix
/// @param r ray to transform
/// @return the (new) transformed ray
t_ray	rt_ray_transform(t_matrix m, t_ray r)
{
	t_ray	transformed;

	transformed.origin = rt_mul_tuple_matrix(m, r.origin);
	transformed.dir = rt_mul_tuple_matrix(m, r.dir);
	return (transformed);
}
