/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_phong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:30:23 by pberset           #+#    #+#             */
/*   Updated: 2025/06/06 12:43:33 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_lighting_params	rt_dark_diffuse_specular(t_lighting_params v)
{
	v.diffuse = rt_color(0, 0, 0);
	v.specular = rt_color(0, 0, 0);
	return (v);
}

t_lighting_params	rt_colorize_diffuse_specular(t_light l, t_comps comp,
	t_intermediate_vars in, t_lighting_params v)
{
	t_object	obj;
	t_tuple		eyev;
	t_tuple		normalv;

	obj = comp.object;
	eyev = comp.eyev;
	normalv = comp.normalv;
	v.diffuse = rt_scale_color(
			in.color, obj.material.diffuse * in.light_dot_normal);
	in.reflect = rt_reflect(rt_negate_vector(in.dir_to_light), normalv);
	in.reflect = rt_normalize(in.reflect);
	in.reflect_dot_camera = rt_dot_product(in.reflect, eyev);
	if (in.reflect_dot_camera <= 0)
		v.specular = rt_color(0, 0, 0);
	else
	{
		in.factor = powf(in.reflect_dot_camera, obj.material.shininess);
		v.specular = rt_scale_color(
				l.color, l.intensity * obj.material.specular * in.factor);
	}
	return (v);
}

/// @brief computes ambient, diffuse and specular components of a pixel's color
/// @details - ambient = ambient color * intensity * material ambient component
///			 - if object is in shadows, return ambient light only
///			 - otherwise, calculates diffuse and specular lighting
///			 - the color returned is an addition of all types of lighting
/// @param l light
/// @param comp the prepared computations
/// @return the color of the point with lighting applied
t_tuple	rt_lighting(t_light l, t_comps comp)
{
	t_tuple				ambient_color;
	t_lighting_params	v;
	t_intermediate_vars	intm;

	ambient_color = rt_scale_color(l.ambient.color, l.ambient.intensity);
	v.ambient = rt_scale_color(ambient_color, comp.object.material.ambient);
	if (comp.in_shadow == true)
		return (rt_color(255, 192, 203));
		// return (v.ambient);
	
	/////// DIFFUSE AND SPECULAR ///////
	intm.color = rt_scale_color(comp.object.color, l.intensity);
	intm.dir_to_light = rt_normalize(rt_sub_tuple(l.coord, comp.point));
	intm.light_dot_normal = rt_dot_product(intm.dir_to_light, comp.normalv);
	if (intm.light_dot_normal < 0)
		v = rt_dark_diffuse_specular(v);
	else
		v = rt_colorize_diffuse_specular(l, comp, intm, v);
	return (rt_add_color(v.ambient, rt_add_color(v.diffuse, v.specular)));
}

/// @brief Tonemapping that gives good results.
/// 	   tweak exposure between 0.5 and 5.0
/// @param color 
/// @return the toned color
t_tuple	rt_reinhard_tonemap(t_tuple color)
{
	t_tuple	normal;
	float	exposure;

	exposure = 0.5f;
	normal.x = color.x / (1 + color.x * exposure);
	normal.y = color.y / (1 + color.y * exposure);
	normal.z = color.z / (1 + color.z * exposure);
	normal.w = COLOR;
	return (normal);
}

/// @brief Sets all colors between 0 and 1 proportionally.
/// 	   Loses a lot of contrast
/// @param color 
/// @return the normalized color
t_tuple	rt_normalize_color(t_tuple color)
{
	float	max;
	t_tuple	normal;

	max = fmax(fmax(color.x, color.y), color.z);
	normal.x = color.x / max;
	normal.y = color.y / max;
	normal.z = color.z / max;
	normal.w = color.w;
	return (normal);
}

/// @brief Tonemapping used in filmmaking
/// @param color 
/// @return the toned color
t_tuple	rt_filmic_tonemap(t_tuple color)
{
	t_tuple	toned;

	toned.x = logf(color.x + 1.0) / logf(2.0 + 8.0);
	toned.y = logf(color.y + 1.0) / logf(2.0 + 8.0);
	toned.z = logf(color.z + 1.0) / logf(2.0 + 8.0);
	toned.w = color.w;
	return (toned);
}
