/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:36:47 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/29 15:33:27 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char **extend_the_map(char **old_map, char *line)
{
	char **new_map;
	int size;
	int	i;

	new_map = NULL;
	i = 0;
	size = 0;
	while (old_map[size])
			size++;
	new_map = ft_calloc((size + 2), sizeof(char *));
	if (!new_map)
		return (NULL);
	while (i < size)
	{
		new_map[i] = old_map[i]; 				//copying adrresses to another container
		i++;
	}
	new_map[size] = ft_strdup(line);
	if (!new_map[size])
		return (free(new_map), NULL);
	if (old_map)								//freeing only container, If i free_split, new_map will also be freed.
		free(old_map);
	return (new_map);
}

int	add_another_line(t_parser *parser, char *line)
{
	char	**new_map;
	char	**old_map;

	old_map = parser->map;
	new_map = NULL;
	if (old_map == NULL) 
	{
		new_map = ft_calloc(2, sizeof(char *)); //calloc 2 position for 1 line to make it NULL at the end.
		if (!new_map)
			return (1);
		new_map[0] = ft_strdup(line);
		parser->map = new_map;
	}
	else if (old_map)
	{
		new_map = extend_the_map(old_map, line);
		if (!new_map)
			return (free_split(old_map), 1);
		parser->map = new_map;
	}
	return (0);
}

int parse_map(t_parser *parser, t_data *data)
{
	char	*line;
	int		i;
	
	i = 0;
	line = NULL;
	line = get_next_line(data->fd);
	while (line != NULL)
	{	
		add_another_line(parser, line); //passing old map saved into the structure and newline-to-add
		free(line);
		line = get_next_line(data->fd);
	}
	return (0);
}

// map grid, normalize rows