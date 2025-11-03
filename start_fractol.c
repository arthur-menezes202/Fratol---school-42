/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:59:24 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/03 15:11:06 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_fractol(char *type, double param1, double param2)
{
	t_data			img;
	t_vars			vars;
	t_info_window	info;

	info = (t_info_window){600, 600, 250, -2, 2, -2, 2};
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, info.wigth, info.height, type);
	img.img = mlx_new_image(vars.mlx, info.wigth, info.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	vars.info = info;
	vars.img = &img;
	vars.param1 = param1;
	vars.param2 = param2;
	calculate_fractol(&vars, param1, param2);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
