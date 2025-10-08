/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:17:49 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/08 08:09:26 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// put pixel/column, ceiling/floor fill

#include "../../includes/cub3d.h"

void	put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)pixel = color;
}

static void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WIN_H)
	{
		if (y < WIN_H / 2)
			color = data->parser->ceiling;
		else
			color = data->parser->floor;
		x = 0;
		while (x < WIN_W)
		{
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_frame(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!data->mlx_ptr)
		return (1);
	draw_floor_ceiling(data);
	distribute_raycast(data); //everything starts here from raycast in a loop
	// TODO:
	// Render map objects
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	return (0);
}
