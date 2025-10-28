/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:35:10 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/28 17:50:32 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	int		count;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	result = malloc(len_s1 + len_s2 + 1);
	count = 0;
	while (s1[count] != '\0')
	{
		result[count] = s1[count];
		count ++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		result[count + len_s1] = s2[count];
		count ++;
	}
	result[count + len_s1] = '\0';
	return (result);
}
