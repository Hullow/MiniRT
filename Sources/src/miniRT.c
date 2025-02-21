/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:55:48 by pberset           #+#    #+#             */
/*   Updated: 2025/02/21 11:17:35 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_puterr_fd("error: one <file>.rt expected\n");
		return (1);
	}
	if (rt_check_ext(argv[1]))
		return (2);
	rt_extract_scene(argv[1]);
	if (rt_check_scene(argv[1]))
		return (3);
	printf("long %ld float %.3f and double %.6lf\n", ft_atol("21474836478749999"), ft_atof("-0123.456"), ft_atod("-789.101112"));
	return (0);
}
