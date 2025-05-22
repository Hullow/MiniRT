/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_magnitude.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:06:43 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 09:58:23 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

float	rt_magnitude(t_tuple vector)
{
	float	mag;

	mag = sqrtf(vector.x * vector.x + \
		vector.y * vector.y + \
		vector.z * vector.z + \
		vector.w * vector.w);
	return (mag);
}

t_tuple	rt_normalize(t_tuple vector)
{
	t_tuple	norm;

	norm.x = vector.x / rt_magnitude(vector);
	norm.y = vector.y / rt_magnitude(vector);
	norm.z = vector.z / rt_magnitude(vector);
	norm.w = (float)vector.w / rt_magnitude(vector);
	return (norm);
}
