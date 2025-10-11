/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:11:02 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/11 16:10:01 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	assign_position(t_data *data, int i, int j, int *player)
{
	if (*player > 0)
		return ;
	data->pos_x = j + 0.5; // to go to the grid cell center.
	data->pos_y = i + 0.5;
	data->player_letter = data->parser->map[i][j];
	*player = 1;
}

int	check_num_player(t_data *data, char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (player == 1)
					return (printf("Error: Multiple players found\n"), 1);
				assign_position(data, i, j, &player);
			}
			j++;
		}
		i++;
	}
	if (player != 1)
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

	i = 0;
	//(void)data;
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
	// map_size(data->parser);
	// printf("Map height: %d\n", data->parser->h);
	// printf("Map width: %d\n", data->parser->w);
	return (0);
}
