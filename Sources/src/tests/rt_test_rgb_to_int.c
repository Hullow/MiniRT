/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:59:13 by fallan            #+#    #+#             */
/*   Updated: 2025/04/18 16:33:05 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

typedef struct s_tuple {
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

int	rgb_to_int(t_tuple col_tuple)
{
	int	color;
	int	hex_r;
	int	hex_g;
	int	hex_b;

	color = 0;
	hex_r = (int) (col_tuple.x * 255);
	hex_g = (int) (col_tuple.y * 255);
	hex_b = (int) (col_tuple.z * 255);

	color += (hex_r / 16) * pow(16, 5) + (hex_r % 16) * pow(16, 4);
	color += (hex_g / 16) * pow(16, 3) + (hex_g % 16) * pow(16, 2);
	color += (hex_b / 16) * 16 + (hex_b % 16);
	return (color);
}
/* 
int main()
{
	t_tuple	rgb_tuple;

	rgb_tuple.x = 1;
	rgb_tuple.y = 1;
	rgb_tuple.z = 1;
	printf("rgb_to_int of (%.2f, %.2f, %.2f) returns %d\n", 
		rgb_tuple.x, rgb_tuple.y, rgb_tuple.z, rgb_to_int(rgb_tuple));
	return 0;
} */