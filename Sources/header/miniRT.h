/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:11:14 by pberset           #+#    #+#             */
/*   Updated: 2025/02/20 18:57:59 by pberset          ###   Lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/header/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <errno.h>
#include <stdio.h>

// Returns 1 if the file extension is wrong or the file does not exist. Otherwise 0
int	rt_check_ext(char *file);
// Returns 1 if the sccene.rt file contains wrong data. Otherwise 0
int	rt_check_scene(char *file);

#endif
