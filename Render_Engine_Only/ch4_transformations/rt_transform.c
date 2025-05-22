/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:17:30 by pberset           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:00 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Init a translation matrix in the direction given by the vector t
t_matrix	rt_translation(t_tuple t)
{
	t_matrix	translate;

	translate = rt_identity_matrix();
	translate.cell[0][3] = t.x;
	translate.cell[1][3] = t.y;
	translate.cell[2][3] = t.z;
	return (translate);
}

// Init a scaling matrix by the amount given by the vector t
t_matrix	rt_scaling(t_tuple t)
{
	t_matrix	scaling;

	scaling = rt_identity_matrix();
	scaling.cell[0][0] = t.x;
	scaling.cell[1][1] = t.y;
	scaling.cell[2][2] = t.z;
	return (scaling);
}

t_matrix	rt_set_transform(t_object object, t_matrix transform)
{
	t_matrix	modified;

	modified = rt_mul_matrix(object.transform, transform);
	return (modified);
}
