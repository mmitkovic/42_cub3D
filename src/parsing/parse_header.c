/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:32:29 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/29 17:41:26 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !!! didnt handle when there is one or more spaces after F and C values !!!

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
			return (free_split(array), free_parser(pars), printf("Wrong color formatttt"), 1);
		if (convert_to_int(pars, array, 'F'))
			return (free_split(array), free_parser(pars), 1);
		free_split(array);
	}
	else if (*trim == 'C')
	{
		array = split_by_colour(pars, trim, 'C');
		if (!are_only_digits(array))
			return (free_split(array), free_parser(pars), printf("Wrong color format"), 1);
		if (convert_to_int(pars, array, 'C'))
			return (free_split(array), free_parser(pars), 1);
		free_split(array);
	}
	return (0);
}

int parse_textures(t_parser *pars, char *trim)
{	
	if (*trim == 'N')
	{
		if (!(pars->n_path = trim_newline(ft_strdup(skip_whitespaces(trim + 2)))))
			return (free_parser(pars), 1);
	}
	else if (*trim == 'S')
	{
		if (!(pars->s_path = trim_newline(ft_strdup(skip_whitespaces(trim + 2)))))
			return (free_parser(pars), 1);
	}
	else if (*trim == 'W')
	{
		if (!(pars->w_path = trim_newline(ft_strdup(skip_whitespaces(trim + 2)))))
			return (free_parser(pars), 1);
	}
	else if (*trim == 'E')
	{
		if (!(pars->e_path = trim_newline(ft_strdup(skip_whitespaces(trim + 2)))))
			return (free_parser(pars), 1);
	}
	return (0);
}

int check_textures_color(t_parser *parser, t_data *data)
{
	char	*line;
	char	*trim;
	int		i;
	int		elements;

	elements = 0;
	i = 0;
	line = NULL;
	line = get_next_line(data->fd);
	while (elements < 6) //|| line != NULL)
	{
		if (line == NULL)
			break;
		trim = skip_whitespaces(line);
		if (*trim == '\0' || *trim == '\n')
		{
			free(line);
			line = NULL;
		} 
		else if (!ft_strncmp(trim, "NO", 2) || !ft_strncmp(trim, "SO", 2) 
				|| !ft_strncmp(trim, "WE", 2) || !ft_strncmp(trim, "EA", 2))
		{
			if (parse_textures(parser, trim))
				return (free(line), 1);
			elements++;
		}
		else if (!ft_strncmp(trim, "F", 1) || !ft_strncmp(trim, "C", 1))
		{
			if (parse_colours(parser, trim))
				return (free(line), drain_out_gnl(data->fd), 1);
			elements++;
		}
		free(line);
		line = get_next_line(data->fd);
	}
	if (line)
		free(line);
	if (elements != 6 || is_it_whitespace(parser))
			return (printf("Missing texture or typo"), free_parser(parser), 1);
	return (0);
}
