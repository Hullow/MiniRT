/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:27:15 by pberset           #+#    #+#             */
/*   Updated: 2025/03/13 11:51:25 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

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
		scene->n_A += *line == 'A' && rt_id_format(*line, *(line + 1), 0);
		scene->n_C += *line == 'C' && rt_id_format(*line, *(line + 1), 0);
		scene->n_L += *line == 'L' && rt_id_format(*line, *(line + 1), 0);
		scene->n_sp += *line == 's' && \
			rt_id_format(*line, *(line + 1), *(line + 2));
		scene->n_pl += *line == 'p' && \
			rt_id_format(*line, *(line + 1), *(line + 2));
		scene->n_cy += *line == 'c' \
			&& rt_id_format(*line, *(line + 1), *(line + 2));
	}
	else if (*line)
	{
		ft_puterr_fd("error: unknown object identifier\n");
		ft_printf(line);
		return (1);
	}
	return (0);
}

// Mallocs the amount of object structs in the scene
// Returns 1 if a unique object is missing or more than once in the scene
// Returns 2 if a malloc failed
// Otherwise 0
int	rt_malloc_objects(t_scene *scene)
{
	if (scene->n_A != 1 || scene->n_C != 1 || scene->n_L != 1)
	{
		ft_puterr_fd("error: need exactly 1 A && 1 C && 1 L\n");
		return (1);
	}
	scene->amb = (t_ambient *)ft_calloc(1, sizeof(t_ambient));
	scene->cam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	scene->lux = (t_light *)ft_calloc(1, sizeof(t_light));
	scene->sp = (t_sphere *)ft_calloc(scene->n_sp, sizeof(t_sphere));
	scene->pl = (t_plane *)ft_calloc(scene->n_pl, sizeof(t_plane));
	scene->cy = (t_cylinder *)ft_calloc(scene->n_cy, sizeof(t_cylinder));
	if (!scene->amb || !scene->cam || !scene->lux || !scene->sp || !scene->pl \
																|| !scene->cy)
	{
		ft_puterr_fd("error: failed to malloc objects\n");
		return (2);
	}
	return (0);
}

