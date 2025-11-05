/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:06:00 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/05 14:32:30 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "Imlx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct info_window {
	int		wigth;
	int		height;
	int		max_iter;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
}				t_info_window;

typedef struct s_vars {
	void				*mlx;
	void				*win;
	t_data				*img;
	t_info_window		*info;
	double				param1;
	double				param2;
	char				*type;
}				t_vars;

typedef struct s_info_calc_fractol {
	double	c_real;
	double	c_imag;
	double	zoom_x;
	double	zoom_y;
	double	z_start_real;
	double	z_start_imag;
}				t_info_calc_fractol;

typedef struct s_ints
{
	int	iteration;
	int	x;
	int	y;
	int	color;
}				t_ints;

void	my_mlx_pixel_put(t_data *lmx, int x, int y, int color);
void	calculate_fractol(t_vars *vars);
int		get_smooth_color(int iterations, int max_iter);
int		burning_ship(double z_real, double z_imag,
			t_info_calc_fractol *calc_fractol, int max_iter);
int		mandelbrot(double z_real, double z_imag,
			t_info_calc_fractol *calc_fractol, int max_iter);
void	my_mlx_pixel_put(t_data *lmx, int x, int y, int color);
int		close_win(int keycode, t_vars *vars);
int		key_hook_fractol(int keycode, t_vars *vars);
void	start_fractol(char *type, double param1, double param2);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		julia(double x, long double y,
			t_info_calc_fractol *calc_fractol, int max_iter);
double	ft_atod(const char *str);
int		ft_is_double(const char *str);

#endif