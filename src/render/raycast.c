/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:38:10 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/09 17:18:41 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void calculate_perpdist(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	if (ray->horizontal)
		ray->perp_dist = ray->side_distx - ray->delta_distx;	
	else if (ray->vertical)
		ray->perp_dist = ray->side_disty - ray->delta_disty;
}

void apply_dda(t_data *data)
{
	int		hit;
	t_ray	*ray;

	ray = data->raycast;
	hit = 0;
	while (hit == 0)
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx = ray->side_distx + ray->delta_distx;
			ray->map_x = ray->map_x + ray->step_x;
			ray->horizontal = 1; //x-axis was hit first, means that horizontal wall was hit (direction N-S)
		}
		else
		{
			ray->side_disty = ray->side_disty + ray->delta_disty;
			ray->map_y = ray->map_y + ray->step_y;
			ray->vertical = 1; //y-axis was hit first, i means that vertical wall was hit (direction W-E)
		}
		if (data->parser->map[ray->map_x][ray->map_y] == '1')
		{
			hit = 1;
			data->raycast->hit = 1;
		}
	}
}

void set_side_dist(t_data *data)
{
	t_ray *ray;
	
	ray = data->raycast;
	if (ray->step_x < 0) 
		ray->side_distx = (data->pos_x - ray->map_x) * ray->delta_distx; //looking to the left, pos (x,x) its always less than map_x (a whole number) so we can substract and not get negative value.
	else
		ray->side_distx = (ray->map_x + 1 - data->pos_x) * ray->delta_distx; //map_x is an integer (whole value), we look for the next the to the right. so we add 1 and substract acutal 0,x position. (with a decimal point) so we get positive value
	if (ray->step_y < 0)
		ray->side_disty = (data->pos_y - ray->map_y) * ray->delta_disty; //same
	else
		ray->side_disty = (ray->map_y + 1 - data->pos_y) * ray->delta_disty; //same
	return ;
}

void set_step(t_data *data)
{
	if (data->raycast->raydir_x < 0)
		data->raycast->step_x = -1;
	else
		data->raycast->step_x = 1;
	if (data->raycast->raydir_y < 0)
		data->raycast->step_y = -1;
	else
		data->raycast->step_y = 1;
	return ;
}

void set_delta_dist(t_data *data)
{
	if (data->raycast->raydir_x == 0)
		data->raycast->delta_distx = INFINITY;
	else
		data->raycast->delta_distx = fabs(1 / data->raycast->raydir_x);
	if (data->raycast->raydir_y == 0)
		data->raycast->delta_disty = INFINITY;
	else
		data->raycast->delta_disty = fabs(1 / data->raycast->raydir_y);
	return ;
}