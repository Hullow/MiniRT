/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_magnitude.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:06:43 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 10:06:23 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @brief computes the magnitude (length) of a vector
/// @param vector a tuple of type VECTOR
/// @return float (-1 if error)
float	rt_magnitude(t_tuple vector)
{
	float	mag;

	if (vector.w != VECTOR)
	{
		rt_handle_error(RT_MAGNITUDE, EINVAL, "\nnot a vector");
		errno = EINVAL;
		return (-1);
	}
	mag = sqrtf(vector.x * vector.x + \
		vector.y * vector.y + \
		vector.z * vector.z + \
		vector.w * vector.w);
	return (mag);
}

/// @brief normalizes a vector, i.e. reduces it to unit vector length
/// while preserving its direction)
/// @param vector a tuple of type VECTOR
/// @return the normalized vector (null vector if error)
t_tuple	rt_normalize(t_tuple vector)
{
	t_tuple	norm;

	if (is_equal_float(rt_magnitude(vector), 0))
	{
		rt_handle_error(RT_NORMALIZE, EINVAL, "\nvector is null	vector, \
			cannot normalize");
		return (vector);
	}
	if (vector.w != VECTOR)
	{
		rt_handle_error(RT_NORMALIZE, EINVAL, "\ninput is not a vector");
		return (vector);
	}
	norm.x = vector.x / rt_magnitude(vector);
	norm.y = vector.y / rt_magnitude(vector);
	norm.z = vector.z / rt_magnitude(vector);
	norm.w = (float)vector.w / rt_magnitude(vector);
	return (norm);
}
