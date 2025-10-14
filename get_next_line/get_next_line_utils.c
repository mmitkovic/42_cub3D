/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:16:33 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/02/13 15:10:10 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t			i;
	unsigned char	*tmp;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	if (num > INT_MAX / size)
		return (NULL);
	i = 0;
	tmp = malloc(num * size);
	if (!tmp)
		return (NULL);
	while (i < num * size)
		tmp[i++] = 0;
	return (tmp);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		join[i + j] = s2 [j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
