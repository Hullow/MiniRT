/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:27:15 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
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

int	rt_count_object(char *line, t_scene *scene)
{
	while ((ft_isspace(*line) || *line == ' '))
		line++;
	if (*line)
	{
		if (rt_id_format(*line, *(line + 1), *(line + 2)))
		{
			if (rt_init_scene(line, scene))
				return (1);
		}
		else
		{
			rt_handle_error(RT_COUNT_OBJECT, EINVAL, (char *)line);
			return (2);
		}
	}
	return (0);
}

// Mallocs the amount of object structs in the scene
// Returns 1 if a unique object is missing or more than once in the scene
// Returns 2 if a malloc failed
// Otherwise 0
int	rt_check_uniques(t_scene *scene)
{
	if (scene->n_a != 1 || scene->n_cam != 1 || scene->n_l != 1)
	{
		errno = ERANGE;
		perror("Error\nneed exactly 1 A && 1 C && 1 L");
		return (1);
	}
	return (0);
}
