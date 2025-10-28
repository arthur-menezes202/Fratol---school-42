/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:03:28 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/31 10:07:33 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		count;
	char		*ptr;

	count = 0;
	ptr = (char *)s;
	while (count < n)
	{
		ptr[count] = (char)c;
		count++;
	}
	return (s);
}
