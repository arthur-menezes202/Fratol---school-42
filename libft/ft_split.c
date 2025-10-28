/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:05:59 by armeneze          #+#    #+#             */
/*   Updated: 2025/09/25 16:52:30 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char const *s, char c);
static int	get_word_len(char const *s, char c);
static	char	**allocate(char **result, char const *s, char c, int num_words);

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	get_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static	char	**allocate(char **result, char const *s, char c, int num_words)
{
	int		i;
	int		j;
	int		word_len;

	i = 0;
	while (i < num_words)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		word_len = get_word_len(s, c);
		result[i] = (char *)ft_calloc(word_len + 1, sizeof(char));
		j = 0;
		while (j < word_len)
		{
			result[i][j] = *s;
			s++;
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		num_words;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	result = (char **)ft_calloc(sizeof(char *) * (num_words + 1), sizeof(char));
	if (!result)
		return (NULL);
	return (allocate(result, s, c, num_words));
}
