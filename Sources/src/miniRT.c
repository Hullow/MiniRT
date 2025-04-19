/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:14:38 by fallan            #+#    #+#             */
/*   Updated: 2025/04/19 18:07:17 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main()
{
	test_matrices();
	// test_ray_sphere();
	return 0;
}

/* // the main function opens the file,
// sends it to the input handling functions,
// then calls the window/event handling functions,
// which call the graph handling and drawing functions
int	main(int argc, char *argv[])
{
	int		fd;
	t_list	*point_list;
	t_list	*anchor;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			perror(argv[1]);
		else
		{
			ft_printf("%s opened\n", argv[1]);
			point_list = ft_file_to_list(fd, argv[1]);
			anchor = point_list;
			(point_list);
			ft_free_list(anchor);
		}
	}
	else
		ft_printf("missing arguments\n");
	// exit(1);
	return (0);
} */

//
//			Final main with scene init from file !!!!!!
//

/*static void	rt_init_counters(t_scene *scene)
{
	scene->n_a = 0;
	scene->n_cam = 0;
	scene->n_l = 0;
	scene->n_sp = 0;
	scene->n_pl = 0;
	scene->n_cy = 0;
}

static int	build_scene(int argc, char *argv[], t_scene *scene)
{
	errno = 0;
	if (argc != 2)
	{
		errno = EBADF;
		perror("Error\nmissing \".rt\" file");
		return (1);
	}
	if (rt_check_ext(argv[1]))
		return (2);
	rt_init_counters(scene);
	if (rt_read_id(argv[1], scene))
		return (3);
	if (rt_malloc_objects(scene))
		return (4);
	if (rt_init_scene(argv[1], scene))
		return (5);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (build_scene(argc, argv, &scene))
		return (1);
	miniRT_input_tests(scene);
	return (0);
}
*/
