/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallan <fallan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:32:42 by fallan            #+#    #+#             */
/*   Updated: 2024/05/07 17:42:31 by fallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H 

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1200
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 900
# endif

# ifndef WINDOW_NAME
#  define WINDOW_NAME "Fil de Fer"
# endif

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "./lib/libft/libft.h"
# include "./lib/ft_printf/ft_printf.h"
# include "./lib/get_next_line/get_next_line.h"
# include "./lib/minilibx/mlx.h"

typedef struct s_env {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_list	*point_list;
}				t_env;

// input utils
int		ft_count_array_elements_debug(char **array);
int		ft_count_array_elements(char **array);
int		ft_hex_string_to_int(char *hex_string);
char	*ft_whitespace_to_space(char *str);
void	ft_free_list(t_list *point_list);
void	ft_free_array(char ***split, int *dimensions);
int		ft_count_columns(char *line);

// for debugging:
void	ft_max_altitude(t_list *point_list);
void	ft_print_point_list(t_env *env);
void	ft_draw_points(t_env *env);

// input handling
int		*ft_find_dimensions(int fd, int *dimensions);
int		*ft_examine_line(int fd, char *line_read, int *dimensions);
t_list	*ft_file_to_list(int fd, char *input);
char	***ft_read_to_array(int fd, int *dimensions);
t_list	*ft_fill_list(char ***split, int *dimensions, int i, int j);
double	*ft_fill_pt(char **split, int i, int j, int *dimensions);

// graph transformation
void	ft_center_points(t_list *point_list, double *min_max);
void	ft_isometric_projection(t_list *point_list);
double	*ft_min_max(t_list *point_list);
double	ft_calculate_zoom(double *min_max, int WIN_W, int WIN_H);
void	ft_apply_zoom(t_list *point_list, float zoom);
void	ft_z_rotation(t_list *point_list);
void	ft_x_rotation(t_list *point_list);
void	ft_orthographic_projection(t_list *point_list);

// graph utils
void	my_mlx_pixel_put(t_env *env, int x, int y, int color);
void	ft_line_put(t_env *env, double *coord);
void	ft_clear_pixels(t_env *env);

// drawing functions
void	ft_draw(t_env *env);
void	ft_draw_lines(t_env *env);
void	ft_draw_horizontal(t_env *env, double *coord, int i);
void	ft_draw_vertical(t_env *env, double *coord, int columns);

// window and event handling
void	launch_window_and_draw(t_list *point_list);
int		window_closed(t_env *env);
int		key_handler(int keycode, t_env *env);

#endif