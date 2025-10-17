/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:17:49 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/15 15:50:15 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*pixel;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_floor_ceiling(t_data *data)
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
	calc_timeframe(data);
	if (data->pl_mv_f || data->pl_mv_b || data->pl_mv_l || data->pl_mv_r)
		handle_movement(data);
	if (data->pl_rot_l || data->pl_rot_r)
		handle_rotation(data);
	distribute_raycast(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	return (0);
}
