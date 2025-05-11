/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuples_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:56:27 by pberset           #+#    #+#             */
/*   Updated: 2025/05/01 10:56:30 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_tuple	rt_add_tuple(t_tuple a, t_tuple b)
{
	t_tuple	add;
	float	add_x;
	float	add_y;
	float	add_z;

	errno = 0;
	if (a.w == POINT && b.w == POINT)
	{
		errno = EINVAL;
		add = rt_point(0, 0, 0);
		return (add);
	}
	add_x = a.x + b.x;
	add_y = a.y + b.y;
	add_z = a.z + b.z;
	add = rt_point(add_x, add_y, add_z);
	add.w = a.w + b.w;
	return (add);
}

t_tuple	rt_sub_tuple(t_tuple a, t_tuple b)
{
	t_tuple	sub;
	float	sub_x;
	float	sub_y;
	float	sub_z;

	errno = 0;
	if ((a.w == VECTOR && b.w == POINT))
	{
		errno = EINVAL;
		sub = rt_point(0, 0, 0);
		return (sub);
	}
	sub_x = a.x - b.x;
	sub_y = a.y - b.y;
	sub_z = a.z - b.z;
	sub = rt_point(sub_x, sub_y, sub_z);
	sub.w = a.w - b.w;
	return (sub);
}

t_tuple	rt_negate_tuple(t_tuple	a)
{
	t_tuple	negate;

	negate.x = -a.x;
	negate.y = -a.y;
	negate.z = -a.z;
	negate.w = a.w;
	return (negate);
}
