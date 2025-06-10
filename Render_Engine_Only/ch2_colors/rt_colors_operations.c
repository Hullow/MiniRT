/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_colors_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:56:42 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tuple	rt_add_color(t_tuple c1, t_tuple c2)
{
	t_tuple	add;

	errno = 0;
	if (!is_equal_float(c1.w, COLOR) || !is_equal_float(c2.w, COLOR))
	{
		rt_handle_error(RT_ADD_COLOR, EINVAL, \
			"\none of the inputs is not a color");
		add = rt_color(0, 0, 0);
		return (add);
	}
	add.x = c1.x + c2.x;
	add.y = c1.y + c2.y;
	add.z = c1.z + c2.z;
	add.w = COLOR;
	return (add);
}

t_tuple	rt_sub_color(t_tuple c1, t_tuple c2)
{
	t_tuple	sub;

	errno = 0;
	if (!is_equal_float(c1.w, COLOR) || !is_equal_float(c2.w, COLOR))
	{
		rt_handle_error(RT_SUB_COLOR, EINVAL, \
			"\none of the inputs is not a color");
		sub = rt_color(0, 0, 0);
		return (sub);
	}
	sub.x = c1.x - c2.x;
	sub.y = c1.y - c2.y;
	sub.z = c1.z - c2.z;
	sub.w = COLOR;
	return (sub);
}

t_tuple	rt_scale_color(t_tuple c1, float s)
{
	t_tuple	mul;

	errno = 0;
	if (!is_equal_float(c1.w, COLOR))
	{
		rt_handle_error(RT_SCALE_COLOR, EINVAL, \
			"\nthe input tuple is not a color");
		mul = rt_color(0, 0, 0);
		return (mul);
	}
	mul.x = c1.x * s;
	mul.y = c1.y * s;
	mul.z = c1.z * s;
	mul.w = COLOR;
	return (mul);
}

t_tuple	rt_mul_color(t_tuple c1, t_tuple c2)
{
	t_tuple	mul;

	errno = 0;
	if (!is_equal_float(c1.w, COLOR) || !is_equal_float(c2.w, COLOR))
	{
		rt_handle_error(RT_MUL_COLOR, EINVAL, \
			"\none of the inputs is not a color");
		mul = rt_color(0, 0, 0);
		return (mul);
	}
	mul.x = c1.x * c2.x;
	mul.y = c1.y * c2.y;
	mul.z = c1.z * c2.z;
	mul.w = COLOR;
	return (mul);
}
