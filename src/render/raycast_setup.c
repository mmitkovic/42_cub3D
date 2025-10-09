/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:16:32 by mmitkovi          #+#    #+#             */
/*   Updated: 2025/10/09 11:56:52 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//Should send for example 60 rays in my FOV, and each ray should have its own raycast sruct
//to hold the information
//Should update each time in the loop the player position (play vector)


//1) Find the direction vector --- OK
//2) Find the ray position --- OK
//3) Find the delsta dist --- OK
//4) Find the step valure ---- IN PROGRESS

void find_ray_position(t_data *data, int *x, double *camera_x)
{
	*camera_x = 2 * *x / (double)(WIN_W) - 1;   //i only look for x. thats enough for each column, always betwen -1 and 1.
	data->raycast->raydir_x = data->dir_x + data->plane_x * *camera_x;
	data->raycast->raydir_y = data->dir_y + data->plane_y * *camera_x;
	return ;
}

void init_camera_plane(t_data *data)
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

void init_direction_vector(t_data *data)   			//how it gets updates when it already started?
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

void distribute_raycast(t_data *data)
{
	int		x;
	double	ray_angle;
	
	ray_angle = 0;
	x = 0;
	//player starting position is pos_x, pos_y in data.
	init_direction_vector(data);   //i think i dont need to &it?
	init_camera_plane(data);
	data->raycast->map_x = (int)data->pos_x;				//why they cast int when its already int?
	data->raycast->map_y = (int)data->pos_y;	
	while (x < WIN_W)
	{
		find_ray_position(data, &x, &data->raycast->camera_x);
		set_delta_dist(data);
		set_step(data);
		set_side_dist(data);
		apply_dda(data);
		//calculate_perpdist(data);
		//draw_wall(data);
		x++;
	}
}

// void init_raycast(t_ray *raycast)
// {
// 	raycast->raydir_x = 0.01;
// 	raycast->raydir_y = 0.01;
// 	raycast->angle = 0.01;
// 	raycast->camera_x = 0.01;
// 	raycast->delta_distx = 0.01;
// 	raycast->delta_disty = 0.01;
// 	raycast->map_x = 0;
// 	raycast->map_x = 0;
// 	raycast->step_x = 0;
// 	raycast->step_y = 0;
// 	raycast->side_distx = 0;
// 	raycast->side_disty = 0;
// 	raycast->hit = 0;
// 	raycast->horizontal = 0;
// 	raycast->vertical = 0;
// 	raycast->perp_dist = 0;
// 	raycast->line_height = 0;
// }
