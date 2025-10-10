/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:50:15 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/10 10:57:11 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*get_correct_texture(t_data *data)				//not sure about the texture assignments
{
	t_ray *ray;

	ray = data->raycast;
	if (ray->horizontal == 1) 
	{
		if (ray->raydir_x > 0)
			return (&data->texture[3]);
		else
			return (&data->texture[2]);
	}
	else if (ray->vertical == 1)
	{
		if (ray->raydir_y > 0)
			return (&data->texture[0]);
		else
			return (&data->texture[1]);
	}
	return (NULL);
}

void	draw_texture_slice(t_data *data)
{
	t_ray	*ray;
	double	y;
	int		color;
	t_img	*texture;
	
	color = 0;
	ray = data->raycast;
	y = ray->draw_start;
	texture = get_correct_texture(data);
	while (y < ray->draw_end)
	{
		//UNDONE
		// put_pixel(data, ray->tex_x, y, texture/*[exact coordinates of a pixel in a texture to cast on a wall]*/);
		y++;
	}
}

void	set_texture_x(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	ray->tex_x = (int)(ray->wall_x * TEX_SIZE/*(double)(data->img->w)*/);
	if (ray->horizontal == 1 && ray->raydir_x > 0)
		ray->tex_x = TEX_SIZE - ray->tex_x - 1;
	else if (ray->vertical == 1 && ray->raydir_y < 0)
		ray->tex_x = TEX_SIZE - ray->tex_x - 1;
	return ;
}

void	set_wall_pixel_x(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	if (ray->vertical)
		ray->wall_x = data->pos_y + ray->perp_dist * ray->raydir_y;
	else if (ray->horizontal)
		ray->wall_x = data->pos_x + ray->perp_dist * ray->raydir_x;
	ray->wall_x = ray->wall_x - floor((ray->wall_x));
	return ;
}

void	draw_wall(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	ray->line_height = WIN_H / ray->perp_dist;
	ray->draw_start = -(ray->line_height) / 2 + WIN_H / 2;
    if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;	
}