/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:53:36 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/24 13:34:26 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int read_map(t_parser *parser, int fd)
{
	if (check_textures_color(parser, fd))
		return (1);
	return (0);
}

void init_parser(t_parser *parser)
{
	parser->n_path = NULL;
	parser->s_path = NULL;
	parser->w_path = NULL;
	parser->e_path = NULL;
	parser->floor = 0;
	parser->ceiling = 0;
	parser->map = NULL;
}

// init ctx, load cfg, window, images