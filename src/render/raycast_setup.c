/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:16:32 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/14 13:52:33 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	setup_ray(t_data *data, int x)
{
	t_ray	*ray;

	ray = data->raycast;
	// calculate ray position and direction
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->raydir_x = data->dir_x + data->plane_x * ray->camera_x;
	ray->raydir_y = data->dir_y + data->plane_y * ray->camera_x;
	// which box of the map we're in
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
		// calculate ray position and directio
		// which box of the map we're in
		setup_ray(data, x);
		// length of ray from one x or y-side to next x or y-side
		set_delta_dist(data);
		// data->raycast->hit = 0;
		// calculate step and initial sideDist
		set_step(data);
		// perform DDA
		apply_dda(data);
		// Calculate distance projected on camera direction
		calculate_perpdist(data);
		// calculate lowest and highest pixel to fill in current stripe
		draw_wall(data);        // Y-axis: where to draw
		set_wall_pixel_x(data); // X-axis: which column of texture to use
		// texturing calculations
		set_texture_x(data);
		draw_texture_slice(data, x);
		x++;
	}
}
