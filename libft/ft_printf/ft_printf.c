/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:10:49 by armeneze          #+#    #+#             */
/*   Updated: 2025/09/15 09:07:10 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include "./../libft.h"
#include <stdarg.h>

static int	find_arguments(char c, va_list args);
static int	validation(const char *string, va_list args);

int	find_arguments(char c, va_list args)
{
	int			size;

	size = 0;
	if (c == 'c')
		size += write_character(va_arg(args, int));
	else if (c == 's')
		size += write_string(va_arg(args, char *));
	else if (c == 'p')
		size += write_pointer(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		size += write_int(va_arg(args, int));
	else if (c == 'u')
	{
		size += write_positive(va_arg(args, unsigned int));
	}
	else if (c == 'x')
		size += write_h_x((long)va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		size += write_h_x((long)va_arg(args, unsigned int), "0123456789ABCDEF");
	return (size);
}

int	validation(const char *string, va_list args)
{
	int		count;
	int		size;

	count = 0;
	size = 0;
	while (string[count] != '\0')
	{
		if (string[count] == '%' && string[count + 1] == '\0')
			size += write_character(string[count]);
		else if (string[count] == '%'
			&& ft_strchr("cspdiuxX", string[count + 1]) == 0)
		{
			size += write_character(string[count]);
			count ++;
		}
		else if (string[count] == '%')
		{
			size += find_arguments(string[count + 1], args);
			count ++;
		}
		else
			size += write_character(string[count]);
		count ++;
	}
	return (size);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, string);
	size = validation(string, args);
	va_end(args);
	return (size);
}
