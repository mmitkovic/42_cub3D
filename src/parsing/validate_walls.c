/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:07:37 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/01 17:30:00 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int check_hole_ver(char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t')
		j++;
	while (map[i][j])
	{
		if ((map[i][j] == '0' && map[i + 1][j] == ' ')
			|| (map[i][j] == ' ' && map[i + 1][j] == '0')
			|| (map[i][j] == '0' && map[i + 1][j] == '\n')
			|| (map[i][j] == '0' && !map[i + 1][j]))
		{
			printf("Break at ver: %s at %d x %d\n", map[i], i+1, j+1);
			printf("Break at ver: %c\n", map[i][j]);
			return (1);
		}
		j++;
	}
	return (0);
}

static int check_hole_hor(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i])
	{
		if ((line[i] == '0' && line[i + 1] == ' ')
			|| (line[i] == ' ' && line[i + 1] == '0')
			|| (line[i] == '0' && line[i + 1] == '\n'))
		{
			printf("Break at hor: %c\n", line[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	validate_hor(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] != '1' && map[i][j] != '\n')
			return (1);
		if (map[i][j] == '\n')
		{
			i++;
			continue;
		}
		else 
		{
			if (check_hole_hor(map[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

static int validate_ver(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		printf("Exit at: %d ", j);
		if (map[i][j] == '\n')
		{
			i++;
			continue ;
		}
		else
		{
			printf("Check hole ver at: %d ", j);
			if (check_hole_ver(map, i, j))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	if (validate_hor(map))
		return (1);
	if (validate_ver(map))
		return (1);
	return (0);
}
