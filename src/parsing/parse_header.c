/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:32:29 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/01 15:09:40 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int parse_colours(t_parser *pars, char *trim)
{
	char	**array_floor;
	char	**array_ceiling;
	char	**array;
	
	array_floor = NULL;
	array_ceiling = NULL;
	if (*trim == 'F')
	{
		array = split_by_colour(pars, trim, 'F');
		if (!are_only_digits(array))
			return (free_split(array), printf("Wrong color format\n"), 1);
		if (convert_to_int(pars, array, 'F'))
			return (free_split(array), 1);
		free_split(array);
	}
	else if (*trim == 'C')
	{
		array = split_by_colour(pars, trim, 'C');
		if (!are_only_digits(array))
			return (free_split(array), printf("Wrong color format\n"), 1);
		if (convert_to_int(pars, array, 'C'))
			return (free_split(array), 1);
		free_split(array);
	}
	return (0);
}

int parse_textures(t_parser *pars, char *trim)
{	
	char *skipped;

	skipped = NULL;
	if (*trim == 'N' || *trim == 'S')
	{
		if (parse_n_s(pars, trim))
			return (1);
	}
	else if (*trim == 'W' || *trim == 'E')
	{
		if (parse_w_e(pars, trim))
			return (1);
	}
	return (0);
}

int dispatch_colour_parser(t_data *data, char *trim)
{
	if ((!ft_strncmp(trim, "NO", 2) && trim[2] == ' ') 
		|| (!ft_strncmp(trim, "SO", 2) && trim[2] == ' ') 
		|| (!ft_strncmp(trim, "WE", 2) && trim[2] == ' ')
		|| (!ft_strncmp(trim, "EA", 2) && trim[2] == ' '))
		{
			if (parse_textures(data->parser, trim))
				return (drain_out_gnl(data->fd), 1);
		}
	else if ((!ft_strncmp(trim, "F", 1) && trim[1] == ' ')
			|| (!ft_strncmp(trim, "C", 1) && trim[1] == ' '))
		{
			if (parse_colours(data->parser, trim))
				return (drain_out_gnl(data->fd), 1);
		}
	else 
		return (drain_out_gnl(data->fd), 1);
	return (0);
}

void init_for_parse(int *elements, int *i, char **line)
{
	*i = 0;
	*line = NULL;
	*elements = 0;
}

int check_textures_color(t_parser *parser, t_data *data)
{
	char	*line;
	char	*trim;
	int		i;
	int		elements;

	init_for_parse(&elements, &i, &line);
	line = get_next_line(data->fd);
	while (elements < 6 && line != NULL)
	{
		trim = skip_white(line);
		if (is_line_nul(trim, &line, data))
			continue ;
		else if (!dispatch_colour_parser(data, trim))
			elements++;
		free(line);
		if (elements == 6)
			return (0);
		line = get_next_line(data->fd);
	}
	if (line)
		free(line);
	if (elements != 6 || is_it_whitespace(parser))
			return (printf("Elements missing or typo"), 1);
	return (0);
}
