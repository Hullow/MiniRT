/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:27:15 by pberset           #+#    #+#             */
/*   Updated: 2025/02/28 12:01:06 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	rt_count_object(const char *line, t_scene *scene)
{
	char	c_next;

	c_next = *(line + 1);
	while ((ft_isspace(*line) || *line == ' ') && *line != '\n')
		line++;
	if (!ft_strchr("ACLspc", *line))
	{
		ft_puterr_fd("error: unknown identifier\n");
		ft_printf("%c\n", *line);
		return (1);
	}
	if (ft_strchr("ACL", *line))
	{
		if (!ft_isspace(*(line + 1)) || *(line + 1) != ' ' || *(line + 1) == '\n')
		ft_puterr_fd("error: unknown identifier\n");
		ft_printf("%c\n", *line);
		return (2);
	}
	scene->n_A += *line == 'A';
	scene->n_C += *line == 'C';
	scene->n_L += *line == 'L';
	scene->n_sp += (*line == 's' && *(line + 1) == 'p');
	scene->n_pl += (*line == 'p' && *(line + 1) == 'l');
	scene->n_cy += (*line == 'c' && *(line + 1) == 'y');
	if (*line != 'A' && *line != 'C' && *line != 'L')
	{
		if (*line != 's' && *line != 'p' && *line != 'c')
		{
			ft_puterr_fd("error: unknown identifier\n");
			ft_printf("%c\n", *line);
			return (1);
		}
		if (*(line + 1) != 'p' && *(line + 1) != 'l' && *(line + 1) != 'y')
		{
			ft_puterr_fd("error: unknown identifier\n");
			ft_printf("%c\n", *line);
			return (2);
		}
		ft_puterr_fd("error: unknown identifier\n");
		ft_printf("%c\n", *line);
		return (3);
	}
	return (0);
}

int	ft_malloc_objects(t_scene *scene)
{
	if (scene->n_A != 1 || scene->n_C != 1 || scene->n_L != 1)
	{
		ft_puterr_fd("error: need axaclty 1 A && 1 C && 1 L\n");
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

