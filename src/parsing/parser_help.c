/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:33:06 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/30 14:49:32 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int are_only_digits(char **array)
{
	int		i;
	size_t		j;

	i = 0;
	while (array[i])
		i++;
	if (i != 3)
		return (printf("Wrong color format"), 0);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < ft_strlen(array[i]))
		{
			if ((array[i][j] < '0' || array[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int is_line_nul(char *trim, char **line, t_data *data)
{
	if (*trim == '\0' || *trim == '\n')
		{
			free(*line);
			*line = NULL;
			*line = get_next_line(data->fd);
			return (1);
		}
	return (0);
}

char **split_c(char *ceil, char *trim, t_parser *pars, char **array)
{
	ceil = trim_newline(ft_strdup(skip_white(trim + 1)));
	if (!ceil)
			return (free_parser(pars), free(floor), NULL);
	trim_newline(ceil);
	array = ft_split(ceil, ',');
	if (!array)
		return (free_parser(pars), free(ceil), free(floor), NULL);
	free(ceil);
	return (array);
}

char **split_by_colour(t_parser *parser, char *trim, char letter)
{
	char **array;
	char *floor;
	char *ceiling;

	array = NULL;
	floor = NULL;
	ceiling = NULL;
	if (letter == 'F')
	{
		floor = trim_newline(ft_strdup(skip_white(trim + 1)));
		if (!floor)
			return (free_parser(parser), free(ceiling), NULL);
		trim_newline(floor);
		array = ft_split(floor, ',');
		if (!array)
			return (free_parser(parser), free(ceiling), free(floor), NULL);
		free(floor);
	}
	else if (letter == 'C')
		array = split_c(ceiling, trim, parser, array);
	return (array);
}

int convert_to_int(t_parser *pars, char **array, char lett)
{
	int t1;
	int	t2;
	int t3;

	t1 = 0;
	t2 = 0;
	t3 = 0;
	if (array[0] == NULL || array[1] == NULL || array[2] == NULL)
		return (1);
	if (array[0])
		t1 = ft_atoi(array[0]);
	if (array[1])
		t2 = ft_atoi(array[1]);
	if (array[2])
		t3 = ft_atoi(array[2]);
	if ((t1 < 0 || t1 > 255)
		|| (t2 < 0 || t2 > 255)
		|| (t3 < 0 || t3 > 255))
		return (printf("Color value out of range"), 1);
	if (lett == 'F')
		pars->floor = (t1 * 256 * 256) + (t2 * 256) + t3;
	if (lett == 'C')
		pars->ceiling = (t1 * 256 * 256) + (t2 * 256) + t3;
	return (0);
}
