/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:55:48 by pberset           #+#    #+#             */
/*   Updated: 2025/02/20 11:13:16 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 100, 100, "miniRT");
	mlx_loop(mlx);
	(void)mlx_win;
	//mlx_destroy_window(mlx, mlx_win);
	//mlx_destroy_display(mlx);
	ft_printf("%d Hello %s World\n", argc, argv[0]);
	return (0);
}
