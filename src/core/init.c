/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:53:36 by hgatarek          #+#    #+#             */
/*   Updated: 2025/09/29 15:26:00 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	read_map(t_parser *parser, t_data *data)
{
	if (check_textures_color(parser, data))
		return (1);
	if (parse_map(parser, data))
		return (1);
	// int i = 0;       //------------------ to print and test 2d map
	// while (parser->map[i])
	// {
	// 	printf("%s", parser->map[i]);
	// 	i++;
	// }
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
	data->fd = -1;
	init_img(&data->img);
}

void	init_parser(t_parser *parser)
{
	parser->n_path = NULL;
	parser->s_path = NULL;
	parser->w_path = NULL;
	parser->e_path = NULL;
	parser->floor = 0;
	parser->ceiling = 0;
	parser->map = NULL;
}
void	init(t_parser *parser, t_data *data)
{
	init_parser(parser);
	init_data(data);
}
// init ctx, load cfg, window, images