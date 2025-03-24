/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transforms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:36:33 by francis           #+#    #+#             */
/*   Updated: 2025/03/21 18:19:17 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	test_shear()
{
	print_matrix(
		matrix_multiplication(
			rt_shear(1, 0, 0, 0, 0, 0), 
			convert_tuple_to_matrix(point(2, 3, 4))));
}

int main()
{
	test_shear();
	return (0);
}
