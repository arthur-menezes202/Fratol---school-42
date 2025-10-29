/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:01:08 by armeneze          #+#    #+#             */
/*   Updated: 2025/10/29 11:27:05 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hook_fractol(int keycode, t_vars *vars)
{
	ft_printf("Hello from key_hook_fractol!\n");
	ft_printf("%d\n", keycode);
	mlx_clear_window(vars->mlx, vars->win);
	return (0);
}
