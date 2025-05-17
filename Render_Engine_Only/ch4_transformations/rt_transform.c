/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_transform_ok.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:17:30 by pberset           #+#    #+#             */
/*   Updated: 2025/05/16 18:32:19 by fallan           ###   ########.fr       */
=======
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:17:30 by pberset           #+#    #+#             */
/*   Updated: 2025/05/07 11:10:26 by pberset          ###   ########.fr       */
>>>>>>> 31eda3a (corrected ch6 xs and intersect)
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

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
