/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:18:10 by pberset           #+#    #+#             */
/*   Updated: 2025/06/02 15:31:11 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	rt_set_transform(t_object object)
{
	t_matrix	transform;

	if (object.shape == SPHERE)
	{
		transform = rt_scaling(\
			rt_vector(object.diameter / 2, object.diameter / 2, object.diameter / 2));
	}
	else if (object.shape == CYLINDER)
	{
		transform = rt_scaling(\
			rt_vector(object.diameter / 2, object.height, object.diameter / 2));
		transform = rt_mul_matrix(rt_rotation(object.norm), transform);
	}
	else if (object.shape == PLANE)
	{
		transform = rt_rotation(object.norm);
	}
	transform = rt_mul_matrix(rt_translation(\
		rt_vector(object.origin.x, object.origin.y, object.origin.z)), transform);
	return (transform);
}

//Detects the type of object and calls the corresponding constructor
static void	rt_assign_object(t_object *object, char **needle, char type)
{
	if (type == 's')
		rt_assign_sphere(object, needle);
	if (type == 'c')
		rt_assign_cylinder(object, needle);
	if (type == 'p')
		rt_assign_plane(object, needle);
}

static void	rt_assign_values(t_scene *scene, char **values)
{
	char		**needle;
	static int	i;

	if (*values != NULL)
	{
		if (i > scene->n_obj || i < 0)
			i = 0;
		needle = values + 1;
		if (**values == 'L')
			rt_assign_light(scene, needle);
		else if (**values == 'A')
			rt_assign_ambient(scene, needle);
		else if (**values == 'C')
		{
			rt_assign_camera(scene, needle);
			if (errno)
				return ;
			scene->cam = rt_calculate_camera_values(scene->cam);
		}
		else
		{
			rt_assign_object(&(scene->objects[i]), needle, **values);
			i++;
		}
	}
}

static void	rt_spacify(char *line)
{
	while (*line)
	{
		if (ft_isspace(*line))
			*line = ' ';
		line++;
	}
}

// Reads file to assign values in scene
int	rt_init_scene(const char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**splitted;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (rt_handle_error("rt_init_scene", errno, (char *)file), 1);
	
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rt_spacify(line);
		splitted = ft_split(line, ' ');
		rt_assign_values(scene, splitted);
		ft_free_tab(splitted);
		free(line);
		if (errno)
		{
			close(fd);
			return (2);
		}
	}
	close(fd);
	return (0);
}
