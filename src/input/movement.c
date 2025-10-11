/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:21:20 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/11 14:44:44 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  WASD, rotate, collision
#include "../../includes/cub3d.h"

void	move_forward(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->pos_x + data->dir_x * WALK_SPEED;
	ny = data->pos_y + data->dir_y * WALK_SPEED;
	if (data->pl_mv_f)
	{
		if (data->parser->map[(int)(data->pos_y)][(int)nx] == '0')
			data->pos_x = nx;
		if (data->parser->map[(int)(ny)][(int)data->pos_x] == '0')
			data->pos_y = ny;
	}
}

void	move_back(t_data *data)
{
	double	nx;
	double	ny;

	ny = data->pos_y - data->dir_x * WALK_SPEED;
	nx = data->pos_x - data->dir_y * WALK_SPEED;
	if (data->pl_mv_b)
	{
		if (data->parser->map[(int)data->pos_y][(int)nx] == '0')
			data->pos_x = nx;
		if ((data->parser->map[(int)ny][(int)data->pos_x]) == '0')
			data->pos_y = ny;
	}
}

void	move_right(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->pos_x + data->dir_x * WALK_SPEED;
	ny = data->pos_y + data->dir_y * WALK_SPEED;
	if (data->pl_mv_r)
	{
		if (data->parser->map[(int)data->pos_y][(int)nx] == '0')
			data->pos_x = nx;
		if (data->parser->map[(int)ny][(int)data->pos_x] == '0')
			data->pos_y = ny;
	}
}

void	move_left(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->pos_x - data->dir_x * WALK_SPEED;
	ny = data->pos_y - data->dir_y * WALK_SPEED;
	if (data->pl_mv_l)
	{
		if (data->parser->map[(int)data->pos_y][(int)nx] == '0')
			data->pos_x = nx;
		if (data->parser->map[(int)ny][(int)data->pos_x] == '0')
			data->pos_y = ny;
	}
}

// void	move_player(t_data *data)
// {
// 	// if (/*moving forward*/)
// 	move_forward(data);
// 	// if (/*moving back*/)
// 	move_back(data);
// 	// if (/*moving right*/)
// 	move_right(data);
// 	// if (/*moving left*/)
// 	move_left(data);
// }
