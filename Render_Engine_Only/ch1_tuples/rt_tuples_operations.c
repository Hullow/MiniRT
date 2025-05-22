/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuples_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:56:27 by pberset           #+#    #+#             */
/*   Updated: 2025/05/23 10:00:15 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

t_tuple	rt_add_tuple(t_tuple a, t_tuple b)
{
	t_tuple	add;


	add.x = a.x + b.x;
	add.y = a.y + b.y;
	add.z = a.z + b.z;
	add.x = a.x + b.x;
	add.y = a.y + b.y;
	add.z = a.z + b.z;
	add.w = a.w + b.w;
	return (add);
}

t_tuple	rt_sub_tuple(t_tuple a, t_tuple b)
{
	t_tuple	sub;
	float	sub_x;
	float	sub_y;
	float	sub_z;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	sub.z = a.z - b.z;
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
