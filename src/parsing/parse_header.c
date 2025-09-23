/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:32:29 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/23 11:13:36 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int parse_textures(t_parser *pars, char *trim)
{	
	if (*trim == 'N')
	{
		if ((pars->n_path = ft_strdup(skip_whitespaces(trim + 2))) == NULL)
			return (1);
	}
	else if (*trim == 'S')
	{
		if ((pars->s_path = ft_strdup(skip_whitespaces(trim + 2))) == NULL)
			return (1);
	}
	else if (*trim == 'W')
	{
		if ((pars->w_path = ft_strdup(skip_whitespaces(trim + 2))) == NULL)
			return (1);
	}
	else if (*trim == 'E')
	{
		if ((pars->e_path = ft_strdup(skip_whitespaces(trim + 2))) == NULL)
			return (1);
	}
	return (0);
}


int check_textures(t_parser *parser, int fd)
{
	char	*line;
	char	*trim;
	int		i;
	int		textures;

	textures = 0;
	i = 0;
	line = NULL;
	line = get_next_line(fd);
	while (textures < 4 && line != NULL)
	{
		trim = skip_whitespaces(line);
		if (*trim == '\0' || *trim == '\n')
		{
			free(line);
		} 
		if (!ft_strncmp(trim, "NO", 2) || !ft_strncmp(trim, "SO", 2) 
				|| !ft_strncmp(trim, "WE", 2) || !ft_strncmp(trim, "EA", 2))
		{
			if (parse_textures(parser, trim))
				return (1);
			textures++;
		}
		//free(line);
		line = get_next_line(fd);
	}
	if (textures != 4 || is_it_whitespace(parser))
		return (printf("Missing texture or typo"), 1);
	return (0);
}
//F/C colors