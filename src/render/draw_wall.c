/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:50:15 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/14 14:09:19 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*get_correct_texture(t_data *data)
{
	t_ray	*ray;

	ray = data->raycast;
	if (ray->side == 0) // hit vertical wall (N-S)
	{
		if (ray->raydir_x > 0)
			return (&data->texture[3]); // east
		else
			return (&data->texture[2]); // west
	}
	else
	{
		if (ray->raydir_y > 0)
			return (&data->texture[1]); // south
		else
			return (&data->texture[0]); // north
	}
	return (NULL);
}

/* --- refactoring needed --- */
void	draw_texture_slice(t_data *data, int x)
{
	t_ray			*ray;
	t_img			*texture;
	int				y;
	double			step;
	double			texture_pos;
	unsigned int	color;

	ray = data->raycast;
	y = ray->draw_start;
	texture = get_correct_texture(data);
	if (!texture || !texture->addr || !texture->mlx_img)
		return ;
	step = 1.0 * (double)texture->h / (double)ray->line_height;
	// Starting texture coordinate
	texture_pos = (ray->draw_start - (WIN_H / 2.0) + ray->line_height / 2.0)
		* step;
	if (ray->draw_start == 0)
		texture_pos = (WIN_H / 2.0 - ray->line_height / 2.0) * -step;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)(texture_pos) & (texture->h - 1);
		// get pixel from texture
		if (ray->tex_y >= 0 && ray->tex_y < texture->h)
		{
			color = *(unsigned int *)(texture->addr + (ray->tex_y
						* texture->line_len + ray->tex_x * (texture->bpp / 8)));
			put_pixel(data, x, y, color);
		}
		texture_pos += step;
		y++;
	}
}

// Update set_texture_x to use actual texture width
void	set_texture_x(t_data *data)
{
	t_ray	*ray;
	t_img	*texture;

	ray = data->raycast;
	texture = get_correct_texture(data);
	if (!texture)
		return ;
	// Use actual texture width
	ray->tex_x = (int)(ray->wall_x * texture->w);
	// Mirror texture based on wall orientation
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = texture->w - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = texture->w - ray->tex_x - 1;
	// Clamp to valid range
	if (ray->tex_x < 0)
		ray->tex_x = 0;
	if (ray->tex_x >= texture->w)
		ray->tex_x = texture->w - 1;
}

void	set_wall_pixel_x(t_data *data)
{
	t_ray	*ray;

	ray = data->raycast;
	if (ray->side == 0)
		ray->wall_x = data->pos_y + ray->perp_dist * ray->raydir_y;
	else
		ray->wall_x = data->pos_x + ray->perp_dist * ray->raydir_x;
	ray->wall_x -= floor((ray->wall_x));
}

void	draw_wall(t_data *data)
{
	t_ray	*ray;

	ray = data->raycast;
	ray->line_height = (int)(WIN_H / ray->perp_dist);
	ray->draw_start = -(ray->line_height) / 2 + WIN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
}
