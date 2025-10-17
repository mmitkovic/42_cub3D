/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:50:15 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/15 11:43:26 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*get_correct_texture(t_data *data)
{
	t_ray	*ray;

	ray = data->raycast;
	if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			return (&data->texture[3]);
		else
			return (&data->texture[2]);
	}
	else
	{
		if (ray->raydir_y > 0)
			return (&data->texture[1]);
		else
			return (&data->texture[0]);
	}
	return (NULL);
}

/* --- refactoring needed --- */
void	draw_texture_slice(t_data *data, int x)
{
	t_ray			*ray;
	t_img			*texture;
	double			step;
	double			texture_pos;
	unsigned int	color;

	ray = data->raycast;
	texture = get_correct_texture(data);
	if (!texture || !texture->addr || !texture->mlx_img)
		return ;
	step = 1.0 * (double)texture->h / (double)ray->line_height;
	// Starting texture coordinate
	texture_pos = (ray->draw_start - (WIN_H / 2.0) + ray->line_height / 2) //remember what actually is texture_pos
		* step;
	// if (ray->draw_start == 0)  //ask GEMINI why we may need it
	// 	texture_pos = (WIN_H / 2.0 - ray->line_height / 2.0) * -step;
	while (ray->draw_start < ray->draw_end)
	{
		ray->tex_y = (int)(texture_pos) & (texture->h - 1);
		// get pixel from texture
		color = *(unsigned int *)(texture->addr + (ray->tex_y
				* texture->line_len + ray->tex_x * (texture->bpp / 8)));
		put_pixel(data, x, ray->draw_start, color);
		texture_pos += step;
		ray->draw_start++;
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
	ray->tex_x = (int)(ray->wall_x * texture->w);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = texture->w - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = texture->w - ray->tex_x - 1;
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
