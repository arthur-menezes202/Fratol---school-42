/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:38:04 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/23 18:21:40 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (!s1 && n > 0)
		return (-1);
	if (!s2 && n > 0)
		return (1);
	while (count < n)
	{
		if (s1[count] != s2[count])
			return (s1[count] - s2[count]);
		count ++;
	}
	return (0);
}
