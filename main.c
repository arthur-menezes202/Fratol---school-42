/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:21:05 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/03 14:18:08 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Imlx_linux/mlx.h"
#include "fractol.h"

static	int	ft_is_double(const char *str)
{
	int	dot_count;
	int	digit_count;

	dot_count = 0;
	digit_count = 0;

	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\f' || *str == '\v'))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			digit_count++;
		else if (*str == '.')
			dot_count++;
		else if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\f' || *str == '\v')
			break ;
		else
			return (0);
		if (dot_count > 1)
			return (0);
		str++;
	}
	if (digit_count == 0)
		return (0);
	while (*str)
	{
		if (!(*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\f' || *str == '\v'))
			return (0);
		str++;
	}
	return (1);
}

void print_message_error()
{
	ft_printf("Incorrectly entered arguments\n");
	ft_printf("Examples:\n");
	exit(0);
}

void	validation_param(char *argv1, char *argv2)
{
	if (argv1 == NULL || argv1 == NULL
		|| ft_is_double(argv1) == 1 && ft_is_double(argv2) == 1)
	{
		print_message_error();
	}
	return ;
}


int	main(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "Julia", 5) == 0)
	{
		if (argc != 4)
			print_message_error();
		validation_param(argv[1], argv[2]);
		start_fractol("Julia", ft_atod(argv[1]), ft_atod(argv[2]));
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		start_fractol("Mandelbrot", 0, 0);
	return (0);
}
