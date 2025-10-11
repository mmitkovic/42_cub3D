/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:50:15 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/11 16:21:53 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*get_correct_texture(t_data *data)				//not sure about the texture assignments
{
	t_ray *ray;

	ray = data->raycast;
	if (ray->horizontal == 1) 
	{
		if (data->dir_x > 0)
			return (&data->texture[3]);
		else
			return (&data->texture[1]);
	}
	else if (ray->vertical == 1)
	{
		if (ray->raydir_y > 0)
			return (&data->texture[1]);
		else
			return (&data->texture[0]);
	}
	return (NULL);
}

void	draw_texture_slice(t_data *data, int x)
{
	t_ray			*ray;
	double			y;
	t_img			*texture;
	double			step;
	char			*pixel_addr;
	double			texture_pos;
	unsigned int	color;
	
	ray = data->raycast;
	y = ray->draw_start;
	step = 1.0 * TEX_SIZE / ray->line_height;
	texture_pos = (y - WIN_H / 2 + ray->line_height / 2) * step;
	texture = get_correct_texture(data);
	if (!texture || !texture->addr)
		return ;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)(texture_pos) & (TEX_SIZE - 1);
		texture_pos = texture_pos + step;
		pixel_addr = texture->addr + (ray->tex_y * texture->line_len + ray->tex_x * (texture->bpp / 8));
		color = *(unsigned int *)pixel_addr;
		put_pixel(data, x, y, color);
		y++;
	}
}

void	set_texture_x(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	ray->tex_x = (int)(ray->wall_x * TEX_SIZE);
	if (ray->vertical == 1 && ray->raydir_x > 0)
		ray->tex_x = TEX_SIZE - ray->tex_x - 1;
	else if (ray->horizontal == 1 && ray->raydir_y < 0)
		ray->tex_x = TEX_SIZE - ray->tex_x - 1;
	return ;
}

void	set_wall_pixel_x(t_data *data)
{
	t_ray *ray;

	ray = data->raycast;
	if (ray->horizontal)
		ray->wall_x = data->pos_y + ray->perp_dist * ray->raydir_y;
	else if (ray->vertical)
		ray->wall_x = data->pos_x + ray->perp_dist * ray->raydir_x;
	ray->wall_x = ray->wall_x - floor((ray->wall_x));
	ray->tex_x = (int)(ray->wall_x * TEX_SIZE);
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