/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:45:17 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/28 09:09:37 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*result;

	count = 0;
	result = ft_calloc(ft_strlen((char *)s) + 1, sizeof(char));
	while (s[count] != '\0')
	{
		result[count] = f(count, s[count]);
		count ++;
	}
	return (result);
}
