/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:15:22 by fallan            #+#    #+#             */
/*   Updated: 2025/04/14 14:09:52 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* scene->sp = (t_object *)ft_calloc(scene->n_sp, sizeof(t_object));

void	rt_assign_sphere(t_scene *scene, char **needle)
{
	char		**coord;
	char		**color;
	t_object	*sp;

	coord = ft_split(*needle, ',');
	color = ft_split(*(needle + 2), ',');
	scene->sp->diameter = ft_strtof(*(needle + 1));
	if (!rt_valid_color(color) || !rt_valid_coord(coord) || errno != 0)
	{
		ft_free_tab(coord);
		ft_free_tab(color);
		return ;
	}
	scene->sp->coord = rt_point(ft_strtof(*coord), ft_strtof(*(coord + 1)),
			ft_strtof(*(coord + 2)));
	scene->sp->color = rt_color(ft_strtof(*color), ft_strtof(*(color + 1)),
			ft_strtof(*(color + 2)));
	scene->sp->type = SPHERE;
	ft_free_tab(coord);
	ft_free_tab(color);
}

typedef struct s_sphere
{
	t_object	type;
	t_tuple		*coord;
	float		diameter;
	t_tuple		*color;
}	t_object;
*/

t_tuple	normal_at(t_object sp, t_tuple point);

void	sp_normal_test(int test_id, char axis, t_tuple desired, t_object sp, t_tuple normal)
{
	char	*tuple_type[3] = {"VECTOR", "POINT", "COLOR"};

	(void)sp;
	printf("Test %d (desired result VECTOR(%f, %3.f, %3.f):\nThe normal on a sphere at a point on the %c axis is %s(%3.f, %3.f, %3.f)\n",
	test_id, desired.x, desired.y, desired.z, axis, tuple_type[(int) normal.w], normal.x, normal.y, normal.z);
}

void	test_normal(void)
{
	t_object sp;
	t_tuple n;
	
	sp.coord = (t_tuple){.x = 0.0, .y = 0.0, .z = 0.0, .w = POINT};
	sp.diameter = 2.0;
	sp.color = (t_tuple){.x = 0.1, .y = 0.1, .z = 0.1, .w = COLOR};

	// Basic test
	sp_normal_test(1, 'x', (t_tuple) {.x = 1.0, .y = 0.0, .z = 0.0}, sp, normal_at(sp, (t_tuple) {.x = 1.0, .y = 0.0, .z = 0.0, .w = POINT}));
	sp_normal_test(1, 'y', (t_tuple) {.x = 0, .y = 1.0, .z = 0.0}, sp, normal_at(sp, (t_tuple) {.x = 0.0, .y = 1.0, .z = 0.0, .w = POINT}));
	sp_normal_test(1, 'z', (t_tuple) {.x = 1.0, .y = 0.0, .z = 0.0}, sp, normal_at(sp, (t_tuple) {.x = 0.0, .y = 0.0, .z = 1.0, .w = POINT}));
	sp_normal_test(1, 'n', (t_tuple) {.x = sqrtf(3) / 3, .y = sqrtf(3) / 3, .z = sqrtf(3) / 3}, sp, normal_at(sp, (t_tuple) {.x = sqrtf(3) / 3, .y = sqrtf(3) / 3, .z = sqrtf(3) / 3, .w = POINT}));

	n = normal_at(sp, (t_tuple) {.x = sqrtf(3) / 3, .y = sqrtf(3) / 3, .z = sqrtf(3) / 3});
	if (is_equal_tuple(n, normalize(n)))
		printf("the normal is a normalized vector\n");
	else
		printf("error: the normal isn't a normalized vector. Please fix\n");

	// Translated sphere test
	// rt_translation();
}

t_tuple	normal_at(t_object sp, t_tuple point)
{
	t_tuple	origin;
	t_tuple	normal;

	(void)sp;
	origin = rt_point(0, 0, 0);
	normal = subtract_tuple(point, origin);
	return (normal);
}
/* 
int main()
{
	test_normal();
	return 0;
}
 */
// compiled with g -g ../*/*.c -I../../include -I../../include/libft/header -I../../mlx -lm -L../../include/libft -lft