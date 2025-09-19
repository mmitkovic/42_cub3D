/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:43:52 by mmitkovi          #+#    #+#             */
/*   Updated: 2024/12/29 15:51:44 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n);
static char	*int_to_str(int num, int len);
static char	*ft_limit(int nbr);

char	*ft_itoa(int n)
{
	char	*limit;
	char	*str;
	int		len;

	limit = ft_limit(n);
	if (limit)
		return (limit);
	len = int_len(n);
	str = int_to_str(n, len);
	return (str);
}

static char	*ft_limit(int nbr)
{
	if (nbr == INT_MIN)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

static int	int_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*int_to_str(int num, int len)
{
	char	*str;

	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
