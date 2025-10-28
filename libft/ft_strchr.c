/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:02:11 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/28 18:03:42 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		count;
	char	*string;

	count = 0;
	string = (char *)s;
	while (string[count] != '\0')
	{
		if (string[count] == (char)c)
		{
			return (string + count);
		}
		count ++;
	}
	if (c == '\0')
	{
		return (&string[count]);
	}
	return (0);
}
