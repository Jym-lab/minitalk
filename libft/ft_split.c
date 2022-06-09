/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:35:43 by yjoo              #+#    #+#             */
/*   Updated: 2021/11/19 16:39:59 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *s, char c)
{
	size_t	i;
	size_t	word_cnt;

	i = 0;
	word_cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_cnt);
}

static void	mallocfree(char	**words)
{
	size_t	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static void	words_split(char const *s, char c, char **words)
{
	size_t	i;
	size_t	j;
	size_t	word_start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_start = i;
			while (s[i] && s[i] != c)
				i++;
			words[j] = (char *)malloc(sizeof(char) * (i - word_start + 1));
			if (!words[j])
				return (mallocfree(words));
			ft_memcpy(words[j], &s[word_start], (i - word_start));
			words[j][i - word_start] = 0;
			j++;
		}
		else
			i++;
	}
	words[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (words_count(s, c) + 1));
	if (!words)
		return (NULL);
	words_split(s, c, words);
	return (words);
}
