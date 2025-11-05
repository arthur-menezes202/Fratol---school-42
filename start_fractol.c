/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:59:24 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/05 14:27:34 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	insert_string(t_vars *vars, char *type)
{
	int	i;

	vars->type = ft_calloc(ft_strlen(type), sizeof(char));
	i = 0;
	while (type[i] != '\0')
	{
		vars->type[i] = type[i];
		i ++;
	}
	return ;
}

int	close_window(t_vars *vars)
{
	if (!vars)
		return (0);
	if (vars->img && vars->img->img && vars->mlx)
	{
		mlx_destroy_image(vars->mlx, vars->img->img);
	}
	if (vars->win && vars->mlx)
	{
		mlx_destroy_window(vars->mlx, vars->win);
	}
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->type)
		free(vars->type);
	exit (0);
	return (0);
}

int	key_hooked(int k_code, t_vars *vars)
{
	if (k_code == 65307)
		close_window(vars);
	return (1);
}

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
	vars.info = &info;
	vars.img = &img;
	vars.param1 = param1;
	vars.param2 = param2;
	insert_string(&vars, type);
	calculate_fractol(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_key_hook(vars.win, key_hooked, &vars);
	mlx_loop(vars.mlx);
}
