/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:05:07 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/31 10:37:18 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_s1;
	int		start;
	char	*result;

	len_s1 = ft_strlen((char *)s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start ++;
	while (s1[len_s1 - 1] && ft_strchr(set, s1[len_s1 - 1]))
	{
		if (len_s1 <= start)
			return (ft_calloc(1, 1));
		len_s1 --;
	}
	result = ft_substr(s1, start, len_s1 - start);
	return (result);
}
