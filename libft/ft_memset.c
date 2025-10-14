/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:33:46 by mmitkovi          #+#    #+#             */
/*   Updated: 2024/12/27 17:46:26 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_c;

	temp_c = (unsigned char *)s;
	while (n > 0)
	{
		temp_c[n - 1] = c;
		n--;
	}
	return (s);
}
