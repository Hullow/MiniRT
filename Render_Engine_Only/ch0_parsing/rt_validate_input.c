/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:03:06 by fallan            #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "miniRT.h"

int	rt_valid_color(char **color)
{
	int	i;
	int	j;

	i = 0;
	errno = 0;
	while (i < 3 && color[i])
	{
		if (ft_atoi(color[i]) > 255 || ft_atoi(color[i]) < 0)
			return (rt_handle_error(RT_VALID_COLOR, ERANGE, color[i]), 0);
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]))
				return (rt_handle_error(RT_VALID_COLOR, EINVAL, color[i]), 0);
			j++;
		}
		i++;
	}
	if (i != 3 || color[i] != 0)
		return (rt_handle_error(RT_VALID_COLOR, EINVAL,
				"\nwrong number of color arguments"), 0);
	return (1);
}

int	rt_valid_coord(char **coord)
{
	int	i;

	i = 3;
	errno = 0;
	while (i > 0 && *coord)
	{
		ft_strtof(*coord);
		if (errno)
			return (rt_handle_error(
					RT_VALID_COORD, EINVAL, "\nbad coordinates in input"), 0);
		i--;
		coord++;
	}
	if (i != 0 || *coord != 0)
		return (rt_handle_error(RT_VALID_COORD, EINVAL,
				"\nwrong number of coordinate arguments"), 0);
	return (1);
}

int	rt_valid_orient(char **orient)
{
	int		i;
	float	ver;

	i = 3;
	errno = 0;
	while (i > 0 && *orient)
	{
		ver = ft_strtof(*orient);
		if (ver < -1.0 || ver > 1.0)
			return (rt_handle_error(RT_VALID_ORIENT, ERANGE, *orient), 0);
		i--;
		orient++;
	}
	if (i != 0 || *orient != 0)
		return (rt_handle_error(RT_VALID_ORIENT, EINVAL,
				"\nwrong number of orientation arguments"), 0);
	return (1);
}
