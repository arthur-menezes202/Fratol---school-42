/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:40:36 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/05 14:12:09 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_vars *v)
{
	double	mouse_real;
	double	mouse_imag;
	double	zoomt;

	if (button == 4 || button == 5)
	{
		mouse_real = v->info->min_x + (double)x * (v->info->max_x
				-v->info->min_x) / v->info->wigth;
		mouse_imag = v->info->min_y + (double)y * (v->info->max_y
				- v->info->min_y) / v->info->height;
		if (button == 4)
			zoomt = 0.8;
		else
			zoomt = 1.25;
		v->info->min_x = mouse_real - (mouse_real - v->info->min_x) * zoomt;
		v->info->max_x = mouse_real + (v->info->max_x - mouse_real) * zoomt;
		v->info->min_y = mouse_imag - (mouse_imag - v->info->min_y) * zoomt;
		v->info->max_y = mouse_imag + (v->info->max_y - mouse_imag) * zoomt;
		calculate_fractol(v);
	}
	return (0);
}
