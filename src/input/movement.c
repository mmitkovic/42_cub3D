/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:21:20 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/08 13:08:38 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  WASD, rotate, collision
#include "../../includes/cub3d.h"

void	move_forward(t_data *data)
{
	// key W
	double nx = data->pos_x + data->player.walk_direction * data->player.walk_speed;
	double ny = data->pos_y + data->player.walk_direction * data->player.walk_speed;
	if (data->parser->map[(int)(data->pos_y)][(int)nx] == '0')
		data->pos_x = nx;
	if (data->parser->map[(int)(ny)][(int)data->pos_x] == '0')
		data->pos_y = ny;
}

void	move_back(t_data *data)
{
	// key S
	if ((data->parser->map[(int)(data->pos_y - data->player.walk_direction
				* data->player.walk_speed)][(int)data->pos_x]) == '0')
			data->pos_y -= data->pos_y * data->player.walk_speed;
	// update x
	if (data->parser->map[(int)(data->pos_y)][(int)(data->pos_x
				- data->player.walk_direction * data->player.walk_speed)] == '0')
			data->pos_x -= data->pos_x * data->player.walk_speed;
}

void	move_right(t_data *data)
{
	// key D
	double nx = data->pos_x + data->player.walk_direction * data->player.walk_speed;
	double ny = data->pos_y + data->player.walk_direction * data->player.walk_speed;
	if (data->parser->map[(int)(data->pos_y)][(int)((int)(nx))])
		data->pos_x = nx;
	//check y
	if (data->parser->map[(int)(ny)][(int)(data->pos_x)] == '0')
		data->pos_y = ny;
	
}

void	move_left(t_data *data)
{
}

void move_player(t_data *data)
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
