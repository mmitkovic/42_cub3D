/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:38:03 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/01 14:30:26 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*trim_newline(char *str)
{
	size_t	len;
	size_t	i;

	i = 1;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (len > 0 && str[len - 1] == '\n')
		str[len - i] = '\0';
	return (str);
}

int	is_it_whitespace(t_parser *parser)
{
	if (*(parser->n_path) == '\n' || *(parser->n_path) == ' '
		|| *(parser->n_path) == '\0')
		return (1);
	if (*(parser->s_path) == '\n' || *(parser->s_path) == ' '
		|| *(parser->s_path) == '\0')
		return (1);
	if (*(parser->w_path) == '\n' || *(parser->w_path) == ' '
		|| *(parser->w_path) == '\0')
		return (1);
	if (*(parser->e_path) == '\n' || *(parser->e_path) == ' '
		|| *(parser->e_path) == '\0')
		return (1);
	return (0);
}

char	*skip_white_after(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line != '.' && *line != ' ')
		return (NULL);
	return (line);
}

char	*skip_white(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}
