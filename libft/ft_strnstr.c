/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:06:00 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/28 18:05:18 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	count2;

	count = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (len < 1)
		return (0);
	while (*big && count < len)
	{
		if (big[count] == little[0])
		{
			count2 = 0;
			while (little[count2] != '\0' && count + count2 < len)
			{
				if (big[count2 + count] != little[count2])
					break ;
				count2 ++;
			}
			if (little[count2] == '\0' && count2 > 0)
				return ((char *)&big[count]);
		}
		count ++;
	}
	return (0);
}
