/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:27:53 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/19 13:41:43 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		count;
	size_t		len;

	count = 0;
	len = 0;
	if (!dst || !src)
		return (0);
	while (src[len] != '\0')
		len ++;
	if (size == 0)
		return (len);
	count = 0;
	while (count < len && count < size - 1)
	{
		dst[count] = src[count];
		count ++;
	}
	dst[count] = '\0';
	return (len);
}
