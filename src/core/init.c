/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:53:36 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/25 14:19:37 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	read_map(t_parser *parser, int fd)
{
	if (check_textures_color(parser, fd))
		return (1);
	return (0);
}

void	init_img(t_img *img)
{
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = -1;
	img->w = 0;
	img->h = 0;
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	init_img(&data->img);
	// data->textures
}

void	init_parser(t_parser *parser)
{
	parser->n_path = NULL;
	parser->s_path = NULL;
	parser->w_path = NULL;
	parser->e_path = NULL;
	parser->floor = 0;
	parser->ceiling = 0;
	// parser->map = NULL;
}
void	init(t_parser *parser, t_data *data)
{
	init_parser(parser);
	init_data(data);
}
// init ctx, load cfg, window, images