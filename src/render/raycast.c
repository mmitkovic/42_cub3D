/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:38:10 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/15 16:09:17 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_perpdist(t_data *data)
{
	t_ray	*ray;

	ray = data->raycast;
	if (ray->side == 0)
		ray->perp_dist = ray->side_distx - ray->delta_distx;
	else
		ray->perp_dist = ray->side_disty - ray->delta_disty;
	if (ray->perp_dist <= 0.1)
		data->cant_move_forward = 1;
	else
		data->cant_move_forward = 0;
}

int check_guards(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	if (ray->map_y < 0 || data->parser->map[ray->map_y] == NULL)
	{
		ray->hit = 1;
		return (1);
	}
	if (ray->map_x < 0 || ray->map_x
					>= (int)(ft_strlen(data->parser->map[ray->map_y])))
	{
		ray->hit = 1;
		return (1);
	}
	return (0);
}

/*deleted max_depth and took guards outside*/
void	apply_dda(t_data *data)
{
	t_ray	*ray;
	
	ray = data->raycast;
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_distx;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_disty += ray->delta_disty;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (check_guards(data))
			continue;
		if (data->parser->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	set_step(t_data *data)
{
	if (data->raycast->raydir_x < 0)
	{
		data->raycast->step_x = -1;
		data->raycast->side_distx = (data->pos_x - data->raycast->map_x)
			* data->raycast->delta_distx;
	}
	else
	{
		data->raycast->step_x = 1;
		data->raycast->side_distx = (data->raycast->map_x + 1.0 - data->pos_x)
			* data->raycast->delta_distx;
	}
	if (data->raycast->raydir_y < 0)
	{
		data->raycast->step_y = -1;
		data->raycast->side_disty = (data->pos_y - data->raycast->map_y)
			* data->raycast->delta_disty;
	}
	else
	{
		data->raycast->step_y = 1;
		data->raycast->side_disty = (data->raycast->map_y + 1.0 - data->pos_y)
			* data->raycast->delta_disty;
	}
}

void	set_delta_dist(t_data *data)
{
	if (data->raycast->raydir_x == 0)
		data->raycast->delta_distx = 1e30;
	else
		data->raycast->delta_distx = fabs(1 / data->raycast->raydir_x);
	if (data->raycast->raydir_y == 0)
		data->raycast->delta_disty = 1e30;
	else
		data->raycast->delta_disty = fabs(1 / data->raycast->raydir_y);
}