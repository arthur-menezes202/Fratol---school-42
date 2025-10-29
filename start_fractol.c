/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:59:24 by armeneze          #+#    #+#             */
/*   Updated: 2025/10/29 12:10:25 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_image_fractol(t_data *img, t_info_window *info,
		int param1, int param2)
{
	calculate_fractol(img, *info, param1, param2);
	return ;
}

void	start_fractol(char *type, int param1, int param2)
{
	t_data			img;
	t_vars			vars;
	t_info_window	info;

	info = (t_info_window){1000, 1000, 1000};
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, info.wigth, info.height, type);
	img.img = mlx_new_image(vars.mlx, info.wigth, info.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	new_image_fractol(&img, &info, param1, param2);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
