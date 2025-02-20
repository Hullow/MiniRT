/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:11:14 by pberset           #+#    #+#             */
/*   Updated: 2025/02/20 18:49:58 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/header/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define VECTOR 0
# define POINT 1

# define EPSILON 0.0001

/* A tuple:
	- has a type (int): either a vector (0) or a point (1)
	- has three coordinates:
		- x (float): lateral->to the right
		- y (float): vertical->up
		- z (float): depth->away from us */
typedef struct s_tuple {
	float	x;
	float	y;
	float	z;
	int		type;
}	t_tuple;

// Utils
	// Math
		// Basic bricks
		
int			is_equal_float(float a, float b);
float		abs_float(float a);

		// Tuples and tuple operations

t_tuple		*point(float x, float y, float z);
t_tuple		*vector(float x, float y, float z);
int			is_equal_tuple(t_tuple *a, t_tuple *b);
t_tuple		*add_tuple(t_tuple *a, t_tuple *b);
t_tuple		*substract_tuple(t_tuple *minuend, t_tuple *subtrahend);

#endif
