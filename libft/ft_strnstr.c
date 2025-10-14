/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:09:25 by mmitkovi          #+#    #+#             */
/*   Updated: 2024/12/27 19:17:58 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_b;
	size_t	i_l;

	i_b = 0;
	i_l = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i_b] && i_b < len)
	{
		i_l = 0;
		while (big[i_b + i_l] == little[i_l] && big[i_b + i_l]
			&& (i_b + i_l) < len)
		{
			i_l++;
			if (little[i_l] == '\0')
				return ((char *)(big + i_b));
		}
		i_b++;
	}
	return (NULL);
}
