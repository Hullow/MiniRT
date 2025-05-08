/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:19:56 by pberset           #+#    #+#             */
/*   Updated: 2025/05/07 11:18:20 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_object	rt_sphere(t_tuple color)
{
	t_object	sphere;

	sphere.shape = SPHERE;
	sphere.origin = rt_point(0, 0, 0);
	sphere.diameter = 0.5f;
	sphere.transform = rt_identity_matrix();
	sphere.color = color;
	return (sphere);
}
