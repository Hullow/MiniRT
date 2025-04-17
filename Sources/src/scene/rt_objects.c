/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:34:36 by pberset           #+#    #+#             */
/*   Updated: 2025/04/14 17:00:01 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int rt_valid_color(char **color)
{
	int	i;
	int	j;

	i = 0;
	errno = 0;
	while (i < 3 && color[i])
	{
		if (ft_atoi(color[i]) > 255 || ft_atoi(color[i]) < 0)
		{
			errno = ERANGE;
			ft_putstr_fd("Error\n", STDERR_FILENO);
			perror(color[i]);
			return (0);
		}
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]))
			{
				errno = EINVAL;
				ft_putstr_fd("Error\n", STDERR_FILENO);
				perror(color[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i != 3 || color[i] != 0)
	{
		errno = EINVAL;
		perror("Error\nwrong number of color arguments");
		return (0);
	}
	return (1);
}

static int	rt_valid_coord(char **coord)
{
	int	i;

	i = 3;
	errno = 0;
	while (i > 0 && *coord)
	{
		ft_strtof(*coord);
		if (errno)
			return (1 && (handle_error(RT_VALID_COORD, EINVAL, "bad coordinates in input")));
		i--;
		coord++;
	}
	if (i != 0 || *coord != 0)
	{
		errno = EINVAL;
		perror("Error\nwrong number of coordinate arguments");
		return (0);
	}
	return (1);
}

static int	rt_valid_orient(char **orient)
{
	int		i;
	float	ver;

	i = 3;
	errno = 0;
	while (i > 0 && *orient)
	{
		ver = ft_strtof(*orient);
		if (ver < -1.0 || ver > 1.0)
			errno = ERANGE;
		if (errno)
		{
			perror(*orient);
			return (0);
		}
		i--;
		orient++;
	}
	if (i != 0 || *orient != 0)
	{
		errno = EINVAL;
		perror("wrong number of orientation arguments");
		return (0);
	}
	return (1);
}

void	rt_assign_light(t_scene *scene, char **needle)
{
	char	**coord;
	char	**color;

	errno = 0;
	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
	scene->lux.ratio = ft_strtof(*(needle + 1));
	if (scene->lux.ratio > 1.0 || scene->lux.ratio < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong ratio value");
	}
	if (errno != 0 || !rt_valid_color(color) || !rt_valid_coord(coord))
	{
		ft_free_tab(coord);
		ft_free_tab(color);
		return ;
	}
	scene->lux.coord = rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)), ft_strtof(*(coord + 2)));
	scene->lux.color = rt_color(ft_strtof(*color), ft_strtof(*(color + 1)), ft_strtof(*(color + 2)));
	ft_free_tab(coord);
	ft_free_tab(color);
}

void	rt_assign_ambient(t_scene *scene, char **needle)
{
	char	**color;

	errno = 0;
	color = ft_split(*(needle + 1), ',');
	scene->amb.ratio = ft_strtof(*(needle));
	if (scene->amb.ratio > 1.0 || scene->amb.ratio < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong ratio value");
	}
	if (!rt_valid_color(color) || errno != 0)
	{
		ft_free_tab(color);
		return ;
	}
	scene->amb.color = rt_color(ft_strtof(*color), ft_strtof(*(color + 1)), ft_strtof(*(color + 2)));
	ft_free_tab(color);
}

void	rt_assign_camera(t_scene *scene, char **needle)
{
	char	**coord;
	char	**orient;

	errno = 0;
	coord = ft_split(*needle, ',');
	orient = ft_split(*(needle + 1), ',');
	scene->cam.fov = ft_strtof(*(needle + 2));
	if (scene->cam.fov > 180.0 || scene->cam.fov < 0.0)
	{
		errno = ERANGE;
		perror("Error\nwrong fov value");
	}
	if (!rt_valid_orient(orient) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_tab(coord);
		ft_free_tab(orient);
		return ;
	}
	scene->cam.orient = rt_vector(ft_strtof(*orient), ft_strtof(*(orient + 1)), ft_strtof(*(orient + 2)));
	scene->cam.coord = rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)), ft_strtof(*(coord + 2)));
	ft_free_tab(coord);
	ft_free_tab(orient);
}

void	rt_assign_sphere(t_object *sphere, char **needle)
{
	char	**coord;
	char	**color;
	
	sphere->type = SPHERE;
	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
	sphere->diameter = ft_strtof(*(needle + 1));
	if (!rt_valid_color(color) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_tab(coord);
		ft_free_tab(color);
		return ;
	}
	sphere->coord = rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)), ft_strtof(*(coord + 2)));
	sphere->color = rt_color(ft_strtof(*color), ft_strtof(*(color + 1)), ft_strtof(*(color + 2)));
	sphere->type = SPHERE;
	ft_free_tab(coord);
	ft_free_tab(color);
}

void	rt_assign_plane(t_object *plane, char **needle)
{
	char	**coord;
	char	**norm;
	char	**color;
	
	plane->type = PLANE;
	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle + 1), ',');
	color = ft_split(*(needle + 2), ',');
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord) || !rt_valid_color(color))
	{
		ft_free_tab(coord);
		ft_free_tab(norm);
		ft_free_tab(color);
		return ;
	}
	plane->coord = rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)), ft_strtof(*(coord + 2)));
	plane->norm = rt_vector(ft_strtof(*norm), ft_strtof(*(norm + 1)), ft_strtof(*(norm + 2)));
	plane->color = rt_color(ft_strtof(*color), ft_strtof(*(color + 1)), ft_strtof(*(color + 2)));
	plane->type = PLANE;
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}

void	rt_assign_cylinder(t_object *cylinder, char **needle)
{
	char	**coord;
	char	**norm;
	char	**color;
	
	cylinder->type = CYLINDER;
	coord = ft_split(*needle, ',');
	norm = ft_split(*(needle + 1), ',');
	color = ft_split(*(needle + 4), ',');
	cylinder->diameter = ft_strtof(*(needle + 2));
	cylinder->height = ft_strtof(*(needle + 3));
	if (!rt_valid_orient(norm) || !rt_valid_coord(coord) || !rt_valid_color(color))
	{
		ft_free_tab(coord);
		ft_free_tab(norm);
		ft_free_tab(color);
		return ;
	}
	cylinder->coord = rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)), ft_strtof(*(coord + 2)));
	cylinder->norm = rt_vector(ft_strtof(*norm), ft_strtof(*(norm + 1)), ft_strtof(*(norm + 2)));
	cylinder->color = rt_color(ft_strtof(*color), ft_strtof(*(color + 1)), ft_strtof(*(color + 2)));
	cylinder->type = CYLINDER;
	ft_free_tab(coord);
	ft_free_tab(norm);
	ft_free_tab(color);
}

/* initializes a sphere based on a tuple for coordinates, a float for diameter, 
and a tuple for color. Both input tuples to be initialized on the stack, thus:
(t_tuple){.x = , .y = , .z = } */
t_sphere	*rt_init_sphere(t_tuple coord, float diam, t_tuple color)
{
	t_sphere	*sp = NULL;

	sp = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (errno)
		return (handle_error(INIT_SP, ENOMEM, NULL));
	sp->coord = rt_point(coord.x, coord.y, coord.z);
	sp->color = rt_color(color.x, color.y, color.z);
	printf("rt_init_sphere\n- input (%f, %f, %f)\n", color.x, color.y, color.z);
	printf("- output (%f, %f, %f)\n", sp->color->x, sp->color->y, sp->color->z);
	sp->transform = identity_matrix(4, 4);
	if (errno)
	{
		free (sp);
		free (sp->coord);
		free (sp->color);
		free (sp->transform);
		return (handle_error(INIT_SP, ENOMEM, NULL));
	}
	sp->diameter = diam;
	return (sp);
}
