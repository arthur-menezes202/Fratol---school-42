/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:11:47 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/23 18:21:03 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		count;
	char		*string;

	count = 0;
	string = (char *)s;
	while (count < n)
	{
		if (string[count] == (char)c)
			return (string + count);
		count ++;
	}
	return (0);
}
