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
			rt_vector(object.radius, object.radius, object.radius));
	}
	else if (object.shape == CYLINDER)
	{
		transform = rt_scaling(\
			rt_vector(object.radius, 1, object.radius));
		transform = rt_mul_matrix(rt_rotation(object.norm), transform);
	}
	else
	{
		transform = rt_rotation(object.norm);
	}
	transform = rt_mul_matrix(rt_translation(\
		rt_vector(object.origin.x, object.origin.y, object.origin.z)), \
			transform);
	return (transform);
}

//Detects the type of object and calls the corresponding constructor
static void	rt_assign_object(t_object *object, char **needle, char type)
{
	if (type == 's' && count_splits(needle) == 3)
		rt_assign_sphere(object, needle);
	else if (type == 'c' && count_splits(needle) == 5)
		rt_assign_cylinder(object, needle);
	else if (type == 'p' && count_splits(needle) == 3)
		rt_assign_plane(object, needle);
	else
		rt_handle_error("RT_ASSIG_OBJ ", ENOMEM, &type);
}

static void	rt_assign_values(t_scene *scene, char **values)
{
	char		**needle;

	needle = values + 1;
	if (**values == 'L' && count_splits(needle) == 3)
		rt_assign_light(scene, needle);
	else if (**values == 'A')
		rt_assign_ambient(scene, needle);
	else if (**values == 'C' && count_splits(needle) == 3)
		rt_assign_camera(scene, needle);
	else if (ft_strchr("spc", **values) && scene->n_obj < MAX_OBJECTS - 1)
	{
		rt_assign_object(&(scene->objects[scene->n_obj]), needle, **values);
		scene->n_obj++;
	}
	else
		rt_handle_error("RT_ASSIG_VALS ", ENOMEM, *needle);
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
int	rt_init_scene(char *file, t_scene *scene)
{
	char	**splitted;

	rt_spacify(file);
	splitted = ft_split(file, ' ');
	if (!splitted)
	{
		rt_handle_error("INIT_SCENE ", ENOMEM, "ft_split failed");
		return (1);
	}
	if (count_splits(splitted) < 3)
	{
		rt_handle_error("INIT_SCENE ", ENOMEM, *splitted);
		ft_free_tab(splitted);
	}
	else
	{
		rt_assign_values(scene, splitted);
		ft_free_tab(splitted);
	}
	if (errno != 0)
		return (2);
	return (0);
}
