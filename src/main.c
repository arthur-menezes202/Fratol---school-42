/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:21:05 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/05 14:32:15 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_message_error(void)
{
	ft_printf("Incorrectly entered arguments\n");
	ft_printf("Examples:\n");
	ft_printf("Julia 0.285 0.01\n");
	ft_printf("Julia 0.45 0.1428\n");
	ft_printf("Julia -0.8 0.156\n");
	ft_printf("Julia -0.835 -0.2321\n");
	ft_printf("Mandelbrot\n");
	ft_printf("Burning_Ship\n");
	return ;
}

int	validation_param(char *argv2, char *argv3)
{
	if (argv2 == NULL || argv3 == NULL
		|| ft_is_double(argv2) == 0 || ft_is_double(argv3) == 0)
	{
		print_message_error();
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "Julia", 6) == 0)
	{
		if (argc != 4)
		{
			print_message_error();
			return (0);
		}
		if (validation_param(argv[2], argv[3]))
			return (0);
		else
			start_fractol("Julia", ft_atod(argv[2]), ft_atod(argv[3]));
	}
	else if ((ft_strncmp(argv[1], "Mandelbrot", 11) == 0
			|| ft_strncmp(argv[1], "Burning_Ship", 13) == 0)
		&& (argc == 2))
		start_fractol(argv[1], 0, 0);
	else
		print_message_error();
	return (0);
}
