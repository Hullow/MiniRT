/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:41:07 by pberset           #+#    #+#             */
/*   Updated: 2025/03/20 15:44:18 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

t_matrix	rt_translation(t_tuple t)
{
	t_matrix	translation;

	translation.rows = 4;
	translation.columns = 4;
	translation.m = {
		{1, 0, 0, t.x},
		{0, 1, 0, t.y},
		{0, 0, 1, t.z},
		{0, 0, 0, 1}
		};
	return (translation);
}

t_matrix	rt_scaling(t_tuple t)
{
	t_matrix	scaling;

	scaling.rows = 4;
	scaling.columns = 4;
	scaling.m = {
		{t.x, 0, 0, 0},
		{0, t.y, 0, 0},
		{0, 0, t.z, 0},
		{0, 0, 0, 1}
		};
	return (scaling);
}

t_matrix	rt_rotation_x(float angle)
{
	t_matrix	rotation;
	float		r;

	r = (angle * PI) / 180;
	rotation.rows = 4;
	rotation.columns = 4;
	rotation.m = {
		{1, 0, 0, 0},
		{0, cos(r), -sin(r), 0},
		{0, sin(r), cos(r), 0},
		{0, 0, 0, 1}
	};
	return (rotation);
}

t_matrix	rt_rotation_y(float angle)
{
	t_matrix	rotation;
	float		r;

	r = (angle * PI) / 180;
	rotation.rows = 4;
	rotation.columns = 4;
	rotation.m = {
		{cor(r), 0, sin(r), 0},
		{0, 1, 0, 0},
		{-sin(r), 0, cos(r), 0},
		{0, 0, 0, 1}
	};
	return (rotation);
}

t_matrix	rt_rotation_z(float angle)
{
	t_matrix	rotation;
	float		r;

	r = (angle * PI) / 180;
	rotation.rows = 4;
	rotation.columns = 4;
	rotation.m = {
		{cos(r), -sin(r), 0, 0},
		{sin(r), cos(r), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	return (rotation);
}

