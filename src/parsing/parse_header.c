/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:32:29 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/19 19:08:27 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_colours(t_data *data, t_parser *pars, char *trim)
{
	char	**array;

	if (*trim == 'F')
	{
		data->elem_f = 1;
		array = split_by_colour(pars, trim, 'F');
		if (!are_only_digits(array))
			return (free_split(array), printf("Error\nWrong color format\n"),
				1);
		if (convert_to_int(pars, array, 'F'))
			return (free_split(array), 1);
		free_split(array);
	}
	else if (*trim == 'C')
	{
		data->elem_c = 1;
		array = split_by_colour(pars, trim, 'C');
		if (!are_only_digits(array))
			return (free_split(array), printf("Error\nWrong color format\n"),
				1);
		if (convert_to_int(pars, array, 'C'))
			return (free_split(array), 1);
		free_split(array);
	}
	return (0);
}

int	parse_textures(t_data *data, t_parser *pars, char *trim)
{
	if (*trim == 'N' || *trim == 'S')
	{
		if (parse_n_s(data, pars, trim))
			return (1);
	}
	else if (*trim == 'W' || *trim == 'E')
	{
		if (parse_w_e(data, pars, trim))
			return (1);
	}
	return (0);
}

int	dispatch_colour_parser(t_data *data, char *trim, int *elements)
{
	if ((!ft_strncmp(trim, "NO", 2) && trim[2] == ' ' && data->elem_no != 1)
		|| (!ft_strncmp(trim, "SO", 2) && trim[2] == ' ' && data->elem_so != 1)
		|| (!ft_strncmp(trim, "WE", 2) && trim[2] == ' ' && data->elem_we != 1)
		|| (!ft_strncmp(trim, "EA", 2) && trim[2] == ' ' && data->elem_ea != 1))
	{
		elements++;
		if (parse_textures(data, data->parser, trim))
			return (drain_out_gnl(data->fd),
				printf("Error\nElem. missing/typo\n"), 1);
	}
	else if ((!ft_strncmp(trim, "F", 1) && trim[1] == ' ' && data->elem_f != 1)
		|| (!ft_strncmp(trim, "C", 1) && trim[1] == ' ' && data->elem_c != 1))
	{
		elements++;
		if (parse_colours(data, data->parser, trim))
			return (drain_out_gnl(data->fd), 1);
	}
	else
		return (drain_out_gnl(data->fd),
			printf("Error\nMissing/extra elem. or duplicate\n"), 1);
	return (0);
}

void	init_for_parse(int *elements, int *i, char **line)
{
	*i = 0;
	*line = NULL;
	*elements = 0;
}

int	check_textures_color(t_parser *parser, t_data *data)
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
		else if (!dispatch_colour_parser(data, trim, &elements))
			elements++;
		free(line);
		if (elements == 6)
			return (0);
		line = get_next_line(data->fd);
	}
	if (line)
		free(line);
	if (elements != 6 || is_it_whitespace(parser))
		return (1);
	return (0);
}
