/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:29:46 by armeneze          #+#    #+#             */
/*   Updated: 2025/08/15 13:46:29 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

static int	count_number_ints(int n);
int			write_int(int number);
int			write_positive(unsigned int number);

int	count_number_ints(int n)
{
	char		letter;
	long int	nb;
	int			count;

	count = 0;
	nb = (long int)n;
	if (nb < 0)
	{
		nb = nb *(-1);
		count ++;
	}
	if (nb >= 10)
	{
		count += count_number_ints(nb / 10);
	}
	letter = nb % 10 + '0';
	count ++;
	return (count);
}

int	write_int(int number)
{
	int		len;

	ft_putnbr_fd(number, 1);
	len = count_number_ints(number);
	return (len);
}

int	write_positive(unsigned int number)
{
	int		count;
	char	c;

	count = 0;
	if (number >= 10)
	{
		count += write_positive(number / 10);
	}
	c = (number % 10) + '0';
	count ++;
	write(1, &c, 1);
	return (count);
}
