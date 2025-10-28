/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:14:23 by armeneze          #+#    #+#             */
/*   Updated: 2025/07/23 18:22:05 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*string;
	int		end;

	count = 0;
	string = (char *)s;
	end = -1;
	while (string[count] != '\0')
	{
		if (string[count] == (char)c)
			end = count;
		count ++;
	}
	if ((char)c == '\0')
	{
		return (&string[count]);
	}
	if (end > -1)
		return (string + end);
	return (0);
}
