/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:08:11 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 17:48:46 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"

// for debugging purposes
// void	ft_max_altitude(t_list *point_list)
// {
// 	int	max_altitude;

// 	max_altitude = 0;
// 	while (point_list)
// 	{
// 		if (((double *)point_list->content)[2] > max_altitude)
// 			max_altitude = ((double *)point_list->content)[2];
// 		point_list = point_list->next;
// 	}
// 	ft_printf("final max altitude: %d\n", max_altitude);
// }

/* void	ft_print_point_list(t_env *env)
{
	int		i;
	t_list	*anchor;
	double	*temp;

	i = 0;
	anchor = env->point_list;
	temp = (double *)malloc (6 * sizeof(double));
	if (env->point_list)
	{
		while (env->point_list)
		{
			temp = (double *) env->point_list->content;
			printf("pt %d: (%f,%f), altitude %f, color %f   ", i++, \
			temp[0], temp[1], temp[2], temp[5]);
			printf("pt %d: (%f,%f), altitude %f,   ", i++, \
			temp[0], temp[1], temp[2]);
			if (i % 3 == 0)
				printf("\n");
			env->point_list = env->point_list->next;
		}
	}
	ft_free((void **)&temp);
	env->point_list = anchor;
} */

// void	ft_draw_points(t_env *env)
// {
// 	t_list	*anchor;
// 	double	*temp;

// 	anchor = env->point_list;
// 	temp = (double *) malloc (sizeof(double) * 6);
// 	if (env->point_list)
// 	{
// 		while (env->point_list)
// 		{
// 			temp = ((double *) env->point_list->content);
// 			my_mlx_pixel_put(env, temp[0], temp[1], temp[5]);
// 			env->point_list = env->point_list->next;
// 		}
// 	}
// 	ft_free((void **)&temp);
// 	env->point_list = anchor;
// }
