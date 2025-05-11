/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_phong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:30:23 by pberset           #+#    #+#             */
/*   Updated: 2025/05/11 18:38:22 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../micro_rt.h"

/// @brief 
/// @param o object for t_material and t_tuple COLOR
/// @param l light
/// @param point point on the object's surface where ray and light hit
/// @param eyev vector from point to camera
/// @param normalv normal vector on the point hit
/// @return the color of the point with lighting applied
t_tuple	rt_lighting(t_object o, t_light l, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_tuple	color;
	t_tuple	dir_to_light;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	float	light_dot_normal;
	t_tuple	reflect;
	float	reflect_dot_camera;
	float	factor;

	color = rt_scale_color(o.color, l.intensity);
	dir_to_light = rt_normalize(rt_sub_tuple(l.coord, point));
	ambient = rt_scale_color(color, o.material.ambient);
	light_dot_normal = rt_dot_product(dir_to_light, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = rt_color(0, 0, 0);
		specular = rt_color(0, 0, 0);
	}
	else
	{
		diffuse = rt_scale_color(color, o.material.diffuse * light_dot_normal);
		reflect = rt_reflect(rt_negate_tuple(dir_to_light), normalv);
		reflect = rt_normalize(reflect);
		reflect_dot_camera = rt_dot_product(reflect, eyev);
		if (reflect_dot_camera <= 0)
			specular = rt_color(0, 0, 0);
		else
		{
			factor = powf(reflect_dot_camera, o.material.shininess);
			specular = rt_scale_color(l.color, l.intensity * o.material.specular * factor);
		}
	}
	return (rt_add_color(ambient, rt_add_color(diffuse, specular)));
}

/// @brief Tonemapping that gives good results. tweak exposure between 0.5 and 5.0
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

/// @brief Sets all colors between 0 and 1 proportionally. Loses a lot of contrast
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
    t_tuple toned;
    toned.x = logf(color.x + 1.0) / logf(2.0 + 8.0);
    toned.y = logf(color.y + 1.0) / logf(2.0 + 8.0);
    toned.z = logf(color.z + 1.0) / logf(2.0 + 8.0);
    toned.w = color.w;
    return toned;
}
