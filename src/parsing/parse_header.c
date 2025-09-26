/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:32:29 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/26 12:43:11 by mmitkovi         ###   ########.fr       */
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
	char	*floor;
	char	*ceiling;
	char	**array_floor;
	char	**array_ceiling;
	
	array_floor = NULL;
	array_ceiling = NULL;
	floor = NULL;
	ceiling = NULL;
	if (*trim == 'F')
	{
		if ((floor = ft_strdup(skip_whitespaces(trim + 1))) == NULL)
			return (free_parser(pars), free(ceiling), 1);
		trim_newline(floor);
		array_floor = ft_split(floor, ',');
		if (!array_floor)
			return (free_parser(pars), free(ceiling), free(floor), 1);
		free(floor);
	}
	else if (*trim == 'C')
	{
		if ((ceiling = ft_strdup(skip_whitespaces(trim + 1))) == NULL)
			return (free_parser(pars), free(floor), 1);
		trim_newline(ceiling);
		array_ceiling = ft_split(ceiling, ',');
		if (!array_ceiling)
			return (free_parser(pars), free(ceiling), free(floor), 1);
		free(ceiling);
	}
	if (array_ceiling)
	{
		if (!are_only_digits(array_ceiling))
			return (free_split(array_ceiling), free_parser(pars), printf("Wrong color format"), 1);
		if (convert_to_int(pars, array_ceiling, 'C'))
			return (free_split(array_ceiling), free_parser(pars), 1);
		free_split(array_ceiling);
	}
	else if (array_floor)
	{
		if (!are_only_digits(array_floor))
			return (free_split(array_floor), free_parser(pars), printf("Wrong color formatttt"), 1);
		if (convert_to_int(pars, array_floor, 'F'))
			return (free_split(array_floor), free_parser(pars), 1);
		free_split(array_floor);
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

int check_textures_color(t_parser *parser, int fd)
{
	char	*line;
	char	*trim;
	int		i;
	int		elements;

	elements = 0;
	i = 0;
	line = NULL;
	line = get_next_line(fd);
	while (elements < 6 && line != NULL)
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
				return (free(line),(drain_out_gnl(fd)), 1);
			elements++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line)
	{
		free(line);
		printf("gnl\n");
		drain_out_gnl(fd);
	}
	if (elements != 6 || is_it_whitespace(parser))
			return (printf("Missing texture or typo"), free_parser(parser), 1);
	return (0);
}
