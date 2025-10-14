/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:32:56 by mmitkovi          #+#    #+#             */
/*   Updated: 2024/12/29 13:53:49 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
