/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:21 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/03 15:10:33 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_fractal(t_data *img, t_info_window info, double param1, double param2)
{
	t_info_calc_fractol	info_calc_fractol;
	double				zoom_x;
	double				zoom_y;
	int					iterations;
	int					x;
	int					y;
	int					color;

	x = 0;
	y = 0;
	zoom_x = (info.max_x - info.min_x) / info.wigth;
	zoom_y = (info.max_y - info.min_y) / info.height;
	while (x < info.wigth)
	{
		while (y < info.height)
		{
			info_calc_fractol.c_real = info.min_x + x * zoom_x;
			info_calc_fractol.c_imag = info.min_y + y * zoom_y;
			iterations = mandelbrot(param1, param2, &info_calc_fractol, info.max_iter);
			color = get_smooth_color(iterations, info.max_iter);
			my_mlx_pixel_put(img, x, y, color);
			y ++;
		}
		y = 0;
		x ++;
	}
}

void	calculate_fractol(t_vars *vars, double param1, double param2)
{
	generate_fractal(vars->img, vars->info, vars->param1, vars->param2);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
