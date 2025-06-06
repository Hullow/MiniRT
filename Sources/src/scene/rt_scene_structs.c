/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:27:15 by pberset           #+#    #+#             */
/*   Updated: 2025/04/19 17:20:21 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	rt_id_format(const char a, const char b, const char c)
{
	if (ft_strchr("ACL", a) && (ft_isspace(b) || b == ' '))
		return (1);
	if (a == 's' && b == 'p' && (ft_isspace(c) || c == ' '))
		return (1);
	if (a == 'p' && b == 'l' && (ft_isspace(c) || c == ' '))
		return (1);
	if (a == 'c' && b == 'y' && (ft_isspace(c) || c == ' '))
		return (1);
	return (0);
}

// Checks the line for an object identifier and increments the counter
int	rt_count_object(const char *line, t_scene *scene)
{
	while ((ft_isspace(*line) || *line == ' '))
		line++;
	if (rt_id_format(*line, *(line + 1), *(line + 2)))
	{
		scene->n_a += *line == 'A' && rt_id_format(*line, *(line + 1), 0);
		scene->n_cam += *line == 'C' && rt_id_format(*line, *(line + 1), 0);
		scene->n_l += *line == 'L' && rt_id_format(*line, *(line + 1), 0);
		scene->n_sp += *line == 's' && \
			rt_id_format(*line, *(line + 1), *(line + 2));
		scene->n_pl += *line == 'p' && \
			rt_id_format(*line, *(line + 1), *(line + 2));
		scene->n_cy += *line == 'c' \
			&& rt_id_format(*line, *(line + 1), *(line + 2));
	}
	else if (*line)
		return (rt_handle_error(RT_COUNT_OBJECT, EINVAL, (char *)line), 1);
	return (0);
}

// Mallocs the amount of object structs in the scene
// Returns 1 if a unique object is missing or more than once in the scene
// Returns 2 if a malloc failed
// Otherwise 0
int	rt_malloc_objects(t_scene *scene)
{
	scene->n_obj = scene->n_sp + scene->n_cy + scene-> n_pl;
	if (scene->n_a != 1 || scene->n_cam != 1 || scene->n_l != 1)
	{
		errno = ERANGE;
		perror("Error\nneed exactly 1 A && 1 C && 1 L");
		return (1);
	}
	scene->objects = (t_object *)ft_calloc(scene->n_obj, sizeof(t_object));
	if (errno)
	{
		perror("Error\nfailed to malloc objects");
		return (2);
	}
	return (0);
}
