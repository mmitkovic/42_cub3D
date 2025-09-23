/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 08:38:03 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/23 11:13:42 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_it_whitespace(t_parser *parser)
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

char	*skip_whitespaces(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}