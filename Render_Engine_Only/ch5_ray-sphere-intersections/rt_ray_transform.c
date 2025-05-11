/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:41:00 by pberset           #+#    #+#             */
/*   Updated: 2025/05/07 11:10:52 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_ray	rt_ray_transform(t_matrix m, t_ray r)
{
	t_ray	transformed;

	transformed.origin = rt_mul_tuple_matrix(m, r.origin);
	transformed.direction = rt_mul_tuple_matrix(m, r.direction);
	return (transformed);
}
