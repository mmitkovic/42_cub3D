/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:28:06 by mmitkovi          #+#    #+#             */
/*   Updated: 2024/12/28 16:55:47 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
