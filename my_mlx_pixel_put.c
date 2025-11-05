/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:00:22 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/05 14:30:18 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
