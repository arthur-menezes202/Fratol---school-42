/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:40:36 by armeneze          #+#    #+#             */
/*   Updated: 2025/10/31 14:11:48 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ZOOM_IN_KEY 4
#define ZOOM_OUT_KEY 5
#define ZOOM_FACTOR 0.8

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	double	mouse_real;
	double	mouse_imag;
	double	zoom_amount;

	if (button == ZOOM_IN_KEY || button == ZOOM_OUT_KEY)
	{
		mouse_real = vars->info.min_x + (double)x * (vars->info.max_x
				-vars->info.min_x) / vars->info.wigth;
		mouse_imag = vars->info.min_y + (double)y * (vars->info.max_y
				- vars->info.min_y) / vars->info.height;
		zoom_amount = (button == ZOOM_IN_KEY) ? ZOOM_FACTOR : 1.0 / ZOOM_FACTOR;
		vars->info.min_x = mouse_real - (mouse_real - vars->info.min_x) * zoom_amount;
		vars->info.max_x = mouse_real + (vars->info.max_x - mouse_real) * zoom_amount;
		vars->info.min_y = mouse_imag - (mouse_imag - vars->info.min_y) * zoom_amount;
		vars->info.max_y = mouse_imag + (vars->info.max_y - mouse_imag) * zoom_amount;
		calculate_fractol(vars, 0, 0);
	}
	return (0);
}
