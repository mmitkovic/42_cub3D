/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:21:20 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/17 12:00:45 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_data *data)
{
	double	nx;
	double	ny;
	float	speed;
	char	dest_char;

	if (data->delta_time <= 0.0f)
		return ;
	speed = WALK_SPEED * data->delta_time;
	nx = data->pos_x + data->dir_x * speed;
	ny = data->pos_y + data->dir_y * speed;
	dest_char = data->parser->map[(int)ny][(int)nx];
	if (dest_char == '0' || dest_char == 'N' || dest_char == 'S'
		|| dest_char == 'W' || dest_char == 'E')
	{
		data->pos_x = nx;
		data->pos_y = ny;
	}
}

void	move_back(t_data *data)
{
	double	nx;
	double	ny;
	float	speed;
	char	dest_char;

	if (data->delta_time <= 0.0f)
		return ;
	speed = WALK_SPEED * data->delta_time;
	ny = data->pos_y - data->dir_y * speed;
	nx = data->pos_x - data->dir_x * speed;
	dest_char = data->parser->map[(int)ny][(int)nx];
	if (dest_char == '0' || dest_char == 'N' || dest_char == 'S'
		|| dest_char == 'W' || dest_char == 'E')
	{
		data->pos_x = nx;
		data->pos_y = ny;
	}
}

void	move_right(t_data *data)
{
	double	nx;
	double	ny;
	float	speed;
	char	dest_char;

	if (data->delta_time <= 0.0f)
		return ;
	speed = WALK_SPEED * data->delta_time;
	nx = data->pos_x + data->plane_x * speed;
	ny = data->pos_y + data->plane_y * speed;
	dest_char = data->parser->map[(int)ny][(int)nx];
	if (dest_char == '0' || dest_char == 'N' || dest_char == 'S'
		|| dest_char == 'W' || dest_char == 'E')
	{
		data->pos_x = nx;
		data->pos_y = ny;
	}
}

void	move_left(t_data *data)
{
	double	nx;
	double	ny;
	float	speed;
	char	dest_char;

	if (data->delta_time <= 0.0f)
		return ;
	speed = WALK_SPEED * data->delta_time;
	nx = data->pos_x - data->plane_x * speed;
	ny = data->pos_y - data->plane_y * speed;
	dest_char = data->parser->map[(int)ny][(int)nx];
	if (dest_char == '0' || dest_char == 'N' || dest_char == 'S'
		|| dest_char == 'W' || dest_char == 'E')
	{
		data->pos_x = nx;
		data->pos_y = ny;
	}
}

void	handle_movement(t_data *data)
{
	if (data->pl_mv_f)
		move_forward(data);
	if (data->pl_mv_b)
		move_back(data);
	if (data->pl_mv_r)
		move_right(data);
	if (data->pl_mv_l)
		move_left(data);
}
