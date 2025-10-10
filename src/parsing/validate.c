/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:11:02 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/09 16:11:01 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void assign_position(t_data *data, int i, int j, int *player)
{
	data->pos_x = j;
	data->pos_y = i;
	(*player)++;
}

int	check_num_player(t_data *data, char **map)
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
			{
				data->player_letter = map[i][j];
				assign_position(data, i, j, &player);
			}
			j++;
		}
		i++;
	}
	if (player < 1 || player > 1)
		return (printf("Num of players: %d\n", player), 1);
	return (0);
}

int	check_valid_character(char *line)
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
	if (check_num_player(data, map))
		return (1);
	if (check_walls(map))
		return (1);
	while (map[i])
	{
		if (check_valid_character(map[i]))
			return (1);
		i++;
	}
	return (0);
}
