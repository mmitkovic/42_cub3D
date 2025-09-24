/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:17:49 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/09/24 15:29:24 by hgatarek         ###   ########.fr       */
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

// static void	bckgrd_pix_put(t_data *data, int y, int color)
// {
// 	unsigned int	*row;
// 	int				x;

// 	row = (unsigned int *)(data->img.addr + y * data->img.line_len);
// 	x = 0;
// 	while (x < WIN_W)
// 	{
// 		row[x] = color;
// 		x++;
// 	}
// }

int	render_frame(t_parser *pars, t_data *data)
{
	int	y;
	int	color;

	if (!data->mlx_ptr)
		return (1);
	y = 0;
	while (y < WIN_H)
	{
		if (y < WIN_H / 2)
			color = pars->ceiling;
		else
			color = pars->floor;
		//bckgrd_pix_put(data, y, color);
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
