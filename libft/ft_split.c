/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:38:23 by mmitkovi          #+#    #+#             */
/*   Updated: 2024/12/29 16:05:55 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_word(const char *s, int *start, char c);
static int	words_counter(const char *s, char c);
static char	**free_all(char **arr, int count);

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**result;
	int		i;
	int		start;

	words = words_counter(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result || !s)
		return (NULL);
	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] && s[start] == c)
			start++;
		result[i] = extract_word(s, &start, c);
		if (!result[i])
			return (free_all(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}

static char	*extract_word(const char *s, int *start, char c)
{
	char	*word;
	int		end;
	int		i;

	end = *start;
	while (s[end] && s[end] != c)
		end++;
	word = (char *)malloc((end - *start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < end - *start)
	{
		word[i] = s[*start + i];
		i++;
	}
	word[i] = '\0';
	*start = end + 1;
	return (word);
}

static int	words_counter(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**free_all(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
