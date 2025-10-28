/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:03:03 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/28 17:52:17 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		count;
	char	*new_string;
	size_t	s_len;

	count = 0;
	s_len = ft_strlen((char *)s);
	if (start > s_len)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > s_len)
		len = s_len - start;
	new_string = ft_calloc(len + 1, sizeof(char));
	while (count < (int)len && s[start] != '\0')
	{
		new_string[count] = s[start];
		start ++;
		count ++;
	}
	new_string[count] = '\0';
	return (new_string);
}
