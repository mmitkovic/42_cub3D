/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:55:15 by mmitkovi          #+#    #+#             */
/*   Updated: 2024/12/29 13:30:31 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(const char *set, char c);
static char	*ft_newstr(const char *s1, size_t start, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	int	j;
	int	i;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (ft_find(set, s1[i]) != 0)
		i++;
	while (ft_find(set, s1[j]) != 0)
		j--;
	if (i > j)
		return (ft_strdup(""));
	return (ft_newstr(s1, i, j - i + 1));
}

static int	ft_find(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_newstr(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (len == 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
