/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:44:21 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/31 10:37:10 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int			count;
	long long	result;
	int			sign;

	count = 0;
	result = 0;
	sign = 1;
	while (nptr[count] == ' ' || (nptr[count] >= '\t' && nptr[count] <= '\r'))
		count ++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign = -1;
		count++;
	}
	while (nptr[count] != '\0')
	{
		if (nptr[count] >= '0' && nptr[count] <= '9')
			result = result * 10 + (nptr[count] - '0');
		else
			return ((int)(result * sign));
		count ++;
	}
	return ((int)(result * sign));
}
