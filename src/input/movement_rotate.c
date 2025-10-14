/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:19:42 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/14 17:12:49 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-ROT_SPEED) - data->dir_y 
				* sin(-ROT_SPEED);
	data->dir_y = old_dir_x * sin(-ROT_SPEED) + data->dir_y 
				* cos(-ROT_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-ROT_SPEED) - data->plane_y
		* sin(-ROT_SPEED);
	data->plane_y = old_plane_x * sin(-ROT_SPEED) + data->plane_y
		* cos(-ROT_SPEED);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(ROT_SPEED) - data->dir_y * sin(ROT_SPEED);
	data->dir_y = old_dir_x * sin(ROT_SPEED) + data->dir_y * cos(ROT_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(ROT_SPEED) - data->plane_y
		* sin(ROT_SPEED);
	data->plane_y = old_plane_x * sin(ROT_SPEED) + data->plane_y
		* cos(ROT_SPEED);
}

void	handle_rotation(t_data *data)
{
	if (data->pl_rot_l)
		rotate_left(data);
	if (data->pl_rot_r)
		rotate_right(data);
}
