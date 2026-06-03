/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:21 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/05 12:00:25 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_fractal_julia(t_vars *vars, int (fractal)(double z_real,
	double z_imag, t_info_calc_fractol *calc_fractol, int max_iter))
{
	t_info_calc_fractol	i_c_f;
	t_ints				ints;

	ints.x = 0;
	ints.y = 0;
	i_c_f.zoom_x = (vars->info->max_x - vars->info->min_x) / vars->info->wigth;
	i_c_f.zoom_y = (vars->info->max_y - vars->info->min_y) / vars->info->height;
	i_c_f.c_real = vars->param1;
	i_c_f.c_imag = vars->param2;
	while (ints.x < vars->info->wigth)
	{
		while (ints.y < vars->info->height)
		{
			i_c_f.z_start_real = vars->info->min_x + ints.x * i_c_f.zoom_x;
			i_c_f.z_start_imag = vars->info->min_y + ints.y * i_c_f.zoom_y;
			ints.iteration = fractal(i_c_f.z_start_real, i_c_f.z_start_imag,
					&i_c_f, vars->info->max_iter);
			ints.color = get_smooth_color(ints.iteration, vars->info->max_iter);
			my_mlx_pixel_put(vars->img, ints.x, ints.y, ints.color);
			ints.y ++;
		}
		ints.y = 0;
		ints.x ++;
	}
}

void	generate_fractal(t_vars *vars, int (fractal)(double z_real,
	double z_imag, t_info_calc_fractol *calc_fractol, int max_iter))
{
	t_info_calc_fractol	i_c_f;
	int					its;
	int					x;
	int					y;
	int					color;

	x = 0;
	y = 0;
	i_c_f.zoom_x = (vars->info->max_x - vars->info->min_x) / vars->info->wigth;
	i_c_f.zoom_y = (vars->info->max_y - vars->info->min_y) / vars->info->height;
	while (x < vars->info->wigth)
	{
		while (y < vars->info->height)
		{
			i_c_f.c_real = vars->info->min_x + x * i_c_f.zoom_x;
			i_c_f.c_imag = vars->info->min_y + y * i_c_f.zoom_y;
			its = fractal(vars->param1, vars->param2, &i_c_f,
					vars->info->max_iter);
			color = get_smooth_color(its, vars->info->max_iter);
			my_mlx_pixel_put(vars->img, x, y, color);
			y ++;
		}
		y = 0;
		x ++;
	}
}

void	calculate_fractol(t_vars *vars)
{
	if (ft_strncmp(vars->type, "Julia", 5) == 0)
		generate_fractal_julia(vars, mandelbrot);
	else if (ft_strncmp(vars->type, "Mandelbrot", 5) == 0)
		generate_fractal(vars, mandelbrot);
	else if (ft_strncmp(vars->type, "Burning_Ship", 12) == 0)
		generate_fractal(vars, burning_ship);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
