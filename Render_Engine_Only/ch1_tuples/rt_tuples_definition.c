/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_tuples_definition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:39:50 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/// @return t_tuple of type VECTOR (0.0)
t_tuple	rt_vector(float x, float y, float z)
{
	t_tuple	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = VECTOR;
	return (vector);
}

/// @return t_tuple of type POINT (1.0)
t_tuple	rt_point(float x, float y, float z)
{
	t_tuple	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = POINT;
	return (point);
}

/// @brief sets a normalized t_tuple COLOR
/// @param r RED [0-255] value
/// @param g GREEN [0-255] value
/// @param b BLUE [0-255] value
/// @return t_tuple of type COLOR (2.0) with normalized values (/255).
/// On error, sets errno and returns nulled color.
t_tuple	rt_color(float r, float g, float b)
{
	t_tuple	color;

	errno = 0;
	if ((r < 0.0f || r > 255.0f) || \
		(g < 0.0f || g > 255.0f) || \
		(b < 0.0f || b > 255.0f))
	{
		rt_handle_error(RT_COLOR, EINVAL, "\ninvalid color input");
		return (rt_color(0.0f, 0.0f, 0.0f));
	}
	color.x = r / 255.0f;
	color.y = g / 255.0f;
	color.z = b / 255.0f;
	color.w = COLOR;
	return (color);
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
