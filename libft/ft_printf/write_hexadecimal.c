/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:38:53 by armeneze          #+#    #+#             */
/*   Updated: 2025/08/15 13:43:32 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_h_x(unsigned long number, const char *base);

int	write_h_x(unsigned long number, const char *base)
{
	int	count;

	count = 0;
	if (number >= 16)
	{
		count += write_h_x(number / 16, base);
	}
	write(1, &base[number % 16], 1);
	count++;
	return (count);
}
