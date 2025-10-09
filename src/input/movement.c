/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:21:20 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/09 12:37:26 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  WASD, rotate, collision
#include "../../includes/cub3d.h"

void	move_forward(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->pos_x + data->player.walk_direction * data->player.walk_speed;
	ny = data->pos_y + data->player.walk_direction * data->player.walk_speed;
	if (data->parser->map[(int)(data->pos_y)][(int)nx] == '0')
		data->pos_x = nx;
	if (data->parser->map[(int)(ny)][(int)data->pos_x] == '0')
		data->pos_y = ny;
}

void	move_back(t_data *data)
{
	double	nx;
	double	ny;

	ny = data->pos_y - data->player.walk_direction * data->player.walk_speed;
	nx = data->pos_x - data->player.walk_direction * data->player.walk_speed;
	if (data->parser->map[(int)data->pos_y][(int)nx] == '0')
		data->pos_x = nx;
	if ((data->parser->map[(int)ny][(int)data->pos_x]) == '0')
		data->pos_y = ny;
}

void	move_right(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->pos_x + data->player.walk_direction * data->player.walk_speed;
	ny = data->pos_y + data->player.walk_direction * data->player.walk_speed;
	if (data->parser->map[(int)data->pos_y][(int)nx] == '0')
		data->pos_x = nx;
	if (data->parser->map[(int)ny][(int)data->pos_x] == '0')
		data->pos_y = ny;
}

void	move_left(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->pos_x - data->player.walk_direction * data->player.walk_speed;
	ny = data->pos_y + data->player.walk_direction * data->player.walk_speed;
	if (data->parser->map[(int)data->pos_y][(int)nx] == '0')
		data->pos_x = nx;
	if (data->parser->map[(int)ny][(int)data->pos_x] == '0')
		data->pos_y = ny;
}

void	move_player(t_data *data)
{
	// if (/*moving forward*/)
	move_forward(data);
	// if (/*moving back*/)
	move_back(data);
	// if (/*moving right*/)
	move_right(data);
	// if (/*moving left*/)
	move_left(data);
}
