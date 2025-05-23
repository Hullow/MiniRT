/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:27:46 by fallan            #+#    #+#             */
/*   Updated: 2025/05/23 11:13:32 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
/* 
void	miniRT_input_tests(t_scene scene)
{
	if (!errno)
	{
		printf("light coords x: %f y: %f z: %f\n", scene.lux.coord.x, scene.lux.coord.y, scene.lux.coord.z);
		printf("light ratio : %f\n", scene.lux.ratio);
		printf("light color R: %f G: %f B: %f\n", scene.lux.color.x, scene.lux.color.y, scene.lux.color.z);
		printf("ambient ratio : %f\n", scene.amb.ratio);
		printf("ambient color R: %f G: %f B: %f\n", scene.amb.color.x, scene.amb.color.y, scene.amb.color.z);
		printf("camera coords x: %f y: %f z: %f\n", scene.cam.coord.x, scene.cam.coord.y, scene.cam.coord.z);
		printf("camera orient x: %f y: %f z: %f\n", scene.cam.orient.x, scene.cam.orient.y, scene.cam.orient.z);
		printf("camera field_of_view: %f\n", scene.cam.field_of_view);
		printf("sphere coords x: %f y: %f z: %f\n", scene.objects->coord.x, scene.objects->coord.y, scene.objects->coord.z);
		printf("sphere diameter : %f\n", scene.objects->diameter);
		printf("sphere color R: %f G: %f B: %f\n", scene.objects->color.x, scene.objects->color.y, scene.objects->color.z);
		printf("plane coords x: %f y: %f z: %f\n", scene.objects->coord.x, scene.objects->coord.y, scene.objects->coord.z);
		printf("plane normal x: %f y: %f z: %f\n", scene.objects->norm.x, scene.objects->norm.y, scene.objects->norm.z);
		printf("plane color R: %f G: %f B: %f\n", scene.objects->color.x, scene.objects->color.y, scene.objects->color.z);
		printf("cylinder coords x: %f y: %f z: %f\n", scene.objects->coord.x, scene.objects->coord.y, scene.objects->coord.z);
		printf("cylinder normal x: %f y: %f z: %f\n", scene.objects->norm.x, scene.objects->norm.y, scene.objects->norm.z);
		printf("cylinder diameter : %f\n", scene.objects->diameter);
		printf("cylinder height : %f\n", scene.objects->height);
		printf("cylinder color R: %f G: %f B: %f\n", scene.objects->color.x, scene.objects->color.y, scene.objects->color.z);
	}
}


void	miniRT_input_tests(t_scene scene)
{
	if (!errno)
	{
		printf("light coords x: %f y: %f z: %f\n", scene.lux.coord.x, scene.lux.coord.y, scene.lux.coord.z);
		printf("light ratio : %f\n", scene.lux.ratio);
		printf("light color R: %f G: %f B: %f\n", scene.lux.color.x, scene.lux.color.y, scene.lux.color.z);
		printf("ambient ratio : %f\n", scene.amb.ratio);
		printf("ambient color R: %f G: %f B: %f\n", scene.amb.color.x, scene.amb.color.y, scene.amb.color.z);
		printf("camera coords x: %f y: %f z: %f\n", scene.cam.coord.x, scene.cam.coord.y, scene.cam.coord.z);
		printf("camera orient x: %f y: %f z: %f\n", scene.cam.orient.x, scene.cam.orient.y, scene.cam.orient.z);
		printf("camera field_of_view: %f\n", scene.cam.field_of_view);
		int i = 0;
		while (i < scene.n_obj)
		{
			switch(scene.objects[i].type)
			{
				case SPHERE:
					printf("Type: SPHERE\n");
					break ;
				case PLANE:
					printf("Type: PLANE\n");
					break ;
				case CYLINDER:
					printf("Type: CYLINDER\n");
					break ;
				default:
					printf("not an object\n");
			}
			printf("coord: %f\n", scene.objects[i].coord.x);
			printf("coord: %f\n", scene.objects[i].coord.y);
			printf("coord: %f\n", scene.objects[i].coord.z);
			i++;
		}
	}
}
*/