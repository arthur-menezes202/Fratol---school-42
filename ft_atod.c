/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:25:38 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/03 15:48:09 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\v');
}

const char	*parse_number(const char *str, double *out)
{
	double	power;

	*out = 0.0;
	power = 0.1;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		*out = *out * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str && (*str >= '0' && *str <= '9'))
		{
			*out += (*str - '0') * power;
			power /= 10.0;
			str++;
		}
	}
	return (str);
}

double	ft_atod(const char *str)
{
	double		result;
	int			sign;
	const char	*rest;

	result = 0.0;
	sign = 1;
	while (*str && ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	rest = parse_number(str, &result);
	while (*rest)
	{
		if (!ft_is_space(*rest))
			return (0.0);
		rest++;
	}
	return (result * sign);
}
