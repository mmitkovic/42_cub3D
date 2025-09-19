/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:08:10 by mmitkovi          #+#    #+#             */
/*   Updated: 2024/12/27 18:11:54 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize > 0)
	{
		while (dstsize-- > 1 && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_len);
}
