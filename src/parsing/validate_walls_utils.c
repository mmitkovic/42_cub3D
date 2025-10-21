/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:27:40 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/21 11:46:25 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_outer_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] && (map[i][0] == '\n' || map[i][0] == '\0'))
		i++;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '0')
			return (1);
		j++;
	}
	return (0);
}

int	is_invalid_wall(char **map, int i, int j)
{
	if (i > 0)
	{
		if (!map[i - 1][j] || map[i - 1][j] == ' ' || map[i - 1][j] == '\n')
			return (1);
	}
	else
		return (1);
	if (map[i + 1])
	{
		if (!map[i + 1][j] || !map[i + 1] || map[i + 1][j] == ' ' || map[i
			+ 1][j] == '\n')
			return (1);
	}
	else
		return (1);
	return (0);
}
