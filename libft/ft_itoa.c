/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:21:28 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/31 10:00:15 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static int	ft_strlen_int(long int n);
static char	*convert(long int nb, int n, int count_sig);

static int	ft_strlen_int(long int n)
{
	int	result;

	result = 1;
	if (n < 0)
	{
		result ++;
		n = -n;
	}
	while (n > 10)
	{
		n = n / 10;
		result ++;
	}
	return (result);
}

static char	*convert(long int nb, int n, int count_sig)
{
	char	*letter;
	int		count;

	letter = ft_calloc(ft_strlen_int(nb) + count_sig, sizeof(char));
	if (n > 0)
		count = ft_strlen_int(nb) - 1;
	else
		count = ft_strlen_int(nb);
	while (nb != 0)
	{
		letter[count--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (letter);
}

char	*ft_itoa(int n)
{
	char		*letter;
	int			sing;
	int			count_sig;
	long int	nb;

	nb = (long int)n;
	count_sig = 1;
	sing = 1;
	if (nb < 0)
	{
		nb = -nb;
		sing = -1;
		count_sig ++;
	}
	letter = convert(nb, n, count_sig);
	if (sing < 0)
		letter[0] = '-';
	if (n == 0)
		letter[0] = '0';
	return (letter);
}
