/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberset <pberset@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:11:14 by pberset           #+#    #+#             */
/*   Updated: 2025/02/21 16:34:48 by pberset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/header/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_ambient
{
	float	ratio;
	int		r;
	int		g;
	int		b;
}	t_ambient;

typedef struct s_camera
{
	float	x_coord;
	float	y_coord;
	float	z_coord;
	float	x_ort;
	float	y_ort;
	float	z_ort;
}	t_camera;

typedef struct s_light
{
	float	x_coord;
	float	y_coord;
	float	z_coord;
	float	ratio;
	int		r;
	int		g;
	int		b;
}	t_light;

typedef struct s_sphere
{
	float	x_coord;
	float	y_coord;
	float	z_coord;
	float	diameter;
	int		r;
	int		g;
	int		b;
}	t_sphere;

typedef struct s_plane
{
	float	x_coord;
	float	y_coord;
	float	z_coord;
	float	x_norm;
	float	y_norm;
	float	z_norm;
	int		r;
	int		g;
	int		b;
}	t_plane;

typedef struct s_cylinder
{
	float	x_coord;
	float	y_coord;
	float	z_coord;
	float	x_norm;
	float	y_norm;
	float	z_norm;
	float	diameter;
	float	height;
	int		r;
	int		g;
	int		b;
}	t_cylinder;

typedef struct s_scene
{
	t_ambient	*amb;
	t_camera	*cam;
	t_light		*lux;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}	t_scene;

// Returns 1 if the file extension is wrong. Otherwise 0
int	rt_check_ext(char *file);
// Returns 1 if the sccene.rt file contains wrong data. Otherwise 0
int	rt_check_scene(char *file);
// Extracts the values contained in .rt file and stores them in a struct
// Returns 1 if the struct is successfully created. Otherwise 0
int	rt_extract_scene(char *file);

#endif
