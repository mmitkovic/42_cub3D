/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:11:02 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/29 18:06:42 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_num_player(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player < 1 || player > 1)
	{
		printf("Num of players: %d\n", player);
		return (1);
	}
	return (0);
}

static int	check_valid_character(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\t' && line[i] != '1'
			&& line[i] != '0' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	map_check(t_data *data, char **map)
{
	int	i;

	(void)data;
	i = 0;
	// int j = 0;
	if (check_num_player(map))
		return (1);
	while (map[i])
	{
		if (check_valid_character(map[i]))
			return (1);
		i++;
	}
	return (0);
}
