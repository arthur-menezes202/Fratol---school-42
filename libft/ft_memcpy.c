/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:33:21 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/28 18:02:22 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		count;
	char		*ptr;
	char		*copi;

	ptr = (char *)dest;
	copi = (char *)src;
	count = 0;
	while (count < n)
	{
		ptr[count] = copi[count];
		count ++;
	}
	return (ptr);
}
