/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:35:32 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/05 14:23:36 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_smooth_color(int iterations, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iterations / max_iter;
	r = (int)(9.0 * (1.0 - t) * t * t * t * 255.0);
	g = (int)(15.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0);
	b = (int)(8.5 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0);
	if (iterations == max_iter)
		return (0x000000);
	return (create_trgb(r, g, b));
}
