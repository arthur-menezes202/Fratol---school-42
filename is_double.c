/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:17:18 by armeneze          #+#    #+#             */
/*   Updated: 2025/11/04 14:09:03 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

int	check_space(const char *str)
{
	while (*str)
	{
		if (!ft_is_space(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_is_double(const char *str)
{
	int	dot_count;
	int	digit_count;

	dot_count = 0;
	digit_count = 0;
	while (*str && ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && !ft_is_space(*str))
	{
		if (*str >= '0' && *str <= '9')
			digit_count++;
		else if (*str == '.')
			dot_count++;
		else
			break ;
		if (dot_count > 1)
			return (0);
		str++;
	}
	if (digit_count == 0 || check_space(str) == 0)
		return (0);
	return (1);
}
