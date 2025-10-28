/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:57:51 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/23 18:20:41 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		count;
	size_t		len;
	size_t		len_src;

	if (!dst || !src)
		return (0);
	count = 0;
	len = 0;
	len_src = 0;
	while (dst[len] != '\0')
		len ++;
	while (src[len_src] != '\0')
		len_src ++;
	if (size <= len)
		return (len_src + size);
	while (src[count] != '\0' && count < size - len - 1)
	{
		dst[len + count] = src[count];
		count ++;
	}
	dst[len + count] = '\0';
	return (len_src + len);
}
