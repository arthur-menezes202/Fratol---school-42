/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:06:00 by armeneze          #+#    #+#             */
/*   Updated: 2025/10/29 13:36:34 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "Imlx_linux/mlx.h"
# include <math.h>


typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct min_max {
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}				t_min_max;

typedef struct info_window {
	int		wigth;
	int		height;
	int		max_iter;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}				t_info_window;

typedef struct info_calc_fractol {
	double	c_real;
	double	c_imag;
	double	zoom_x;
	double	zoom_y;
}				t_info_calc_fractol;


void	my_mlx_pixel_put(t_data *lmx, int x, int y, int color);
void	calculate_fractol(t_data *img, t_info_window info,
			int param1, int param2);
int		get_smooth_color(int iterations, int max_iter);
int		burning_ship(double z_real, double z_imag,
			t_info_calc_fractol *calc_fractol, int max_iter);
int		mandelbrot(double z_real, double z_imag,
			t_info_calc_fractol *calc_fractol, int max_iter);
void	my_mlx_pixel_put(t_data *lmx, int x, int y, int color);
int		close_win(int keycode, t_vars *vars);
int		key_hook_fractol(int keycode, t_vars *vars);
void	start_fractol(char *type, int param1, int param2);

#endif