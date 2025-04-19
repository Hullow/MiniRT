/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:08:48 by pberset           #+#    #+#             */
/*   Updated: 2025/04/19 15:08:49 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//Frees the matrices stored in the objects list
static void	free_objects(t_object *objects)
{
	int			i;
	t_matrix	*matrix;

	i = 0;
	while (&(objects[i]))
	{
		matrix = &(objects[i]).transform;
		ft_free_float_tab(matrix->m, matrix->rows);
		matrix = &(objects[i]).inverse;
		ft_free_float_tab(matrix->m, matrix->rows);
		i++;
	}
	free(objects);
}
//Free all elements of the scene
//Not needed if there are only the objects to free at the end of the program
void 	rt_free_scene(t_scene *scene)
{
	free_objects(scene->objects);
}
