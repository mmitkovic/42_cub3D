/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:16:32 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/15 15:54:10 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*calculate ray position and direction and which box of the map we're in*/
void	setup_ray(t_data *data, int x)
{
	t_ray	*ray;

	ray = data->raycast;
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->raydir_x = data->dir_x + data->plane_x * ray->camera_x;
	ray->raydir_y = data->dir_y + data->plane_y * ray->camera_x;
	ray->map_x = (int)data->pos_x;
	ray->map_y = (int)data->pos_y;
}

void	init_camera_plane(t_data *data)
{
	if (data->player_letter == 'N')
	{
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (data->player_letter == 'S')
	{
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else if (data->player_letter == 'W')
	{
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	else if (data->player_letter == 'E')
	{
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	return ;
}

void	init_direction_vector(t_data *data)
{
	if (data->player_letter == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (data->player_letter == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	else if (data->player_letter == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	else if (data->player_letter == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	return ;
}

void	init_raycast(t_ray *raycast)
{
	raycast->raydir_x = 0.00;
	raycast->raydir_y = 0.00;
	raycast->angle = 0.00;
	raycast->camera_x = 0.00;
	raycast->delta_distx = 0.00;
	raycast->delta_disty = 0.00;
	raycast->map_x = 0;
	raycast->map_y = 0;
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->side_distx = 0;
	raycast->side_disty = 0;
	raycast->hit = 0;
	raycast->perp_dist = 0;
	raycast->line_height = 0;
	raycast->draw_start = 0;
	raycast->draw_end = 0;
	raycast->wall_x = 0;
	raycast->tex_x = 0;
	raycast->tex_y = 0;
	raycast->side = 0;
}

void	distribute_raycast(t_data *data)
{
	int	x;

	x = 0;
	draw_floor_ceiling(data);
	while (x < WIN_W)
	{
		setup_ray(data, x);
		set_delta_dist(data);
		set_step(data);
		apply_dda(data);
		calculate_perpdist(data);
		draw_wall(data);
		set_wall_pixel_x(data);
		set_texture_x(data);
		draw_texture_slice(data, x);
		x++;
	}
}
