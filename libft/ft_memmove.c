/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:31:42 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/31 10:07:06 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, void *src, size_t n)
{
	int		count;
	char	*ptr;
	char	*copi;

	if (!dest && !src)
		return (0);
	ptr = (char *)dest;
	copi = (char *)src;
	count = 0;
	if (dest <= src)
	{
		while (n--)
		{
			*ptr++ = *copi++;
		}
	}
	else if (dest > src)
	{
		ptr += n - 1;
		copi += n - 1;
		while (n--)
			*ptr-- = *copi--;
	}
	return (dest);
}
