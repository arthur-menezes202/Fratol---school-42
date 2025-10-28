/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:21:05 by armeneze          #+#    #+#             */
/*   Updated: 2025/10/28 09:46:26 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Imlx_linux/mlx.h"
#include "fractol.h"

void	my_mlx_pixel_put(t_data *lmx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1080 && y >= 0 && y < 1080)
	{
		dst = lmx->addr + (y * lmx->line_length + x
				* (lmx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}


int	main(void)
{
	void			*mlx;
	void			*mlx_win;
	t_data			*img;
	int				x;
	t_info_window	info;

	info = (t_info_window){1000, 1000, 1000};
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, info.wigth, info.height, "Julia");
	img->img = mlx_new_image(mlx, info.wigth, info.height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	calculate_fractol(&img, info);
	x = 0;
	while (x < 1)
	{
		x ++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}
