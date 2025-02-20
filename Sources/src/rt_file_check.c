/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:31:00 by pberset           #+#    #+#             */
/*   Updated: 2025/02/20 17:41:45 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	rt_check_ext(char *file)
{
	int	fd;
	fd = open(file, O_RDONLY);
	if (fd != 0)
	{
		ft_puterr_fd("error: file does not exist\n");
		return (1);
	}
	else
		close(fd);
	//check ext.rt
	return (0);
}

int	rt_check_scene(char *file)
{
	return (0);
}
