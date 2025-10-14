/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:17:36 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/14 14:10:05 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_size(t_parser *parser)
{
	int	y;
	int	x_end;
	int	x_start;
	int	line_w;

	y = 0;
	parser->w = 0;
	while (parser->map[y])
	{
		x_start = 0;
		x_end = 0;
		while (parser->map[y][x_end] != '\0')
			x_end++;
		x_end--;
		while (x_end >= x_start && parser->map[y][x_end] == ' ')
			x_end--;
		line_w = x_end - x_start + 1;
		if (line_w > parser->w)
			parser->w = line_w;
		y++;
	}
	parser->h = y;
}
