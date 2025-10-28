/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:26:48 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/22 16:42:21 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		count;
	int		len;
	char	*string;

	count = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	string = (char *)malloc(len + 1);
	while (count < len)
	{
		string[count] = s[count];
		count ++;
	}
	string[count] = '\0';
	return (string);
}
