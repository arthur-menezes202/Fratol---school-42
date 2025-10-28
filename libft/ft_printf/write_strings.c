/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:21:01 by armeneze          #+#    #+#             */
/*   Updated: 2025/08/15 13:44:40 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_character(char c);
int	write_string(char *s);

int	write_character(char c)
{
	write(1, &c, 1);
	return (1);
}

int	write_string(char *s)
{
	int	len;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
