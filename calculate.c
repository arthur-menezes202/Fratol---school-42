/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:21 by armeneze          #+#    #+#             */
/*   Updated: 2025/10/29 11:17:36 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	generate_fractal(t_data *img, t_min_max min_max, t_info_window info)
{
	t_info_calc_fractol	*info_calc_fractol;
	double				zoom_x;
	double				zoom_y;
	int					iterations;
	int					x;
	int					y;
	int					color;

	x = 0;
	y = 0;
	zoom_x = (min_max.max_x - min_max.min_x) / info.wigth;
	zoom_y = (min_max.max_y - min_max.min_y) / info.height;

	while (x < info.wigth)
	{
		while (y < info.height)
		{
			info_calc_fractol->c_real = min_max.min_x + x * zoom_x;
			info_calc_fractol->c_imag = min_max.min_y + y * zoom_y;
			iterations = mandelbrot(0.0, 0.0, info_calc_fractol, info.max_iter);
			color = get_smooth_color(iterations, info.max_iter);
			my_mlx_pixel_put(img, x, y, color);
			y ++;
		}
		y = 0;
		x ++;
	}
}

void	calculate_fractol(t_data *img, t_info_window info,
	int param1, int param2)
{
	t_min_max	min_max;

	min_max = (t_min_max){-2.0, 1.0, -1.5, 1.5};
	generate_fractal(img, min_max, info);
}
