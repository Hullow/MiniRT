/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_multiply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:02:22 by pberset           #+#    #+#             */
/*   Updated: 2025/03/07 18:18:28 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"

t_tuple	rt_hadamard(t_tuple color1, t_tuple color2)
{
	t_tuple	output;

	output.x = color1.x * color2.x;
	output.y = color1.y * color2.y;
	output.z = color1.z * color2.z;
	return (output);
}
