/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:17:49 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/23 15:27:13 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// put pixel/column, ceiling/floor fill

#include "../../includes/cub3d.h"

void put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*pixel;
	
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)pixel = color;
}

static void	bckgrd_pix_put(t_data *data, int y, int color)
{
	unsigned int	*row;
	int				x;

	row = (unsigned int *)(data->img.addr + y * data->img.line_len);
	x = 0;
	while (x < WIN_W)
	{
		row[x] = color;
		x++;
	}
}

int	render_frame(t_parser *pars, t_data *data, t_img *img)
{
	int	y;
	int	color;

	if (!data->mlx_ptr)
		return (1);
	y = 0;
	while (y < WIN_H)
	{
		if (y < WIN_H / 2)
			color = 0xFFFFFF; // Add color from struct
		else
			color = 0x000000; // Add color from struct
		bckgrd_pix_put(data, y, color);
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}
