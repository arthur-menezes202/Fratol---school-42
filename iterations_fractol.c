/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:32:13 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/05 14:32:40 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(double z_real, double z_imag,
	t_info_calc_fractol *calc_fractol, int max_iter)
{
	double	temp_real;
	int		i;
	double	abs_z_real;
	double	abs_z_imag;

	i = 0;
	while (z_real * z_real + z_imag * z_imag < 4.0 && i < max_iter)
	{
		abs_z_real = fabs(z_real);
		abs_z_imag = fabs(z_imag);
		temp_real = abs_z_real;
		z_real = abs_z_real * abs_z_real - abs_z_imag * abs_z_imag
			+ calc_fractol->c_real;
		z_imag = 2.0 * temp_real * abs_z_imag + calc_fractol->c_imag;
		i++;
	}
	return (i);
}

int	mandelbrot(double z_real, double z_imag,
	t_info_calc_fractol *calc_fractol, int max_iter)
{
	double	temp_real;
	int		i;

	i = 0;
	while (z_real * z_real + z_imag * z_imag < 4.0 && i < max_iter)
	{
		temp_real = z_real * z_real - z_imag * z_imag + calc_fractol->c_real;
		z_imag = 2.0 * z_real * z_imag + calc_fractol->c_imag;
		z_real = temp_real;
		i++;
	}
	return (i);
}
