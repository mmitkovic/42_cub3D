/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:33:06 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/29 17:31:24 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		if (!(floor = trim_newline(ft_strdup(skip_whitespaces(trim + 1)))))
			return (free_parser(parser), free(ceiling), NULL);
		trim_newline(floor);
		array = ft_split(floor, ',');
		if (!array)
			return (free_parser(parser), free(ceiling), free(floor), NULL);
		free(floor);
	}
	else if (letter == 'C')
	{
		if (!(ceiling = trim_newline(ft_strdup(skip_whitespaces(trim + 1)))))
			return (free_parser(parser), free(floor), NULL);
		trim_newline(ceiling);
		array = ft_split(ceiling, ',');
		if (!array)
			return (free_parser(parser), free(ceiling), free(floor), NULL);
		free(ceiling);
	}
	return (array);
}

int convert_to_int(t_parser *pars, char **array, char lett)
{
	int t1;
	int	t2;
	int t3;

	t1 = 0,
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
